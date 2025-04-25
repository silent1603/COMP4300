#ifndef SLIFESPAN_H
#define SLIFESPAN_H
#include "Manager/EntityManager/EntityManager.h"
inline void SLifespan(EntityManager& entityManager)
{
    for(auto& e : entityManager.GetEntities())
    {
        if(!e->Has<CLifespan>()) {continue;}
        e->Get<CLifespan>().remainingLifespan--;
        if(e->Get<CLifespan>().remainingLifespan <= 0)
        {
            e->Destroy();
        }
    }
}
#endif