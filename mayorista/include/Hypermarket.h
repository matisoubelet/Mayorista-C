#ifndef HYPERMARKET_H
#define HYPERMARKET_H
#include<iostream>
#include "Hypermarket.h"
#include "Menu.h"
#include "ArchivoHypermarket.h"
#include "ArchivoProveedor.h"
#include "ArchivoEmpleados.h"

using namespace std;


class Hypermarket : public Menu
{
    public:

        void menu();
        void comprar();
        void vender();
        void pagos();
        void inventario();

        void setFondos(float fondos);
        float getFondos();

};

#endif // HYPERMARKET_H
