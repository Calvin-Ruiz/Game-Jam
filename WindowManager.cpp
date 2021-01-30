/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.cpp
*/
#include "WindowManager.hpp"
#include "Core.hpp"

WindowManager::WindowManager(sf::RenderWindow &window) : window(window)
{
    this->player = nullptr;
}

WindowManager::~WindowManager()
{}

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
}

void WindowManager::refresh()
{
    window.clear();
    window.display();
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
