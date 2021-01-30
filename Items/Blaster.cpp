/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Blaster.cpp
*/
#include "Blaster.hpp"
#include "Core.hpp"
#include "Player.hpp"

Blaster::Blaster(sf::RenderWindow &window, sf::Texture &texture, sf::Texture &bulletTexture, float speed, int ammos, DynamicItem::actionType action) :
    Item(window, texture), bulletTexture(bulletTexture), speed(speed), maxAmmos(ammos), ammos(ammos), action(action)
{}

Blaster::~Blaster()
{}

bool Blaster::use(int _x, int _y)
{
    auto tmp = Core::core->getDynamicItem();
    Core::core->getCenteredCoordFromPos(_x, _y);
    switch (Player::instance->getOrientation()) {
        case GraphicPlayer::LEFT:
            tmp->redefine(bulletTexture, _x, _y, -speed, 0, action);
            break;
        case GraphicPlayer::RIGHT:
            tmp->redefine(bulletTexture, _x, _y, speed, 0, action);
            break;
        case GraphicPlayer::TOP:
            tmp->redefine(bulletTexture, _x, _y, 0, -speed, action);
            break;
        case GraphicPlayer::BOTTOM:
            tmp->redefine(bulletTexture, _x, _y, 0, speed, action);
            break;
    }
    if (--ammos <= 0)
        return true;
    value = (float) ammos / (float) maxAmmos;
    return false;
}
