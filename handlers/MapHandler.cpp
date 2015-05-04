//
// Created by Guillaume on 5/1/2015.
//

#include <fstream>
#include <iostream>
#include "MapHandler.h"


using namespace std;
using namespace handlers;

MapHandler::MapHandler()
{
    _map = Map::getInstance();
}

MapHandler::~MapHandler()
{
    _map->kill();
}

/**
 * @brief This method retrieve the map from the file and fill up our map object
 *
 * @param path  The full path to the file location
 */
void MapHandler::readMap(const string & path) {
    try {
        // Travail sur le fichier contenant la map
        _fileHandler.setFileSource(path);
        _fileHandler.getDataFromFile(_data);

        // On récupère la première ligne contenant les informations (taille du labyrinthe) et on la retire de la map.
        if(_data.size() > 1 )
        {
            this->parseMapInformations(_data.front());
            _data.erase(_data.begin());
        }

        // On set la map
        _map->setMap(_data);
    } catch(exception & e) {
        cerr << "Unable to read file" << endl; ///TODO handle nicely errors to log them.
    }
}

void MapHandler::showMap()
{
    for( string data : _map->getMap())
        cout << data << endl;
}

void MapHandler::parseMapInformations(const string & data)
{
    size_t pos = data.find(" ");
    string str = data.substr(pos+1);

    //Retrieve X
    pos = str.find(" ");
    string stringSizeX = str.substr(0, pos);

    //Retrieve Y
    pos = str.find(" ");
    string stringSizeY = str.substr(pos+1, pos);

    //Set them up on our Map object
    _map->setSizeX(atoi(stringSizeX.c_str()));
    _map->setSizeY(atoi(stringSizeY.c_str()));
}