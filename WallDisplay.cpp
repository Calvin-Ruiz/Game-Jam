/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WallDisplay.cpp
*/
#include "WallDisplay.hpp"
#include "Room.hpp"

WallDisplay::WallDisplay(sf::RenderWindow &window, std::vector<std::vector<room>> &rooms) : window(window), rooms(rooms), state(&tex)
{
    bufferContent.resize(rooms.size());
    for (unsigned i = 0; i < rooms.size(); i++) {
        buffers.emplace_back(sf::PrimitiveType::Triangles, sf::VertexBuffer::Static);
        bufferContent[i].resize(rooms[0].size() * 6, sf::Vertex(sf::Vector2f(0, 0)));
        auto &bc = bufferContent[i];
        for (int j = 0; j < rooms[0].size(); ++j) {
            auto &r = rooms[i][j];
            const int j6 = j * 6;
            //std::cout << r.top << r.right << r.bottom << r.left << std::endl;
            bc[j6].position.x = bc[j6 + 1].position.x = bc[j6 + 3].position.x = 256 * i;
            bc[j6].position.y = bc[j6 + 2].position.y = bc[j6 + 4].position.y = 256 * j;
            bc[j6 + 5].position.x = bc[j6 + 2].position.x = bc[j6 + 4].position.x = 256 + bc[j6].position.x;
            bc[j6 + 5].position.y = bc[j6 + 1].position.y = bc[j6 + 3].position.y = 256 + bc[j6].position.y;
            bc[j6].texCoords.x = bc[j6 + 1].texCoords.x = bc[j6 + 3].texCoords.x = 256 * !r.left + 512 * !r.right;
            bc[j6].texCoords.y = bc[j6 + 2].texCoords.y = bc[j6 + 4].texCoords.y = 256 * !r.top + 512 * !r.bottom;
            bc[j6 + 5].texCoords.x = bc[j6 + 2].texCoords.x = bc[j6 + 4].texCoords.x = 256 + bc[j6].texCoords.x;
            bc[j6 + 5].texCoords.y = bc[j6 + 1].texCoords.y = bc[j6 + 3].texCoords.y = 256 + bc[j6].texCoords.y;
        }
        buffers.back().create(bufferContent[i].size());
        buffers.back().update(bufferContent[i].data());
    }
    tex.loadFromFile("textures/wall.png");
}

WallDisplay::~WallDisplay()
{}

void WallDisplay::draw()
{
    for (int x = this->x; x < this->x + width; ++x) {
        auto &b = buffers[x];
        auto &bc = bufferContent[x];
        for (int y = this->y; y < this->y + height; ++y) {
            if (rooms[x][y].hasWallChanged) {
                bc[y * 6].texCoords.x = bc[y * 6 + 1].texCoords.x = bc[y * 6 + 3].texCoords.x = 256 * !rooms[x][y].left + 512 * !rooms[x][y].right;
                bc[y * 6].texCoords.y = bc[y * 6 + 2].texCoords.y = bc[y * 6 + 4].texCoords.y = 256 * !rooms[x][y].top + 512 * !rooms[x][y].bottom;
                bc[y * 6 + 5].texCoords.x = bc[y * 6 + 2].texCoords.x = bc[y * 6 + 4].texCoords.x = 256 + bc[y * 6].texCoords.x;
                bc[y * 6 + 5].texCoords.y = bc[y * 6 + 1].texCoords.y = bc[y * 6 + 3].texCoords.y = 256 + bc[y * 6].texCoords.y;
                rooms[x][y].hasWallChanged = false;
                b.update(bc.data() + y * 6, 6, y * 6);
            }
        }
    }
    for (int i = x; i < this->x + width; ++i) {
        window.draw(buffers[i], y * 6, height * 6, state);
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
