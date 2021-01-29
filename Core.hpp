/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** Core.hpp
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <thread>
class ThreadedModule;

class Core {
public:
    Core(int argc, char const *argv[]);
    virtual ~Core();
    Core(const Core &cpy) = delete;
    Core &operator=(const Core &src) = delete;

    void mainloop();
    void startMainloop(int refreshFrequency, ThreadedModule *module);
    void kill() {isAlive = false;}
    void setPause(bool state) {isPaused = state;}
private:
    bool isAlive = true;
    bool isPaused = true;
    static void threadLoop(bool *isAlive, bool *pIsPaused, int refreshFrequency, IEngine *engine);
    std::vector<std::thread> threads;
    std::vector<ThreadedModule *> modules;
};

#endif /* CORE_HPP_ */
