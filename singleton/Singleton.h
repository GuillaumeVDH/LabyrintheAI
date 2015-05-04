//
// Created by Guillaume on 5/4/2015.
//

#ifndef LABYRINTHE_SINGLETON_H
#define LABYRINTHE_SINGLETON_H
#include <stddef.h>
#include <iostream>
#include <string>

template <class T>
class Singleton
{
    public:
        static T* getInstance()
        {
            if (NULL == _singleton)
            {
                _singleton = new T;
            }
            return (static_cast<T*> (_singleton));
        }
        static void kill ()
        {
            if (NULL != _singleton)
            {
                delete _singleton;
                _singleton = NULL;
            }
        }
    protected:
        Singleton() {};
        ~Singleton() {};
    private:
        static T *_singleton;
};

template <typename T>
T *Singleton<T>::_singleton = NULL;
#endif //LABYRINTHE_SINGLETON_H
