/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperDisplay.cpp
*/
#include "CreeperDisplay.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Room.hpp"
#include "Core.hpp"

CreeperDisplay *CreeperDisplay::instance = nullptr;

CreeperDisplay::CreeperDisplay(sf::RenderWindow &window, std::vector<std::vector<room>> &rooms) : window(window), rooms(rooms)
{
    bufferContent.resize(rooms.size());
    for (unsigned i = 0; i < rooms.size(); i++) {
        buffers.emplace_back(sf::PrimitiveType::Triangles, sf::VertexBuffer::Dynamic);
        bufferContent[i].resize(rooms[0].size() * 6, sf::Vertex(sf::Vector2f(0, 0), sf::Color::White));
        auto &bc = bufferContent[i];
        for (int j = 0; j < rooms[0].size() * 6; j += 6) {
            bc[j].texCoords.x = bc[j + 1].texCoords.x = bc[j + 3].texCoords.x = 0;
            bc[j].texCoords.y = bc[j + 2].texCoords.y = bc[j + 4].texCoords.y = 0;
            bc[j + 5].texCoords.x = bc[j + 2].texCoords.x = bc[j + 4].texCoords.x = 256;
            bc[j + 5].texCoords.y = bc[j + 1].texCoords.y = bc[j + 3].texCoords.y = 256;
        }
        buffers.back().create(bufferContent[i].size());
        buffers.back().update(bufferContent[i].data());
    }
    textures.resize(4);
    textures[0].loadFromFile("textures/amoeba0.png");
    textures[1].loadFromFile("textures/amoeba1.png");
    textures[2].loadFromFile("textures/amoeba2.png");
    textures[3].loadFromFile("textures/amoeba3.png");
    states.emplace_back(&textures[0]);
    states.emplace_back(&textures[1]);
    states.emplace_back(&textures[2]);
    states.emplace_back(&textures[3]);
    instance = this;
}

CreeperDisplay::~CreeperDisplay()
{}

void CreeperDisplay::update()
{
    for (int x = this->x; x < this->x + width; ++x) {
        auto &b = buffers[x];
        auto &bc = bufferContent[x];
        for (int y = this->y; y < this->y + height; ++y) {
            if (rooms[x][y].hasChanged) {
                if (rooms[x][y].hasCreeper) {
                    bc[y * 6].position.x = bc[y * 6 + 1].position.x = bc[y * 6 + 3].position.x = x * 256;
                    bc[y * 6].position.y = bc[y * 6 + 2].position.y = bc[y * 6 + 4].position.y = y * 256;
                    bc[y * 6 + 5].position.x = bc[y * 6 + 2].position.x = bc[y * 6 + 4].position.x = bc[y * 6].position.x + 256;
                    bc[y * 6 + 5].position.y = bc[y * 6 + 1].position.y = bc[y * 6 + 3].position.y = bc[y * 6].position.y + 256;
                } else {
                    bc[y * 6].position = bc[y * 6 + 1].position = bc[y * 6 + 2].position
                    = bc[y * 6 + 3].position = bc[y * 6 + 4].position = bc[y * 6 + 5].position
                    = sf::Vector2f(0, 0);
                }
                rooms[x][y].hasChanged = false;
                b.update(bc.data() + (y * 6), 6, y * 6);
            }
        }
    }
}

void CreeperDisplay::draw()
{
    update();
    for (int i = x; i < this->x + width; ++i) {
        window.draw(buffers[i], y * 6, height * 6, states[time / 5]);
    }
    if (++time >= 20) time = 0;
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
