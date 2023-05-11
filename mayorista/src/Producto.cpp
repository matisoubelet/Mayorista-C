#include<iostream>
#include "Producto.h"
#include <cstring>
using namespace std;

void Producto::setID(int id){
    _id = id;
}

void Producto::setNombre(char nombre[20]){
   strcpy(_nombre, nombre);
}

void Producto::setPrecio(float precio){
    _precio = precio;
}

void Producto::setTipoDeProducto(int tipoDeProducto){
   _tipoDeProducto = tipoDeProducto;
}

int Producto::getID(){
    return _id;
}

char Producto::getNombre(){
    return *_nombre;
}

float Producto::getPrecio(){
    return _precio;
}

int Producto::getTipoDeProducto(){
    return _tipoDeProducto;
}
