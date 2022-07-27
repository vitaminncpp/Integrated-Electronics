#pragma once
#define PI 3.141592653589793

inline double wrapAngle(double ang) {
	return ang - 2 * PI * floor(ang / (2 * PI));
}
