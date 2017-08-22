#include "Window.h"
#include "SDL.h"
#include "Snake_Constants.h"
#include "Game.h"
#include "Position.h"
Window::Window(){

	// Init and show window
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow(Snake_Constants::WINDOW_TITLE, Snake_Constants::START_WINDOW_X, Snake_Constants::START_WINDOW_Y
		, Snake_Constants::WINDOW_WIDTH, Snake_Constants::WINDOW_HEIGHT, NULL);
	SDL_ShowWindow(window);
	this->surface = SDL_GetWindowSurface(window);
	SDL_UpdateWindowSurface(window);

}

void Window::maintain_framerate(Uint32 starting_tick)
{
	if ((Snake_Constants::MS_IN_SEC / Snake_Constants::FPS) > SDL_GetTicks() - starting_tick)
		SDL_Delay(Snake_Constants::MS_IN_SEC / Snake_Constants::FPS - (SDL_GetTicks() - starting_tick));
}

void Window::performMainLoop()
{
	Uint32 starting_tick;
	SDL_Event event;
	long long fpsPassed = 0;
	bool exit = false;

	while (!exit) {
		starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit = true;
				break;}
			game->interpretEventKey(event.key.keysym.sym);}
		if (fpsPassed % 8 == 0){
			game->onTick();
			SDL_UpdateWindowSurface(window);
		}
		maintain_framerate(starting_tick);
		fpsPassed++;
	}
	SDL_DestroyWindow(window);
}

void Window::printRect(const Position * pos, int r, int g, int b)
{
	SDL_Rect rect;
	rect.w = Snake_Constants::FIELD_WIDTH;
	rect.h = Snake_Constants::FIELD_WIDTH;
	rect.x = pos->x;
	rect.y = pos->y;
	
	SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, r, g, b));

}

void Window::resetScreen()
{
	SDL_FillRect(surface, nullptr, 0);
}

Window::~Window()
{

}
