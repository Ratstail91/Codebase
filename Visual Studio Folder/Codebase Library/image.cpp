/* File Name: image.cpp
 * Author: Kayne Ruse
 * Date: 20/3/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Codebase Library.
 * 
 * Codebase Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Codebase Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Codebase Library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     A wrapper for SDL_Surface, and it's rendering functionality.
 *     This is the oldest and most stable piece of code I own.
*/
#include <exception>
#include "image.h"

//-------------------------
//Preprocessor
//-------------------------

#define CHECK_LOADED if (m_pSurface == NULL) throw(std::exception("No bitmap loaded"))
#define CHECK_UNLOADED if (m_pSurface != NULL) throw(std::exception("Bitmap loaded"))

//-------------------------
//Public access members
//-------------------------

Image::Image() {
	m_pSurface = NULL;
	m_bLocal = false;

	m_sclip.x = 0;
	m_sclip.y = 0;
	m_sclip.w = 0;
	m_sclip.h = 0;
	m_dclip.x = 0;
	m_dclip.y = 0;
}

Image::Image(const char* szFileName, int x, int y, int w, int h) {
	Load(szFileName, x, y, w, h);
}

Image::Image(SDL_Surface* pSurface,  int x, int y, int w, int h) {
	m_pSurface = pSurface;
	m_bLocal = false;

	m_sclip.x = 0;
	m_sclip.y = 0;
	m_sclip.w = (w == 0) ? m_pSurface->w : w;
	m_sclip.h = (h == 0) ? m_pSurface->h : h;
	m_dclip.x = x;
	m_dclip.y = y;
}

Image::~Image() {
	Unload();
}

void Image::Load(const char* szFileName, int x, int y, int w, int h) {
	CHECK_UNLOADED;
	m_pSurface = SDL_LoadBMP(szFileName);
	CHECK_LOADED;

	m_bLocal = true;

	SetColorKey();

	m_sclip.x = 0;
	m_sclip.y = 0;
	m_sclip.w = (w == 0) ? m_pSurface->w : w;
	m_sclip.h = (h == 0) ? m_pSurface->h : h;
	m_dclip.x = x;
	m_dclip.y = y;
}

void Image::Unload() {
	if (m_bLocal)
		SDL_FreeSurface(m_pSurface);
	m_pSurface = NULL;
	m_bLocal = false;
}

void Image::DrawTo(SDL_Surface* const pDest, int iCamX, int iCamY) {
	CHECK_LOADED;

	SDL_Rect dclip = m_dclip;

	dclip.x += iCamX;
	dclip.y += iCamY;

	SDL_BlitSurface(m_pSurface, &m_sclip, pDest, &dclip);
}

void Image::SetColorKey(int iRed, int iGreen, int iBlue) {
	CHECK_LOADED;
	SDL_SetColorKey(m_pSurface, SDL_SRCCOLORKEY, SDL_MapRGB(m_pSurface->format, iRed, iGreen, iBlue));
}

void Image::ClearColorKey() {
	CHECK_LOADED;
	SDL_SetColorKey(m_pSurface, 0, 0);
}

bool Image::Local() {
	return m_bLocal;
}

//-------------------------
//Overloaded oprators
//-------------------------

Image& Image::operator=(Image& other) {
	m_pSurface = other.m_pSurface;
	m_bLocal = false;

	//deep copy
	m_sclip.x = other.m_sclip.x;
	m_sclip.y = other.m_sclip.y;
	m_sclip.w = other.m_sclip.w;
	m_sclip.h = other.m_sclip.h;
	m_dclip.x = other.m_dclip.x;
	m_dclip.y = other.m_dclip.y;

	return *this;
}

Image& Image::operator=(SDL_Surface* other) {
	m_pSurface = other;
	m_bLocal = false;

	//defaults
//	m_sclip.x = 0;
//	m_sclip.y = 0;
//	m_sclip.w = m_pSurface->w;
//	m_sclip.h = m_pSurface->h;
//	m_dclip.x
//	m_dclip.y

	return *this;
}

//-------------------------
//Accessors and mutators
//-------------------------

int Image::SetX(int x) {
	return m_dclip.x = x;
}

int Image::SetY(int y) {
	return m_dclip.y = y;
}

int Image::SetW(int w) {
	return m_sclip.w = w;
}

int Image::SetH(int h) {
	return m_sclip.h = h;
}

int Image::GetX() {
	return m_dclip.x;
}

int Image::GetY() {
	return m_dclip.y;
}

int Image::GetW() {
	return m_sclip.w;
}

int Image::GetH() {
	return m_sclip.h;
}

int Image::SetSheetX(int x) {
	return m_sclip.x = x;
}

int Image::SetSheetY(int y) {
	return m_sclip.y = y;
}

int Image::GetSheetX() {
	return m_sclip.x;
}

int Image::GetSheetY() {
	return m_sclip.y;
}

int Image::GetSheetW() {
	CHECK_LOADED;
	return m_pSurface->w;
}

int Image::GetSheetH() {
	CHECK_LOADED;
	return m_pSurface->h;
}

//-------------------------
//Protected access members
//-------------------------

SDL_Surface* Image::SetSurface(SDL_Surface* pSurface) {
	return m_pSurface = pSurface;
}

SDL_Surface* Image::GetSurface() {
	return m_pSurface;
}
