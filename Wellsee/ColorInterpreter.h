#pragma once
#include "SDL.h"
class ColorInterpreter
{
public:
	static unsigned int BLACK;
	static unsigned int WHITE;
	static unsigned int GREEN;
	static unsigned int RED;

	ColorInterpreter();
	~ColorInterpreter();
	Uint32 getColorById(SDL_PixelFormat &pf,unsigned int id);
};

