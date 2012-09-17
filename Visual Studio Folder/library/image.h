#ifndef KR_IMAGE_H_
#define KR_IMAGE_H_

#include "SDL.h"

class Image {
public:
	/* Public access members */
	Image();
	~Image();

	/* Surface handlers */
	void LoadSurface(const char* fname);
	void UnloadSurface();

	SDL_Surface* SetSurface(SDL_Surface*);
	SDL_Surface* GetSurface();

	void SetColorKey(Uint8 r, Uint8 g, Uint8 b);
	void ClearColorKey();

	/* Rendering */
	void DrawTo(SDL_Surface* const, int x, int y);

	/* Clip handlers */
	SDL_Rect SetClip(SDL_Rect r) { return m_clip = r; }
	SDL_Rect GetClip() { return m_clip; }

	Sint16 SetClipX(Sint16 x) { return m_clip.x = x; }
	Sint16 SetClipY(Sint16 y) { return m_clip.y = y; }
	Uint16 SetClipW(Uint16 w) { return m_clip.w = w; }
	Uint16 SetClipH(Uint16 h) { return m_clip.h = h; }

	Sint16 GetClipX() { return m_clip.x; }
	Sint16 GetClipY() { return m_clip.y; }
	Uint16 GetClipW() { return m_clip.w; }
	Uint16 GetClipH() { return m_clip.h; }

	bool IsLoaded() { return m_pSurface != NULL; }
	bool IsLocal() { return m_bLocal; }

private:
	SDL_Rect m_clip;
	SDL_Surface* m_pSurface;
	bool m_bLocal;
};

#endif
