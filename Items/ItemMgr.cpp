/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** ItemMgr.cpp
*/
#include "ItemMgr.hpp"
#include "Core.hpp"
#include <random>
#include "Blaster.hpp"
#include "Door.hpp"
#include "Key.hpp"
#include "MediKit.hpp"
#include "Item.hpp"
#include "Room.hpp"

ItemMgr::ItemMgr(sf::RenderWindow &window) : window(window)
{}

ItemMgr::~ItemMgr()
{}

bool ItemMgr::setItemData(enum itemType itype, const std::string &filename, float frequency, float value)
{
    bool ret = itemData[itype].tex.loadFromFile(filename);
    itemData[itype].frequency = frequency;
    itemData[itype].value = value;

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
            item = std::make_shared<Blaster>(window, itemData[itm].tex, itemData[BULLET].tex, itemData[BULLET].value, itemData[itm].value, DynamicItem::BULLET);
            break;
        case BAZOOKA:
            item = std::make_shared<Blaster>(window, itemData[itm].tex, itemData[ROCKET].tex, itemData[ROCKET].value, itemData[itm].value, DynamicItem::ROCKET);
            break;
        case DOOR:
            item = std::make_shared<Door>(window, itemData[itm].tex, itemData[itm].value);
            break;
        case KEY:
            item = std::make_shared<Key>(window, itemData[itm].tex);
            break;
        case MEDIKIT:
            item = std::make_shared<MediKit>(window, itemData[itm].tex);
            break;
        default:
            break;
    }
    Core::core->getItemList().push_back(item);
    return item.get();
}

void ItemMgr::setLoot()
{
    auto &rooms = Core::core->rooms;
    //auto &list = Core::core->getItemList();
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
            rooms[pos % rooms.size()][pos / rooms.size()].item = create((enum itemType) i);
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
                room.isBlocking = (f == DOOR);
                break;
            }
        }
    }
}
