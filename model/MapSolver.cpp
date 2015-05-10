//
// Created by Anthony Callaert on 09/05/15.
//

#include "MapSolver.h"

void model::MapSolver::solve() {
    for(int i = 0; i < _map->getSizeX(); i++){
        for(int j = 0; j < _map->getSizeY(); j++){
            _historic[i][j] = false;
            _correctPath[i][j]= false;
        }
    }
    bool b = recursiveSolve(_map->getStart());
}

bool model::MapSolver::recursiveSolve(model::Coordinates coordinates) {
    int endX = _map->getFinish().getX();
    int endY = _map->getFinish().getY();

    if(coordinates.getX() == endX && coordinates.getY() == endY)
        return true;


}

void model::MapSolver::initHistoric() {

}

void model::MapSolver::initCorrectPath() {

}

model::MapSolver::MapSolver() {

}

model::MapSolver::~MapSolver() {

}
