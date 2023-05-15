#ifndef LISTADOPROVEEDOR_H
#define LISTADOPROVEEDOR_H
#include "Producto.h"

class ListadoProveedor
{
    public:
        void listadoProductos();
        void cargarProducto();
        /// Esta Clase debe ser capaz de entrar al archivo donde se esten guardando los productos
        /// de los proovedores a la hora de querer comprar algo de ellos. Cada producto debera incluir
        /// Su Id, Nombre del producto, precio por unidad y precio por bulto

    protected:
        /// Se heredaria lo necesario para luego en una clase ListadoDeNuestroLocal
    private:
};

#endif // LISTADOPROVEEDOR_H
