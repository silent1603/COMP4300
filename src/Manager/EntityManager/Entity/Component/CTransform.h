#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "Math/Vector.h"
#include "Component.h"
class CTransform : public Component
{
public:
	Vector<float,2> pos;
	Vector<float,2> velocity;
	Vector<float,2> scale;
	float angle;

	CTransform()
	{

	}
	CTransform(const Vector<float,2> &p , const Vector<float,2>& v,float angle) : pos(p),velocity(v),angle(angle)
	{
		
	}
};
#endif