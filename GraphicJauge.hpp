/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GraphicJauge.hpp
*/

#ifndef GRAPHICJAUGE_HPP_
#define GRAPHICJAUGE_HPP_

#include "GraphicPlayer.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class GraphicJauge {
public:
    GraphicJauge(sf::RenderWindow &window, GraphicPlayer &player);
    virtual ~GraphicJauge();
    GraphicJauge(const GraphicJauge &cpy) = default;
    GraphicJauge &operator=(const GraphicJauge &src) = default;

    void onResize();
    void setValue(float value);
    void update();
    void draw();
private:
    int width = 0;
    int height = 0;
    int x = 0;
    int y = 0;
    sf::RenderWindow &window;
    GraphicPlayer &player;
    sf::VertexArray buffer;
};

#endif
