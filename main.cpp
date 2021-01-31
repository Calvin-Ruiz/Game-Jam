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
#include "CreeperDisplay.hpp"

#include "Room.hpp"

int main(/*int argc, char const *argv[]*/)
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Amoeba Dungeon", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    sf::Event event;
    StartMenu startMenu(window, event);
    ItemMgr imgr(window);
    imgr.setItemData(ItemMgr::BLASTER, "blaster.png", 0.3, 24);
    imgr.setItemData(ItemMgr::BAZOOKA, "bazooka.png", 0.1, 2);
    imgr.setItemData(ItemMgr::DOOR, "door.png", 0.5, 32);
    imgr.setItemData(ItemMgr::KEY, "key.png", -1);
    imgr.setItemData(ItemMgr::MEDIKIT, "medikit.png", 0.2);
    imgr.setItemData(ItemMgr::BULLET, "bullet.png", 0, 0.1f);
    imgr.setItemData(ItemMgr::ROCKET, "rocket.png", 0, 0.15f);
    imgr.setItemData(ItemMgr::EXIT, "exit.png", 0);

    int width = 20;
    int height = 20;
    while (window.isOpen()) {
        // main menu
        startMenu.mainloop();

        if (!window.isOpen())
            break;
        Core core;
        int x = 5, y = 5; // must be replaced by the entry location
        core.initX = x;
        core.initY = y;
        createLaby(core.getSeed(), width, height, core.rooms, core.getItemList());
        imgr.setLoot();

        // Build everything here
        auto cd = new CreeperDisplay(window, core.rooms);
        auto cw = new CreeperWalk(core.rooms);
        cw->reset(150, 25, x, y); // 30 seconds before creeper comes, then 5 seconds per step
        core.startMainloop(30, cd);
        core.startMainloop(5, cw);
        core.startMainloop(20, new GlobalActivity());
        core.startMainloop(60, new WindowManager(window));
        core.mainloop();
    }
    return 0;
}
