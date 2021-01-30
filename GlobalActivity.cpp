/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** GlobalActivity.cpp
*/
#include "GlobalActivity.hpp"
#include "Core.hpp"
#include "DynamicItem.hpp"

GlobalActivity::GlobalActivity()
{}

GlobalActivity::~GlobalActivity()
{}

void GlobalActivity::update()
{
    for (auto &value : Core::core->getDynamicItemList()) {
        value->update();
    }
}
