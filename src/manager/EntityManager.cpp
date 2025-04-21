#include "EntityManager.h"


std::shared_ptr<OOP_Entity<int>> EntityManager::AddEntity(const std::string& tag)
{
    auto e = std::make_shared<OOP_Entity<int>>(tag,m_totalEntities++);
    m_toAdd.push_back(e);
    return e;
}

void EntityManager::Update()
{
    for(auto e : m_toAdd)
    {
        m_entites.push_back(e);
        m_entityMap[e->Tag()].push_back(e);
    }
    for(auto e : m_entites)
    {
        
    }
    m_toAdd.clear();
}