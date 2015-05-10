//
// Created by Guillaume on 5/4/2015.
//

#include <synchapi.h>
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
        _mapHandler.readMap(Constants::PATH_LABYRINTHE); // Affichage de la map contenu dans le fichier texte

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
            for (int i = 0; i < move.size(); i++) {
                cout<<"Mouvement : " + move[i]<<endl;
            }
            _map->Debugg();
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
}

bool Labyrinthe::FindWay(int X, int Y)
{
//-------Enregistrement des mouvements de l'algo dans un vecteur -------//
    if (X==oldX+1)
    {
        move.push_back("E");
        cout<<"dernier mouvement : E"<<endl;
    }
    if (X==oldX-1)
    {
        move.push_back("O");
        cout<<"dernier mouvement : O"<<endl;
    }
    if (Y==oldY+1)
    {
        move.push_back("S");
        cout<<"dernier mouvement : S"<<endl;
    }
    if (Y==oldY-1)
    {
        move.push_back("N");
        cout<<"dernier mouvement : N"<<endl;
    }
    oldX=X;
    oldY=Y;
//-------------------------------------------------------//
    Coordinates end = _map->getFinish();
    const int Free = 0;
    const char somedude =2;
    _map->setValue(X,Y,somedude);   //Marquer par un 2 la position de l'algo dans le tableau

    //Affichage de la map
    //_map->Debugg();
    //cout<<""<<endl;
    //Sleep(100);
    // Regarder si nous avons atteind le point final
    if (X == (unsigned int)end.getX() && Y == (unsigned int)end.getY())
    {
        return true;
    }

    // Chercher le point final récursivement.
    try {
        if (X > 0 && _map->getValue(X - 1, Y) == Free && _map->getValue(X - 1, Y) != 2 &&
                     FindWay(X - 1, Y)) //test vers ouest
        {
            return true;
        }
        if (X < _map->getSizeX() && _map->getValue(X + 1, Y) == Free && _map->getValue(X + 1, Y) != 2 &&
                                    FindWay(X + 1, Y)) //test vers l'Est
        {
            return true;
        }
        if (Y > 0 && _map->getValue(X, Y - 1) == Free && _map->getValue(X, Y - 1) != 2 &&
                     FindWay(X, Y - 1)) //test vers le sud
        {
            return true;
        }
        if (Y < _map->getSizeY() && _map->getValue(X, Y + 1) == Free && _map->getValue(X, Y + 1) != 2 &&
                                    FindWay(X, Y + 1)) //test vers le nord
        {
            return true;
        }
    }
    catch (exception &e)
    {cout<<"Invalid argument X :"<< X<<"    Y :"<<Y<<endl;}
    // Otherwise we need to backtrack and find another solution.

    _map->setValue(X,Y,Free);
    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();
    //Sleep(50);
    return false;
}