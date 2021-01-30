/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** MediKit.hpp
*/

#ifndef MEDIKIT_HPP_
#define MEDIKIT_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "Item.hpp"

class MediKit : public Item {
public:
    MediKit(sf::RenderWindow &window, sf::Texture &texture);
    virtual ~MediKit();
    MediKit(const MediKit &cpy) = default;
    MediKit &operator=(const MediKit &src) = default;

    virtual bool use(int x, int y) override;
private:
};

#endif /* MEDIKIT_HPP_ */
