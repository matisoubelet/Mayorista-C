#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include<iostream>
#include "Menu.h"
#include "ListadoProveedor.h"
#include "ListadoHypermarket.h"
#include "Proveedor.h"


using namespace std;

class Proveedor : Menu {


public:

    void menu();
    void comprar(int );

};

#endif // PROVEEDOR_H
