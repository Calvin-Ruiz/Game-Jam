/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Door.cpp
*/
#include "Door.hpp"
#include "Core.hpp"
#include "Room.hpp"

Door::Door(sf::RenderWindow &window, sf::Texture &texture, int health) : Item(window, texture, 1), maxHealth(health), health(health)
{}

Door::~Door()
{}

bool Door::damage()
{
    if (--health < 0) {
        // The door is broken !
        return (true);
    }
    value = (float) health / (float) maxHealth;
    return (false);
}

bool Door::drop(int x, int y)
{
    Item *&target = Core::core->rooms[x][y].item;
    bool &b = Core::core->rooms[x][y].isBlocking;
    if (target)
        return false;
    Core::core->getCoordFromPos(x, y);
    setPosition(x, y);
    isOnLand = true;
    target = this;
    b = true;
    return true;
}

bool Door::use(int x, int y)
{
    return (drop(x, y));
}
