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
class Item;
class DynamicItem;

class Core {
public:
    Core();
    virtual ~Core();
    Core(const Core &cpy) = delete;
    Core &operator=(const Core &src) = delete;

    void mainloop();
    void startMainloop(int refreshFrequency, ThreadedModule *module);
    void setPause(bool state) {isPaused = state;}
    //! Exposed for performance reasons, any use must match the following rules
        //! On display, if hasChanged is True, first set hasChanged to False, then read hasCreeper value
        //! On state change, first set hasCreeper to the new value, then set hasChanged to True
        //! To interact with an item, pick this item, check if it is a nullptr, then you can use it (else it could became a nullptr in between)
    std::vector<std::vector<room>> rooms;
    //! Only WindowManager is allowed to use draw and drawInInventory
    std::vector<std::shared_ptr<Item>> &getItemList() {return items;}
    void kill() {isAlive = false;}
    //! Convert position to screen coordinates
    void getCoordFromPos(int &x, int &y);
    void getCenteredCoordFromPos(int &x, int &y);
    void getPosFromCoords(int &x, int &y);
    void clampPos(int &x, int &y);
    int getSeed();
    std::shared_ptr<DynamicItem> getDynamicItem();
    static Core *core;
    bool isCompleted = false;
    //! For GlobalActivity
    std::vector<std::shared_ptr<DynamicItem>> &getDynamicItemList() {return animatedItems;}
    void setRoomSize(int offsetX, int offsetY, int width, int height) {x = offsetX; y = offsetY; roomWidth = width; roomHeight = height;}
    inline int getRoomWidth() {return roomWidth;}
    inline int getRoomHeight() {return roomHeight;}
    int initX, initY;
    bool paused() {return isPaused;}
private:
    bool isAlive = false;
    bool isPaused = false;
    static void threadLoop(bool *isAlive, bool *pIsPaused, int refreshFrequency, ThreadedModule *engine);
    std::vector<std::thread> threads;
    std::vector<ThreadedModule *> modules;
    std::vector<std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<DynamicItem>> animatedItems;
    int x, y, roomWidth, roomHeight;
    unsigned int dynamicItemIndex = 0;
};

#endif /* CORE_HPP_ */
