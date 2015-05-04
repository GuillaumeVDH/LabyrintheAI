//
// Created by Guillaume on 5/4/2015.
//

#include "Labyrinthe.h"

Labyrinthe::Labyrinthe()
{

}

Labyrinthe::~Labyrinthe()
{

}

void Labyrinthe::run()
{
    MapHandler mapHandler;
    //mapHandler.readMap("C:\\Users\\Guillaume\\ClionProjects\\Labyrinthe\\labyrinthe.txt");
    mapHandler.readMap("C:/Users/Guillaume/ClionProjects/Labyrinthe/labyrinthe.txt");
    mapHandler.showMap();
}