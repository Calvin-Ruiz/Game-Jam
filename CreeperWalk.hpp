/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** CreeperWalk.hpp
*/

#ifndef CREEPERWALK_HPP_
#define CREEPERWALK_HPP_

#include "ThreadedModule.hpp"

class CreeperWalk : public ThreadedModule {
public:
    CreeperWalk();
    virtual ~CreeperWalk();
    CreeperWalk(const CreeperWalk &cpy) = default;
    CreeperWalk &operator=(const CreeperWalk &src) = default;

    virtual void initalize() override;
    virtual void update() override;
private:
};

#endif /* CREEPERWALK_HPP_ */
