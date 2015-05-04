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
    MapHandler mapHandler;
    //mapHandler.readMap("C:\\Users\\Guillaume\\ClionProjects\\Labyrinthe\\labyrinthe.txt");
    mapHandler.readMap("C:/Users/Guillaume/ClionProjects/Labyrinthe/labyrinthe.txt");

    ///SHOW
    cout << "Map x: " << _map->getSizeX() << " / Map y: " << _map->getSizeY() << endl;
    mapHandler.showMap();

    ///TODO create logic map from X/Y + vector data
    //_map->InitMap(_map->getSizeX(), _map->getSizeY());
}