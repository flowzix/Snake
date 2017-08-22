#include "Snake.h"
#include "SnakeNode.h"
#include "Snake_Constants.h"
#include "Position.h"
#include "Game.h"
#include "Map.h"

Snake::Snake(Game * game)
{
	this->game = game;
	snakeInit();
}

void Snake::snakeInit()
{
	int halfWidthIndex = Snake_Constants::WINDOW_WIDTH / Snake_Constants::FIELD_WIDTH / 2;
	int halfHeightIndex = Snake_Constants::WINDOW_HEIGHT / Snake_Constants::FIELD_WIDTH / 2;
	snakeNodes.push(new SnakeNode(new Position(halfWidthIndex, halfHeightIndex)));	// push first node on the center of the screen
	game->GetMap()->putObject(new Position(halfWidthIndex, halfHeightIndex), Snake_Constants::FIELD_SNAKE);
}

void Snake::deleteSnake()
{
	while (!snakeNodes.empty())
	{
		SnakeNode *x = snakeNodes.front();
		snakeNodes.pop();
		delete x;
	}
}



void Snake::moveSnake()
{

	SnakeNode* first = snakeNodes.front(); // first in queue
	SnakeNode* last = snakeNodes.back();

	int lastx = last->pos->x;	// last x represents the head of snake ( last in queue )
	int lasty = last->pos->y;




	if (game->getDirection() == Snake_Constants::DOWN)
		lasty += Snake_Constants::FIELD_WIDTH;
	else if (game->getDirection() == Snake_Constants::UP)
		lasty -= Snake_Constants::FIELD_WIDTH;
	else if (game->getDirection() == Snake_Constants::LEFT)
		lastx -= Snake_Constants::FIELD_WIDTH;
	else if (game->getDirection() == Snake_Constants::RIGHT)
		lastx += Snake_Constants::FIELD_WIDTH;


	if (lasty >= Snake_Constants::WINDOW_HEIGHT || lasty < 0){
		game->startNewGame();
		return;
	}
	if ((lastx < 0 && game->getDirection() == Snake_Constants::LEFT)) {
		game->startNewGame();
		return;
	}
	if (lastx >= Snake_Constants::WINDOW_WIDTH  && game->getDirection() == Snake_Constants::RIGHT) {
		game->startNewGame();
		return;
	}
		


	unsigned int objectMet = game->GetMap()->GetObjectAt(new Position(lastx / Snake_Constants::FIELD_WIDTH, lasty / Snake_Constants::FIELD_WIDTH));

	if (objectMet == Snake_Constants::FIELD_EMPTY) 
	{

		int firstPrevX, firstPrevY;	// previous position of snake
		firstPrevX = first->pos->x;
		firstPrevY = first->pos->y;

		first->pos->x = lastx;	// setting new position for last node ( lifting it to the front )
		first->pos->y = lasty;


		snakeNodes.pop();	// pop and then add it at the end
		snakeNodes.push(first);

		game->snakeMoved(snakeNodes.back()->pos, new Position(firstPrevX, firstPrevY)); // should work as there is no copy constructor but fields are ints and should be copied easily
	}
	else if (objectMet == Snake_Constants::FIELD_POINT)
	{
		SnakeNode *newNode = new SnakeNode(new Position(lastx / Snake_Constants::FIELD_WIDTH, lasty / Snake_Constants::FIELD_WIDTH));
		snakeNodes.push(newNode);
		game->snakeMoved(newNode->pos, nullptr);

	}
	else if (objectMet == Snake_Constants::FIELD_SNAKE) 
	{
		game->startNewGame();
	}

}


Snake::~Snake()
{

	while (!snakeNodes.empty())
	{
		SnakeNode *x = snakeNodes.front();
		snakeNodes.pop();
		delete x;
	}

}
