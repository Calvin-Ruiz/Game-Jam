/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Room.hpp
*/

#ifndef ROOM_HPP_
#define ROOM_HPP_

struct room {
    bool hasCreeper;
    bool hasChanged;
    bool left;
    bool right;
    bool top;
    bool bottom;
    Item *item;
};

#endif /* ROOM_HPP_ */
