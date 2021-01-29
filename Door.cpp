/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Door.cpp
*/
#include "Door.hpp"

Door::Door(sf::RenderWindow &window, sf::Texture &texture, int health) : Item(window, texture), health(health)
{}

Door::~Door()
{}

bool Door::damage()
{
    if (--health < 0) {
        // The door is broken !
        return (true);
    }
    return (false);
}