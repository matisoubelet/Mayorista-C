#include<iostream>
#include "Hypermarket.h"
#include "Proveedor.h"
using namespace std;

void Hypermarket::setFondos(float fondos)
{
    _fondos = fondos;
}

float Hypermarket::getFondos()
{
    return _fondos;
}

void Hypermarket::menu()
{
    do
    {
        system("cls");
        cout << "+=====================+" << endl;
        cout << "|-----HYPERMARKET-----|" << endl;
        cout << "| 1 - COMPRAR         |" << endl;
        cout << "| 2 - VENDER          |" << endl;
        cout << "| 3 - PAGOS           |" << endl;
        cout << "| 4 - INVENTARIO      |" << endl;
        cout << "| 5 - CIERRE Z        |" << endl;
        cout << "| 0 - SALIR           |" << endl;
        cout << "+=====================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR: ";
        cin >> opcion;
        cout << endl;

        while(opcion < '0' || opcion > '5')
        {
            OpcionNoValida();
            cin >> opcion;
            cout << endl;
        }

        switch(opcion)
        {
        case '1':
            Hypermarket::comprar();
            break;
        case '2':
            /// Hypermarket::vender();
            break;
        case '3':
            /// Hypermarket::pagos();
            break;
        case '4':
            Hypermarket::inventario();
            break;
        case '5':
            /// Hypermarket::cierreZ();
            break;
        }
    }
    while(opcion != '0');
}

void Hypermarket::comprar()
{
    float fondos, precio;
    int idCompra, UoB, cantCompra;
    char mostrarMas = '0';
    Proveedor proveedor;
    ListadoProveedor listado;
    ListadoHypermarket local;

    proveedor.mostrar();

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
    fondos = local.mostrarFondos();
    cout << "FONDOS: " << fondos << endl;

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
        local.modificarInventario(true, idCompra, opcion, cantCompra);
        cout << "Compra realizada!" << endl;
    }

    precio = 0;
    cantCompra = 0;

    cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
    cin >> mostrarMas,
        cout << endl;

    if(mostrarMas == '1')
    {
        proveedor.mostrar();
    }
}

void Hypermarket::inventario()
{
    int tipoProducto;
    ListadoHypermarket local;

    system("cls");
    cout << "+=====================+" << endl;
    cout << "| 1 - BEBIDA          |" << endl;
    cout << "| 2 - ROPA            |"<< endl;
    cout << "| 3 - COMIDA          |" << endl;
    cout << "| 4 - ART. LIMPIEZA   |" << endl;
    cout << "| 0 - LISTA COMPLETA  |" << endl;
    cout << "+=====================+" << endl;
    cout << "Que tipo de producto esta buscando?: ";
    cin >> tipoProducto;
    cout << endl << endl;
    local.listadoProductos(tipoProducto);
}

