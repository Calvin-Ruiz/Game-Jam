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
#include "ItemMgr.hpp"
#include "GlobalActivity.hpp"
#include "CreeperWalk.hpp"
#include "WindowManager.hpp"

#include "Room.hpp"

int main(/*int argc, char const *argv[]*/)
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Labyrinth", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    sf::Event event;
    StartMenu startMenu(window, event);

    int width = 20;
    int height = 20;
    while (window.isOpen()) {
        // main menu
        startMenu.mainloop();

        if (!window.isOpen())
            break;
        Core core;
        createLaby(core.getSeed(), width, height, core.rooms, core.getItemList());

        // Build everything here
        core.startMainloop(5, new CreeperWalk(core.rooms));
        core.startMainloop(20, new GlobalActivity());
        //core.startMainloop(60, new WindowManager(window));
        core.mainloop();
    }
    return 0;
}
