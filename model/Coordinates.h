//
// Created by Guillaume on 06/05/2015.
//

#ifndef LABYRINTHE_COORDINATES_H
#define LABYRINTHE_COORDINATES_H


namespace model {
    class Coordinates {
    public:
        Coordinates() {};
        virtual ~Coordinates() {};

        void setX(const unsigned int & x) { _x = x; }
        void setY(const unsigned int & y) { _y = y; }

        unsigned int getX() { return _x; }
        unsigned int getY() { return _y; }

    private:
        unsigned int _x;
        unsigned int _y;
    };
}

#endif //LABYRINTHE_COORDINATES_H
