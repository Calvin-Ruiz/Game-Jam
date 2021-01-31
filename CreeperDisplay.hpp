/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperDisplay.hpp
*/

#ifndef CREEPERDISPLAY_HPP_
#define CREEPERDISPLAY_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics/VertexBuffer.hpp>
#include "ThreadedModule.hpp"
#include <SFML/Graphics/Texture.hpp>
class room;

namespace sf {
    class RenderWindow;
    class RenderStates;
}

class CreeperDisplay : public ThreadedModule {
public:
    CreeperDisplay(sf::RenderWindow &window, std::vector<std::vector<room>> &rooms);
    virtual ~CreeperDisplay();
    CreeperDisplay(const CreeperDisplay &cpy) = default;
    CreeperDisplay &operator=(const CreeperDisplay &src) = default;

    void setDimension(int height, int width);
    void setOrigin(int x, int y);
    // Better if called in a dedicated thread
    virtual void update() override;
    void draw();
    static CreeperDisplay *instance;
private:
    sf::RenderWindow &window;
    std::vector<sf::Texture> textures;
    std::vector<sf::RenderStates> states;
    std::vector<std::vector<room>> &rooms;
    std::vector<sf::VertexBuffer> buffers;
    std::vector<std::vector<sf::Vertex>> bufferContent;
    bool needRedefine = false;
    int x = 0;
    int y = 0;
    int height = 0;
    int width = 0;
    int time = 0;
};

#endif /* CREEPERDISPLAY_HPP_ */
