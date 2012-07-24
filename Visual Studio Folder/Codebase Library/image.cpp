/* File Name: image.cpp
 * Author: Kayne Ruse
 * Date: 25/7/2012
 * Copyright: (c) Kayne Ruse 2012
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * Description:
 *     A wrapper for SDL_Surface, and it's rendering functionality.
*/
#include <exception>
#include "image.h"

//-------------------------
//Preprocessor
//-------------------------

//lazy shortcut
#define CHECK_LOADED if (m_pSurface == NULL) throw(std::exception("No bitmap loaded"))
#define CHECK_UNLOADED if (m_pSurface != NULL) throw(std::exception("Bitmap loaded"))

//-------------------------
//Public access members
//-------------------------

Image::Image() {
	Init();
}

Image::Image(const char* szFileName, Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	Init();
	LoadImage(szFileName, x, y, w, h);
}

Image::Image(SDL_Surface* pSurface,  Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	Init();
	LoadImage(pSurface, x, y, w, h);
}

Image::~Image() {
	UnloadImage();
}

void Image::LoadImage(const char* szFileName, Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	UnloadImage();
	m_pSurface = SDL_LoadBMP(szFileName);

	CHECK_LOADED;

	m_bLocal = true;

	SetImageColorKey();

	m_sclip.x = 0;
	m_sclip.y = 0;
	m_sclip.w = (w == 0) ? m_pSurface->w : w;
	m_sclip.h = (h == 0) ? m_pSurface->h : h;
	m_dclip.x = x;
	m_dclip.y = y;
}

void Image::LoadImage(SDL_Surface* pSurface, Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	UnloadImage();

	if (pSurface == NULL) return; //dh protection

	m_pSurface = pSurface;
	m_bLocal = false;

	m_sclip.x = 0;
	m_sclip.y = 0;
	m_sclip.w = (w == 0) ? m_pSurface->w : w;
	m_sclip.h = (h == 0) ? m_pSurface->h : h;
	m_dclip.x = x;
	m_dclip.y = y;
}

void Image::UnloadImage() {
	if (m_pSurface == NULL)
		return;

	if (m_bLocal)
		SDL_FreeSurface(m_pSurface);

	m_pSurface = NULL;
	m_bLocal = false;
}

void Image::SetImageColorKey(Uint8 iRed, Uint8 iGreen, Uint8 iBlue) {
	CHECK_LOADED;
	SDL_SetColorKey(m_pSurface, SDL_SRCCOLORKEY, SDL_MapRGB(m_pSurface->format, iRed, iGreen, iBlue));
}

void Image::ClearColorKey() {
	CHECK_LOADED;
	SDL_SetColorKey(m_pSurface, 0, 0);
}

void Image::DrawTo(SDL_Surface* const pDest, Sint16 iCamX, Sint16 iCamY) {
	CHECK_LOADED;

	//local dclip to compensate the camera hooks
	SDL_Rect dclip = m_dclip;

	dclip.x += iCamX;
	dclip.y += iCamY;

	SDL_BlitSurface(m_pSurface, &m_sclip, pDest, &dclip);
}

//-------------------------
//Accessors and mutators
//-------------------------

void Image::SetImagePosition(Sint16 x, Sint16 y) {
	m_dclip.x = x;
	m_dclip.y = y;
}

Sint16 Image::SetImageX(Sint16 x) {
	return m_dclip.x = x;
}

Sint16 Image::SetImageY(Sint16 y) {
	return m_dclip.y = y;
}

Uint16 Image::SetImageW(Uint16 w) {
	return m_sclip.w = w;
}

Uint16 Image::SetImageH(Uint16 h) {
	return m_sclip.h = h;
}

Sint16 Image::GetImageX() {
	return m_dclip.x;
}

Sint16 Image::GetImageY() {
	return m_dclip.y;
}

Uint16 Image::GetImageW() {
	return m_sclip.w;
}

Uint16 Image::GetImageH() {
	return m_sclip.h;
}

Sint16 Image::SetSheetX(Sint16 x) {
	return m_sclip.x = x;
}

Sint16 Image::SetSheetY(Sint16 y) {
	return m_sclip.y = y;
}

Sint16 Image::GetSheetX() {
	return m_sclip.x;
}

Sint16 Image::GetSheetY() {
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

bool Image::IsLoadedImage() {
	return m_pSurface != NULL;
}

bool Image::IsLocalImage() {
	return m_bLocal;
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

//-------------------------
//Private access members
//-------------------------

void Image::Init() {
	m_sclip.x = 0;
	m_sclip.y = 0;
	m_sclip.w = 0;
	m_sclip.h = 0;
	m_dclip.x = 0;
	m_dclip.y = 0;

	m_pSurface = NULL;
	m_bLocal = false;
}
