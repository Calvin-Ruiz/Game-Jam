/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <array>
#include "GraphicPlayer.hpp"
class room;
class Item;

class Player {
public:
    Player(GraphicPlayer *gPlayer);
    virtual ~Player();
    Player(const Player &cpy) = delete;
    Player &operator=(const Player &src) = delete;

    GraphicPlayer &get() {return *gPlayer;}
    void setPosition(int x, int y);
    void useItem(int idx);
    // Damage player if walking on creeper, return true if alive, false is dead
    bool update();
    // movements
    void left();
    void right();
    void top();
    void bottom();
    GraphicPlayer::orientation getOrientation() {return dir;}
    static Player *instance;
private:
    GraphicPlayer::orientation dir = GraphicPlayer::TOP;
    room *pos = nullptr;
    std::unique_ptr<GraphicPlayer> gPlayer;
    std::array<Item *, 10> inventory;
    int x, y, health;
};

#endif /* PLAYER_HPP_ */
