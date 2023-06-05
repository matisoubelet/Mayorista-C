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
        bool comprar();
        bool vender();
        void pagos();
        int inventario();

        void setFondos(float fondos);
        float getFondos();

};

#endif // HYPERMARKET_H
