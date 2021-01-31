/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Room.hpp
*/

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <random>
#include <memory>

class Item;

enum Exit {
    NONE,
    EXIT,
    ENTER,
};

struct room
{
    bool hasCreeper;
    bool hasChanged;
    bool hasWallChanged = false;
    bool isBlocking; // Is it blocking for creeper
    bool left = false;
    bool right = false;
    bool top = false;
    bool bottom = false;

    bool visited = false; // Only for generation
    Exit exit = NONE;
    Item *item;
};

struct position
{
    int x;
    int y;
    room *target;
};

class RandomDevice
{
private:
    std::default_random_engine engine;

public:
    RandomDevice(unsigned long n) { engine.seed(n); }
    int randInt(int min, int max)
    {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(engine);
    }
};

#endif /* ROOM_HPP_ */

void createLaby(int seed, int width, int height, std::vector<std::vector<room>> &rooms, std::vector<std::shared_ptr<Item>> &items);
