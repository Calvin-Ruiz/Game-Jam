/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** Core.cpp
*/
#include "Core.hpp"
#include "ThreadedModule.hpp"
#include "Room.hpp"
#include "Item.hpp"
#include <SFML/System/Clock.hpp>
#include <chrono>
#include <string>

Core *Core::core = nullptr;

Core::Core()
{
    core = this;
}

Core::~Core()
{
    isAlive = false;
    for (auto &th : threads) {
        th.join();
    }
}

void Core::getCoordFromPos(int &_x, int &_y)
{
    _x = x + roomWidth * _x;
    _y = y + roomHeight * _y;
}

void Core::clampPos(int &_x, int &_y)
{
    if (_x >= (int) rooms.size()) _x = rooms.size() - 1;
    if (_y >= (int) rooms[0].size()) _y = rooms[0].size() - 1;
    if (_x < 0) _x = 0;
    if (_y < 0) _y = 0;
}

void Core::getPosFromCoords(int &_x, int &_y)
{
    _x = (_x - x) / roomWidth;
    _y = (_y - y) / roomHeight;
    clampPos(_x, _y);
}

void Core::mainloop()
{
    std::string command = "\0";

    bool aliveProcess = false;
    int timeout = 600; // 30 seconds
    while (!aliveProcess && timeout--) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        aliveProcess = true;
        for (auto &module : modules) {
            aliveProcess &= module->isReady();
        }
    }
    if (timeout == -1) {
        isPaused = true;
        std::cerr << "Timeout : Modules has taken too many time to start.\n";
        return;
    }
    isAlive = true;
    while (isAlive && aliveProcess) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (auto &module : modules) {
            aliveProcess &= module->isReady();
        }
    }
}

void Core::startMainloop(int refreshFrequency, ThreadedModule *module)
{
    modules.push_back(module);
    threads.emplace_back(threadLoop, &isAlive, &isPaused, refreshFrequency, std::move(module));
}

void Core::threadLoop(bool *pIsAlive, bool *pIsPaused, int refreshFrequency, ThreadedModule *module)
{
    bool &isAlive = *pIsAlive;
    bool &isPaused = *pIsPaused;
    refreshFrequency = 1000000/refreshFrequency;
    module->initialize();

    // Wait other threads
    while (!isAlive && !isPaused) // isPaused is set to true in case of timeout
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 100 check per second
    sf::Clock clock;
    long next = clock.getElapsedTime().asMicroseconds();
    while (isAlive) {
        next += refreshFrequency;
        if (!isPaused)
            module->update();
        module->refresh();
        if (isPaused)
            module->onPause();
        long actual = clock.getElapsedTime().asMicroseconds();
        if (actual < next)
            std::this_thread::sleep_for(std::chrono::microseconds(next - actual));
    }
    delete module;
}

std::shared_ptr<DynamicItem> Core::getDynamicItem()
{
    if (dynamicItemIndex == animatedItems.size())
        dynamicItemIndex = 0;
    return (animatedItems[dynamicItemIndex++]);
}
