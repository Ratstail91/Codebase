/* File Name: image.h
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
#ifndef KR_IMAGE_H_
#define KR_IMAGE_H_ 2012072501

#include "SDL.h"

class Image {
public:
	/* Public access members */
	Image();
	Image(const char* szFileName, Sint16 x=0, Sint16 y=0, Uint16 w=0, Uint16 h=0);
	Image(SDL_Surface* pSurface,  Sint16 x=0, Sint16 y=0, Uint16 w=0, Uint16 h=0);
	virtual ~Image();

	virtual void LoadImage(const char* szFileName, Sint16 x=0, Sint16 y=0, Uint16 w=0, Uint16 h=0);
	virtual void LoadImage(SDL_Surface* pSurface,  Sint16 x=0, Sint16 y=0, Uint16 w=0, Uint16 h=0);
	virtual void UnloadImage();

	virtual void SetImageColorKey(Uint8 iRed=255, Uint8 iGreen=0, Uint8 iBlue=255);
	virtual void ClearColorKey();

	virtual void DrawTo(SDL_Surface* const, Sint16 iCamX=0, Sint16 iCamY=0);

	/* Accessors and mutators */
	virtual void SetImagePosition(Sint16 x, Sint16 y);

	virtual Sint16 SetImageX(Sint16 x);
	virtual Sint16 SetImageY(Sint16 y);
	virtual Uint16 SetImageW(Uint16 w);
	virtual Uint16 SetImageH(Uint16 h);

	virtual Sint16 GetImageX();
	virtual Sint16 GetImageY();
	virtual Uint16 GetImageW();
	virtual Uint16 GetImageH();

	virtual Sint16 SetSheetX(Sint16 x);
	virtual Sint16 SetSheetY(Sint16 y);

	virtual Sint16 GetSheetX();
	virtual Sint16 GetSheetY();
	virtual int GetSheetW();
	virtual int GetSheetH();

	virtual bool IsLoadedImage();
	virtual bool IsLocalImage();

protected:
	/* Protected access members */
	virtual SDL_Surface* SetSurface(SDL_Surface*);
	virtual SDL_Surface* GetSurface();

private:
	/* Private access members */
	void Init();

	SDL_Rect m_sclip;
	SDL_Rect m_dclip;
	SDL_Surface* m_pSurface;
	bool m_bLocal;
};

#endif
