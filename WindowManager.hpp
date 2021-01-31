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
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexBuffer.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Window/Event.hpp>
#include "WallDisplay.hpp"

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
    std::unique_ptr<WallDisplay> disp;
    sf::Texture *ground;
    sf::VertexBuffer buffer;
    std::unique_ptr<sf::RenderStates> gstate;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
};

#endif /* WINDOW_MANAGER_HPP_ */
