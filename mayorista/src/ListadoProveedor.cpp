#include<iostream>
#include "ListadoProveedor.h"
using namespace std;

void ListadoProveedor::cargarProducto()
{

    Producto producto;
    FILE *p;
    char nombre[20];
    float precio;
    int ID, tipoDeProducto, cargOtro = 1;

    p = fopen("listadoProductos.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }
    while(cargOtro == 1){

        cout << "Nombre: ";
        cin >> nombre;
        cout << endl;
        producto.setNombre(nombre);

        cout << "Precio: ";
        cin >> precio;
        cout << endl;
        producto.setPrecio(precio);

        cout << "ID: ";
        cin >> ID;
        cout << endl;
        producto.setID(ID);

        cout << "Tipo de Producto: ";
        cin >> tipoDeProducto;
        cout << endl;
        producto.setTipoDeProducto(tipoDeProducto);

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

void ListadoProveedor::listadoProductos(int tipoDeProducto){

    Producto producto;
    FILE *p;

    p = fopen("listadoProductos.dat", "rb");
    if(p == NULL)
        {
            cout << "No se ha podido abrir el archivo." << endl;
            fclose(p);
            return;
        }

    while(fread(&producto, sizeof(Producto), 1, p) != 0){

        if(producto.getTipoDeProducto() == tipoDeProducto){

            cout << "----------------------" << endl;
            cout << "Nombre: ";
            producto.getNombre();
            cout << endl;
            cout << "Precio: " << producto.getPrecio() << endl;
            cout << "ID: " << producto.getID() << endl;
            cout << "Tipo de Producto: " << producto.getTipoDeProducto() << endl;
            cout << "----------------------" << endl << endl;

        }

    }

    fclose(p);
}
