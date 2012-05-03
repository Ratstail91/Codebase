#include <stdio.h>
#include "SDL.h"
#include "Deprecated\xFramework 2012050302\xFramework.h"

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

void quitEvent(SDL_Event const* const event) { xQuit(0); }
void keyDown(SDL_Event const* const);
void mouseButtonDown(SDL_Event const* const);

/* mainline */
int SDL_main(int argc,char** argv) {
	int i = 0;

	i = xAlloc( _SCENE_COUNT );

	i += xSetInitCallback( init );
	i += xSetQuitCallback( quit );

/*	i += xSetHeadCallback( SCENE_ONE, head );
	i += xSetTailCallback( SCENE_ONE, tail );
	i += xSetUpdateCallback( SCENE_ONE, update );
*/

	i += xSetHeadCallback( SCENE_ONE, headOne );
	i += xSetHeadCallback( SCENE_TWO, headTwo );

	i += xSetRenderCallback( SCENE_ONE, render );
	i += xSetRenderCallback( SCENE_TWO, render );

	/* duplicated sets, for each scene: can fix with iteration? */
	i += xSetEventCallback( SCENE_ONE, keyDown, SDL_KEYDOWN );
	i += xSetEventCallback( SCENE_ONE, mouseButtonDown, SDL_MOUSEBUTTONDOWN );
	i += xSetEventCallback( SCENE_ONE, quitEvent, SDL_QUIT );

	i += xSetEventCallback( SCENE_TWO, keyDown, SDL_KEYDOWN );
	i += xSetEventCallback( SCENE_TWO, mouseButtonDown, SDL_MOUSEBUTTONDOWN );
	i += xSetEventCallback( SCENE_TWO, quitEvent, SDL_QUIT );

	if (i != 0) {
		printf("Error, xFramework returned a non-zero value: %d\n", i);
		return 1;
	}

	return xProc();
}

/* definitions */
void init(void) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Failed to initialize SDL\n");
		xQuit(-1);
		return;
	}

	g_pScreen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (g_pScreen == NULL) {
		printf("Failed to initialize the screen\n");
		xQuit(-1);
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
		case SDLK_ESCAPE:	xQuit(0); break;
		case SDLK_1:		xSwitch(SCENE_ONE); break;
		case SDLK_2:		xSwitch(SCENE_TWO); break;
	}

/*	printf("key down\n"); */
}

void mouseButtonDown(SDL_Event const* const event) {
/*	printf("mouse button down\n"); */
}
