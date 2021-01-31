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

#define COEF 10.f

void findExit(int &x, int &y, std::vector<std::vector<room>> &rooms, Exit exit);

int main(/*int argc, char const *argv[]*/)
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Amoeba Dungeon", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    sf::Event event;
    StartMenu startMenu(window, event);
    ItemMgr imgr(window);
    imgr.setItemData(ItemMgr::BLASTER, "blaster.png", COEF * 0.3, 24);
    imgr.setItemData(ItemMgr::BAZOOKA, "bazooka.png", COEF * 0.1, 2);
    imgr.setItemData(ItemMgr::DOOR, "door.png", COEF * 0.5, 32);
    imgr.setItemData(ItemMgr::KEY, "key.png", -1);
    imgr.setItemData(ItemMgr::MEDIKIT, "medikit.png", COEF * 0.2);
    imgr.setItemData(ItemMgr::BULLET, "bullet.png", 0, 25);
    imgr.setItemData(ItemMgr::ROCKET, "rocket.png", 0, 15);
    imgr.setItemData(ItemMgr::EXIT, "exit.png", 0);

    while (window.isOpen()) {
        // main menu
        startMenu.mainloop();
        int width = startMenu.getLevel() * 10 + 10;
        int height = startMenu.getLevel() * 10 + 10;

        if (!window.isOpen())
            break;
        Core core;
        core.setRoomSize(0, 0, 256, 256);
        int x = 5, y = 5; // must be replaced by the entry location
        createLaby(core.getSeed(), width, height, core.rooms, core.getItemList());
        findExit(x, y, Core::core->rooms, ENTER);
        core.initX = x;
        core.initY = y;
        imgr.setLoot();

        // Build everything here
        auto cd = new CreeperDisplay(window, core.rooms);
        auto cw = new CreeperWalk(core.rooms);
        cw->reset(50, 15, x, y); // 10 seconds before creeper comes, then 3 seconds per step
        //core.startMainloop(30, cd);
        core.startMainloop(5, cw);
        core.startMainloop(20, new GlobalActivity());
        core.startMainloop(60, new WindowManager(window));
        core.mainloop();
        if (core.isCompleted)
            startMenu.setMaxLevel(startMenu.getLevel() + 1);
    }
    startMenu.destroy();
    return 0;
}
