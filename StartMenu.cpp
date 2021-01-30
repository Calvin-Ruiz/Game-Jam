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

void StartMenu::selectLvlLoop()
{
    bool back = false;
    int x = 1;
    while (back == false) {
        sf::Vector2i localPosition = sf::Mouse::getPosition(this->window);
        sf::CircleShape triangle1(40, 3);
        sf::CircleShape triangle2(40, 3);
        sf::RectangleShape rectangle(sf::Vector2f(170, 60));
        sf::Text selectLvlText;
        sf::Text numberLvlText;
        sf::Font gameOverFont;
        if (!gameOverFont.loadFromFile("Sprite/game_over.ttf"))
            std::cerr << "gameOverFont can't load from file" << std::endl;

        numberLvlText.setFont(gameOverFont);
        numberLvlText.setString(std::to_string(x));
        numberLvlText.setCharacterSize(80);
        numberLvlText.setFillColor(sf::Color::Green);
        if (x >= 100)
            numberLvlText.setPosition((this->window.getSize().x / 2) - 20, (this->window.getSize().y / 2) + 70);
        else if (x >= 10)
            numberLvlText.setPosition((this->window.getSize().x / 2) - 15, (this->window.getSize().y / 2) + 70);
        else
            numberLvlText.setPosition((this->window.getSize().x / 2) - 9, (this->window.getSize().y / 2) + 70);

        selectLvlText.setFont(gameOverFont);
        selectLvlText.setString("Select Your Level");
        selectLvlText.setCharacterSize(80);
        selectLvlText.setFillColor(sf::Color::Green);
        selectLvlText.setPosition((this->window.getSize().x / 2) - 120, (this->window.getSize().y / 2));

        // (this->window.getSize().x / 2) - 120, (this->window.getSize().y / 2) + 70
        rectangle.setPosition((this->window.getSize().x / 2) - 85, (this->window.getSize().y / 2) + 110);
        triangle1.setRotation(270);
        triangle1.setPosition((this->window.getSize().x / 2) - 300, (this->window.getSize().y / 2) + 180);
        // triangle1.setPosition(200, 480);
        triangle2.setRotation(90);
        triangle2.setPosition((this->window.getSize().x / 2) + 300, (this->window.getSize().y / 2) + 100);
        // triangle2.setPosition(700, 400);

        // 101 | 440
        // printf("%d | %d\n", localPosition.x, localPosition.y);

        if (// sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
            localPosition.x <= triangle1.getPosition().x + 70 && 
            localPosition.x >= triangle1.getPosition().x && 
            localPosition.y <= triangle1.getPosition().y && 
            localPosition.y >= triangle1.getPosition().y - 80) {
            std::cout << "triangle1" << std::endl;
            // x = x - 1;
        } else if (// sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
            localPosition.x <= triangle2.getPosition().x + 100 && 
            localPosition.x >= triangle2.getPosition().x && 
            localPosition.y <= triangle2.getPosition().y - 100 && 
            localPosition.y >= triangle2.getPosition().y) {
            std::cout << "triangle2" << std::endl;
            // x = x + 1;
        } else
            printf("%d | %d\n", localPosition.x, localPosition.y);

        this->window.clear();
        this->window.draw(this->menuStartBackgroundS);
        this->window.draw(triangle1);
        this->window.draw(triangle2);
        this->window.draw(rectangle);
        this->window.draw(selectLvlText);
        this->window.draw(numberLvlText);
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
            // selectLvlLoop();
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