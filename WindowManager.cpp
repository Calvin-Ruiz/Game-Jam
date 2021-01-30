/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.cpp
*/
#include "WindowManager.hpp"

WindowManager::WindowManager(sf::RenderWindow &window) : window(window)
{}

WindowManager::~WindowManager()
{}

void WindowManager::onPause()
{
    this->window.clear(); // maybe ne sert a rien, maybe fais tout bug
    this->window.draw(this->rectangle);
    this->window.draw(this->menuButtonLeaveS);
    this->window.draw(this->menuButtonResumeS);
    this->window.draw(this->menuButtonRetryS);
    this->window.display(); // maybe ne sert a rien, maybe fais tout bug
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
}