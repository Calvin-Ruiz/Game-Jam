/*
** EPITECH PROJECT, 2021
** Game-Jam
** File description:
** StartMenu
*/

#include "StartMenu.hpp"

StartMenu::StartMenu(sf::RenderWindow &window, sf::Event &event) : window(window), event(event)
{
    if (!this->menuStartBackgroundT.loadFromFile("Sprite/splash.png", sf::IntRect(0, 0, 1980, 1080)))
        std::cerr << "menuStartBackground can't load from file" << std::endl;
    if (!this->menuButtonExitT.loadFromFile("Sprite/Exit_button.png"))
        std::cerr << "menuButtonExit can't load from file" << std::endl;
    if (!this->menuButtonPlayT.loadFromFile("Sprite/play_button.png"))
        std::cerr << "menuButtonPlay can't load from file" << std::endl;
    if (!this->gameOverFont.loadFromFile("Sprite/game_over.ttf"))
        std::cerr << "gameOverFont can't load from file" << std::endl;
    
    this->menuButtonPlayS.setTexture(menuButtonPlayT);
    this->menuButtonExitS.setTexture(menuButtonExitT);
    this->menuStartBackgroundS.setTexture(menuStartBackgroundT);
    this->triangle1.setRadius(40);
    this->triangle1.setPointCount(3);
    this->triangle2.setRadius(40);
    this->triangle2.setPointCount(3);
    this->rectangle.setSize((sf::Vector2f(170, 60)));
    this->numberLvlText.setFont(this->gameOverFont);
    this->numberLvlText.setCharacterSize(80);
    this->numberLvlText.setFillColor(sf::Color::Green);
    this->selectLvlText.setFont(this->gameOverFont);
    this->selectLvlText.setString("Select Your Level");
    this->selectLvlText.setCharacterSize(80);
    this->selectLvlText.setFillColor(sf::Color::Green);
    this->level = 1;
}

StartMenu::~StartMenu()
{
}

void StartMenu::selectLvlLoop()
{
    bool back = false;
    while (back == false) {
        sf::Vector2i localPosition = sf::Mouse::getPosition(this->window);

        this->numberLvlText.setString(std::to_string(this->level));
        if (this->level >= 100)
            this->numberLvlText.setPosition((this->window.getSize().x / 2) - 20, (this->window.getSize().y / 2) + 70);
        else if (this->level >= 10)
            this->numberLvlText.setPosition((this->window.getSize().x / 2) - 15, (this->window.getSize().y / 2) + 70);
        else
            this->numberLvlText.setPosition((this->window.getSize().x / 2) - 9, (this->window.getSize().y / 2) + 70);

        this->selectLvlText.setPosition((this->window.getSize().x / 2) - 120, (this->window.getSize().y / 2));
        this->rectangle.setPosition((this->window.getSize().x / 2) - 85, (this->window.getSize().y / 2) + 110);
        this->triangle1.setRotation(270);
        this->triangle1.setPosition((this->window.getSize().x / 2) - 300, (this->window.getSize().y / 2) + 180);
        this->triangle2.setRotation(90);
        this->triangle2.setPosition((this->window.getSize().x / 2) + 300, (this->window.getSize().y / 2) + 100);
        this->menuButtonPlayS.setPosition((window.getSize().x / 2) - 80, (window.getSize().y / 2) + 180);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    return mainloop();
                }
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (
                        localPosition.x <= this->triangle1.getPosition().x + 70 && 
                        localPosition.x >= this->triangle1.getPosition().x && 
                        localPosition.y <= this->triangle1.getPosition().y && 
                        localPosition.y >= this->triangle1.getPosition().y - 80) {
                        if (this->level > 1)
                            this->level = this->level - 1;
                    } else if (
                        localPosition.x <= this->triangle2.getPosition().x && 
                        localPosition.x >= this->triangle2.getPosition().x - 70 && 
                        localPosition.y <= this->triangle2.getPosition().y + 80 && 
                        localPosition.y >= this->triangle2.getPosition().y) {
                        if (this->level < this->maxLevel) // nombre max de lvl debloquée
                            this->level = this->level + 1;
                    }
                }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
            localPosition.x <= this->menuButtonPlayS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonPlayS.getPosition().x && 
            localPosition.y <= this->menuButtonPlayS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonPlayS.getPosition().y) {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(320, 0, 160, 80));
            return;
        } else if (localPosition.x <= this->menuButtonPlayS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonPlayS.getPosition().x && 
            localPosition.y <= this->menuButtonPlayS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonPlayS.getPosition().y) {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(160, 0, 160, 80));
        } else {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(0, 0, 160, 80));
        }

        this->window.clear();
        this->window.draw(this->menuStartBackgroundS);
        this->window.draw(this->triangle1);
        this->window.draw(this->triangle2);
        this->window.draw(this->rectangle);
        this->window.draw(this->selectLvlText);
        this->window.draw(this->numberLvlText);
        this->window.draw(this->menuButtonPlayS);
        this->window.display();
    }
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
            selectLvlLoop();
        } else if (localPosition.x <= this->menuButtonPlayS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonPlayS.getPosition().x && 
            localPosition.y <= this->menuButtonPlayS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonPlayS.getPosition().y) {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(160, 0, 160, 80));
        } else {
            this->menuButtonPlayS.setTextureRect(sf::IntRect(0, 0, 160, 80));
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
            localPosition.x <= this->menuButtonExitS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonExitS.getPosition().x && 
            localPosition.y <= this->menuButtonExitS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonExitS.getPosition().y) {
            this->menuButtonExitS.setTextureRect(sf::IntRect(320, 0, 160, 80));
            exit(0);
        } else if (localPosition.x <= this->menuButtonExitS.getPosition().x + 160 && 
            localPosition.x >= this->menuButtonExitS.getPosition().x && 
            localPosition.y <= this->menuButtonExitS.getPosition().y + 80 && 
            localPosition.y >= this->menuButtonExitS.getPosition().y) {
            this->menuButtonExitS.setTextureRect(sf::IntRect(160, 0, 160, 80));
        } else {
            this->menuButtonExitS.setTextureRect(sf::IntRect(0, 0, 160, 80));
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    exit(0);
                }
            }
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