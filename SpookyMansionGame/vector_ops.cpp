#include "olcPixelGameEngine.h"
#include<math.h>

// element wise product
static olc::vf2d fHadamardProduct2D(olc::vf2d a, olc::vf2d b) {return olc::vf2d(a.x * b.x, a.y * b.y);}
static olc::vi2d iHadamardProduct2D(olc::vi2d a, olc::vi2d b) { return olc::vi2d(a.x * b.x, a.y * b.y); }
