#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:

    char _nombre[20];
    float _precio;
    int _id, _tipoDeProducto;

public:

    void Cargar();
    void Mostrar();

    ///Setters:
    void setNombre(char nombre[20]);
    void setPrecio(float);
    void setID(int);
    void setTipoDeProducto(int);

    ///Getters:
    const char* getNombre();
    float getPrecio();
    int getID();
    int getTipoDeProducto();




};

#endif // PRODUCTO_H
