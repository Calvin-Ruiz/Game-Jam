/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** Core.cpp
*/
#include "Core.hpp"
#include "ThreadedModule.hpp"
#include <SFML/System/Clock.hpp>
#include <chrono>
#include <string>
#include "graphicModule/CoreDraw.hpp"
#include "dataModule/Interface.hpp"
#include "ttyModule/CoreTTY.hpp"

Core::Core(int argc, char const *argv[])
{
    int width = 800;
    int height = 600;
    bool fullscreen = false;
    bool tty = false;
    int frequency = 5;
    std::string name = "MyGKrellm";

    argc--;
    argv++;
    while (argc-- > 0) {
        std::string arg = argv++[0];
        if (arg == "--fullscreen") {
            fullscreen = true;
        } else if (argc > 1 && arg == "--size") {
            width = std::stoi(argv++[0]);
            height = std::stoi(argv++[0]);
            argc -= 2;
        } else if (arg == "--tty") {
            tty = true;
        } else if (argc > 0 && arg == "--frequency") {
            frequency = std::stoi(argv++[0]);
            argc--;
        } else if (argc > 0 && arg == "--name") {
            name = argv++[0];
            argc--;
        }
    }
    startMainloop(frequency + 1, new Interface()); // Increase update frequency to ensure always display new content
    if (tty) {
        startMainloop(frequency, new CoreTTY());
    } else {
        startMainloop(frequency, new CoreDraw(fullscreen, name, width, height));
    }
}

Core::~Core()
{
    isAlive = false;
    for (auto &th : threads) {
        th.join();
    }
}

void Core::mainloop()
{
    std::string command = "\0";

    bool aliveProcess = false;
    int timeout = 600; // 30 seconds
    while (!aliveProcess && timeout--) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        aliveProcess = true;
        for (auto &engine : engines) {
            aliveProcess &= engine->isReady();
        }
    }
    if (timeout == 600) {
        std::cerr << "Timeout : Modules has taken too many time to start.\n";
        return;
    }
    bool isAlive = true;
    while (isAlive && aliveProcess) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        for (auto &engine : engines) {
            aliveProcess &= engine->isReady();
        }
    }
}

void Core::startMainloop(int refreshFrequency, IEngine *engine)
{
    engines.push_back(engine);
    threads.emplace_back(threadLoop, &isAlive, &isPaused, refreshFrequency, std::move(engine));
}

void Core::threadLoop(bool *pIsAlive, bool *pIsPaused, int refreshFrequency, ThreadedModule *engine)
{
    bool &isAlive = *pIsAlive;
    bool &isPaused = *pIsAlive;
    refreshFrequency = 1000000/refreshFrequency;
    engine->init();

    sf::Clock clock;
    long next = clock.getElapsedTime().asMicroseconds();
    while (isAlive) {
        next += refreshFrequency;
        if (isPaused)
            engine->onPause()
        engine->refresh();
        long actual = clock.getElapsedTime().asMicroseconds();
        if (actual < next)
            std::this_thread::sleep_for(std::chrono::microseconds(next - actual));
    }
    delete engine;
}
