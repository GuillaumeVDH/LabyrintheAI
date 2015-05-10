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
#include "cstdlib"
#include "time.h"
#include "stdlib.h"

using namespace handlers;
using namespace model;
class Labyrinthe {
public:
    Labyrinthe();
    ~Labyrinthe();
    bool FindWay(int X, int Y); //algorithme de resolution

    void run();
private:
    Map* _map;
    MapHandler _mapHandler;
    vector<string> move; // vecteur contenant les positions faites par l'algo

    int oldX,oldY;
};

#endif //LABYRINTHE_LABYRINTHE_H
