#include <stdio.h>
#include "SDL.h"
#include "complex_callbacks.h"

/* globals */
SDL_Surface* g_pScreen = NULL;

enum {
	SCENE_ONE,
	SCENE_TWO,
	_SCENE_COUNT
};

/* forward declarations */
void init(void);
void quit(void);

void headOne(void);
void headTwo(void); /* testing more than one scene */
void tail(void);
void update(void);
void render(void);

void quitEvent(SDL_Event const* const event) { ccQuit(0); }
void keyDown(SDL_Event const* const);
void mouseButtonDown(SDL_Event const* const);

/* mainline */
int SDL_main(int argc,char** argv) {
	int i = 0;

	i = ccAlloc( _SCENE_COUNT );

	i += ccSetInitCallback( init );
	i += ccSetQuitCallback( quit );

/*	i += ccSetHeadCallback( SCENE_ONE, head );
	i += ccSetTailCallback( SCENE_ONE, tail );
	i += ccSetUpdateCallback( SCENE_ONE, update );
*/

	i += ccSetHeadCallback( SCENE_ONE, headOne );
	i += ccSetHeadCallback( SCENE_TWO, headTwo );

	i += ccSetRenderCallback( SCENE_ONE, render );
	i += ccSetRenderCallback( SCENE_TWO, render );

	/* duplicated sets, for each scene: can fix with iteration? */
	i += ccSetEventCallback( SCENE_ONE, keyDown, SDL_KEYDOWN );
	i += ccSetEventCallback( SCENE_ONE, mouseButtonDown, SDL_MOUSEBUTTONDOWN );
	i += ccSetEventCallback( SCENE_ONE, quitEvent, SDL_QUIT );

	i += ccSetEventCallback( SCENE_TWO, keyDown, SDL_KEYDOWN );
	i += ccSetEventCallback( SCENE_TWO, mouseButtonDown, SDL_MOUSEBUTTONDOWN );
	i += ccSetEventCallback( SCENE_TWO, quitEvent, SDL_QUIT );

	if (i != 0) {
		printf("Error, complex callbacks returned a non-zero value: %d\n", i);
		return 1;
	}

	return ccProc();
}

/* definitions */
void init(void) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Failed to initialize SDL\n");
		ccQuit(-1);
		return;
	}

	g_pScreen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (g_pScreen == NULL) {
		printf("Failed to initialize the screen\n");
		ccQuit(-1);
		return;
	}
}

void quit(void) {
	SDL_Quit();
}

void headOne(void) {
	printf("one\n");
}

void headTwo(void) {
	printf("two\n");
}

void tail() {
/*	printf("tail\n"); */
}

void update() {
/*	printf("update\n"); */
}

void render() {
/*	printf("render\n"); */

	SDL_Flip(g_pScreen);
}

void keyDown(SDL_Event const* const event) {
	switch(event->key.keysym.sym) {
		case SDLK_ESCAPE:	ccQuit(0); break;
		case SDLK_1:		ccSwitch(SCENE_ONE); break;
		case SDLK_2:		ccSwitch(SCENE_TWO); break;
	}

/*	printf("key down\n"); */
}

void mouseButtonDown(SDL_Event const* const event) {
/*	printf("mouse button down\n"); */
}
