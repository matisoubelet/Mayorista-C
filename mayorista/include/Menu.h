#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>
#include <thread>
using namespace std;
using namespace this_thread;


class Menu {
protected:
    char opcion;

    void OpcionNoValida();

};

#endif // MENU_H
