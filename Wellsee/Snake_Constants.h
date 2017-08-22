#pragma once
#include "SDL.h"
class Snake_Constants
{
public:
	static const unsigned int FPS;
	static const unsigned int FIELD_WIDTH;
	static const unsigned int FIELDS_PER_SECOND;
	static const unsigned int WINDOW_WIDTH;
	static const unsigned int WINDOW_HEIGHT;
	static const unsigned int MS_IN_SEC;
	static const unsigned int START_DIRECTION;
	static const unsigned int UP;
	static const unsigned int DOWN;
	static const unsigned int LEFT;
	static const unsigned int RIGHT;
	static const unsigned int FIELD_EMPTY;
	static const unsigned int FIELD_SNAKE;
	static const unsigned int FIELD_POINT;
	static const int START_WINDOW_X;
	static const int START_WINDOW_Y;
	static const char* WINDOW_TITLE;

	virtual ~Snake_Constants() = 0;
};

