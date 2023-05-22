#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "ListadoProveedor.h"
#include "ListadoHypermarket.h"
#include "Menu.h"

class Proveedor : Menu
{
    public:

        void mostrar();

    private:

        float _descuentoBulto = 0.85;
        bool _comproBulto = false;
        int _precioEntrega = 1000, _bulto = 10;

};

#endif // PROVEEDOR_H
