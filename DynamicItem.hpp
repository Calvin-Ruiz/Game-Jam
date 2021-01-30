/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** DynamicItem.hpp
*/

#ifndef DYNAMICITEM_HPP_
#define DYNAMICITEM_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "Item.hpp"
class room;

class DynamicItem : public Item {
public:
    enum actionType {
        BULLET,
        ROCKET
    };
    enum orientation {
        NONE,
        LEFT,
        RIGHT,
        TOP,
        BOTTOM
    };
    DynamicItem(sf::RenderWindow &window, sf::Texture &texture);
    virtual ~DynamicItem();
    DynamicItem(const DynamicItem &cpy) = default;
    DynamicItem &operator=(const DynamicItem &src) = default;

    void redefine(sf::Texture &texture, int x, int y, float vel_x, float vel_y, enum actionType action);
    virtual void update();
protected:
    void reaction(int x, int y, orientation dir);
    void explode(int x, int y, int radius);
    enum actionType action;
    int x, y;
    float vel_x, vel_y;
};

#endif /* DYNAMICITEM_HPP_ */
