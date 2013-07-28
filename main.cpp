#include "image.hpp"
#include "sprite_sheet.hpp"

#include "SDL/SDL.h"

#include <stdexcept>
#include <iostream>
#include <chrono>

void init();
void loop();
void quit();

void handleEvents(SDL_Event const&);

void unit(double);

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

SpriteSheet sprite;

void init() {
	if (SDL_Init(0)) {
		throw(std::runtime_error("Failed to init SDL"));
	}

	screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	if (!screen) {
		throw(std::runtime_error("Failed to create the screen"));
	}

	sprite.LoadSurface("elliot2.bmp", 4, 4);
	sprite.SetDelay(.25); //one second
}

void loop() {
	using namespace std::chrono;
	steady_clock::time_point tick = steady_clock::now();

	while(running) {
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			handleEvents(event);
		}

		double delta = (double)(steady_clock::now()-tick).count() / steady_clock::duration::period::den;
		tick = steady_clock::now();

		unit(delta);

		sprite.DrawTo(screen, 0, 0);
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

void unit(double delta) {
	SDL_FillRect(screen, 0, 0);

	sprite.Update(delta);
}
