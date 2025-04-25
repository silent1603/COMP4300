#ifndef ENTITY_DEFINE_H
#define ENTITY_DEINFE_H
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Manager/EntityManager/Entity/OOP_Entity.h"
using EntityVec =  std::vector<std::shared_ptr<OOP_Entity>>;
using EntityMap =  std::map<std::string,EntityVec>;
#endif