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

namespace sf {
    class RenderWindow;
    class Texture;
};

class Item {
public:
    Item(sf::RenderWindow &window, sf::Texture &texture);
    virtual ~Item();
    Item(const Item &cpy) = default;
    Item &operator=(const Item &src) = default;

    virtual void draw() = 0;
    virtual void drawInInventory(int index) = 0;
private:
    sf::RenderWindow &window;
};

#endif /* ITEM_HPP_ */
