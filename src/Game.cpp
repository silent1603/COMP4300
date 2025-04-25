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

    return players.size() > 0 ? players.front() : nullptr ;
}

void Game::run()
{
    while (m_running)
    {
        Update();
    }
    Close();
}

void Game::SpawnEnemy()
{
    m_lastEnemySpawnTime = m_currentFrame;
}

void Game::SpawnPlayer()
{
    auto entity = m_entities.AddEntity("player");
    entity->Add<CTransform>(Vector<float,2>{200.f,200.f}, Vector<float, 2>{200.f,200.f},0.0f);
    entity->Add<CShape>(32.0f,8,sf::Color(10,10,10),sf::Color(255,0,0),4.0f,Vector<float,2>{0.0f,0.0f});
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
    std::shared_ptr<OOP_Entity> player = Player();
    if (player)
    {
        auto& transform = player->Get<CTransform>();
        transform.pos.data[0] += transform.velocity.data[0];
        transform.pos.data[1] += transform.velocity.data[1];
    }
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
    m_window.clear();
    std::shared_ptr<OOP_Entity> player = Player();
    if (player)
    {
        Player()->Get<CShape>().circle.setPosition({ Player()->Get<CTransform>().pos[0],Player()->Get<CTransform>().pos[1] });
        Player()->Get<CTransform>().angle += 1.0f;
        Player()->Get<CShape>().circle.setRotation(sf::degrees({ Player()->Get<CTransform>().angle }));
        m_window.draw(Player()->Get<CShape>().circle);
    }
    ImGui::SFML::Render(m_window);
    m_window.display();
}
void Game::SUserInput()
{
    while (const auto event = m_window.pollEvent()) {
        ImGui::SFML::ProcessEvent(m_window, *event);

        if (event->is<sf::Event::Closed>()) {
            m_running = false;
        }

        if (event->is<sf::Event::KeyReleased>())
        {
            const auto* keyPressed = event->getIf<sf::Event::KeyReleased>();
            switch (keyPressed->code)
            {
            case sf::Keyboard::Key::W:
            default:
                break;
            }
        }
        if (event->is<sf::Event::KeyPressed>())
        {
            const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
            switch (keyPressed->code)
            {
            case sf::Keyboard::Key::W:
            default:
                break;
            }
        }

        if (event->is<sf::Event::MouseButtonPressed>())
        {
            if (ImGui::GetIO().WantCaptureMouse)
            {
                continue;
            }
            const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>();
            if (mouseButtonPressed->button == sf::Mouse::Button::Left)
            {
                //call spawnwBullet here
            }

            if (mouseButtonPressed->button ==  sf::Mouse::Button::Right)
            {
                //call spawnwSpecialWeapon here
            }
        }
    }

}

void Game::Update()
{
    m_entities.Update();
    ImGui::SFML::Update(m_window, m_deltaClock.restart());
    SEnemySpawnser();
    SMovement();
    SCollision();
    SUserInput();
    SGUI();
    SRender();

    m_currentFrame++;
}

void Game::Close()
{
    ImGui::SFML::Shutdown();
}