/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperDisplay.cpp
*/
#include "CreeperDisplay.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include "Room.hpp"

CreeperDisplay::CreeperDisplay(sf::RenderWindow &window, std::vector<std::vector<room>> &rooms) : window(window), rooms(rooms)
{
    bufferContent.resize(rooms.size());
    for (unsigned i = 0; i < rooms.size(); i++) {
        buffers.emplace_back(sf::PrimitiveType::Triangles, sf::VertexBuffer::Dynamic);
        bufferContent[i].resize(rooms[0].size() * 6, sf::Vertex(sf::Vector2f(0, 0), sf::Color(96, 0, 255, 63)));
        buffers.back().create(bufferContent.size() * 6);
        buffers.back().update(bufferContent[i].data());
    }
}

CreeperDisplay::~CreeperDisplay()
{}

void CreeperDisplay::preDraw()
{
    for (int x = this->x; x < width; ++x) {
        auto &b = buffers[x];
        auto &bc = bufferContent[x];
        for (int y = this->y; y < height; ++y) {
            if (rooms[x][y].hasChanged) {
                if (rooms[x][y].hasCreeper) {
                    bc[y * 6].position.x = bc[y * 6 + 1].position.x = bc[y * 6 + 3].position.x;
                    bc[y * 6].position.y = bc[y * 6 + 2].position.y = bc[y * 6 + 4].position.y;
                    bc[y * 6 + 5].position.x = bc[y * 6 + 2].position.x = bc[y * 6 + 4].position.x;
                    bc[y * 6 + 5].position.y = bc[y * 6 + 1].position.y = bc[y * 6 + 3].position.y;
                } else {
                    bc[y * 6] = bc[y * 6 + 1] = bc[y * 6 + 2]
                    = bc[y * 6 + 3] = bc[y * 6 + 4] = bc[y * 6 + 5]
                    = sf::Vertex(sf::Vector2f(0, 0), sf::Color(96, 0, 255, 63));
                }
                rooms[x][y].hasChanged = false;
                b.update(bc.data() + y * 6, y, 6);
            }
        }
    }
}

void CreeperDisplay::draw()
{
    for (int i = x; i < width; ++i) {
        window.draw(buffers[x], y * 6, height * 6);
    }
}

void CreeperDisplay::setDimension(int _height, int _width)
{
    height = _height;
    width = _width;
}

void CreeperDisplay::setOrigin(int _x, int _y)
{
    x = _x;
    y = _y;
}