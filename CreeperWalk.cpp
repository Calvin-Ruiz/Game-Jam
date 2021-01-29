/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperWalk.cpp
*/
#include "CreeperWalk.hpp"

CreeperWalk::CreeperWalk(std::vector<std::vector<room>> &rooms) : rooms(rooms)
{}

CreeperWalk::~CreeperWalk()
{}

void CreeperWalk::reset(int time, int x, int y)
{
    creepers.clear();
    spawnTime = time;
    spawnX = x;
    spawnY = y;
}

inline void CreeperWalk::creeperify(int x, int y)
{
    room &target = rooms[x][y];

    if (!target.hasCreeper) {
        target.hasCreeper = true;
        target.hasChanged = true;
        newCreepers.push_back({x, y, &target});
    }
}

void CreeperWalk::update()
{
    if (spawnTime) {
        spawnTime--;
        return;
    }
    newCreepers.clear();
    creeperify(spawnX, spawnY);
    for (position &value : creepers) {
        if (value.target->left)
            creeperify(value.x - 1, value.y);
        if (value.target->right)
            creeperify(value.x + 1, value.y);
        if (value.target->top)
            creeperify(value.x, value.y - 1);
        if (value.target->bottom)
            creeperify(value.x, value.y + 1);
    }
    creepers.swap(newCreepers);
}
