/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperWalk.cpp
*/
#include "CreeperWalk.hpp"
#include "Door.hpp"
#include <thread>

CreeperWalk *CreeperWalk::instance = nullptr;

CreeperWalk::CreeperWalk(std::vector<std::vector<room>> &rooms) : rooms(rooms)
{
    instance = this;
}

CreeperWalk::~CreeperWalk()
{}

void CreeperWalk::reset(int time, int interval, int x, int y)
{
    creepers.clear();
    spawnTime = time;
    spawnInterval = interval;
    spawnX = x;
    spawnY = y;
}

inline bool CreeperWalk::creeperify(int x, int y)
{
    room &target = rooms[x][y];

    if (!target.hasCreeper) {
        if (target.isBlocking) {
            Door *tmp = dynamic_cast<Door *>(target.item);
            if (tmp) {
                if (tmp->damage())
                    // The door is broken !
                    target.item = nullptr;
                else // The door resist
                    return false;
            }
        }
        target.hasCreeper = true;
        target.hasChanged = true;
        newCreepers.push_back({x, y, &target});
    }
    return true;
}

void CreeperWalk::update()
{
    if (spawnTime) {
        spawnTime--;
        return;
    }
    mtx.lock();
    newCreepers.clear();
    creeperify(spawnX, spawnY);
    for (position &value : creepers) {
        if (!value.target->hasCreeper)
            continue;
        bool unblocked = true;
        if (value.target->left)
            unblocked &= creeperify(value.x - 1, value.y);
        if (value.target->right)
            unblocked &= creeperify(value.x + 1, value.y);
        if (value.target->top)
            unblocked &= creeperify(value.x, value.y - 1);
        if (value.target->bottom)
            unblocked &= creeperify(value.x, value.y + 1);
        if (!unblocked)
            newCreepers.push_back(value);
    }
    creepers.swap(newCreepers);
    spawnTime = spawnInterval;
    mtx.unlock();
}
