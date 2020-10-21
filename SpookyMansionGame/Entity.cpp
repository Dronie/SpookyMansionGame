#ifndef ENTITY_CPP
#define ENTITY_CPP

#include "olcPixelGameEngine.h"
class Entity {
public:
	olc::vi2d vPosition;
	olc::vi2d vSize;
	olc::vf2d vSpeed;
	std::string spriteLoc;

	Entity(olc::vi2d a, olc::vi2d b, olc::vf2d c, std::string d) 
	{
		vPosition = a;
		vSize = b;
		vSpeed = c;
		spriteLoc = d;
	}
};

#endif