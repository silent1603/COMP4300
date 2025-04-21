#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

struct AppInitData
{
    sf::RenderWindow window;
    sf::Clock deltaClock;
};

AppInitData appData;
sf::CircleShape shape(100.f);

void inline init()
{
    appData.window.create(sf::VideoMode({ 800,600 }), "Game");
    appData.window.setFramerateLimit(60);
    appData.window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(appData.window);
    shape.setFillColor(sf::Color::Green);

}

void inline processInput()
{
    while (const auto event = appData.window.pollEvent()) {
        ImGui::SFML::ProcessEvent(appData.window, *event);

        if (event->is<sf::Event::Closed>()) {
            appData.window.close();
        }
    }

}

void inline ImGuiUpdate()
{
    ImGui::SFML::Update(appData.window, appData.deltaClock.restart());

}

void inline update()
{
    ImGuiUpdate();
}



void inline render()
{
    appData.window.clear();
    appData.window.draw(shape);
    ImGui::SFML::Render(appData.window);
    appData.window.display();
}


void inline close()
{
    ImGui::SFML::Shutdown();
}
int main() {

    init();
    while (appData.window.isOpen()) {
        processInput();
        update();
        render();
    }
    close();

}