#include "SDL.h"
#include "Snake_Constants.h"
#include <iostream>
#include "Window.h"
#include "Game.h"
using namespace std;
#define fps 60



int main(int argc, char* argv[])
{
	Window window;
	Game game(&window);
	window.hookGame(&game);
	window.performMainLoop();

	return 0;
}