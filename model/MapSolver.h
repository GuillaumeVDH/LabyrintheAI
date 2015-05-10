//
// Created by Anthony Callaert on 09/05/15.
//

#ifndef LABYRINTHE_MAPSOLVER_H
#define LABYRINTHE_MAPSOLVER_H

#include "Coordinates.h"
#include "Map.h"

namespace model {
    class MapSolver {
    public:
        void solve();
        bool recursiveSolve(Coordinates coordinates);
        void initHistoric();
        void initCorrectPath();

    private:
        MapSolver();
        virtual ~MapSolver();
        bool** _historic;
        bool** _correctPath;
        Map* _map;
    };
}

#endif //LABYRINTHE_MAPSOLVER_H
