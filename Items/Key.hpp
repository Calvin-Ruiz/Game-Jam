/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Key.hpp
*/

#ifndef KEY_HPP_
#define KEY_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "Item.hpp"

class Key : public Item {
public:
    Key(sf::RenderWindow &window, sf::Texture &texture);
    virtual ~Key();
    Key(const Key &cpy) = default;
    Key &operator=(const Key &src) = default;

    virtual bool use(int x, int y) override;
private:
};

#endif /* KEY_HPP_ */
