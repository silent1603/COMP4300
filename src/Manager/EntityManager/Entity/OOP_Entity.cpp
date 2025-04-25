#include "OOP_Entity.h"
size_t OOP_Entity::Id() const
{
    return this->m_id;
}


bool OOP_Entity::IsAlive() const
{
    return this->m_alive;
}


void OOP_Entity::Destroy() const
{
    
}


const std::string& OOP_Entity::Tag() const
{
    return this->m_tag;
}


OOP_Entity::OOP_Entity(/* args */)
{
}


OOP_Entity::OOP_Entity(const size_t id,const std::string& tag):
    m_tag(tag),m_id(id)
{
}



OOP_Entity::~OOP_Entity()
{
}
