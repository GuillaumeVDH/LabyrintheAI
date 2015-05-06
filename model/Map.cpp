//
// Created by Guillaume on 5/1/2015.
//

#include <iomanip>
#include "Map.h"

using namespace std;
using namespace model;

Map::Map() {
    _map.clear();
}

void Map::InitMap(int x, int y)
{
    cout << "#Map::InitMap() " << endl;
    _map2 = new int*[y];
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            _map2[i] = new int[x];
        }
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            _map2[i][j] = 0;
        }
    }
}

void Map::addWall(const int &x, const int &y)
{
    this->setValue(x,y,1);
}

void Map::removeWall(const int &x, const int &y)
{
    this->setValue(x,y,0);
}

void Map::setValue(const int & x, const int & y, const int & value)
{
    _map2[y][x] = value;
}


void Map::Debugg()
{
    cout << "#Map::Debugg() " << endl;
    cout << "Informations: " << "x:" << _sizeX << " / y:" << _sizeY << endl;

    for (int i = 0; i < _sizeY; ++i) {   // for each row
        cout << setfill('0') << setw(2) << i << "- " ;
        for (int j = 0; j < _sizeX; ++j) { // for each column
            cout << _map2[i][j];
        }
        cout << endl;
    }
}

