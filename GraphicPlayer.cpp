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

        switch (this->dir) {
            case orientation::LEFT:

                if (this->animate_x >= 1.0f)
                    return;

                this->animate_x += this->speed;
                break;
            case orientation::RIGHT:

                if (this->animate_x <= -1.0f)
                    return;

                this->animate_x -= this->speed;
                break;
            case orientation::TOP:

                if (this->animate_y <= -1.0f)
                    return;

                this->animate_y -= this->speed;
                break;
            case orientation::BOTTOM:

                if (this->animate_y >= 1.0f)
                    return;

                this->animate_y += this->speed;
                break;
        }

    if (this->animate_x >= 1.0f) {
        this->animate_x = 0.0f;
        this->x++;
    }

    if (this->animate_x <= -1.0f) {
        this->animate_x = 0.0f;
        this->x--;
    }

    if (this->animate_y >= 1.0f) {
        this->animate_y = 0.0f;
        this->y++;
    }

    if (this->animate_y <= -1.0f) {
        this->animate_y = 0.0f;
        this->y--;
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

    this->animate_x = 0.0f;
    this->animate_y = 0.0f;
}

// inform left movement
void GraphicPlayer::left() {
    this->setDirection(orientation::LEFT);
}

// inform right movement
void GraphicPlayer::right() {
    this->setDirection(orientation::RIGHT);
}

// inform top movement
void GraphicPlayer::top() {
    this->setDirection(orientation::TOP);
}

// inform bottom movement
void GraphicPlayer::bottom() {
    this->setDirection(orientation::BOTTOM);
}

// (from 0 to 1, 1 is 100% and 0 is 0%)
void GraphicPlayer::setHealth(float value) {
    this->health = value;
}

// set orientation
void GraphicPlayer::setDirection(orientation dir)
{
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
