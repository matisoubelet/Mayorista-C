#ifndef LISTADOHYPERMARKET_H
#define LISTADOHYPERMARKET_H
#include "Producto.h"
#include "Hypermarket.h"

class ListadoHypermarket
{
    public:

        void listadoProductos(int);
        void cargarProducto();
        void cargarFondos();
        void modificarFondos(float monto);
        float fondos();

};

#endif // LISTADOHYPERMARKET_H
