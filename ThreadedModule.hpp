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

    //! For heavy initializations
    virtual void initialize() {ready = true;}
    //! Called after update and before onPause
    virtual void refresh() {}
    //! Only called while not paused
    virtual void update() = 0;
    //! Only called while paused
    virtual void onPause() {}
    //! Tell if initialization has completed
    virtual bool isReady() {return ready;}
protected:
    //! Set to true once initialization complete
    //! Set this to false once initialized to close the program
    bool ready = false;
};

#endif /* THREADEDMODULE_HPP_ */
