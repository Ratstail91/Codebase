#include <stdio.h>
#include "SDL.h"
#include "simple_callbacks.h"

#include "image.h"

/* globals */
SDL_Surface* g_pScreen = NULL;
Image g_image;

/* forward declarations */
void init(void);
void quit(void);

void head(void);
void tail(void);
void update(void);
void render(void);

void quitEvent			(SDL_Event const* const event) { scQuit(); }
void keyDown			(SDL_Event const* const);
void mouseButtonDown	(SDL_Event const* const);

/* mainline */
int SDL_main(int argc,char** argv) {
	scSetInitCallback( init );
	scSetQuitCallback( quit );
	scSetUpdateCallback( update );
	scSetRenderCallback( render );

	scSetEventCallback( keyDown, SDL_KEYDOWN );
	scSetEventCallback( mouseButtonDown, SDL_MOUSEBUTTONDOWN );

	scProc();

	return 0;
}

/* definitions */
void init(void) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Failed to initialize SDL\n");
		scQuit();
		return;
	}

	g_pScreen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (g_pScreen == NULL) {
		printf("Failed to initialize the screen\n");
		scQuit();
		return;
	}

	//etc...
	g_image.Load("player_red.bmp");
}

void quit(void) {
	g_image.Unload();

	SDL_Quit();
}

void head(void) {
	//
}

void tail() {
	//
}

void update() {
	//
}

void render() {
	g_image.DrawTo(g_pScreen);

	SDL_Flip(g_pScreen);
}

void keyDown(SDL_Event const* const event) {
	switch(event->key.keysym.sym) {
		case SDLK_ESCAPE:
			scQuit();
			break;
	}
}

void mouseButtonDown(SDL_Event const* const event) {
	//
}
