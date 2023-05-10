#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    public:
        Producto();
        void comprar(int cantidad, bool unidadOBulto);
        void vender(int cantidad, bool unidadOBulto, bool retiroOEnvian, bool metodoDePago);

    protected:
    /// A la hora de hacer herencia, se buscaria distribuir en grupos, ejemplo: Bebida, Comida, Mueble, etc. Aunque habria que definir que tipo de mayorista somos
    private:
        int _cantidad, _minimo, _maximo;
        float precio;
};

#endif // PRODUCTO_H
