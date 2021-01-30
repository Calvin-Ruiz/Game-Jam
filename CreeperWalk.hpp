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
    // return false if blocked
    inline bool creeperify(int x, int y);
    void lock() {mtx.lock();}
    // The following functions must be called while locked :
    void reset(int time, int interval, int x, int y);
    inline void killCreeper(int x, int y);
    void unlock() {mtx.unlock();}
private:
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

#endif /* CREEPERWALK_HPP_ */
