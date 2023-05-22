#include<iostream>
//#include <thread>
#include "Proveedor.h"
using namespace std;
//using namespace this_thread;


void Proveedor::mostrar()
{
    int tipoDeProducto, idCompra, cantCompra, UoB;
    float precio, fondos;
    char mostrarMas='0';
    ListadoProveedor listado;
    ListadoHypermarket local;

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

            cout << "Ingrese el ID del producto que desee comprar: ";
            cin >> idCompra;
            cout << endl;

            while(idCompra < 1 || idCompra > 10)
            {

                cout << "Ese ID no es valido, asegurese que se encuentre entre el 1 y el 10" << endl;
                cout << "Vuelva a ingresar el ID por favor: ";
                cin >> idCompra;
                cout << endl;

            }

            precio = listado.enseniarCompra(idCompra);
            fondos = local.fondos();

            cout << "Desea comprar en unidades o en bultos (10 unidades): (Unidades: 1 | Bultos: 2): ";
            cin >> UoB;
            cout << endl;

            switch(UoB)
            {

            case 1:
                cout << "Cuantas unidades desea comprar?: ";
                cin >> cantCompra;
                cout << endl;
                precio *= cantCompra;
                break;

            case 2:
                cout << "Cuantos bultos desea comprar?: ";
                cin >> cantCompra;
                cout << endl;
                cantCompra *= 10;
                precio *= cantCompra;
                break;

            default:
                cout << "Opcion inexistente, la compra sera cancelada." << endl;
                break;
            }

            if(fondos-precio < 0)
            {
                cout << "La compra no puede realizarse por falta de fondos" << endl;
            }
            else
            {
                fondos -= precio;
                local.modificarFondos(fondos);
                cout << "Compra realizada!" << endl;
            }



            precio = 0;
            cantCompra = 0;

            cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
            cin >> mostrarMas,
                cout << endl;

            switch(mostrarMas)
            {
            case '1':
                tipoDeProducto = 0;
                break;
            case '0':
                break;
            default:
                OpcionNoValida();
                mostrarMas ='1';
                break;
            }
        }
        else
        {
            OpcionNoValida();
            mostrarMas ='1';

        }

    }
    while(mostrarMas == '1');
}

