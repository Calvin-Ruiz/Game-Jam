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

class CreeperWalk : public ThreadedModule {
public:
    CreeperWalk(std::vector<std::vector<room>> &rooms);
    virtual ~CreeperWalk();
    CreeperWalk(const CreeperWalk &cpy) = default;
    CreeperWalk &operator=(const CreeperWalk &src) = default;

    //! must be called while in pause
    void reset(int time, int x, int y);
    virtual void initialize() override;
    virtual void update() override;
    inline void creeperify(int x, int y);
private:
    int spawnTime;
    int spawnX, spawnY;
    std::vector<position> creepers;
    std::vector<position> newCreepers;
    std::vector<std::vector<room>> &rooms;
};

#endif /* CREEPERWALK_HPP_ */
