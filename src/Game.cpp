#include "Game.h"
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "Math/Vector.h"
Game::Game(const std::string& config): m_text(m_font)
{
    Init(config);
}

void Game::Init(const std::string& path)
{
    m_window.create(sf::VideoMode({1280,720}),"Game");
    m_window.setFramerateLimit(60);

    ImGui::SFML::Init(m_window);
    ImGui::GetStyle().ScaleAllSizes(2.0f);
    ImGui::GetIO().FontGlobalScale = 2.0f;
}

std::shared_ptr<OOP_Entity> Game::Player()
{
    auto& players = m_entities.GetEntities("player");
    return players.front();
}

void Game::run()
{
    while (m_running)
    {
        m_entities.Update();
        ImGui::SFML::Update(m_window,m_deltaClock.restart());
        SEnemySpawnser();
        SMovement();
        SCollision();
        SUserInput();
        SGUI();
        SRender();

        m_currentFrame++;
    }
}

void Game::SpawnEnemy()
{
    m_lastEnemySpawnTime = m_currentFrame;
}

void Game::SpawnPlayer()
{
    auto entity = m_entities.AddEntity("player");
    entity->Add<CTransform>({200.f,200.f},{200.f,200.f},0.0f);
    entity->Add<CShape>(32.0f,8,sf::Color(10,10,10),sf::Color(255,0,0),4.0f);
    entity->Add<CInput>();
}

void Game::SpawnSmallEnemies(std::shared_ptr<OOP_Entity> entity)
{
}

void  Game::SpawnBullet(std::shared_ptr<OOP_Entity> entity,const Vector<float,2> mousePos)
{

}

void  Game::SpawnSpecialWeapon(std::shared_ptr<OOP_Entity> entity)
{

}

void  Game::SMovement()
{
    auto& transform = Player()->Get<CTransform>();
    transform.pos.data[0] += transform.velocity.data[0];
    transform.pos.data[1] += transform.velocity.data[1];
}

void Game::SLifepan()
{

}

void Game::SEnemySpawnser()
{

}

void Game::SCollision()
{

}
void Game::SGUI()
{
    ImGui::Begin("Geometry Wars");
    ImGui::Text("");
    ImGui::End();
}

void Game::SRender()
{

}
void Game::SUserInput()
{

}

void Game::Update()
{
    //entites update
    //UserInput
    //Movement
    //collision
    //render
    //frame++
}