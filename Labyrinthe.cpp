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
    try {
        cout << "#Generating the map.. " << endl;
        _mapHandler.readMap(Constants::PATH_LABYRINTHE);

        cout << "#Map generated! " << endl;
        _map->Debugg();

        cout << "#Setting up goals... ";
        _mapHandler.getStardAndFinish();
        cout << "done." << endl;
        cout << "Start: " << _map->getStart().getX() << "/" << _map->getStart().getY() << endl;
        cout << "Finish: " << _map->getFinish().getX() << "/" << _map->getFinish().getY() << endl;

    } catch(exception & e) {
        cerr << e.what() << endl;
        cerr << "Aborted." << endl;
    }



    ///TODO create logic map from X/Y + vector data

}