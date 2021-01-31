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
    x = 0;
    for (int xx = 0; xx < rooms.size(); xx++) {
        y = 0;
        for (int xy = 0; xy < rooms[xx].size(); xy++) {
            if (&rooms[xx][xy] == myRoom) return;
            y++;
        }
        x++;
    }
}

bool canGoHere(int x, int y, std::vector<std::vector<room>> rooms)
{
    if (x >= 0 && x < rooms.size())
        if (y >= 0 && y < rooms[x].size())
            if (!rooms[x][y].visited) return true;
    return false;
}

int getLengthWay(int x, int y, room myRoom, std::vector<std::vector<room>> rooms)
{
    int res = 0;
    if (!myRoom.top && canGoHere(x, y - 1, rooms)) res++;
    if (!myRoom.bottom && canGoHere(x, y + 1, rooms)) res++;
    if (!myRoom.left && canGoHere(x - 1, y, rooms)) res++;
    if (!myRoom.right && canGoHere(x + 1, y, rooms)) res++;
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

    if (!myRoom->top && canGoHere(x, y - 1, rooms)) {
        if (ran == 0) {
            rooms[x][y].top = true;
            y--;
            rooms[x][y].bottom = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
        ran--;
    } if (!myRoom->bottom && canGoHere(x, y + 1, rooms)) {
        if (ran == 0) {
            rooms[x][y].bottom = true;
            y++;
            rooms[x][y].top = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
        ran--;
    } if (!myRoom->right && canGoHere(x + 1, y, rooms)) {
        if (ran == 0) {
            rooms[x][y].right = true;
            x++;
            rooms[x][y].left = true;
            listRoom.push_front(&(rooms[x][y]));
            return true;
        }
        ran--;
    } if (!myRoom->left && canGoHere(x - 1, y, rooms))
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
        y = 1;
        for (room room : r) {
            laby[x][y] = ' ';
            if (room.top) laby[x][y - 1] = ' ';
            if (room.bottom) laby[x][y + 1] = ' ';
            if (room.left) laby[x - 1][y] = ' ';
            if (room.right) laby[x + 1][y] = ' ';
            if (room.exit == EXIT) laby[x][y] = 'E';
            if (room.exit == ENTER) laby[x][y] = 'O';
            y += 2;
        }
        x += 2;
    }

    for (std::string r : laby)
        std::cout << r << std::endl;
}

void findExit(int &x, int &y, std::vector<std::vector<room>> &rooms, Exit exit)
{
    x = 0;
    for (int xx = 0; xx < rooms.size(); xx++) {
        y = 0;
        for (int xy = 0; xy < rooms[xx].size(); xy++) {
            if (rooms[xx][xy].exit == exit) return;
            y++;
        }
        x++;
    }
}

void createLaby(int seed, int width, int height, std::vector<std::vector<room>> &rooms, std::vector<std::shared_ptr<Item>> &items)
{
    /* Clear Vector */
    rooms.clear();
    items.clear();

    /* Resize my room */
    rooms.resize(width);
    for (std::vector<room> &line : rooms)
        line.resize(height);
    items.resize(width);

    /* Init Random And Seed */
    RandomDevice rand(seed);

    /* Create list of Visited Room */
    std::list<room*> listRoom;
    listRoom.push_front(&rooms[0][0]);
    listRoom.front()->visited = true;
    int x = 0;
    int y = 0;
    while (1) {
        if (listRoom.empty()) break;
        if (findPath(x, y, rooms, listRoom, rand)) { listRoom.front()->visited = true; }
        else listRoom.pop_front();
    }

    // rooms[rand.randInt(0, width - 1)][0].exit = Exit::ENTER;
    // rooms[rand.randInt(0, width - 1)][height - 1].exit = Exit::EXIT;

    rooms[0][0].exit = Exit::ENTER;
    rooms[width - 1][height - 1].exit = Exit::EXIT;

    // showLaby(rooms);
}