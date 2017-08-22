#pragma once
#include <random>
#include <iostream>
#include <time.h>
class Generator
{
public:
	Generator() {mt.seed(time(nullptr));}
	~Generator();
	int rand(int a, int b)
	{
		std::uniform_int_distribution<int> dist(a, b);
		return dist(mt);
	}
private:
	std::mt19937 mt;
};

