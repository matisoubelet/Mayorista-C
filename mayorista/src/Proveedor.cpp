<<<<<<< HEAD
#include<iostream>
<<<<<<< HEAD
#include <chrono>
#include <thread>
#include "Proveedor.h"
using namespace std;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;
=======
//#include <thread>
=======
>>>>>>> mayorista
#include "Proveedor.h"

>>>>>>> mayorista

<<<<<<< HEAD
void Proveedor::mostrar()
{
    int tipoDeProducto;
<<<<<<< HEAD
    char menu, mostrarMas='0';
=======
    char mostrarMas='0';
>>>>>>> mayorista
    ListadoProveedor listado;
    do
    {
=======
void Proveedor::menu() {

    char mostrarMas='0';
    int tipoDeProducto;
>>>>>>> mayorista

    do {
        system("cls");
        cout << "+=====================+" << endl;
        cout << "| 1 - BEBIDA          |" << endl;
        cout << "| 2 - ROPA            |"<< endl;
        cout << "| 3 - COMIDA          |" << endl;
        cout << "| 4 - ART. LIMPIEZA   |" << endl;
        cout << "+=====================+" << endl;
<<<<<<< HEAD
        cout << "Que tipo de producto esta buscando?: ";
<<<<<<< HEAD
        cin >> menu;
        cout << endl << endl;


        if(menu>'0' && menu<'5'){

            tipoDeProducto=isdigit(menu);
=======
=======

        cout << "Que tipo de producto esta buscando?: "<< endl;
>>>>>>> mayorista
        cin >> opcion;
        cout << endl << endl;

        if(opcion>'0' && opcion<'5') {
            tipoDeProducto=isdigit(opcion);

            comprar(tipoDeProducto);

<<<<<<< HEAD
            tipoDeProducto=isdigit(opcion);
>>>>>>> mayorista
            cout<<tipoDeProducto<< endl;
            listado.listadoProductos(tipoDeProducto);
=======
            cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
            cin >> mostrarMas;
>>>>>>> mayorista

            while(mostrarMas!='1'||mostrarMas!='0'){
            OpcionNoValida();
            cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
<<<<<<< HEAD
            cin >> mostrarMas,
            cout << endl;

            switch(mostrarMas){
            case '1':
                tipoDeProducto = 0;
                break;
            case '0':
                break;
            default:
<<<<<<< HEAD
                cout <<"ESE VALOR ES INEXISTENTE";
                mostrarMas ='1';
                sleep_for(800ms);
=======
               OpcionNoValida();
                mostrarMas ='1';
>>>>>>> mayorista
                break;
            }
        }
        else{
<<<<<<< HEAD
            cout<< "ESE VALOR ES INEXISTENTE, POR FAVOR SELECCIONE OTRA OPCION: ";
            mostrarMas ='1';
            sleep_for(800ms);
=======
            OpcionNoValida();
            mostrarMas ='1';
>>>>>>> mayorista
=======
            cin >> mostrarMas;
            }


        } else {
            OpcionNoValida();
            mostrarMas = '1';
            }

    } while(mostrarMas == '1');
}
>>>>>>> mayorista

void Proveedor::comprar(int tipoDeProducto) {
    int idCompra;
    int cantCompra, UoB;
    float precio, fondos;
    ListadoProveedor listado;
    ListadoHypermarket local;
    listado.listadoProductos(tipoDeProducto);

    cout << "Ingrese el ID del producto que desee comprar: (1 a 10)"<< endl;
    cin >> idCompra;
    cout << endl;

    while (cin.fail() || idCompra<1 || idCompra>10) {
        cin.clear(); // Restablecer el estado de error
        cin.ignore(); // Ignorar el resto de la l�nea
        OpcionNoValida();
        cin >> idCompra;
        cout << endl;
    }

    precio = listado.enseniarCompra(idCompra);
    fondos = local.mostrarFondos();
    cout << "FONDOS: " << fondos << endl;

    cout << "Desea comprar en unidades o en bultos (10 unidades): (Unidades: 1 | Bultos: 2): ";
    cin >> UoB;
    cout << endl;

    switch(UoB) {

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
        precio*=0.85; //se aplica descuento por compra por bulto.
        break;

    default:
        OpcionNoValida();
        cout << endl<< "La compra sera cancelada." << endl;
        break;
    }

    if(fondos-precio < 0) {
        cout << "La compra no puede realizarse por falta de fondos" << endl;
    } else {
        fondos -= precio;
        local.modificarFondos(fondos);
        local.modificarInventario(true, idCompra, opcion, cantCompra);
        cout << "Compra realizada!" << endl;
    }


}


