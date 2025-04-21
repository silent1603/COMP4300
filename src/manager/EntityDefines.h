#ifndef ENTITY_DEFINE_H
#define ENTITY_DEINFE_H
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "OOP_Entity.h"
template<typename Type>
using EntityVec =  std::vector<std::shared_ptr<OOP_Entity<Type>>>;

template<typename Type>
using EntityMap =  std::map<std::string,EntityVec<Type>>;
#endif