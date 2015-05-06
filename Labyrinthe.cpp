//
// Created by Guillaume on 5/4/2015.
//

#include "Labyrinthe.h"

Labyrinthe::Labyrinthe()
{
    _map = Map::getInstance();
}

Labyrinthe::~Labyrinthe()
{
    _map->kill();
}

void Labyrinthe::run()
{
    _mapHandler;
    _mapHandler.readMap(Constants::PATH_LABYRINTHE);

    ///TODO create logic map from X/Y + vector data

}