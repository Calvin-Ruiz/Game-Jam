/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** MediKit.cpp
*/
#include "MediKit.hpp"
#include "Player.hpp"

MediKit::MediKit(sf::RenderWindow &window, sf::Texture &texture) : Item(window, texture)
{}

MediKit::~MediKit()
{}

bool MediKit::use(int, int)
{
    Player::instance->recover();
    return (true);
}
