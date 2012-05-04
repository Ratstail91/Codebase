/* File Name: image.h
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
#ifndef KR_IMAGE_H_
#define KR_IMAGE_H_ 2012032001

#include "SDL.h"

class Image {
public:
	/* Public access members */
	Image();
	Image(const char* szFileName, int x=0, int y=0, int w=0, int h=0);
	Image(SDL_Surface* pSurface,  int x=0, int y=0, int w=0, int h=0);
	virtual ~Image();

	void Load(const char* szFileName, int x=0, int y=0, int w=0, int h=0);
	void Unload();
	virtual void DrawTo(SDL_Surface* const, int iCamX=0, int iCamY=0);

	void SetColorKey(int iRed=255, int iGreen=0, int iBlue=255);
	void ClearColorKey();

	bool Local();

	/* Overloaded oprators */
	Image& operator=(Image&);
	Image& operator=(SDL_Surface*);

	/* Accessors and mutators */
	int SetX(int);
	int SetY(int);
	int SetW(int);
	int SetH(int);

	int GetX();
	int GetY();
	int GetW();
	int GetH();

	int SetSheetX(int);
	int SetSheetY(int);

	int GetSheetX();
	int GetSheetY();
	int GetSheetW();
	int GetSheetH();

	/* Preferences */
	int SetWidth		(int i) { return SetW(i); }
	int SetHeight		(int i) { return SetH(i); }
	int GetWidth		() { return GetW(); }
	int GetHeight		() { return GetH(); }
	int GetSheetWidth	() { return GetSheetW(); }
	int GetSheetHeight	() { return GetSheetH(); }

protected:
	/* Protected access members */
	SDL_Surface* SetSurface(SDL_Surface*);
	SDL_Surface* GetSurface();

private:
	/* Private access members */
	SDL_Rect m_sclip;
	SDL_Rect m_dclip;
	SDL_Surface* m_pSurface;
	bool m_bLocal;
};

#endif
