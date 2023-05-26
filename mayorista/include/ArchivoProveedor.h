#ifndef ARCHIVOPROVEEDOR_H
#define ARCHIVOPROVEEDOR_H
#include<iostream>
#include "Producto.h"
#include "Menu.h"
using namespace std;

class ArchivoProveedor: public Menu
{
    public:
        void listadoProductos(int);
        void cargarProducto();
        float precioProducto(int idCompra);
        void mostrarProducto();
        /// Esta Clase debe ser capaz de entrar al archivo donde se esten guardando los productos
        /// de los proovedores a la hora de querer comprar algo de ellos. Cada producto debera incluir
        /// Su Id, Nombre del producto, precio por unidad y precio por bulto

};

#endif // ARCHIVOPROVEEDOR_H
