#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "EntityDefines.h"
#include "Manager/EntityManager/Entity/OOP_Entity.h"
class EntityManager
{
private:
    EntityVec m_entites;
    EntityMap m_entityMap;
    EntityVec m_toAdd;
    size_t m_totalEntities = 0;
public:
    EntityManager();
    void Update();
    std::shared_ptr<OOP_Entity> AddEntity(const std::string& tag);
    void RemoveDeadEntities(EntityVec& vec);
    EntityVec& GetEntities();
    EntityVec& GetEntities(const std::string& tag);
};

#endif