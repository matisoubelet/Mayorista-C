#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "Producto.h"

class Proveedor
{
    public:

        void mostrar(int tipoDeProducto);


    private:
        float _descuentoBulto = 0.85;
        bool _comproBulto = false;
        int _precioEntrega = 1000, _bulto = 10;

};

#endif // PROVEEDOR_H
