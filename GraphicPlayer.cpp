/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GraphicPlayer.cpp
*/
#include "GraphicPlayer.hpp"

GraphicPlayer::GraphicPlayer()
{
    this->speed = 3;
}

GraphicPlayer::~GraphicPlayer()
{}

// define or redefine position
void GraphicPlayer::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

// inform left movement
void GraphicPlayer::left() {
    this->x += this->speed;
    this->setDirection(orientation::LEFT);
}

// inform right movement
void GraphicPlayer::right() {
    this->x -= this->speed;
    this->setDirection(orientation::RIGHT);
}

// inform top movement
void GraphicPlayer::top() {
    this->y -= this->speed;
    this->setDirection(orientation::TOP);
}

// inform bottom movement
void GraphicPlayer::bottom() {
    this->y += this->speed;
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
