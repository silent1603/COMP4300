#ifndef SRENDER_H
#define SRENDER_H
#include "Manager/EntityManager/EntityManager.h"

inline void SRender(EntityManager& entityManager)
{
    for(auto& e : entityManager.GetEntities())
    {
        if(!e->Has<CShape>() && e->Has<CTransform>()) 
        {
            CShape& shape = e->Get<CShape>();
            CTransform& tranforms = e->Get<CTransform>();
            shape.circle.setPosition({tranforms.pos.data[0],tranforms.pos.data[1]});
            //window.raw(shape)
        }
    }
}
#endif