#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Manager/EntityManager/EntityManager.h"

struct PlayerConfig {int SR,CR,FR,FG,FB,OR,OG,OB,OT,V;float S;};
struct EnemyConfig {int SR, CR, OR,OG,OT,VMIN,VMAX,L,SI; float SMIN,SMAX;};
struct BulletConfig {int SR, CR, FR,FG,OR,OG,OB,OT,V,L; float S;};
class Game
{
private:
    sf::RenderWindow m_window;
    EntityManager m_entities;
    sf::Font    m_font;
    sf::Text    m_text;
    sf::Clock   m_deltaClock;
    int         m_score = 0;
    int         m_currentFrame = 0;
    int         m_lastEnemySpawnTime = 0;
    bool        m_paused;
    bool        m_running;


    void Init(const std::string& config);
    void SetPaused();
    void SMovement();
    void SUserInput();
    void SLifepan();
    void SGUI();
    void SRender();
    void SEnemySpawnser();
    void SCollision();

    void SpawnPlayer();
    void SpawnEnemy();
    void SpawnSmallEnemies(std::shared_ptr<OOP_Entity> entity);
    void SpawnBullet(std::shared_ptr<OOP_Entity> entity,const Vector<float,2> mousePos);
    void SpawnSpecialWeapon(std::shared_ptr<OOP_Entity> entity);

    void Update();

    std::shared_ptr<OOP_Entity> Player();
public:
    Game(const std::string& config);
    void run();
};
#endif