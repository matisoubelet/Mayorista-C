#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "Producto.h"

class Proveedor
{
    public:
        Proveedor();
        void cargarProducto();

    protected:

    private:
        char _nombre[20];
        float _precioEntrega, _precioPorBulto, _precioPorUnidad;
        Producto producto;

};

#endif // PROVEEDOR_H
