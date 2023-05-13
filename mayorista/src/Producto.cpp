#include<iostream>
#include <cstring>
#include "Producto.h"
#include "funciones.h"

using namespace std;

void Producto::mostrarCadena(char nombre[20])
{
    int cant = strlen(nombre);
    for(int i = 0; i < 20 ; i++)
    {
        if(i < cant)
        {
            cout << nombre[i];
        }
    }
     cout << endl;
}

void Producto::setID(int id)
{
    _id = id;
}

void Producto::setNombre(char nombre[20])
{
    strcpy(_nombre, nombre);
}

void Producto::setPrecio(float precio)
{
    _precio = precio;
}

void Producto::setTipoDeProducto(int tipoDeProducto)
{
    _tipoDeProducto = tipoDeProducto;
}

int Producto::getID()
{
    return _id;
}

void Producto::getNombre()
{
    mostrarCadena(_nombre);
}

float Producto::getPrecio()
{
    return _precio;
}

int Producto::getTipoDeProducto()
{
    return _tipoDeProducto;
}
