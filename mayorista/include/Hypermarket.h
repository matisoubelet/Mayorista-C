#ifndef HYPERMARKET_H
#define HYPERMARKET_H
#include "Menu.h"
#include "ListadoHypermarket.h"

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

        float _fondos, _precioPorBulto = 1.25, _precioPorUnidad = 1.10;
        int _precioEntrega = 1500;
};

#endif // HYPERMARKET_H
