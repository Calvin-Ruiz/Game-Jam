/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GraphicPlayer.hpp
*/

#ifndef GRAPHICPLAYER_HPP_
#define GRAPHICPLAYER_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class GraphicPlayer {
public:
    enum orientation {
        LEFT,
        RIGHT,
        TOP,
        BOTTOM
    };
    GraphicPlayer(sf::RenderWindow &window);
    virtual ~GraphicPlayer();
    GraphicPlayer(const GraphicPlayer &cpy) = delete;
    GraphicPlayer &operator=(const GraphicPlayer &src) = delete;

    // call on each tick
    void update();

    void render(); // Temporary

    // define or redefine position
    void setPosition(int x, int y);
    // return coordinates
    void getCoords(int &x, int &y) {
        x = rx;
        y = ry;
    }

    // inform left movement
    void left();
    // inform right movement
    void right();
    // inform top movement
    void top();
    // inform bottom movement
    void bottom();
    // (from 0 to 1, 1 is 100% and 0 is 0%)
    void setHealth(float value);
    // set orientation
    void setDirection(orientation dir);
private:
    float speed; // deplacement distance on each tick
    int x; // case x
    int y; // case y
    int rx;
    int ry;
    float animate_x; // animation x, 0 = start, abs(1) = end
    float animate_y; // animation y, 0 = start, abs(1) = end
    const int fullTime = 10;
    const int phaseCount = 5;
    int time = 0;
    bool moving = false;
    float health;
    orientation dir;
    sf::RenderWindow &window;
    sf::IntRect rect;
    sf::Texture tex;
    sf::Sprite sprite;
};

#endif /* GRAPHICPLAYER_HPP_ */
