//
// Created by Guillaume on 5/1/2015.
//

#ifndef LABYRINTHE_MAP_H
#define LABYRINTHE_MAP_H
#include <vector>
#include <string>
#include "../singleton/Singleton.h"
#include "stdexcept"
#include "Coordinates.h"

using namespace std;
namespace model {
    class Map : public Singleton<Map>
    {
    friend class Singleton<Map>;
    public:
        void InitMap(int x, int y);

        void addWall(const int & x, const int & y);
        void removeWall(const int & x, const int & y);

        void setMapInformations(const string & data)    { _mapInformations = data; }
        void setSizeX(const int & x)                    { _sizeX = x-1; } //TODO check why the example says 29 but is 28 length
        void setSizeY(const int & y)                    { _sizeY = y; }
        void setStart(const Coordinates & start )       { _start = start; }
        void setFinish(const Coordinates & finish )     { _finish = finish; }

        string getMapInformations()     { return _mapInformations; }
        int getSizeX()                  { return  _sizeX; }
        int getSizeY()                  { return  _sizeY; }
        Coordinates getStart()          { return  _start; }
        Coordinates getFinish()         { return  _finish; }
        int getValue(const unsigned & x, const unsigned & y);


        //DEBUG
        void Debugg();  //Debug method drawing _map

    private:
        Map();
        virtual ~Map();
        void setValue(const int & x, const int & y, const int & value);

        string               _mapInformations;
        //vector<vector<int>> _map;
        int**               _map;
        int                 _sizeX;
        int                 _sizeY;
        Coordinates         _start;
        Coordinates         _finish;
    };
}

#endif //LABYRINTHE_MAP_H
