/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GlobalActivity.hpp
*/

#ifndef GLOBALACTIVITY_HPP_
#define GLOBALACTIVITY_HPP_

#include "ThreadedModule.hpp"

// Manage everything else than creeper, player and events
class GlobalActivity : public ThreadedModule {
public:
    GlobalActivity();
    virtual ~GlobalActivity();
    GlobalActivity(const GlobalActivity &cpy) = default;
    GlobalActivity &operator=(const GlobalActivity &src) = default;
private:
    virtual void update() override;
};

#endif /* GLOBALACTIVITY_HPP_ */
