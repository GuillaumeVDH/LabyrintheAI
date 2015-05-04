//
// Created by Guillaume on 5/1/2015.
//

#ifndef LABYRINTHE_MAPHANDLER_H
#define LABYRINTHE_MAPHANDLER_H
#include <string>
#include <vector>
#include "../model/Map.h"
#include "FileHandler.h"

using namespace std;
using namespace model;
namespace handlers {
    class MapHandler {
    public:
        MapHandler();
        ~MapHandler();
        void readMap(const string & path);
        void showMap();

    private:
        void parseMapInformations(const string & data);

        FileHandler _fileHandler;
        vector<string> _data;
        Map* _map;
    };
}

#endif //LABYRINTHE_MAPHANDLER_H
