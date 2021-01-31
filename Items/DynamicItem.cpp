/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** DynamicItem.cpp
*/
#include "DynamicItem.hpp"
#include "Core.hpp"
#include "CreeperWalk.hpp"
#include "Room.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

sf::Texture DynamicItem::tex;

DynamicItem::DynamicItem(sf::RenderWindow &window) : Item(window, tex)
{
}

DynamicItem::~DynamicItem()
{}

void DynamicItem::redefine(sf::Texture &texture, int _x, int _y, float _vel_x, float _vel_y, enum actionType _action)
{
    sprite.setTexture(texture, true);
    auto tmp = sprite.getTextureRect();
    _x -= tmp.width / 2;
    _y -= tmp.height / 2;
    sprite.setPosition(x, y);
    x = _x;
    y = _y;
    vel_x = _vel_x;
    vel_y = _vel_y;
    action = _action;
    isOnLand = true;
}

void DynamicItem::explode(int x1, int y1, int radius)
{
    auto tmp = CreeperWalk::instance;
    int x2 = x1 + radius;
    int y2 = y1 + radius;
    x1 -= radius;
    y1 -= radius;
    Core::core->clampPos(x1, y1);
    Core::core->clampPos(x2, y2);
    tmp->lock();
    while (y1 <= y2) {
        for (int _x = x1; _x <= x2; _x++) {
            tmp->killCreeper(_x, y1);
        }
        y2++;
    }
    tmp->unlock();
}

void DynamicItem::reaction(int _x, int _y, orientation dir)
{
    switch (action) {
        case BULLET:
            explode(_x, _y, 0);
            break;
        case ROCKET:
            explode(_x, _y, 5);
            switch (dir) {
                case LEFT:
                    Core::core->rooms[_x][_y].left = true;
                    Core::core->rooms[_x - 1][_y].right = true;
                    Core::core->rooms[_x][_y].hasWallChanged = true;
                    Core::core->rooms[_x - 1][_y].hasWallChanged = true;
                    break;
                case RIGHT:
                    Core::core->rooms[_x][_y].right = true;
                    Core::core->rooms[_x + 1][_y].left = true;
                    Core::core->rooms[_x][_y].hasWallChanged = true;
                    Core::core->rooms[_x + 1][_y].hasWallChanged = true;
                    break;
                case TOP:
                    Core::core->rooms[_x][_y].top = true;
                    Core::core->rooms[_x][_y - 1].bottom = true;
                    Core::core->rooms[_x][_y].hasWallChanged = true;
                    Core::core->rooms[_x][_y - 1].hasWallChanged = true;
                    break;
                case BOTTOM:
                    Core::core->rooms[_x][_y].bottom = true;
                    Core::core->rooms[_x][_y + 1].top = true;
                    Core::core->rooms[_x][_y].hasWallChanged = true;
                    Core::core->rooms[_x][_y + 1].hasWallChanged = true;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    isOnLand = false;
}

void DynamicItem::update()
{
    if (isOnLand) {
        sprite.move(vel_x, vel_y);
        sf::FloatRect rect = sprite.getGlobalBounds();
        int x1 = rect.left;
        int y1 = rect.top;
        int x2 = x1 + rect.width;
        int y2 = y1 + rect.width;
        Core::core->getPosFromCoords(x1, y1);
        Core::core->getPosFromCoords(x2, y2);
        room *t1 = &Core::core->rooms[x1][y1];
        room *t2 = &Core::core->rooms[x2][y2];
        if (t1 == t2) {
            if (t1->hasCreeper) {
                reaction(x1, y1, NONE);
            }
            return;
        }
        if (vel_x == 0) {
            if (vel_y < 0) { // top
                if (!t2->top)
                    reaction(x2, y2, TOP);
            } else { // bottom
                if (!t1->bottom)
                    reaction(x1, y1, BOTTOM);
            }
        } else {
            if (vel_x < 0) { // left
                if (!t2->left)
                    reaction(x2, y2, LEFT);
            } else { // right
                if (!t1->right)
                    reaction(x1, y1, RIGHT);
            }
        }
    }
}
