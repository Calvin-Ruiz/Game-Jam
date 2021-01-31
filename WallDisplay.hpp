/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WallDisplay.hpp
*/

#ifndef WALLDISPLAY_HPP_
#define WALLDISPLAY_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/VertexBuffer.hpp>
class room;

class WallDisplay {
public:
    WallDisplay(sf::RenderWindow &window, std::vector<std::vector<room>> &rooms);
    virtual ~WallDisplay();
    WallDisplay(const WallDisplay &cpy) = default;
    WallDisplay &operator=(const WallDisplay &src) = default;

    void setDimension(int height, int width);
    void setOrigin(int x, int y);
    void draw();
private:
    sf::RenderWindow &window;
    std::vector<std::vector<room>> &rooms;
    std::vector<sf::VertexBuffer> buffers;
    std::vector<std::vector<sf::Vertex>> bufferContent;
    sf::Texture tex;
    sf::RenderStates state;
    int x = 0;
    int y = 0;
    int height = 0;
    int width = 0;
};

#endif /* WALLDISPLAY_HPP_ */
