/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GraphicPlayer.cpp
*/
#include "GraphicPlayer.hpp"

GraphicPlayer::GraphicPlayer()
{
    this->speed = 0.2f;
    this->animate_x = 0.0f;
    this->animate_y = 0.0f;

    this->setDirection(orientation::LEFT);
}

GraphicPlayer::~GraphicPlayer()
{}

void GraphicPlayer::update()
{

    if (this->animate_x == 0 || this->animate_y == 0)
        return;

    switch (this->dir) {
        case orientation::LEFT:
            this->animate_x += this->speed;
            break;
        case orientation::RIGHT:
            this->animate_x -= this->speed;
            break;
        case orientation::TOP:
            this->animate_y -= this->speed;
            break;
        case orientation::BOTTOM:
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

// define or redefine position
void GraphicPlayer::setPosition(int x, int y) {
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
void GraphicPlayer::setDirection(orientation dir) {
    this->dir = dir;
}
