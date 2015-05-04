//
// Created by Guillaume on 5/1/2015.
//

#include "Map.h"

using namespace std;
using namespace model;

Map::Map() {
    _map.clear();
}

void Map::InitMap(int x, int y)
{
    cout << "InitMap() " << endl;
    _map2 = new int*[x];
    for (int i = 0; i < x; ++i) {   // for each row
        for (int j = 0; j < y; ++j) { // for each column
            cout << _map.at(i)[j];
            _map2[i][j] = _map.at(i)[j];
        }
        cout << endl;
    }


    cout << "DEBUUUG " << endl;
    for (int i = 0; i < x; ++i) {   // for each row
        for (int j = 0; j < y; ++j) { // for each column
            cout << _map2[i][j];
        }
        cout << endl;
    }
}