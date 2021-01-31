/*
** EPITECH PROJECT, 2020
** Game-Jam
** File description:
** Room.cpp
*/

#include <vector>
#include <list>
#include "Room.hpp"
#include <iostream>

void findRoom(int &x, int &y, room *myRoom, std::vector<std::vector<room>> &rooms)
{
    y = 0;
    for (int xy = 0; xy < rooms.size(); xy++) {
        x = 0;
        for (int xx = 0; xx < rooms[xy].size(); xx++) {
            if (&rooms[xx][xy] == myRoom) return;
            x++;
        }
        y++;
    }
}

bool canGoHere(int x, int y, room myRoom, std::vector<std::vector<room>> rooms)
{
    if (y >= 0 && y < rooms.size())
        if (x >= 0 && x < rooms[y].size())
            if (!rooms[x][y].visited) return true;
    return false;
}

int getLengthWay(int x, int y, room myRoom, std::vector<std::vector<room>> rooms)
{
    int res = 0;
    if (!myRoom.top && canGoHere(x, y - 1, myRoom, rooms)) res++;
    if (!myRoom.bottom && canGoHere(x, y + 1, myRoom, rooms)) res++;
    if (!myRoom.left && canGoHere(x - 1, y, myRoom, rooms)) res++;
    if (!myRoom.right && canGoHere(x + 1, y, myRoom, rooms)) res++;
    return res;
}

/* Try to find a room */
bool findPath(int &x, int &y, std::vector<std::vector<room>> &rooms, std::list<room*> &listRoom, RandomDevice &rand)
{
    room* myRoom = listRoom.front();
    findRoom(x, y, myRoom, rooms);
    int len = getLengthWay(x, y, *myRoom, rooms);
    if (len == 0) return false;

    int ran = rand.randInt(0, len - 1);


    if (!myRoom->top && canGoHere(x, y - 1, *myRoom, rooms)) {
        if (ran == 0) {
            rooms[x][y].top = true;
            y--;
            rooms[x][y].bottom = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
        ran--;
    } if (!myRoom->bottom && canGoHere(x, y + 1, (*myRoom), rooms)) {
        if (ran == 0) {
            rooms[x][y].bottom = true;
            y++;
            rooms[x][y].top = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
        ran--;
    } if (!myRoom->right && canGoHere(x + 1, y, (*myRoom), rooms)) {
        if (ran == 0) {
            rooms[x][y].right = true;
            x++;
            rooms[x][y].left = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
        ran--;
    } if (!myRoom->left && canGoHere(x - 1, y, (*myRoom), rooms))
        if (ran == 0) {
            rooms[x][y].left = true;
            x--;
            rooms[x][y].right = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
    return false;
}

void showLaby(std::vector<std::vector<room>> rooms)
{
    std::string line = "#";
    for (int i = 0; i < rooms[0].size() * 2; i++)
        line += "#";
    std::vector<std::string> laby;
    laby.resize(rooms.size() * 2 + 1);
    for (std::string &r : laby)
        r = line;

    int y = 1;
    int x = 1;
    for (std::vector<room> r : rooms) {
        x = 1;
        for (room room : r) {
            laby[x][y] = ' ';
            if (room.top) laby[y - 1][x] = ' ';
            if (room.bottom) laby[y + 1][x] = ' ';
            if (room.left) laby[y][x - 1] = ' ';
            if (room.right) laby[y][x + 1] = ' ';
            x += 2;
        }
        y += 2;
    }

    for (std::string r : laby)
        std::cout << r << std::endl;
}

void createLaby(int seed, int width, int height, std::vector<std::vector<room>> &rooms, std::vector<std::shared_ptr<Item>> &items)
{
    /* Clear Vector */
    rooms.clear();
    items.clear();

    /* Resize my room */
    rooms.resize(height);
    for (std::vector<room> &line : rooms)
        line.resize(width);
    items.resize(height);

    /* Init Random And Seed */
    RandomDevice rand(seed);

    /* Create list of Visited Room */
    std::list<room*> listRoom;
    listRoom.push_front(&rooms[0][0]);
    int x = 0;
    int y = 0;
    while (1) {
        if (listRoom.empty()) break;
        if (findPath(x, y, rooms, listRoom, rand)) { listRoom.front()->visited = true; }
        else listRoom.pop_front();
    }

    // showLaby(rooms);
}
