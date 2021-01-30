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

    virtual void setPosition(int x, int y);
    virtual bool drop(int x, int y);
    virtual void draw();
    virtual void drawInInventory();
    //! take from the ground
    virtual bool take() {isOnLand = false; return true;}
    //! return true when this item must be removed of inventory
    virtual bool use(int x, int y);
protected:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    bool isOnLand = true;
};

#endif /* ITEM_HPP_ */
