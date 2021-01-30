/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.hpp
*/

#ifndef WINDOW_MANAGER_HPP_
#define WINDOW_MANAGER_HPP_

#include "ThreadedModule.hpp"
#include "Player.hpp"
#include "GraphicPlayer.hpp"
#include <SFML/Graphics.hpp>

class WindowManager : public ThreadedModule {
public:
    WindowManager(sf::RenderWindow &window);
    virtual ~WindowManager();
    WindowManager(const WindowManager &cpy) = default;
    WindowManager &operator=(const WindowManager &src) = default;

    //! For heavy initializations
    void initialize() override;
    //! Draw game
    virtual void refresh() override;
    //! Manage game events
    virtual void update() override;
    //! Manage pause menu
    void onPause() override;

private:
    sf::RenderWindow &window;
    sf::Texture menuButtonResumeT;
    sf::Sprite menuButtonResumeS;
    sf::Texture menuButtonRetryT;
    sf::Sprite menuButtonRetryS;
    sf::Texture menuButtonLeaveT;
    sf::Sprite menuButtonLeaveS;
    sf::RectangleShape rectangle;
    Player *player;
};

#endif /* WINDOW_MANAGER_HPP_ */
