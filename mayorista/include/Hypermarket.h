#ifndef HYPERMARKET_H
#define HYPERMARKET_H


class Hypermarket
{
    public:

        void menu();
        void comprar();
        void vender();
        void pagos();
        void inventario();
        ///void agregarProducto();
        ///void borrarProducto();
    private:

        float _fondos, _precioEntrega, _precioPorBulto, _precioPorUnidad;
};

#endif // HYPERMARKET_H
