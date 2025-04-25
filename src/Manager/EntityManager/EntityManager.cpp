#include "EntityManager.h"


std::shared_ptr<OOP_Entity> EntityManager::AddEntity(const std::string& tag)
{
    auto e = std::make_shared<OOP_Entity>(m_totalEntities++,tag);
    m_toAdd.push_back(e);
    if (m_entityMap.find(tag) == m_entityMap.end())
    {
        m_entityMap[tag] = EntityVec();
    }
    m_entityMap[tag].push_back(e);
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
    RemoveDeadEntities(m_entites);
    for (auto& [tag, entityVec] : m_entityMap)
    {
        RemoveDeadEntities(entityVec);
    }
}

void EntityManager::RemoveDeadEntities(EntityVec& vec)
{

}

EntityVec& EntityManager::GetEntities()
{
    return m_entites;
}

EntityVec& EntityManager::GetEntities(const std::string& tag)
{
    return m_entityMap[tag];
}