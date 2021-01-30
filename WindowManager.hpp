/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.hpp
*/

#ifndef WINDOW_MANAGER_HPP_
#define WINDOW_MANAGER_HPP_

#include "ThreadedModule.hpp"
#include <SFML/Graphics.hpp>

class WindowManager : public ThreadedModule {
public:
    WindowManager(sf::RenderWindow &window);
    virtual ~WindowManager();
    WindowManager(const WindowManager &cpy) = default;
    WindowManager &operator=(const WindowManager &src) = default;

    //! For heavy initializations
    virtual void initialize() override;
    //! Draw game
    virtual void refresh() override;
    //! Manage game events
    virtual void update() override;
    //! Manage pause menu
    virtual void onPause() override;
private:
    sf::RenderWindow &window;
    sf::Texture menuStartBackgroundT;
    sf::Sprite menuStartBackgroundS;
    sf::Texture menuButtonPlayT;
    sf::Sprite menuButtonPlayS;
    sf::Texture menuButtonExitT;
    sf::Sprite menuButtonExitS;
};

#endif /* WINDOW_MANAGER_HPP_ */
