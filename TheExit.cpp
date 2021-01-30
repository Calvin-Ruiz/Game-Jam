/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** TheExit.cpp
*/
#include "TheExit.hpp"

TheExit::TheExit(sf::RenderWindow &window, sf::Texture &texture) : Item(window, texture)
{}

TheExit::~TheExit()
{}

bool TheExit::take()
{
    return false;
}
