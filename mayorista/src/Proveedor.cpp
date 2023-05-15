#include<iostream>
#include "Proveedor.h"
using namespace std;

void Proveedor::mostrar(){

    int tipoDeProducto, mostrarMas;
    ListadoProveedor listado;

    do{
        cout << "==========================" << endl;
        cout << "1 - BEBIDA" << endl;
        cout << "2 - ROPA" << endl;
        cout << "3 - COMIDA" << endl;
        cout << "4 - ART. LIMPIEZA" << endl;
        cout << "==========================" << endl;
        cout << "Que tipo de producto esta buscando?: ";
        cin >> tipoDeProducto;
        cout << endl << endl;

        listado.listadoProductos(tipoDeProducto);

        cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
        cin >> mostrarMas,
        cout << endl;

        if(mostrarMas == 1){
            system("CLS");
            tipoDeProducto = 0;
        }

    } while(mostrarMas == 1);



}
