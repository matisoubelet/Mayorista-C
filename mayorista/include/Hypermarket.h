#ifndef HYPERMARKET_H
#define HYPERMARKET_H
#include<iostream>
#include "Menu.h"
#include "ArchivoHypermarket.h"
#include "Hypermarket.h"
#include "ArchivoProveedor.h"
using namespace std;


class Hypermarket : public Menu
{
    public:

        void menu();
        void comprar();
        void vender();
        void pagos();
        void inventario();
        ///void agregarProducto();
        ///void borrarProducto();

        void setFondos(float fondos);
        float getFondos();

    private:

        float _fondos, _precioPorUnidad = 1.10;
        int _precioEntrega = 1500;
};

#endif // HYPERMARKET_H
