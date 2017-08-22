#pragma once
#include "Snake_Constants.h"
#include "Position.h"
#include <vector>
#include "Generator.h"
class Map
{
private:
	unsigned int **map;
	int width;
	int height;
	Generator gen;
public:
	void clearMap();
	void putObject(Position *pos, unsigned int type);
	unsigned int GetObjectAt(const Position *pos) { return map[pos->x][pos->y]; }
	Position GetEmptyPos();
	Map();
	~Map();
};

