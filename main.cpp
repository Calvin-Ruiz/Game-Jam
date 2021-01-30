/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** main.cpp
*/
#include <iostream>
#include <string>
#include "Core.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Labyrinth", sf::Style::Default);

    while (window.isOpen()) {
        // main menu

        if (!window.isOpen())
            break;
        Core core;

        // Build everything here
        core.mainloop();
    }
    return 0;
}
