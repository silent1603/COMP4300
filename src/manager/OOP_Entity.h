#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <tuple>
#include <string>
//using ComponentTuple = std::tuple<CTransform,CLifeSpan,CInput,CBoundingBox,CAnimation,CGravity,CState>

template<typename Type>
class OOP_Entity
{
private:
   //ComponentTuple m_components;
   bool m_alive = true;
   std::string m_tag = "default";
   size_t m_id = 0;
   Type         data;
public:
    OOP_Entity(/* args */);
    ~OOP_Entity();
    void                      Add(Type component);
    Type&                     Get();
    size_t                    Id() const;
    bool                      IsAlive() const;
    void                      Destroy() const;
    const std::string&        Tag() const;
};


template <typename Type> 
void OOP_Entity<Type>::Add(Type component)
{

}

template <typename Type> 
Type& OOP_Entity<Type>::Get()
{
    return this->data;
}

template <typename Type> 
Type& OOP_Entity<Type>::Get()
{
    return this->data;
}


template <typename Type> 
size_t OOP_Entity<Type>::Id() const
{
    return this->id;
}

template <typename Type> 
bool OOP_Entity<Type>::IsAlive() const
{
    return this->m_alive
}

template <typename Type> 
void OOP_Entity<Type>::Destroy() const
{
    
}

template <typename Type> 
const std::string& OOP_Entity<Type>::Tag() const
{
    return this->;
}

template <typename Type> 
OOP_Entity<Type>::OOP_Entity(/* args */)
{
}

template <typename Type> 
OOP_Entity<Type>::~OOP_Entity()
{
}


#endif