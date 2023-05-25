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

void ListadoHypermarket::listadoProductos(int tipoDeProducto = 0)
{
    Hypermarket local;
    Producto producto;
    FILE *p, *f;
    float fondos;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    f = fopen("fondosHypermarket.dat", "rb");
    if(f == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(f);
        return;
    }

    if(tipoDeProducto == 0)
    {

        while(fread(&producto, sizeof(Producto), 1, p) != 0)
        {
            producto.Mostrar();
        }
    }
    else
    {
        while(fread(&producto, sizeof(Producto), 1, p) != 0)
        {
            if(producto.getTipoDeProducto() == tipoDeProducto)
            {
                producto.Mostrar();
            }
        }
    }
    while(fread(&local, sizeof(Hypermarket), 1, f) != 0)
    {
        cout << "Fondos: " << local.getFondos() << endl;
    }
    system("pause");
    fclose(f);
    fclose(p);
}

void ListadoHypermarket::cargarFondos()
{

    FILE *p;
    Hypermarket fondosLocal;
    float fondos;

    p = fopen("fondosHypermarket.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    cout << "Fondos del local: ";
    cin >> fondos;
    cout << endl;
    fondosLocal.setFondos(fondos);

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

    while(fread(&local, sizeof (Hypermarket), 1, p) != 0)
    {

        local.setFondos(monto);
        fseek(p, ftell(p)-sizeof (Hypermarket), 0);
        fwrite(&local, sizeof (Hypermarket), 1, p);

    }



    fclose(p);

}

float ListadoHypermarket::mostrarFondos()
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

    while(fread(&local, sizeof (Hypermarket), 1, p) != 0)
    {
        local.getFondos();
    }
    fclose(p);
}

void ListadoHypermarket::modificarInventario(bool sumaOresta, int idProducto, int tipoProducto, int cant)
{

    Producto producto;
    FILE *p;
    int aux;

    p = fopen("listadoHypermarket.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    if(sumaOresta == true) /// Si es Bool es verdadero, suma la cantidad de ese producto en la cantidad
    {
        while(fread(&producto, sizeof(Producto), 1, p) != 0)
        {

            if(producto.getTipoDeProducto() == tipoProducto && producto.getID() == idProducto)
            {
                aux = producto.getCantidad();
                aux += cant;
                producto.setCantidad(aux);
            }

        }

    }
    else /// Si el bool es falso, resta la cantidad de ese producto en la cantidad.
    {
        while(fread(&producto, sizeof(Producto), 1, p) != 0)
        {

            if(producto.getTipoDeProducto() == tipoProducto && producto.getID() == idProducto)
            {
                aux = producto.getCantidad();
                aux -= cant;
                producto.setCantidad(aux);
            }

        }

    }

    fclose(p);
}
