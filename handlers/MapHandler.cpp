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

MapHandler::~MapHandler() { }

/**
 * @brief This method retrieve the map from the file and fill up our map object
 *
 * @param path  The full path to the file location
 */
void MapHandler::readMap(const string & path) {
    try {
        //Travail sur le fichier contenant la map
        _fileHandler.setFileSource(path);
        _fileHandler.getDataFromFile(_data);

        //On récupère la première ligne contenant les informations (taille du labyrinthe) et on la retire de la map.
        if(_data.size() > 1 )
        {
            this->parseMapInformations(_data.front());
            _data.erase(_data.begin());
        }

        //DEBUG
        for( string data : _data)
            cout << data << endl;

        //Now that we've got the x/y size from the text file, let's init our 2d array
        _map->InitMap(_map->getSizeX(), _map->getSizeY());
        _map->Debugg();

        //Generate the walls..
        unsigned int y = 0;
        for( string data : _data)
        {
            for(unsigned int i = 0; i < data.length(); ++i)
            {
                if(data[i] == '#')
                {
                    try {
                        _map->addWall(i, y);
                    } catch(exception & e) {
                        cerr << e.what() << endl;
                    }
                }

            }
            ++y;
        }

        _map->Debugg();

    } catch(exception & e) {
        cerr << "Unable to read file" << endl;
    }
}

void MapHandler::showMap()
{
//    for( string data : _map->getMap())
//        cout << data << endl;
}

void MapHandler::parseMapInformations(const string & data)
{
    size_t pos = data.find(" ");
    string str = data.substr(pos+1);

    //Retrieve Y
    pos = str.find(" ");
    string stringSizeY = str.substr(0, pos);

    //Retrieve X
    pos = str.find(" ");
    string stringSizeX = str.substr(pos+1, pos);

    //Set them up on our Map object
    _map->setSizeX(atoi(stringSizeX.c_str()));
    _map->setSizeY(atoi(stringSizeY.c_str()));
}