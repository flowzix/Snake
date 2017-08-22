#pragma once
#include <queue>
class SnakeNode;
class Game;
class Snake
{
public:
	Snake(Game * game);
	void moveSnake();
	void snakeInit();
	void deleteSnake();
	~Snake();
private:
	std::queue<SnakeNode*> snakeNodes;
	Game * game;
	
	
};

