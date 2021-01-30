/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** ItemMgr.hpp
*/

#ifndef ITEMMGR_HPP_
#define ITEMMGR_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
class Item;

namespace sf {
    class RenderWindow;
};

class ItemMgr {
public:
    enum itemType {
        BLASTER = 0,
        BAZOOKA = 1,
        DOOR = 2,
        KEY = 3,
        MEDIKIT = 4,
        BULLET = 5,
        ROCKET = 6
    };
    ItemMgr(sf::RenderWindow &window);
    virtual ~ItemMgr();
    ItemMgr(const ItemMgr &cpy) = default;
    ItemMgr &operator=(const ItemMgr &src) = default;

    // frequency must be in percent (0.f to 100.f). Set to -1.f for unique.
    bool setItemData(enum itemType itype, const std::string &filename, float frequency = 0, float value = 0);
    void setLoot();
    Item *create(enum itemType);
private:
    struct imgData {
        sf::Texture tex;
        float frequency;
        // ammo for Blaster or bazooka, health for Door, speed for DynamicItem
        float value;
    };
    sf::RenderWindow &window;
    std::array<imgData, 7> itemData;
    std::vector<enum itemType> freq;
};

#endif /* ITEMMGR_HPP_ */
