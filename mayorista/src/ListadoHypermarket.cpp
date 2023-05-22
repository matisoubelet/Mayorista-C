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

    while(cargOtro)
    {
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

void ListadoHypermarket::listadoProductos(int tipoDeProducto)
{

    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0)
    {

        if(producto.getTipoDeProducto() == tipoDeProducto)
        {
            producto.Mostrar();
        }

    }

    fclose(p);
}

void ListadoHypermarket::cargarFondos()
{

    FILE *p;
    float fondos;
    Hypermarket fondosLocal;

    p = fopen("fondosHypermarket.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    cout << "Fondos del local: ";
    cin >> fondos;
    fondosLocal.setFondos(fondos);
    cout << endl;

    fwrite(&fondosLocal, sizeof(Hypermarket), 1, p);
    fclose(p);
}

void ListadoHypermarket::modificarFondos(float monto)
{

    FILE *p;
    Hypermarket local;
    int totalFondos;

    p = fopen("fondosHypermarket.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    fread(&local, sizeof (Hypermarket), 1, p);

    local.setFondos(monto);
    fseek(p, ftell(p)-sizeof (Hypermarket), 0);
    fwrite(&local, sizeof (Hypermarket), 1, p);

    fclose(p);

}

float ListadoHypermarket::fondos()
{

    FILE *p;
    Hypermarket local;

    p = fopen("fondosHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return -1;
    }

    fread(&local, sizeof (Hypermarket), 1, p);
    local.getFondos();
    fclose(p);
}
