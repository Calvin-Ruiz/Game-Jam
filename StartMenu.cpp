/*
** EPITECH PROJECT, 2021
** Game-Jam
** File description:
** StartMenu
*/

#include "StartMenu.hpp"

StartMenu::StartMenu(sf::RenderWindow &window, sf::Event &event) : window(window), event(event)
{
    if (!this->menuStartBackgroundT.loadFromFile("Sprite/wallhaven-51384-1024x576.jpeg", sf::IntRect(0, 0, 1980, 1080)))
        std::cerr << "menuStartBackground can't load from file" << std::endl;
    if (!this->menuButtonExitT.loadFromFile("Sprite/Exit_button.png"))
        std::cerr << "menuButtonExit can't load from file" << std::endl;
    if (!this->menuButtonPlayT.loadFromFile("Sprite/play_button.png"))
        std::cerr << "menuButtonPlay can't load from file" << std::endl;
    
    this->menuButtonPlayS.setTexture(menuButtonPlayT);
    this->menuButtonExitS.setTexture(menuButtonExitT);
    this->menuStartBackgroundS.setTexture(menuStartBackgroundT);
}

StartMenu::~StartMenu()
{
}

void StartMenu::mainloop()
{
    bool buttonClick = false;
    while (buttonClick == false) {
        sf::Vector2i localPosition = sf::Mouse::getPosition(this->window);
        this->menuButtonPlayS.setPosition((this->window.getSize().x / 2) - 160 - 200, (this->window.getSize().y / 2) + 150);
        this->menuButtonExitS.setPosition((this->window.getSize().x / 2) - 160 + 350, (this->window.getSize().y / 2) + 150);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
            localPosition.x <= this->menuButtonPlayS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonPlayS.getPosition().x && 
            localPosition.y <= this->menuButtonPlayS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonPlayS.getPosition().y) {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(320, 0, 160, 80));
            buttonClick = true;
        } else if (localPosition.x <= this->menuButtonPlayS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonPlayS.getPosition().x && 
            localPosition.y <= this->menuButtonPlayS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonPlayS.getPosition().y) {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(160, 0, 160, 80));
        } else {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(0, 0, 160, 80));
        }

        if (this->event.type == sf::Event::MouseButtonPressed && this->event.mouseButton.button == sf::Mouse::Left && 
            localPosition.x <= this->menuButtonExitS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonExitS.getPosition().x && 
            localPosition.y <= this->menuButtonExitS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonExitS.getPosition().y) {
            this->menuButtonExitS.setTextureRect(sf::IntRect(320, 0, 160, 80));
            buttonClick = true;
        } else if (localPosition.x <= this->menuButtonExitS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonExitS.getPosition().x && 
            localPosition.y <= this->menuButtonExitS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonExitS.getPosition().y) {
            this->menuButtonExitS.setTextureRect(sf::IntRect(160, 0, 160, 80));
        } else {
            this->menuButtonExitS.setTextureRect(sf::IntRect(0, 0, 160, 80));
        }

        this->window.clear();
        this->window.draw(this->menuStartBackgroundS);
        this->window.draw(this->menuButtonPlayS);
        this->window.draw(this->menuButtonExitS);
        this->window.display();
    }
}

sf::Sprite StartMenu::getMenuStartBackground()
{
    return (this->menuStartBackgroundS);
}

sf::Sprite StartMenu::getMenuButtonPlay()
{
    return (this->menuButtonPlayS);
}

sf::Sprite StartMenu::getMenuButtonExit()
{
    return (this->menuButtonExitS);
}