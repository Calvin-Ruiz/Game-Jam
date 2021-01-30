/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Key.cpp
*/
#include "Key.hpp"
#include "TheExit.hpp"
#include "Core.hpp"
#include "Room.hpp"

Key::Key(sf::RenderWindow &window, sf::Texture &texture) : Item(window, texture)
{}

Key::~Key()
{}

bool Key::use(int x, int y)
{
    TheExit *check = dynamic_cast<TheExit *>(Core::core->rooms[x][y].item);

    if (check) {
        // It's the exit !
        Core::core->isCompleted = true;
        Core::core->kill();
        return (true);
    }
    return (false);
}
