/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** WindowManager.cpp
*/
#include "WindowManager.hpp"

WindowManager::WindowManager()
{}

WindowManager::~WindowManager()
{}

void WindowManager::initialize()
{
    if (!menuStartBackgroundT.loadFromFile("Sprite/wallhaven-51384-1024x576.jpeg", sf::IntRect(0, 0, 1980, 1080)))
        printf("menuStartBackground can't load from file");
    if (!menuButtonExitT.loadFromFile("Sprite/Exit_button.png"))
        printf("menuButtonExit can't load from file");
    if (!menuButtonPlayT.loadFromFile("Sprite/play_button.png"))
        printf("menuButtonPlay can't load from file");
    menuButtonPlayS.setTexture(menuButtonPlayT);
    menuButtonExitS.setTexture(menuButtonExitT);
    menuStartBackgroundS.setTexture(menuStartBackgroundT);
}