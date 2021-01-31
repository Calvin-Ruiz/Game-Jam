/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.cpp
*/
#include "WindowManager.hpp"
#include "Core.hpp"
#include "CreeperDisplay.hpp"
#include "Item.hpp"
#include "DynamicItem.hpp"
#include <vector>
#include "Room.hpp"

WindowManager::WindowManager(sf::RenderWindow &window) : window(window), buffer(sf::PrimitiveType::TriangleStrip, sf::VertexBuffer::Static)
{
    this->player = nullptr;
}

WindowManager::~WindowManager()
{
    delete player;
    delete ground;
}

void WindowManager::initialize()
{
    this->rectangle.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    this->rectangle.setFillColor(sf::Color(169,169,169, 128));

    if (!this->menuButtonResumeT.loadFromFile("Sprite/Resume_button.png"))
        std::cerr << "menuButtonResume can't load from file" << std::endl;
    if (!this->menuButtonLeaveT.loadFromFile("Sprite/Leave_button.png"))
        std::cerr << "menuButtonLeave can't load from file" << std::endl;
    if (!this->menuButtonRetryT.loadFromFile("Sprite/Retry_button.png"))
        std::cerr << "menuButtonRetryT can't load from file" << std::endl;

    this->menuButtonResumeS.setTexture(this->menuButtonResumeT);
    this->menuButtonResumeS.setScale(0.5, 0.5);
    this->menuButtonResumeS.setPosition((window.getSize().x / 2) - 360, (window.getSize().y / 2) + 150);
    this->menuButtonLeaveS.setTexture(this->menuButtonLeaveT);
    this->menuButtonLeaveS.setScale(0.5, 0.5);
    this->menuButtonLeaveS.setPosition((window.getSize().x / 2) + 190, (window.getSize().y / 2) + 150);
    this->menuButtonRetryS.setTexture(this->menuButtonRetryT);
    this->menuButtonRetryS.setScale(0.5, 0.5);
    this->menuButtonRetryS.setPosition((window.getSize().x / 2) - 80, (window.getSize().y / 2) + 150);

    this->player = new Player(new GraphicPlayer());

    this->ready = true;
    disp = std::make_unique<WallDisplay>(window, Core::core->rooms);
    ground = new sf::Texture();
    ground->loadFromFile("textures/floor.png");
    ground->setRepeated(true);
    float x = Core::core->getRoomWidth() * Core::core->rooms.size();
    float y = Core::core->getRoomHeight() * Core::core->rooms[0].size();
    sf::Vertex v[4] = {{{0, 0}, {0, 0}}, {{0, y}, {0, y}}, {{x, 0}, {x, 0}}, {{x, y}, {x, y}}};
    buffer.create(4);
    buffer.update(v);
    gstate = std::make_unique<sf::RenderStates>(ground);
    player->setPosition(Core::core->initX, Core::core->initY);
}

void WindowManager::refresh()
{
    sf::View v = window.getView();
    sf::View v2(sf::FloatRect(0, 0, 256*4*4, 4*256*3));
    window.setView(v2);
    window.clear();
    window.draw(buffer, *gstate);
    CreeperDisplay::instance->draw();
    for (auto &item : Core::core->getDynamicItemList()) {
        item->draw();
    }
    Item *ptr;
    for (int _x = x; _x < width; ++_x) {
        for (int _y = y; _y < height; ++_y) {
            ptr = Core::core->rooms[_x][_y].item;
            if (ptr)
                ptr->draw();
        }
    }
    disp->draw();
    if (!Core::core->paused())
        window.display();
    window.setView(v);
}

void WindowManager::update()
{
    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

            case sf::Event::Closed:
                this->ready = false;
                break;

            case sf::Event::KeyPressed:

                if (event.key.code == sf::Keyboard::Escape) {
                    Core::core->setPause(true);
                }

                else if (event.key.code == sf::Keyboard::Up) {
                    this->player->top();
                }

                else if (event.key.code == sf::Keyboard::Down) {
                    this->player->bottom();
                }

                else if (event.key.code == sf::Keyboard::Left) {
                    this->player->left();
                }

                else if (event.key.code == sf::Keyboard::Right) {
                    this->player->right();
                }

                break;

            default:
                break;
        }

    }
}

void WindowManager::onPause()
{

    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

            case sf::Event::Closed:
                this->ready = false;
                break;

            case sf::Event::KeyPressed:

                if (event.key.code == sf::Keyboard::Escape) {
                    Core::core->setPause(true);
                }

                break;

            default:
                break;
        }

    }

    this->window.clear(); // maybe ne sert a rien, maybe fais tout bug
    this->window.draw(this->rectangle);
    this->window.draw(this->menuButtonLeaveS);
    this->window.draw(this->menuButtonResumeS);
    this->window.draw(this->menuButtonRetryS);
    this->window.display(); // maybe ne sert a rien, maybe fais tout bug
}
