#include "button.h"

//-------------------------
//Public access members
//-------------------------

Button::Button() {
	//
}

Button::~Button() {
	//
}

void Button::LoadImage(const char* fname) {
	spr.LoadSurface(fname);

	box.w = spr.GetClipW();
	box.h = spr.GetClipH();
}

void Button::DrawTo(SDL_Surface* const pDest) {
	spr.DrawTo(pDest, (int)pos.x, (int)pos.y);
}

BBox Button::GetRealBox(int16_t x, int16_t y, uint16_t w, uint16_t h) {
	return BBox(box.x + (int)pos.x + x, box.y + (int)pos.y + y, box.w + w, box.h + h);
}
