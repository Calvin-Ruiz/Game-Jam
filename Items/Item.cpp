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

Item::Item(sf::RenderWindow &window, sf::Texture &texture, int phaseCount, int fullTime) :
    window(window), sprite(texture), buffer(sf::PrimitiveType::TriangleStrip, 4), fullTime(fullTime), phaseCount(phaseCount)
{
    buffer[0].color = buffer[1].color = buffer[2].color = buffer[3].color = sf::Color::Green;
    rect = sprite.getTextureRect();
    rect.width /= phaseCount;
}

Item::~Item()
{}

void Item::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
    lastValue = 0;
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
        drawInInventory();
    }
}

void Item::drawInInventory()
{
    rect.left = rect.width * (phaseCount * time / fullTime);
    sprite.setTextureRect(rect);
    window.draw(sprite);
    if (++time >= fullTime)
        time = 0;
    if (value != lastValue) {
        auto tmp = sprite.getGlobalBounds();
        const int x1 = tmp.left + 2;
        const int y1 = tmp.top + tmp.height - 10;
        buffer[0].position.x = buffer[1].position.x = x1;
        buffer[2].position.x = buffer[3].position.x = x1 + value * (tmp.width - 4);
        buffer[0].position.y = buffer[2].position.y = y1;
        buffer[1].position.y = buffer[3].position.y = y1 + 8;
        lastValue = value;
    }
    window.draw(buffer);
}

bool Item::take(int idx)
{
    sprite.setPosition(256 * (idx + 3), 2560);
    isOnLand = false;
    return true;
}

bool Item::use(int x, int y)
{
    return (drop(x, y));
}
