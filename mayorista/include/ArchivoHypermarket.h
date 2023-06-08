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
        int stock(int idCompra, int tipoProducto);
        void cargarProducto();
        void modificarInventario(bool sumaOresta, int idProducto, int tipoProducto, int cant);
        float precioProducto(int idCompra, int tipoProducto);
        void modificarFondos(float monto);
        float mostrarFondos();

};

#endif // ARCHIVOHYPERMARKET_H
