#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "Component.h"
class CCollision :public Component
{

public:
    float radius;
    CCollision(){}
    CCollision(float r):radius(r){}
};

#endif