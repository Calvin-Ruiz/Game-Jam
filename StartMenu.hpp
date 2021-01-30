/*
** EPITECH PROJECT, 2021
** Game-Jam
** File description:
** StartMenu
*/

#ifndef STARTMENU_HPP_
#define STARTMENU_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class StartMenu {
    public:
        StartMenu(sf::RenderWindow &window, sf::Event &event);
        virtual ~StartMenu();

        void mainloop();
        void selectLvlLoop();
        sf::Sprite getMenuStartBackground();
        sf::Sprite getMenuButtonPlay();
        sf::Sprite getMenuButtonExit();

    protected:
    private:
        sf::RenderWindow &window;
        sf::Event &event;
        sf::Texture menuStartBackgroundT;
        sf::Sprite menuStartBackgroundS;
        sf::Texture menuButtonPlayT;
        sf::Sprite menuButtonPlayS;
        sf::Texture menuButtonExitT;
        sf::Sprite menuButtonExitS;
};

#endif /* !STARTMENU_HPP_ */
