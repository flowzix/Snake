#include "Map.h"
#include "Snake_Constants.h"
#include "Position.h"
#include "Generator.h"
#include <iostream>

Position Map::GetEmptyPos()
{
	int x = gen.rand(0, width - 1);
	int y = gen.rand(0, height - 1);

	if (map[x][y] != Snake_Constants::FIELD_EMPTY) {
		std::cout << x << " b" << y << ".\n";
		int empty = 0;
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				if (map[i][j] == Snake_Constants::FIELD_EMPTY)
					empty++;
		std::cout << "th\n";
		int *emptyIndexes = new int[empty];

		int a = 0;
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				if (map[i][j] == Snake_Constants::FIELD_EMPTY)
					emptyIndexes[a++] = i+ j*width;

		std::cout << "th2\n";

		int ran = gen.rand(0, empty-1);
		std::cout << "Ran:" << ran << "\n";
		int emptyField = emptyIndexes[ran];
		x = emptyField % width;
		y = emptyField / width;

		std::cout << x << " " << y << '\n';
		delete emptyIndexes;

	}


	return Position(x, y);
}

Map::Map()
{
	this->width = Snake_Constants::WINDOW_WIDTH / Snake_Constants::FIELD_WIDTH;
	this->height = Snake_Constants::WINDOW_HEIGHT / Snake_Constants::FIELD_WIDTH;
	map = new unsigned int*[width];
	for (int i = 0; i < width; i++)
		map[i] = new unsigned int[height];

	clearMap();
}

void Map::clearMap()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			map[i][j] = 0;
}

void Map::putObject(Position *pos,unsigned int type)
{
	map[pos->x][pos->y] = type;
}

Map::~Map()
{
	for (int i = 0; i < width; i++)
		delete[] map[i];
	delete[] map;
}
