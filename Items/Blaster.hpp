/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Blaster.hpp
*/

#ifndef BLASTER_HPP_
#define BLASTER_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "Item.hpp"
#include "DynamicItem.hpp"

class Blaster : public Item {
public:
    Blaster(sf::RenderWindow &window, sf::Texture &texture, sf::Texture &bulletTexture, float speed, int ammos, enum DynamicItem::actionType action);
    virtual ~Blaster();
    Blaster(const Blaster &cpy) = default;
    Blaster &operator=(const Blaster &src) = default;

    virtual bool use(int x, int y) override;
private:
    sf::Texture &bulletTexture;
    float speed;
    int maxAmmos;
    int ammos;
    enum DynamicItem::actionType action;
};

#endif /* BLASTER_HPP_ */
