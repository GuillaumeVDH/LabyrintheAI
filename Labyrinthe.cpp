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

        Coordinates start =_map->getStart();

        if (FindWay(start.getX(), start.getY()))
        {
            cout<<"Done"<<endl;
        }
        else
        {
            cout<<("Damn\n")<<endl;
        }

    } catch(exception & e) {
        cerr << e.what() << endl;
        cerr << "Aborted." << endl;
    }



    ///TODO create logic map from X/Y + vector data

}

bool Labyrinthe::FindWay(int X, int Y)
{
    Coordinates end = _map->getFinish();
    const int Free = 0;
    const char somedude =2;
    // Make the move (if it's wrong, we will backtrack later.
    _map->setValue(X,Y,somedude);


    // If you want progressive update, uncomment these lines...
    _map->Debugg();
    cout<<""<<endl;
    //sleep(50);

    // Check if we have reached our goal.
    if (X == (unsigned int)end.getX() && Y == (unsigned int)end.getY())
    {
        return true;
    }

    // Recursively search for our goal.
    if (X > 0 && _map->getValue(Y,X - 1) == Free && FindWay(X - 1, Y))
    {
        return true;
    }
    if (X < _map->getSizeX() && _map->getValue(Y,X + 1) == Free && FindWay(X + 1, Y))
    {
        return true;
    }
    if (Y > 0 && _map->getValue(Y - 1,X) == Free && FindWay(X, Y - 1))
    {
        return true;
    }
    if (Y < _map->getSizeY() && _map->getValue(Y + 1,X) == Free && FindWay(X, Y + 1))
    {
        return true;
    }
    // Otherwise we need to backtrack and find another solution.

    _map->setValue(X,Y,Free);
    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();
    //Sleep(50);
    return false;
}