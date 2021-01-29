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

    //! For heavy initializations
    virtual void initalize() override;
    //! Draw game
    virtual void refresh() override;
    //! Manage game events
    virtual void update() override;
    //! Manage pause menu
    virtual void onPause() override;
private:
};

#endif /* WINDOW_MANAGER_HPP_ */
