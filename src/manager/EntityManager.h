#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "EntityDefines.h"
#include "OOP_Entity.h"
class EntityManager
{
private:
    EntityVec<int> m_entites;
    EntityMap<int> m_entityMap;
    size_t m_totalEntities = 0;
    EntityVec<int> m_toAdd;
public:
    EntityManager();
    void Update();
    std::shared_ptr<OOP_Entity<int>> AddEntity(const std::string& tag);
    EntityVec<int>& GetEntities();
    EntityVec<int>& GetEntities(const std::string& tag);
};

#endif