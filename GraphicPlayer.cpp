/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GraphicPlayer.cpp
*/
#include "GraphicPlayer.hpp"

GraphicPlayer::GraphicPlayer(sf::RenderWindow &window) : window(window)
{
    this->speed = 0.2f;
    this->animate_x = 0.0f;
    this->animate_y = 0.0f;

    this->setDirection(orientation::LEFT);
    tex.loadFromFile("textures/player.png");
    sprite.setTexture(tex);
    sprite.setOrigin(128, 128);
    rect = sprite.getTextureRect();
    rect.width /= phaseCount;
}

GraphicPlayer::~GraphicPlayer()
{}

void GraphicPlayer::update()
{
    if (!moving)
        return;

    switch (this->dir) {
        case orientation::LEFT:
            rx = x * 256 + (256 * (1.f - ((float) ++time) / fullTime));
            break;
        case orientation::RIGHT:
            rx = x * 256 - (256 * (1.f - ((float) ++time) / fullTime));
            break;
        case orientation::TOP:
            ry = y * 256 + (256 * (1.f - ((float) ++time) / fullTime));
            break;
        case orientation::BOTTOM:
            ry = y * 256 - (256 * (1.f - ((float) ++time) / fullTime));
            break;
    }
    if (time == fullTime) {
        time = 0;
        moving = false;
        rx = x * 256;
        ry = y * 256;
    }
}

void GraphicPlayer::render()
{
    rect.left = rect.width * (phaseCount * time / fullTime);
    sprite.setTextureRect(rect);
    int x, y;
    getCoords(x, y);
    sprite.setPosition(x + 128, y + 128);
    window.draw(sprite);
}

// define or redefine position
void GraphicPlayer::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    rx = x * 256;
    ry = y * 256;
}

// inform left movement
void GraphicPlayer::left() {
    this->setDirection(orientation::LEFT);
    --x;
    moving = true;
    time = 0;
}

// inform right movement
void GraphicPlayer::right() {
    this->setDirection(orientation::RIGHT);
    ++x;
    moving = true;
    time = 0;
}

// inform top movement
void GraphicPlayer::top() {
    this->setDirection(orientation::TOP);
    --y;
    moving = true;
    time = 0;
}

// inform bottom movement
void GraphicPlayer::bottom() {
    this->setDirection(orientation::BOTTOM);
    ++y;
    moving = true;
    time = 0;
}

// (from 0 to 1, 1 is 100% and 0 is 0%)
void GraphicPlayer::setHealth(float value) {
    this->health = value;
}

// set orientation
void GraphicPlayer::setDirection(orientation dir)
{
    rx = x * 256;
    ry = y * 256;
    switch (dir) {
        case BOTTOM:
            sprite.setRotation(0);
            break;
        case LEFT:
            sprite.setRotation(90);
            break;
        case TOP:
            sprite.setRotation(180);
            break;
        case RIGHT:
            sprite.setRotation(270);
            break;
    }
    this->dir = dir;
}
