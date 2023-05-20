#include<iostream>
#include <chrono>
#include <thread>
#include "Proveedor.h"
using namespace std;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

void Proveedor::mostrar()
{
    int tipoDeProducto;
    char menu, mostrarMas='0';
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
        cin >> menu;
        cout << endl << endl;


        if(menu>'0' && menu<'5'){

            tipoDeProducto=isdigit(menu);
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
                cout <<"ESE VALOR ES INEXISTENTE";
                mostrarMas ='1';
                sleep_for(800ms);
                break;
            }
        }
        else{
            cout<< "ESE VALOR ES INEXISTENTE, POR FAVOR SELECCIONE OTRA OPCION: ";
            mostrarMas ='1';
            sleep_for(800ms);

        }

    }
    while(mostrarMas == '1');

}
