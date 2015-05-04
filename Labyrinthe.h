//
// Created by Guillaume on 5/4/2015.
//

#ifndef LABYRINTHE_LABYRINTHE_H
#define LABYRINTHE_LABYRINTHE_H
#include "handlers/MapHandler.h"
#include "model/Map.h"

using namespace handlers;
using namespace model;
class Labyrinthe {
public:
    Labyrinthe();
    ~Labyrinthe();

    void run();
private:
    Map* _map;
    MapHandler _mapHandler;
};

#endif //LABYRINTHE_LABYRINTHE_H
