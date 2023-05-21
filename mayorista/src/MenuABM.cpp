#include <iostream>
#include "Hypermarket.h"
#include "MenuABM.h"
#include <cstring>
#include <cstdlib>
#include "Empleado.h"
using namespace std;

void MenuABM::CargarMenuAdmin() {

    do {
        cout << "+===================+" << endl;
        cout << "|     -AMB DE EMPLEADOS-" << endl;
        cout << "| 1 - ALTA" << endl;
        cout << "| 2 - BAJA" << endl;
        cout << "| 3 - MODIFICAR" << endl;
        cout << "| 4 - LISTAR VINCULADOS" << endl;
        cout << "| 5 - LISTAR DESVINCULADOS" << endl;
        cout << "|                  " << endl;
        cout << "| 0 - SALIR" << endl;
        cout << "+===================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR: ";
        cin >> opcion;
        cout << endl;

        while(opcion < '0' || opcion > '5') {

            OpcionNoValida();
            cin >> opcion;
            cout << endl;

        }

        switch(opcion) {

        case 1:
            AltaEmpleado();
            break;

        case 2:
            cout<<"Ingrese el DNI del empleado a Dar de baja: "<<endl;
            int dni;
            cin >> dni;
            BajaEmpleado(dni);
            break;

        case 3:
            ModificarEmpleado();
            break;

        case 4:
            ListarVinculados();
            break;

        case 5:
            ListarDesvinculados();
            break;

        }

    } while(opcion != 0);

}

void MenuABM::AltaEmpleado() {

    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado=fopen("Empleados.dat","ab");

    if(pEmpleado==NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO EMPLEADO" << endl;
        fclose(pEmpleado);
        return ;
    }

    empleado.Cargar();
    if(BuscarEmpleado(empleado.getDni())==0) {
        fwrite(&empleado, sizeof (Empleado),1,pEmpleado);
        cout<<"EMPLEADO REGISTRADO CON EXITO"<<endl;
    } else {
        cout<<"EMPLEADO NO AGREGADO"<<endl;
    }

    fclose(pEmpleado);
    return;
}

int MenuABM::BuscarEmpleado(int dni) {
    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado = fopen("Empleados.dat","rb");

    if(pEmpleado == NULL) {
        cout << "ERROR DE LECTURA, NO SE PUDO BUSCAR AL EMPLEADO" << endl;
        fclose(pEmpleado);
        return -1;
    }

    while(fread(&empleado,sizeof(Empleado),1,pEmpleado)==1) {
        if(empleado.getDni()==dni) {
            cout << "EL EMPLEADO YA SE ENCUENTRA REGISTRADO" << endl;
            fclose(pEmpleado);
            return 1;
        }

    }
    cout << "EL EMPLEADO NO SE ENCUENTRA REGISTRADO" << endl;
    fclose(pEmpleado);
    return 0;

}



void MenuABM::BajaEmpleado(int dni) {


    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado = fopen("Empleados.dat","rb+");

    if(pEmpleado == NULL) {
        cout << "ERROR DE LECTURA, NO SE PUDO ABRIR EL ARCHIVO" << endl;
        fclose(pEmpleado);
        return;
    }

    while(fread(&empleado,sizeof(Empleado),1,pEmpleado)==1) {
        if(empleado.getDni()==dni) {
            empleado.setEstado(false);
            fwrite(&empleado, sizeof (Empleado), 1, pEmpleado);
            break;
        }
    }

    fclose(pEmpleado);
    return ;
}


void MenuABM::ModificarEmpleado() {


}

void MenuABM::ListarVinculados() {
    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado = fopen("Empleados.dat","rb");

    if(pEmpleado == NULL) {
        cout << "ERROR DE LECTURA, NO SE PUDO ABIR EL ARCHIVO" << endl;
        fclose(pEmpleado);
        return;
    }

    while(fread(&empleado,sizeof(Empleado),1,pEmpleado)==1) {

        if(empleado.GetEstado()==true) {
            empleado.Mostrar();
        }
    }
    fclose(pEmpleado);
    return ;
}

void MenuABM::ListarDesvinculados() {
    FILE* pEmpleado;
    Empleado empleado;

    pEmpleado = fopen("Empleados.dat","rb");

    if(pEmpleado == NULL) {
        cout << "ERROR DE LECTURA, NO SE PUDO ABIR EL ARCHIVO" << endl;
        fclose(pEmpleado);
        return;
    }

    while(fread(&empleado,sizeof(Empleado),1,pEmpleado)==1) {

        if(empleado.GetEstado()==false) {
            empleado.Mostrar();
        }
    }
    fclose(pEmpleado);
    return ;
}
