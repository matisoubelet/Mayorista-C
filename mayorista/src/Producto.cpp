#include<iostream>
#include <cstring>
#include "Producto.h"
#include "funciones.h"

using namespace std;

void Producto::Cargar() {

    cout << "Nombre: ";
    cin.getline(_nombre, 20);
    cin.ignore();
    cout << endl;

    cout << "Precio: ";
    cin >> _precio;
    cout << endl;

    cout << "ID: ";
    cin >> _id;
    cout << endl;

    cout << "Tipo de Producto: ";
    cin >> _tipoDeProducto;
    cout << endl;

}


void Producto::Mostrar() {

    cout << "----------------------" << endl;
    cout << "Nombre: "<< _nombre <<endl;
    cout << "Precio: " << _precio <<endl;
    cout << "ID: " << _id <<endl;
    cout << "Tipo de Producto: " << _tipoDeProducto <<endl;
    cout << "----------------------" << endl << endl;
}

void Producto::setID(int id) {
    _id = id;
}

void Producto::setNombre(char nombre[20]) {
    strcpy(_nombre, nombre);
}

void Producto::setPrecio(float precio) {
    _precio = precio;
}

void Producto::setTipoDeProducto(int tipoDeProducto) {
    _tipoDeProducto = tipoDeProducto;
}

int Producto::getID() {
    return _id;
}

const char* Producto::getNombre() {
    return _nombre;
}

float Producto::getPrecio() {
    return _precio;
}

int Producto::getTipoDeProducto() {
    return _tipoDeProducto;
}
