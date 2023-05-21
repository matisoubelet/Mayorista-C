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
#include "Proveedor.h"
using namespace std;
//using namespace this_thread;

>>>>>>> mayorista

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

        system("cls");
        cout << "+=====================+" << endl;
        cout << "| 1 - BEBIDA          |" << endl;
        cout << "| 2 - ROPA            |"<< endl;
        cout << "| 3 - COMIDA          |" << endl;
        cout << "| 4 - ART. LIMPIEZA   |" << endl;
        cout << "+=====================+" << endl;
        cout << "Que tipo de producto esta buscando?: ";
<<<<<<< HEAD
        cin >> menu;
        cout << endl << endl;


        if(menu>'0' && menu<'5'){

            tipoDeProducto=isdigit(menu);
=======
        cin >> opcion;
        cout << endl << endl;


        if(opcion>'0' && opcion<'5'){

            tipoDeProducto=isdigit(opcion);
>>>>>>> mayorista
            cout<<tipoDeProducto<< endl;
            listado.listadoProductos(tipoDeProducto);

            cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
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

        }

    }
    while(mostrarMas == '1');

}
