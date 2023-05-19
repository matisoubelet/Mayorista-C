#include<iostream>
#include "ListadoHypermarket.h"
using namespace std;

void ListadoHypermarket::cargarProducto()
{
    FILE *p;
    bool cargOtro = true;

    p = fopen("listadoHypermarket.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    while(cargOtro){
        Producto producto;
        producto.Cargar();
        cout << "========================" << endl;
        fwrite(&producto, sizeof(Producto), 1, p);
        cout << "¡Se ha guardado el producto exitosamente!" << endl;
        cout << "¿Quiere cargar otro producto? (Si = 1 | No = 0): ";
        cin >> cargOtro;
        cout << endl;
        cout << "========================" << endl;
    }
    fclose(p);
}

void ListadoHypermarket::listadoProductos(int tipoDeProducto){

    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL)
        {
            cout << "No se ha podido abrir el archivo." << endl;
            fclose(p);
            return;
        }

    while(fread(&producto, sizeof(Producto), 1, p) != 0){

        if(producto.getTipoDeProducto() == tipoDeProducto){
            producto.Mostrar();
        }

    }

    fclose(p);
}
