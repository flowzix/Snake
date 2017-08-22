#pragma once
#include "SDL.h"

class Game;
class Position;

class Window
{
private:
	SDL_Window *window;
	SDL_Surface *surface;
	int i = 0;
	Game *game;
public:
	Window();
	~Window();
	void performMainLoop();
	void printRect(const Position * pos, int r, int g, int b);
	void resetScreen();
	SDL_Window *GetWindow() { return window; }
	void updateWindowSurface(){ SDL_UpdateWindowSurface(window); }
	void hookGame(Game *game) { this->game = game; }
	SDL_Surface * GetSurface() { return surface; }
	void maintain_framerate(Uint32 starting_tick);
};

