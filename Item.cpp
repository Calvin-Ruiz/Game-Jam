/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Item.cpp
*/
#include "Item.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Core.hpp"
#include "Room.hpp"

Item::Item(sf::RenderWindow &window, sf::Texture &texture) : window(window), sprite(texture)
{}

Item::~Item()
{}

void Item::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

bool Item::drop(int x, int y)
{
    Item *&target = Core::core->rooms[x][y].item;
    if (target)
        return false;
    Core::core->getCoordFromPos(x, y);
    setPosition(x, y);
    isOnLand = true;
    target = this;
    return true;
}

void Item::draw()
{
    if (isOnLand) {
        window.draw(sprite);
    }
}

void Item::drawInInventory()
{
    window.draw(sprite);
}

bool Item::use(int x, int y)
{
    return (drop(x, y));
}
