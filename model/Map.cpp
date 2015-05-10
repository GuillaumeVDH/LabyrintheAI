//
// Created by Guillaume on 5/1/2015.
//

#include <iomanip>
#include "Map.h"

using namespace std;
using namespace model;

Map::Map() {
    _start.setX(0);
    _start.setY(0);
    _finish.setX(0);
    _finish.setY(0);
}

Map::~Map()
{
    //De-allocate memory of our 2d array
    for (int i = 0; i < _sizeY; ++i)
        delete [] _map[i];
    delete [] _map;
}

void Map::InitMap(int x, int y)
{
    cout << "#Map::InitMap() " << endl;
    _map = new int*[y];
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            _map[i] = new int[x];
        }
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            _map[i][j] = 0;
        }
    }
}

int Map::getValue(const unsigned &x, const unsigned &y)
{
    int result = -1;
    if((x >= 0 && x <= _sizeX) && (y >= 0 && y <= _sizeY))
        result = _map[y][x];
    else
        throw invalid_argument("Out of bound.");
    return result;
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
    if((x >= 0 && x <= _sizeX) && (y >= 0 && y <= _sizeY))
        _map[y][x] = value;
    else
        throw invalid_argument("Out of bound.");
}


void Map::Debugg()
{
    cout << "#Map::Debugg() " << endl;
    cout << "Informations: " << "x:" << _sizeX << " / y:" << _sizeY << endl;

    for (int i = 0; i < _sizeY; ++i) {      // for each row
        cout << setfill('0') << setw(2) << i << "- " ;
        for (int j = 0; j < _sizeX; ++j) {  // for each column
            cout << _map[i][j];
        }
        cout << endl;
    }
}


