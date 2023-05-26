#include <iostream>
#include "Hypermarket.h"
#include "Producto.h"
#include "ArchivoProveedor.h"
#include "ArchivoHypermarket.h"
#include "ArchivoEmpleados.h"
using namespace std;

int main()
{
    //MenuABM menu;
    //menu.CargarMenuAdmin();

    Hypermarket local;
    ArchivoHypermarket localarchivo;
    localarchivo.modificarFondos(2000);
    local.menu();

    //ListadoHypermarket listado;
    //listado.cargarFondos();

    return 0;
}
