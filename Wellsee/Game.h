#pragma once
#include "SDL.h"
class Map;
class Window;
class Snake;
class Position;

class Game
{
public:
	Game(Window *gameHolderWindow);
	void interpretEventKey(SDL_Keycode code);
	void gameLoop();
	~Game();
	void onTick(); // moves are done by some frames intervals, so tick represents action
	unsigned int getDirection() { return snakeDirection; }
	Map * GetMap() { return map; }
	void snakeMoved(const Position* next, const Position* prev);
	void startNewGame();
private:
	void createPoint();
	bool pointOnMap;
	unsigned int snakeDirection;
	Snake *snake;
	Window *gameWindow;
	Map *map;
	int playerPoints;
	int gameDuration;

};

