#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    public:
        Producto();
        void comprar(int id , int cantidad, bool unidadOBulto);
        void vender(int cantidad, bool unidadOBulto, bool retiranOEnvio, bool metodoDePago);

    protected:
    /// Bebida, comida, limpieza, ropa


    private:
        int _cantidad, _minimo, _maximo;
        float _precio;
        int _id;

};

#endif // PRODUCTO_H
