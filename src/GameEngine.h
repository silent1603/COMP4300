#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Manager/EntityManager/EntityManager.h"
class GameEngine
{
private:
    sf::RenderWindow m_window;
    EntityManager m_entities;
    bool        m_paused;
    bool        m_running;
private:
    void movement();
    void userInput();
    void enemySpawnser();
    void collision();
    void render();
public:
    void init();
    void Update();
};
#endif