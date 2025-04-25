#ifndef CLIFESPAN_H
#define CLIFESPAN_H
#include "Math/Vector.h"
#include "Component.h"

class CLifespan : public Component
{
public:
    int totalLifespan = 0;
    int remainingLifespan = 0;
    CLifespan() {}
    CLifespan(int totalLifespan) : totalLifespan(totalLifespan),remainingLifespan(totalLifespan) {}
};
#endif