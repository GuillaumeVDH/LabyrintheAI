//
// Created by Guillaume on 5/1/2015.
//

#ifndef LABYRINTHE_MAP_H
#define LABYRINTHE_MAP_H
#include <vector>
#include <string>
#include "../singleton/Singleton.h"

using namespace std;
namespace model {
    class Map : public Singleton<Map>
    {
    friend class Singleton<Map>;
    public:
        void InitMap(int x, int y);

        void setMapInformations(const string & data)    { _mapInformations = data; }
        void setMap(vector<string> map)                 { _map = map; }
        void setSizeX(const int & x)                    { _sizeX = x-1; } //TODO check why the example says 29 but is 28 length
        void setSizeY(const int & y)                    { _sizeY = y; }

        void addWall(const int & x, const int & y);
        void removeWall(const int & x, const int & y);

        string getMapInformations()     { return _mapInformations; }
        vector<string> getMap()         { return _map; }
        int getSizeX()                  { return  _sizeX; }
        int getSizeY()                  { return  _sizeY; }


        //DEBUG
        void Debugg();  //Debug method drawing _map2

    private:
        Map();
        virtual ~Map() {};

        void setValue(const int & x, const int & y, const int & value);

        string          _mapInformations;
        vector<string>  _map;
        int**           _map2;
        int             _sizeX;
        int             _sizeY;
    };
}

#endif //LABYRINTHE_MAP_H
