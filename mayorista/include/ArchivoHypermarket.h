#ifndef ARCHIVOHYPERMARKET_H
#define ARCHIVOHYPERMARKET_H
#include<iostream>
#include "Producto.h"
#include "Hypermarket.h"
using namespace std;

class ArchivoHypermarket
{
    public:

        void listadoProductos(int);
        void cargarProducto();
        void modificarInventario(bool sumaOresta, int idProducto, int tipoProducto, int cant);

        void modificarFondos(float monto);
        float mostrarFondos();

};

#endif // ARCHIVOHYPERMARKET_H
