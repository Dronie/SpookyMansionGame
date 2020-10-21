#ifndef PLAYERCONTROLLER_CPP
#define PLAYERCONTROLLER_CPP

#include "olcPixelGameEngine.h"
#include "Entity.cpp"
#include "vector_ops.cpp"
// Class to handle Player Controllers : Inherits from Entity
// Constructor ARGS: (olc::vi2d Position, olc::vi2d Size, olc::vf2d Speed, std::string SpriteLocation)
class Player : public Entity{
public:

	olc::vi2d vSize = { 32, 64 };
	olc::vf2d vSpeed = { 500.0f, 500.0f };

	Player(olc::vi2d a, std::string b) : Entity( a, vSize, vSpeed, b ) {

	}
	
	void CheckMovement(olc::PixelGameEngine* pge, float elapsedTime) {
		// Move Up
		if (pge->GetKey(olc::Key::W).bHeld) vPosition -= fHadamardProduct2D(vSpeed, olc::vf2d(0.0f, 1.0f)) * elapsedTime;
		// Move Left
		if (pge->GetKey(olc::Key::A).bHeld) vPosition -= fHadamardProduct2D(vSpeed, olc::vf2d(1.0f, 0.0f)) * elapsedTime;
		// Move Down
		if (pge->GetKey(olc::Key::S).bHeld) vPosition += fHadamardProduct2D(vSpeed, olc::vf2d(0.0f, 1.0f)) * elapsedTime;
		// Move Right
		if (pge->GetKey(olc::Key::D).bHeld) vPosition += fHadamardProduct2D(vSpeed, olc::vf2d(1.0f, 0.0f)) * elapsedTime;
	}
};

// have to define member funtions inside the class or you get a LNK2005 error
// multiplying a vi2d by a decimal makes the output zero - vi2d is for 32bit ints ONLY, use vf2d for floats

#endif