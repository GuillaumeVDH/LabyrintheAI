//
// Created by Guillaume on 5/4/2015.
//

#ifndef LABYRINTHE_LABYRINTHE_H
#define LABYRINTHE_LABYRINTHE_H
#include "handlers/MapHandler.h"
#include "model/Map.h"
#include "Constants.h"
#include <unistd.h>
#include <vector>
#include "iostream"
#include <string>

using namespace handlers;
using namespace model;
class Labyrinthe {
public:
    Labyrinthe();
    ~Labyrinthe();
    bool FindWay(int X, int Y);

    void run();
private:
    Map* _map;
    MapHandler _mapHandler;
    vector<string> move;
    int oldX,oldY;
};

#endif //LABYRINTHE_LABYRINTHE_H
