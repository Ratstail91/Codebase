#include "image.hpp"

#include "SDL/SDL.h"

#include <stdexcept>
#include <iostream>

void init();
void loop();
void quit();

void handleEvents(SDL_Event const&);

void unit();

int SDL_main(int, char**) {
	try {
		init();
		loop();
		quit();
	}
	catch(std::exception& e) {
		std::cerr << "Fatal Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

SDL_Surface* screen = nullptr;
bool running = true;

void init() {
	if (SDL_Init(0)) {
		throw(std::runtime_error("Failed to init SDL"));
	}

	screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (!screen) {
		throw(std::runtime_error("Failed to create the screen"));
	}
}

void loop() {
	while(running) {
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			handleEvents(event);
		}
		unit();
		SDL_Flip(screen);
	}
}

void quit() {
	SDL_Quit();
}

void handleEvents(SDL_Event const& event) {
	switch(event.type) {
		case SDL_QUIT:
			running = false;
		break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
				break;
			}
		break;
	}
}

void unit() {
	using std::cout;
	using std::endl;

	SDL_FillRect(screen, 0, 0);

	Image a("krstudios.bmp");
	Image b = a;

	cout << "a: " << a.GetLocal() << endl;
	a.DrawTo(screen, 0, 0);
	cout << "b: " << b.GetLocal() << endl;
	b.DrawTo(screen, 50, 0);
}