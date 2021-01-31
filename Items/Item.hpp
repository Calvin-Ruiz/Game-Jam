/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Item.hpp
*/

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics/VertexArray.hpp"

namespace sf {
    class RenderWindow;
    class Texture;
};

class Item {
public:
    Item(sf::RenderWindow &window, sf::Texture &texture, int phaseCount = 4, int fullTime = 60);
    virtual ~Item();
    Item(const Item &cpy) = delete;
    Item &operator=(const Item &src) = delete;

    virtual void setPosition(int x, int y);
    virtual bool drop(int x, int y);
    virtual void draw();
    virtual void drawInInventory();
    //! take from the ground
    virtual bool take(int idx);
    //! return true when this item must be removed of inventory
    virtual bool use(int x, int y);
protected:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::IntRect rect;
    bool isOnLand = false;
    //! attached value in percent
    float value = 0;
private:
    sf::VertexArray buffer;
    float lastValue = 0;
    int time = 0;
    int fullTime;
    int phaseCount;
};

#endif /* ITEM_HPP_ */
