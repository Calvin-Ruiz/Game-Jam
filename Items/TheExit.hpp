/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** TheExit.hpp
*/

#ifndef THEEXIT_HPP_
#define THEEXIT_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "Item.hpp"

class TheExit : public Item {
public:
    TheExit(sf::RenderWindow &window, sf::Texture &texture);
    virtual ~TheExit();
    TheExit(const TheExit &cpy) = default;
    TheExit &operator=(const TheExit &src) = default;

    virtual bool take() override;
private:
};

#endif /* THEEXIT_HPP_ */
