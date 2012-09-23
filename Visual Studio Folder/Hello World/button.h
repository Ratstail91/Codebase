#ifndef KR_BUTTON_H_
#define KR_BUTTON_H_

#include "SDL.h"

#include "image.h"
#include "bbox.h"
#include "vector2.h"

class Button {
public:
	/* Public access members */
	Button();
	virtual ~Button();

	void LoadImage(const char* fname);
	void DrawTo(SDL_Surface* const);

	BBox GetRealBox(int16_t x = 0, int16_t y = 0, uint16_t w = 0, uint16_t h = 0);

	/* Cheap Accessors */
	Image* GetSprite()		{ return &spr; }
	BBox* GetBBox()			{ return &box; }
	Vector2* GetPosition()	{ return &pos; }

private:
	/* Private access members */
	Image spr;
	BBox box;
	Vector2 pos;
};

#endif
