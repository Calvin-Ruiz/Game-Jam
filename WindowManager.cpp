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

WindowManager::WindowManager(sf::RenderWindow &window) : window(window), buffer(sf::PrimitiveType::TriangleStrip, sf::VertexBuffer::Static), band(sf::PrimitiveType::TriangleStrip, sf::VertexBuffer::Static)
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
    this->rectangle.setFillColor(sf::Color(169,169,169, 128));

    if (!this->menuButtonResumeT.loadFromFile("Sprite/Resume_button.png"))
        std::cerr << "menuButtonResume can't load from file" << std::endl;
    if (!this->menuButtonLeaveT.loadFromFile("Sprite/Leave_button.png"))
        std::cerr << "menuButtonLeave can't load from file" << std::endl;
    if (!this->menuButtonRetryT.loadFromFile("Sprite/Retry_button.png"))
        std::cerr << "menuButtonRetryT can't load from file" << std::endl;

    this->menuButtonResumeS.setTexture(this->menuButtonResumeT);
    this->menuButtonResumeS.setScale(0.5, 0.5);
    this->menuButtonLeaveS.setTexture(this->menuButtonLeaveT);
    this->menuButtonLeaveS.setScale(0.5, 0.5);
    this->menuButtonRetryS.setTexture(this->menuButtonRetryT);
    this->menuButtonRetryS.setScale(0.5, 0.5);

    this->player = new Player(new GraphicPlayer(window));

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
    CreeperDisplay::instance->setDimension(height, width);
    disp->setDimension(height, width);
    {
        float x1 = 256*3;
        float y1 = 2560;
        float x2 = x1 + 256 * 10;
        float y2 = y1 + 256;
        sf::Color c(255, 255, 255, 127);
        sf::Vertex v2[4] = {{{x1, y1}, c}, {{x2, y1}, c}, {{x1, y2}, c}, {{x2, y2}, c}};
        band.create(4);
        band.update(v2);
    }
}

void WindowManager::refresh()
{
    sf::View v = window.getView();
    sf::View v2(sf::FloatRect(0, 0, 256*4*4, 4*256*3));
    player->get().getCoords(x, y);
    x += 128;
    y += 128;
    // CLAMPS
    if (x < 128*4*4) x = 128*4*4;
    if (y < 128*4*3) y = 128*4*3;
    if (x > Core::core->rooms.size() * 256 - 128*4*4) x = Core::core->rooms.size() * 256 - 128*4*4;
    if (y > Core::core->rooms[0].size() * 256 - 128*4*3) y = Core::core->rooms[0].size() * 256 - 128*4*3;
    v2.setCenter(x, y);
    x = (x - 128 * 4 * 4) / 256;
    y = (y - 128 * 4 * 3) / 256;
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > Core::core->rooms.size() - width) x = Core::core->rooms.size() - width;
    if (y > Core::core->rooms[0].size() - height) y = Core::core->rooms[0].size() - height;
    CreeperDisplay::instance->setOrigin(x, y);
    disp->setOrigin(x, y);
    window.setView(v2);
    window.clear();
    window.draw(buffer, *gstate);
    CreeperDisplay::instance->draw();
    for (auto &item : Core::core->getDynamicItemList()) {
        item->draw();
    }
    Item *ptr;
    for (int _x = x; _x < x + width; ++_x) {
        for (int _y = y; _y < y + height; ++_y) {
            ptr = Core::core->rooms[_x][_y].item;
            if (ptr)
                ptr->draw();
        }
    }
    if (!player->update())
        ready = false;
    player->get().render();
    disp->draw();
    v2.setCenter(128*4*4, 128*4*3);
    window.setView(v2);
    window.draw(band);
    player->draw();
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
                } else if (event.key.code == sf::Keyboard::Up) {
                    this->player->top();
                } else if (event.key.code == sf::Keyboard::Down) {
                    this->player->bottom();
                } else if (event.key.code == sf::Keyboard::Left) {
                    this->player->left();
                } else if (event.key.code == sf::Keyboard::Right) {
                    this->player->right();
                } else if (event.key.code == sf::Keyboard::Num1) {
                    this->player->useItem(0);
                } else if (event.key.code == sf::Keyboard::Num2) {
                    this->player->useItem(1);
                } else if (event.key.code == sf::Keyboard::Num3) {
                    this->player->useItem(2);
                } else if (event.key.code == sf::Keyboard::Num4) {
                    this->player->useItem(3);
                } else if (event.key.code == sf::Keyboard::Num5) {
                    this->player->useItem(4);
                } else if (event.key.code == sf::Keyboard::Num6) {
                    this->player->useItem(5);
                } else if (event.key.code == sf::Keyboard::Num7) {
                    this->player->useItem(6);
                } else if (event.key.code == sf::Keyboard::Num8) {
                    this->player->useItem(7);
                } else if (event.key.code == sf::Keyboard::Num9) {
                    this->player->useItem(8);
                } else if (event.key.code == sf::Keyboard::Num0) {
                    this->player->useItem(9);
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
    sf::Vector2i localPosition = sf::Mouse::getPosition(this->window);
    this->rectangle.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    this->menuButtonResumeS.setPosition((window.getSize().x / 2) - 360, (window.getSize().y / 2) + 150);
    this->menuButtonLeaveS.setPosition((window.getSize().x / 2) + 190, (window.getSize().y / 2) + 150);
    this->menuButtonRetryS.setPosition((window.getSize().x / 2) - 80, (window.getSize().y / 2) + 150);

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
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        localPosition.x <= this->menuButtonLeaveS.getPosition().x + 180 &&
        localPosition.x >= this->menuButtonLeaveS.getPosition().x &&
        localPosition.y <= this->menuButtonLeaveS.getPosition().y + 130 &&
        localPosition.y >= this->menuButtonLeaveS.getPosition().y) {
        exit(0);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        localPosition.x <= this->menuButtonResumeS.getPosition().x + 180 &&
        localPosition.x >= this->menuButtonResumeS.getPosition().x &&
        localPosition.y <= this->menuButtonResumeS.getPosition().y + 130 &&
        localPosition.y >= this->menuButtonResumeS.getPosition().y) {
        Core::core->setPause(false);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        localPosition.x <= this->menuButtonRetryS.getPosition().x + 180 &&
        localPosition.x >= this->menuButtonRetryS.getPosition().x &&
        localPosition.y <= this->menuButtonRetryS.getPosition().y + 130 &&
        localPosition.y >= this->menuButtonRetryS.getPosition().y) {
        std::cout << "clic retry | doit relancer le niveau" << std::endl;
    }

    // this->window.clear(); // maybe ne sert a rien, maybe fais tout bug
    this->window.draw(this->rectangle);
    this->window.draw(this->menuButtonLeaveS);
    this->window.draw(this->menuButtonResumeS);
    this->window.draw(this->menuButtonRetryS);
    this->window.display(); // maybe ne sert a rien, maybe fais tout bug
}
