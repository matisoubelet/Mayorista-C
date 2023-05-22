#include <iostream>
#include "Hypermarket.h"
#include "MenuABM.h"
#include <cstring>
#include <cstdlib>
#include "Empleado.h"
using namespace std;

void MenuABM::CargarMenuAdmin()
{

    do
    {
        cout << "+===================+" << endl;
        cout << "|     -AMB DE EMPLEADOS-" << endl;
        cout << "| 1 - ALTA" << endl;
        cout << "| 2 - BAJA" << endl;
        cout << "| 3 - MODIFICAR" << endl;
        cout << "| 4 - LISTAR VINCULADOS" << endl;
        cout << "| 5 - LISTAR DESVINCULADOS" << endl;
        cout << "| 6 - LISTAR PERMISOS" << endl;
        cout << "|                  " << endl;
        cout << "| 0 - SALIR" << endl;
        cout << "+===================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR: ";
        cin >> opcion;
        cout << endl;

        while(opcion < '0' || opcion > '6')
        {

            OpcionNoValida();
            cin >> opcion;
            cout << endl;

        }

        switch(opcion)
        {

        case '1':
            AltaEmpleado();
            break;

        case '2':
            cout<<"Ingrese el Legajo del empleado a dar de baja: "<<endl;
            int leg;
            cin >> leg;
            if(BajaEmpleado(leg)!=1)
            {
                cout<<"No se pudo dar de baja el empleado"<<endl;
            }
            break;

        case '3':
            ModificarEmpleado();
            break;

        case '4':
            ListarEmpleadosActivos();
            break;

        case '5':
            ListarEmpleadosInactivos();
            break;

        case '6':
            ListadoPermisos();
            break;
        }

    }
    while(opcion != 0);

}

void MenuABM::AltaEmpleado()
{

    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado=fopen("Empleados.dat","ab");                                  /// ESTA FUNCION DEBERIA SER DE OTRO ARCHIVO "LISTADOEMPLEADO.H"

    if(pEmpleado==NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO EMPLEADO" << endl;
        fclose(pEmpleado);
        return ;
    }

    empleado.Cargar();
    if(BuscarEmpleado(empleado.getDni())==0)
    {
        fwrite(&empleado, sizeof (Empleado),1,pEmpleado);
        cout<<"EMPLEADO REGISTRADO CON EXITO"<<endl;
    }
    else
    {
        cout<<"EMPLEADO NO AGREGADO"<<endl;
    }

    fclose(pEmpleado);
    return;
}

int MenuABM::BuscarEmpleado(int dni)
{
    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado = fopen("Empleados.dat","rb");

    if(pEmpleado == NULL)
    {
        cout << "ERROR DE LECTURA, NO SE PUDO BUSCAR AL EMPLEADO" << endl;
        fclose(pEmpleado);
        return -1;
    }

    while(fread(&empleado,sizeof(Empleado),1,pEmpleado)==1)
    {
        if(empleado.getDni()==dni)
        {
            cout << "EL EMPLEADO YA SE ENCUENTRA REGISTRADO" << endl;
            fclose(pEmpleado);
            return 1;
        }

    }
    cout << "EL EMPLEADO NO SE ENCUENTRA REGISTRADO" << endl;
    fclose(pEmpleado);
    return 0;

}


int MenuABM::BajaEmpleado(int legajo)
{
    FILE *p;
    Empleado empleado;

    int escribio;
    p=fopen("Empleados.dat","rb+");

    if(p==NULL)
    {
        cout<<"ERROR DE LECTURA, NO SE PUDO ABRIR EL ARCHIVO";
        return -1;
    }

    while(fread(&empleado, sizeof (Empleado), 1, p)==1)
    {
        if(legajo == empleado.getLegajo())
        {
            empleado.setEstado(false);
            fseek(p, ftell(p)-sizeof (Empleado), 0);
            escribio=fwrite(&empleado, sizeof (Empleado), 1, p);
            fclose(p);
            return escribio;
        }
    }
    fclose(p);
    return -2;
}



void MenuABM::ModificarEmpleado()
{


}

bool MenuABM::ListarEmpleadosActivos()
{
    FILE* p;
    Empleado empleado;

    p = fopen("Empleados.dat","rb");

    if(p == NULL)
    {
        cout << "ERROR DE LECTURA, NO SE PUDO ABIR EL ARCHIVO" << endl;
        fclose(p);
        return false;
    }

    while(fread(&empleado,sizeof(Empleado),1,p)==1)
    {

        if(empleado.GetEstado()==true)
        {
            empleado.Mostrar();
        }
    }
    fclose(p);
    return true;
}

bool MenuABM::ListarEmpleadosInactivos()
{
    FILE* p;
    Empleado empleado;

    p = fopen("Empleados.dat","rb");

    if(p == NULL)
    {
        cout << "ERROR DE LECTURA, NO SE PUDO ABIR EL ARCHIVO" << endl;
        fclose(p);
        return false;
    }

    while(fread(&empleado,sizeof(Empleado),1,p)==1)
    {

        if(empleado.GetEstado()==false)
        {
            empleado.Mostrar();
        }
    }
    fclose(p);
    return true;
}

void MenuABM::ListadoPermisos()
{

    cout << "El empleado tendra los permisos que le asiga su nivel, asi como todos los anteriores." << endl << endl;
    cout << "+================================================================================+" << endl;
    cout << "Nivel 0: Limpieza" << endl;                                                                                                        ///Empleado de Limpieza
    cout << "Nivel 1: Apertura y cierre del local. Reposicion de gondolas. Atencion al cliente." << endl;                 /// Empleado de comercio
    cout << "Nivel 2: Manejo de caja registradora. Cierre Z." << endl;                                                              /// Empleado de comercio+
    cout << "Nivel 3: Manejo de Stock con Proveedores. Manejo de sueldo" << endl;                                       /// Gerente
    cout << "Nivel 4: Contratacion o Despido de personal." << endl;                                                             /// Jefe
    cout << "+================================================================================+" << endl;
    system("pause");
    system("cls");
}
