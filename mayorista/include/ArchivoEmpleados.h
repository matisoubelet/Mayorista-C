#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Empleado.h"
#include "Hypermarket.h"
using namespace std;

class ArchivoEmpleados:public Menu {
public:
    void MenuAdmin();
    void AltaEmpleado();
    int BuscarEmpleado(int dni);
    int BajaEmpleado(int legajo);
    void ModificarEmpleado();
    bool ListarEmpleadosActivos();
    bool ListarEmpleadosInactivos();
    void ListadoPermisos();
};


#endif // ARCHIVOEMPLEADOS_H_INCLUDED
