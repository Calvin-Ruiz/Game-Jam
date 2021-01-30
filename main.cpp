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

#include "Room.hpp"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Labyrinth", sf::Style::Default);
    sf::Event event;
    StartMenu startMenu(window, event);

    // std::vector<std::vector<room>> rooms;
    // std::vector<std::shared_ptr<Item>> items;
    // createLaby(11, 5, 5, rooms, items);


    // Build everything here
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
