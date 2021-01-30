/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** main.cpp
*/
#include <iostream>
#include <string>
#include "Core.hpp"
#include "StartMenu.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Labyrinth", sf::Style::Default);
    sf::Event event;
    StartMenu startMenu(window, event);

    while (window.isOpen()) {
        // main menu
        startMenu.mainloop();

        if (!window.isOpen())
            break;
        Core core;

        // Build everything here
        core.mainloop();
    }
    return 0;
}
