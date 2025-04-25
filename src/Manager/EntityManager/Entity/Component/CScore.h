#ifndef CSCORE_H
#define CSCORE_H
#include "Component.h"
class CScore : public Component
{
public:
    int score;

    CScore() {};
    CScore(int s) :score(s) {}
};
#endif