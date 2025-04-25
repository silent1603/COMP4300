#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <tuple>
#include <string>
#include "Manager/EntityManager/Entity/Component/CCollision.h"
#include "Manager/EntityManager/Entity/Component/CInput.h"
#include "Manager/EntityManager/Entity/Component/CLifespan.h"
#include "Manager/EntityManager/Entity/Component/CScore.h"
#include "Manager/EntityManager/Entity/Component/CTransform.h"
#include "Manager/EntityManager/Entity/Component/CShape.h"
using ComponentTuple = std::tuple<CTransform,CLifespan,CInput,CScore,CCollision,CShape>;

template <typename T, typename Tuple>
struct has_type;

class OOP_Entity
{
private:
   
   ComponentTuple m_components;
   bool m_alive = true;
   std::string m_tag = "default";
   size_t m_id = 0;
public:
    OOP_Entity();
    OOP_Entity(const size_t id, const std::string& tag);
    ~OOP_Entity();
    template<typename Type,typename... TArgs>
    Type&                      Add(TArgs&&... mArgs);
    template<typename Type>
    Type&                     Get();
    template<typename Type>
    bool                      Has();
    template<typename Type>
    bool                      Remove();
    size_t                    Id() const;
    bool                      IsAlive() const;
    void                      Destroy() const;
    const std::string&        Tag() const;
};

template<typename Type,typename... TArgs>
Type& OOP_Entity::Add(TArgs&&... mArgs)
{
    auto& component = Get<Type>();
    component = Type(std::forward<TArgs>(mArgs)...);
    component.exists = true;
    return component;
}

template <typename Type> 
Type& OOP_Entity::Get()
{
    return std::get<Type>(m_components);
}

template <typename Type> 
bool OOP_Entity::Has()
{
    return std::get<Type>().exists;
}

template <typename Type>
bool OOP_Entity::Remove()
{
    return std::get<Type>() = Type();
}

#endif