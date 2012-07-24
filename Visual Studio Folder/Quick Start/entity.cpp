/* File Name: entity.cpp
 * Author: 
 * Date: 
 * Copyright: 
 * Description: 
*/
#include "entity.h"

//-------------------------
//Public access members
//-------------------------

Entity::Entity() {
	//
}

Entity::~Entity() {
	//
}

void Entity::LoadImage(const char* szFileName, Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	Image::LoadImage(szFileName, x, y, w, h);

	BBox2D::SetBBox( GetImageX(), GetImageY(), GetImageW(), GetImageH() );
}

void Entity::LoadImage(SDL_Surface* pSurface,  Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	Image::LoadImage(pSurface, x, y, w, h);

	BBox2D::SetBBox( GetImageX(), GetImageY(), GetImageW(), GetImageH() );
}

void Entity::Update(int iDelta) {
	Origin2D::Update(iDelta);

	Image::SetImageX( (Sint16)Origin2D::GetOriginX() );
	Image::SetImageY( (Sint16)Origin2D::GetOriginY() );
}

SDL_Rect Entity::GetWorldBBox() {
	return BBox2D::GetWorldBBox( (Sint16)Origin2D::GetOriginX(), (Sint16)Origin2D::GetOriginY());
}

int Entity::CheckWorldBBox(SDL_Rect otherBox) {
	return BBox2D::CheckWorldBBox(otherBox, (Sint16)Origin2D::GetOriginX(), (Sint16)Origin2D::GetOriginY());
}
