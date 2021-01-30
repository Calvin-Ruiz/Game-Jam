/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Door.hpp
*/

#ifndef DOOR_HPP_
#define DOOR_HPP_

#include "Item.hpp"

class Door : public Item {
public:
    Door(sf::RenderWindow &window, sf::Texture &texture, int health = 16);
    virtual ~Door();
    Door(const Door &cpy) = default;
    Door &operator=(const Door &src) = default;

    bool damage();
private:
    int maxHealth;
    int health;
};

#endif /* DOOR_HPP_ */
