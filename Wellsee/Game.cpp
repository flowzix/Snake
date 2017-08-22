#include "Game.h"
#include "Window.h"
#include "SDL.h"
#include "Snake_Constants.h"
#include "SDL.h"
#include "Map.h"
#include "Snake.h"
#include "Position.h"
#include "Window.h"
#include <iostream>
Game::Game(Window *gameHolderWindow)
{
	gameWindow = gameHolderWindow;
	snakeDirection = Snake_Constants::START_DIRECTION;
	map = new Map();
	snake = new Snake(this);

	// init point
	Position p = map->GetEmptyPos();
	gameWindow->printRect(new Position(p.x * Snake_Constants::FIELD_WIDTH, p.y * Snake_Constants::FIELD_WIDTH), 255, 0, 0);
	GetMap()->putObject(new Position(p.x, p.y), Snake_Constants::FIELD_POINT);
	pointOnMap = true;

}

void Game::interpretEventKey(SDL_Keycode code)
{
	if (code == SDLK_UP && snakeDirection != Snake_Constants::DOWN)
		snakeDirection = Snake_Constants::UP;
	else if (code == SDLK_DOWN && snakeDirection != Snake_Constants::UP)
		snakeDirection = Snake_Constants::DOWN;
	else if (code == SDLK_LEFT && snakeDirection != Snake_Constants::RIGHT)
		snakeDirection = Snake_Constants::LEFT;
	else if (code == SDLK_RIGHT && snakeDirection != Snake_Constants::LEFT)
		snakeDirection = Snake_Constants::RIGHT;
	else if (code == SDLK_n)
		startNewGame();
}


Game::~Game()
{
	delete map;
	delete snake;
}

void Game::onTick()
{
	snake->moveSnake();
}

void Game::snakeMoved(const Position* next, const Position* prev) // if nullptr given, field wont be emptied
{

	gameWindow->printRect(next, 0, 255, 0); //toedit
	int x1 = next->x / Snake_Constants::FIELD_WIDTH;
	int y1 = next->y / Snake_Constants::FIELD_WIDTH;
	map->putObject(new Position(x1, y1), Snake_Constants::FIELD_SNAKE);

	if (prev != nullptr) {
		gameWindow->printRect(prev, 0, 0, 0);
		int x2 = prev->x / Snake_Constants::FIELD_WIDTH;
		int y2 = prev->y / Snake_Constants::FIELD_WIDTH;
		map->putObject(new Position(x2, y2), Snake_Constants::FIELD_EMPTY);
	}


	if (prev == nullptr){
		createPoint();
		gameWindow->updateWindowSurface();
	}
	
}

void Game::createPoint()
{
	Position p = map->GetEmptyPos();
	gameWindow->printRect(new Position(p.x * Snake_Constants::FIELD_WIDTH, p.y * Snake_Constants::FIELD_WIDTH), 255, 0, 0);
	GetMap()->putObject(new Position(p.x, p.y), Snake_Constants::FIELD_POINT);
	pointOnMap = true;
}


void Game::startNewGame()
{
	// cleanup
	gameWindow->resetScreen();
	map->clearMap();
	snake->deleteSnake();
	//init
	snake->snakeInit();
	createPoint();
}

void Game::gameLoop()
{


}
