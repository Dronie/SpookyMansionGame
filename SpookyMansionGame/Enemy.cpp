#include "olcPixelGameEngine.h"
#include "Entity.cpp"
// Class to handle enemies : inherits from Entity
// Constructor ARGS: (olc::vi2d Position, olc::vi2d Size, olc::vf2d Speed, std::string SpriteLocation)
class Enemy : public Entity{
public:

	enum EnemyState {
		Idle,
		Seeking,
		Fleeing,
		Dead
	};

	EnemyState CurrentState;
	olc::vi2d vSize = { 32, 32 };
	olc::vf2d vSpeed = { 500.0f, 500.0f };

	Enemy(olc::vi2d a, std::string b, EnemyState c) : Entity{ a, vSize, vSpeed, b} {
		this->vPosition = a;
		this->spriteLoc = c;
	}

	void EnemyBehaviour(olc::PixelGameEngine* pge, EnemyState initialState) {
		this->CurrentState = initialState;
		
		switch (this->CurrentState) {
		case Idle:
			break;
		case Seeking:
			break;
		case Fleeing:
			break;
		case Dead:
			break;
		}
	}

};