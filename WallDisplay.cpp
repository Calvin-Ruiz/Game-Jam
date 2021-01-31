/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WallDisplay.cpp
*/
#include "WallDisplay.hpp"
#include "Room.hpp"

WallDisplay::WallDisplay(sf::RenderWindow &window, std::vector<std::vector<room>> &rooms) : window(window), rooms(rooms)
{
    bufferContent.resize(rooms.size());
    for (unsigned i = 0; i < rooms.size(); i++) {
        buffers.emplace_back(sf::PrimitiveType::Triangles, sf::VertexBuffer::Static);
        bufferContent[i].resize(rooms[0].size() * 6, sf::Vertex(sf::Vector2f(0, 0)));
        auto &bc = bufferContent[i];
        for (int j = 0; j < rooms[0].size(); ++j) {
            auto &r = rooms[i][j];
            const int j6 = j * 6;
            bc[j6].texCoords.x = bc[j6 + 1].texCoords.x = bc[j6 + 3].texCoords.x = 0.25 * !r.left + 0.5 * !r.right;
            bc[j6].texCoords.y = bc[j6 + 2].texCoords.y = bc[j6 + 4].texCoords.y = 0.25 * !r.top + 0.5 * !r.bottom;
            bc[j6 + 5].texCoords.x = bc[j6 + 2].texCoords.x = bc[j6 + 4].texCoords.x = 0.25 + bc[j6].texCoords.x;
            bc[j6 + 5].texCoords.y = bc[j6 + 1].texCoords.y = bc[j6 + 3].texCoords.y = 0.25 + bc[j6].texCoords.y;
        }
        buffers.back().create(bufferContent.size() * 6);
        buffers.back().update(bufferContent[i].data());
    }
}

WallDisplay::~WallDisplay()
{}

void WallDisplay::draw()
{
    for (int x = this->x; x < width; ++x) {
        auto &b = buffers[x];
        auto &bc = bufferContent[x];
        for (int y = this->y; y < height; ++y) {
            if (rooms[x][y].hasWallChanged) {
                bc[y * 6].texCoords.x = bc[y * 6 + 1].texCoords.x = bc[y * 6 + 3].texCoords.x = 0.25 * !rooms[x][y].left + 0.5 * !rooms[x][y].right;
                bc[y * 6].texCoords.y = bc[y * 6 + 2].texCoords.y = bc[y * 6 + 4].texCoords.y = 0.25 * !rooms[x][y].top + 0.5 * !rooms[x][y].bottom;
                bc[y * 6 + 5].texCoords.x = bc[y * 6 + 2].texCoords.x = bc[y * 6 + 4].texCoords.x = 0.25 + bc[y * 6].texCoords.x;
                bc[y * 6 + 5].texCoords.y = bc[y * 6 + 1].texCoords.y = bc[y * 6 + 3].texCoords.y = 0.25 + bc[y * 6].texCoords.y;
                rooms[x][y].hasWallChanged = false;
                b.update(bc.data() + y * 6, y, 6);
            }
        }
    }
    for (int i = x; i < width; ++i) {
        window.draw(buffers[x], y * 6, height * 6);
    }
}

void WallDisplay::setDimension(int _height, int _width)
{
    height = _height;
    width = _width;
}

void WallDisplay::setOrigin(int _x, int _y)
{
    x = _x;
    y = _y;
}
