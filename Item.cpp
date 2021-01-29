/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Item.cpp
*/
#include "Item.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

Item::Item(sf::RenderWindow &window, sf::Texture &texture) : window(window)
{}

Item::~Item()
{}
