/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Room.hpp
*/

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <memory>
class Item;

struct room {
    bool hasCreeper;
    bool hasChanged;
    bool isBlocking; // Is it blocking for creeper
    bool left;
    bool right;
    bool top;
    bool bottom;
    Item *item;
};

struct position {
    int x;
    int y;
    room *target;
};

#endif /* ROOM_HPP_ */
