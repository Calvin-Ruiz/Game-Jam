/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** ItemMgr.cpp
*/
#include "ItemMgr.hpp"
#include "Core.hpp"
#include <random>

ItemMgr::ItemMgr()
{}

ItemMgr::~ItemMgr()
{}

bool ItemMgr::setItemData(enum itemType itype, const std::string &filename, float frequency = 0, float value = 0)
{
    bool ret = itemTex[itype].tex.loadFromFile(filename);
    itemTex[itype].frequency = frequency;
    itemTex[itype].value = value;

    if (frequency > 0)
        freq.push_back(itype);
    if (!ret)
        std::cerr << "Failed to load image '" << filename << "'.\n";
    return ret;
}

Item *ItemMgr::create(enum itemType itm)
{
    std::shared_ptr<Item> item;
    switch (itm) {
        case BLASTER:
            break;
        case BAZOOKA:
            break;
        case DOOR:
            break;
        case KEY:
            break;
        case MEDIKIT:
            break;
        default:
            break;
    }
    Core::core->getItemList.push_back(item);
    return item.get();
}

void ItemMgr::setLoot()
{
    auto &rooms = Core::core->rooms;
    auto &list = Core::core->getItemList();
    std::random_device rdevice;
    std::uniform_real_distribution<float> distr(0, 100);
    std::uniform_int_distribution<long> single(0, rooms.size() * rooms[0].size() - 1);

    int i = 0;
    for (auto &value : itemData) {
        if (value.frequency == -1.) {
            long pos;
            do {
                pos = single(rdevice);
            } while (rooms[pos % rooms.size()][pos / rooms.size()].item);
            rooms[pos % rooms.size()][pos / rooms.size()].item = createItem(i);
        }
        i++;
    }

    for (auto &line : rooms) {
        for (auto &room : line) {
            if (room.item)
                continue;
            float frequency = distr(rdevice);
            for (auto f : freq) {
                frequency -= itemData[f].frequency;
                if (frequency > 0)
                    continue;
                room.item = create(f);
                break;
            }
        }
    }
}
