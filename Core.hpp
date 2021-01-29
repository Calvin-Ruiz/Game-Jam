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
struct room;
class ThreadedModule;

class Core {
public:
    Core(int argc, char const *argv[]);
    virtual ~Core();
    Core(const Core &cpy) = delete;
    Core &operator=(const Core &src) = delete;

    void mainloop();
    void startMainloop(int refreshFrequency, ThreadedModule *module);
    void setPause(bool state) {isPaused = state;}
    //! Exposed for performance reasons, must match the following rules
        //! On display, if hasChanged is True, first set hasChanged to False, then read hasCreeper
        //! On state change, first set hasCreeper to the new value, then set hasChanged to True
        //! To interact with an item, pick this item, check if it is a nullptr, then you can use it (else it could became a nullptr in between)
    std::vector<std::vector<room>> rooms;
    //! Only WindowManager is allowed to use draw and drawInInventory
    std::vector<std::shared_ptr<Item>> &getItemList() {return items;}
private:
    bool isAlive = false;
    bool isPaused = false;
    static void threadLoop(bool *isAlive, bool *pIsPaused, int refreshFrequency, ThreadedModule *engine);
    std::vector<std::thread> threads;
    std::vector<ThreadedModule *> modules;
    std::vector<std::shared_ptr<Item>> items;
};

#endif /* CORE_HPP_ */
