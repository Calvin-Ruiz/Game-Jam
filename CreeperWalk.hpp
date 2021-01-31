/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperWalk.hpp
*/

#ifndef CREEPERWALK_HPP_
#define CREEPERWALK_HPP_

#include "ThreadedModule.hpp"
#include "Room.hpp"
#include <vector>
#include <mutex>

class CreeperWalk : public ThreadedModule {
public:
    CreeperWalk(std::vector<std::vector<room>> &rooms);
    virtual ~CreeperWalk();
    CreeperWalk(const CreeperWalk &cpy) = default;
    CreeperWalk &operator=(const CreeperWalk &src) = default;

    virtual void update() override;
    void lock() {mtx.lock();}
    // The following functions must be called while locked :
    void reset(int time, int interval, int x, int y);
    inline void killCreeper(int x, int y);
    void unlock() {mtx.unlock();}
    static CreeperWalk *instance;
private:
    // return false if blocked
    inline bool creeperify(int x, int y);
    //! use in killCreeper
    inline void actualizeCreeper(int x, int y);
    int spawnTime;
    int spawnInterval;
    int spawnX, spawnY;
    std::vector<position> creepers;
    std::vector<position> newCreepers;
    std::vector<std::vector<room>> &rooms;
    std::mutex mtx;
};

inline void CreeperWalk::actualizeCreeper(int x, int y)
{
    room &target = rooms[x][y];

    if (target.hasCreeper) {
        if (!((target.left && !rooms[x - 1][y].hasCreeper) ||
            (target.right && !rooms[x + 1][y].hasCreeper) ||
            (target.top && !rooms[x][y - 1].hasCreeper) ||
            (target.bottom && !rooms[x][y + 1].hasCreeper)))
            creepers.push_back({x, y, &target});
    }
}

inline void CreeperWalk::killCreeper(int x, int y)
{
    room &target = rooms[x][y];

    if (target.hasCreeper) {
        if (target.left)
            actualizeCreeper(x - 1, y);
        if (target.right)
            actualizeCreeper(x + 1, y);
        if (target.top)
            actualizeCreeper(x, y - 1);
        if (target.bottom)
            actualizeCreeper(x, y + 1);
        target.hasCreeper = false;
        target.hasChanged = true;
    }
}

#endif /* CREEPERWALK_HPP_ */
