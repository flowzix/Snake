#include "SnakeNode.h"
#include "Position.h"


SnakeNode::SnakeNode(Position * indexPos)
{
	indexPos->x *= 25;
	indexPos->y *= 25;
	this->pos = indexPos;
}


SnakeNode::~SnakeNode()
{
	if (pos != nullptr)
		delete pos;
}
