#include "olcPixelGameEngine.h"
#include "PlayerController.cpp" // player controller file
#include <iostream>

// olc is a seperate namespace (like std)

class Spook : public olc::PixelGameEngine { // class that derives from the pixel game engine (inherits publicly from olc::PixelGameEngine)
public:
    Spook() { // typical to override the constructor
        sAppName = "Spook"; // name the application 
    }

private:
    std::unique_ptr<olc::Sprite> sPlayerSprite;

protected:
    Player player = Player(olc::vi2d(250.0f, 250.0f), "./Assets/player.png");

public: // it is typical to override the OnUserCreate and OnUserUpdate functions
    bool OnUserCreate() override {
        
        // load player sprite
        sPlayerSprite = std::make_unique<olc::Sprite>(player.spriteLoc);

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override { // main function where the guts of the game engine lies

        player.CheckMovement(this, fElapsedTime);

        //Draw Screen
        Clear(olc::DARK_BLUE);
        SetPixelMode(olc::Pixel::MASK);
        DrawPartialSprite(player.vPosition, sPlayerSprite.get(), olc::vi2d(0, 0), olc::vi2d(32, 64));
        SetPixelMode(olc::Pixel::NORMAL);

        return true;
    }
};

int main()
{
    Spook demo; // instantiate the example class

    olc::vi2d vScreenResolution = { 1920, 1080 };
    int iPixelSize = 2;
    if (demo.Construct(vScreenResolution.x / iPixelSize, vScreenResolution.y / iPixelSize,  iPixelSize, iPixelSize)) // create a 1280 by 720 screen with pixels of size 1 by 1
        demo.Start(); // if the window is constructed succesfully, then start the engine

    return 0;
}
