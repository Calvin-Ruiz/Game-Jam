/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Player.cpp
*/
#include "Player.hpp"
#include "GraphicPlayer.hpp"
#include "Room.hpp"
#include "Core.hpp"
#include "Item.hpp"

Player *Player::instance = nullptr;

Player::Player(GraphicPlayer *gPlayer) : gPlayer(gPlayer)
{
    instance = this;
    health = maxHealth;
}

Player::~Player()
{}

void Player::setPosition(int _x, int _y)
{
    x = _x;
    y = _y;
    gPlayer->setPosition(x, y);
    pos = &Core::core->rooms[x][y];
}

void Player::left()
{
    dir = GraphicPlayer::LEFT;
    gPlayer->setDirection(dir);
    if (pos->left) {
        gPlayer->left();
        pos = &Core::core->rooms[--x][y];
    }
}

void Player::right()
{
    dir = GraphicPlayer::RIGHT;
    gPlayer->setDirection(dir);
    if (pos->right) {
        gPlayer->right();
        pos = &Core::core->rooms[++x][y];
    }
}

void Player::top()
{
    dir = GraphicPlayer::TOP;
    gPlayer->setDirection(dir);
    if (pos->top) {
        gPlayer->top();
        pos = &Core::core->rooms[x][--y];
    }
}

void Player::bottom()
{
    dir = GraphicPlayer::BOTTOM;
    gPlayer->setDirection(dir);
    if (pos->bottom) {
        gPlayer->bottom();
        pos = &Core::core->rooms[x][++y];
    }
}

void Player::useItem(int idx)
{
    if (inventory[idx]) {
        // use item
        if (inventory[idx]->use(x, y))
            inventory[idx] = nullptr;
    } else {
        // collect item in the ground
        Item *item = pos->item;
        if (item && item->take(idx))
            inventory[idx] = item;
    }
}

bool Player::update()
{
    gPlayer->update();
    if (pos && pos->hasCreeper) {
        gPlayer->setHealth((float) --health / (float) maxHealth);
    }
    return (health > 0);
}

void Player::draw()
{
    for (auto item : inventory) {
        if (item)
            item->drawInInventory();
    }
}

void Player::recover()
{
    health = maxHealth;
    gPlayer->setHealth(1);
}
