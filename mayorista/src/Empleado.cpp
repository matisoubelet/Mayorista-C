#include<iostream>
#include "Empleado.h"
#include <cstring>
using namespace std;


///DNI
void Empleado::setDni(int dni)
{
    _dni = dni;
}
int Empleado::getDni()
{
    return _dni;
}

///NOMBRRE
void Empleado::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}

const char* Empleado::getNombre()
{
    return _nombre;
}

///APELLIDO
void Empleado::setApellido(const char* apellido)
{
    strcpy(_apellido, apellido);
}

const char* Empleado::getApellido()
{
    return _apellido;
}

///LEGAJO
void Empleado::setLegajo(int legajo)
{
    _legajo = legajo;
}
int Empleado::getLegajo()
{
    return _legajo;
}

///SUELDO
void Empleado::setSueldo(float sueldo)
{
    _sueldo = sueldo;
}
float Empleado::getSueldo()
{
    return _sueldo;
}


///TAREAS
void Empleado::setTareas(const char* tareas)
{
    strcpy(_tareas, tareas);
}

const char* Empleado::getTareas()
{
    return _tareas;
}

///PERMISOS
void Empleado::setPermisos(int permisos)
{
    _permisos = permisos;
}

int Empleado::getPermisos()
{
    return _permisos;
}


///ACTIVO
void Empleado::setEstado(bool act)
{
    _estado=act;
}
bool Empleado::GetEstado()
{
    return _estado;
}

void Empleado::Cargar()
{
    cout << "NOMBRE DEL EMPLEADO: " << endl;
    cin.getline(_nombre, 30);
    cin.ignore();
    cout << endl;
    cout << "APELLIDO DEL EMPLEADO: " << endl;
    cin.getline(_apellido, 30);
    cin.ignore();
    cout << endl;
    cout << "DNI: " << endl;
    cin>>_dni;
    cout << endl;
    cout << "NUMERO DE LEGAJO: " << endl;
    cin>>_legajo;
    cout << endl;
    cout << "SUELDO A PERCIBIR: " << endl;
    cin>>_sueldo;
    cout << endl;
    cout << "TAREA/S QUE VA A REALIZAR: " << endl;
    cin.getline(_tareas, 100);
    cin.ignore();
    cout << endl;
    cout << "PERMISOS DEL EMPLEADO: " << endl;
    cin >> _permisos;
    cout << endl;
    _estado=true;
}

void Empleado::Mostrar()
{

    cout << "NOMBRE DEL EMPLEADO: " << getNombre() << endl;
    cout << "APELLIDO DEL EMPLEADO: " << getApellido() << endl;
    cout << "DNI: " << getDni()<< endl;
    cout << "LEGAJO: " << getLegajo() <<endl;
    cout << "SUELDO A PERCIBIR: " << getSueldo()<< endl;
    cout << "TAREA/S QUE VA A REALIZAR: " << getTareas() << endl;
    cout << "PERMISOS DEL EMPLEADO: " << getPermisos()<< endl;
    cout << "ESTADO ACTUAL DEL EMPLEADO: " << _estado << endl;
    cout<<"---------------------------------"<<endl;

}
