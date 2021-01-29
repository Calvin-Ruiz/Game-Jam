/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.hpp
*/

#ifndef WINDOW_MANAGER_HPP_
#define WINDOW_MANAGER_HPP_

#include "ThreadedModule.hpp"

class WindowManager : public ThreadedModule {
public:
    WindowManager();
    virtual ~WindowManager();
    WindowManager(const WindowManager &cpy) = default;
    WindowManager &operator=(const WindowManager &src) = default;

    virtual void initalize() override;
    virtual void refresh() override;
private:
};

#endif /* WINDOW_MANAGER_HPP_ */
