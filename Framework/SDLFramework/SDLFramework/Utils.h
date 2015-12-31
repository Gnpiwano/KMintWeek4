#pragma once
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
#include <iomanip>

//returns a random integer between x and y
inline int   RandInt(int x, int y)
{
	assert(y >= x && "<RandInt>: y is less than x");
	return rand() % (y - x + 1) + x;
}

//returns a random double between zero and 1
inline double RandFloat() { return ((rand()) / (RAND_MAX + 1.0)); }

inline double RandInRange(double x, double y)
{
	return x + RandFloat()*(y - x);
}

//returns a random bool
inline bool   RandBool()
{
	if (RandFloat() > 0.5) return true;

	else return false;
}

inline double RandomClamped() { return RandFloat() - RandFloat(); }