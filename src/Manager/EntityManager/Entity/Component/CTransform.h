#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "Math/Vector.h"
struct CTransform
{
	Vector<float,2> pos;
	Vector<float,2> velocity;
	Vector<float,2> scale;
	float angle;
};
#endif