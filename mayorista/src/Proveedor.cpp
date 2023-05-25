#include<iostream>
//#include <thread>
#include "Proveedor.h"
using namespace std;
//using namespace this_thread;


void Proveedor::mostrar()
{
    int tipoDeProducto;
    char mostrarMas='0';
    ListadoProveedor listado;

    do
    {
        system("cls");
        cout << "+=====================+" << endl;
        cout << "| 1 - BEBIDA          |" << endl;
        cout << "| 2 - ROPA            |"<< endl;
        cout << "| 3 - COMIDA          |" << endl;
        cout << "| 4 - ART. LIMPIEZA   |" << endl;
        cout << "+=====================+" << endl;
        cout << "Que tipo de producto esta buscando?: ";
        cin >> opcion;
        cout << endl << endl;

        if(opcion>'0' && opcion<'5')
        {
            tipoDeProducto=isdigit(opcion);
            listado.listadoProductos(tipoDeProducto);
            mostrarMas = '0';
        }
        else
        {
            OpcionNoValida();
            mostrarMas ='1';
        }
    }
    while(mostrarMas == '1');
}
