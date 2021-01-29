/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** ThreadedModule.hpp
*/

#ifndef THREADEDMODULE_HPP_
#define THREADEDMODULE_HPP_

#include <iostream>
#include <string>
#include <memory>

class ThreadedModule {
public:
    ThreadedModule();
    virtual ~ThreadedModule();
    ThreadedModule(const ThreadedModule &cpy) = default;
    ThreadedModule &operator=(const ThreadedModule &src) = default;

    virtual void initalize() = 0;
    virtual void refresh() = 0;
private:
};

#endif /* THREADEDMODULE_HPP_ */
