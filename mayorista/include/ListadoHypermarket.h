#ifndef LISTADOHYPERMARKET_H
#define LISTADOHYPERMARKET_H
#include "Producto.h"
#include "Hypermarket.h"

class ListadoHypermarket
{
    public:

        void listadoProductos(int);
        void cargarProducto();
        void modificarInventario(bool sumaOresta, int idProducto, int tipoProducto, int cant);

        void cargarFondos();
        void modificarFondos(float monto);
        float mostrarFondos();

};

#endif // LISTADOHYPERMARKET_H
