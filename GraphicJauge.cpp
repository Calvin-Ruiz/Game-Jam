/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GraphicJauge.cpp
*/

#include "GraphicJauge.hpp"
#include "Player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

GraphicJauge::GraphicJauge(sf::RenderWindow &window, Player &player) : window(window), player(player), buffer(sf::PrimitiveType::TriangleStrip, 12)
{
    buffer[0].color = sf::Color::White;
    buffer[1].color = sf::Color::White;
    buffer[2].color = sf::Color::White;
    buffer[3].color = sf::Color::White;
    buffer[4].color = sf::Color::Red;
    buffer[5].color = sf::Color::Red;
    buffer[6].color = sf::Color::Green;
    buffer[7].color = sf::Color::Green;
    buffer[8].color = sf::Color::Black;
    buffer[9].color = sf::Color::Black;
    buffer[10].color = sf::Color::Black;
    buffer[11].color = sf::Color::Black;

    width = 40;
    height = 100;
}

GraphicJauge::~GraphicJauge()
{}

void GraphicJauge::setValue(float value)
{
    float _x = x + (1.f - value) * width;
    buffer[10].position.x = _x;
    buffer[11].position.x = _x;
}

void GraphicJauge::onResize()
{
    buffer[0].position.x = x + width + 1;
    buffer[1].position.x = x + width + 1;
    buffer[2].position.x = x - 1;
    buffer[3].position.x = x - 1;
    buffer[0].position.y = y - 1;
    buffer[2].position.y = y - 1;
    buffer[1].position.y = y + height + 1;
    buffer[3].position.y = y + height + 1;

    buffer[4].position.x = x;
    buffer[5].position.x = x;
    buffer[10].position.x = x;
    buffer[11].position.x = x;
    buffer[6].position.x = x + width;
    buffer[7].position.x = x + width;
    buffer[8].position.x = x + width;
    buffer[9].position.x = x + width;
    buffer[4].position.y = y;
    buffer[6].position.y = y;
    buffer[8].position.y = y;
    buffer[10].position.y = y;
    buffer[5].position.y = y + height;
    buffer[7].position.y = y + height;
    buffer[9].position.y = y + height;
    buffer[11].position.y = y + height;
}

void GraphicJauge::update()
{
    setValue(player->getValue());
}

void GraphicJauge::draw()
{
    window->draw(buffer);
}
