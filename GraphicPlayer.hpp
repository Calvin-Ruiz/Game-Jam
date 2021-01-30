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

class GraphicPlayer {
public:
    enum orientation {
        LEFT,
        RIGHT,
        TOP,
        BOTTOM
    };
    GraphicPlayer();
    virtual ~GraphicPlayer();
    GraphicPlayer(const GraphicPlayer &cpy) = delete;
    GraphicPlayer &operator=(const GraphicPlayer &src) = delete;

    // define or redefine position
    void setPosition(int x, int y);
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
    int speed;
    int x;
    int y;
    float health;
    orientation dir;
};

#endif /* GRAPHICPLAYER_HPP_ */
