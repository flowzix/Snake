#pragma once
class Position;
class SnakeNode
{
public:
	SnakeNode(Position * indexPos);
	~SnakeNode();
	Position * pos;
};

