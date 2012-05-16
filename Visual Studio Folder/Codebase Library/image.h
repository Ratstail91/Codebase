/* File Name: image.h
 * Author: Kayne Ruse
 * Date: 16/5/2012
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
*/
#ifndef KR_IMAGE_H_
#define KR_IMAGE_H_ 2012051601

#include "SDL.h"

class Image {
public:
	/* Public access members */
	Image();
	Image(const char* szFileName, int x=0, int y=0, int w=0, int h=0);
	Image(SDL_Surface* pSurface,  int x=0, int y=0, int w=0, int h=0);
	virtual ~Image();

	void LoadImage(const char* szFileName, int x=0, int y=0, int w=0, int h=0);
	void LoadImage(SDL_Surface* pSurface,  int x=0, int y=0, int w=0, int h=0);
	void UnloadImage();

	void SetColorKey(int iRed=255, int iGreen=0, int iBlue=255);
	void ClearColorKey();

	virtual void DrawTo(SDL_Surface* const, int iCamX=0, int iCamY=0);

	/* Accessors and mutators */
	int SetImageX(int);
	int SetImageY(int);
	int SetImageW(int);
	int SetImageH(int);

	int GetImageX();
	int GetImageY();
	int GetImageW();
	int GetImageH();

	int SetSheetX(int);
	int SetSheetY(int);

	int GetSheetX();
	int GetSheetY();
	int GetSheetW();
	int GetSheetH();

	bool Local();

protected:
	/* Protected access members */
	SDL_Surface* SetSurface(SDL_Surface*);
	SDL_Surface* GetSurface();

private:
	/* Private access members */
	void Init();

	SDL_Rect m_sclip;
	SDL_Rect m_dclip;
	SDL_Surface* m_pSurface;
	bool m_bLocal;
};

#endif
