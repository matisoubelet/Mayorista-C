#include<iostream>
using namespace std;
#include "ArchivoCierreZ.h"

int ArchivoCierreZ::hacerCierreZ(Fecha fecha, float totalFondos)  // Aca faltaria agregar que verifique que la fecha no se repita
{
    FILE *l, *f;
    Hypermarket local;
    Fecha fechaArchivo;
    int dia, mes, anio;
    bool fechaRepetida = false;

    l = fopen("cierreZ.dat", "rb+");
    if(l == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    f = fopen("fechas.dat", "rb+");
    if(f == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    do
    {
        while(fread(&fechaArchivo, sizeof(Fecha), 1, f) != 0)
        {
            if(fechaArchivo.getDia() == fecha.getDia() && fechaArchivo.getMes() == fecha.getMes() && fechaArchivo.getAnio() == fecha.getAnio())
            {
                fechaRepetida = true;
            }
        }

        if(fechaRepetida == true)
        {
            cout << "La fecha que introdujo ya era existente, por favor cargue una fecha correcta: " << endl;
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            cout << "Anio: ";
            cin >> anio;
            fecha = ArchivoCierreZ::cambioDeFecha(dia, mes, anio);
            fseek(f, 0, SEEK_SET);
            fechaRepetida = false;
        }
        else
        {
            local.setVentasTotales(totalFondos);
            fwrite(&local, sizeof(Hypermarket), 1, l);
            fwrite(&fecha, sizeof(Fecha), 1, f);
            fechaRepetida = false;
        }
    }while(fechaRepetida == true);

    fclose(l);
    fclose(f);
}

int ArchivoCierreZ::leerUltimoArchivo()
{

    FILE *l, *f;
    Hypermarket local;
    Fecha fechaArchivo;

    l = fopen("cierreZ.dat", "rb");
    if(l == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    f = fopen("fechas.dat", "rb");
    if(f == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    fseek(l, -(sizeof(local)), SEEK_END);
    fseek(f, -(sizeof(fechaArchivo)), SEEK_END);
    while(fread(&local, sizeof(Hypermarket), 1, l) != 0 && fread(&fechaArchivo, sizeof(Fecha), 1, f) != 0)
    {

        cout << "+========================+" << endl;
        cout << "Fecha del CierreZ: " << fechaArchivo.getDia() << "/" << fechaArchivo.getMes() << "/" << fechaArchivo.getAnio() << endl;
        cout << "Total recaudado: " << local.getVentasTotales() << endl;
        cout << "+========================+" << endl;

    }
    system("pause");
    system("cls");
    fclose(l);
    fclose(f);
}

int ArchivoCierreZ::leerUltimaSemana()
{

    FILE *l, *f;
    Hypermarket local;
    Fecha fechaArchivo;

    l = fopen("cierreZ.dat", "rb");
    if(l == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    f = fopen("fechas.dat", "rb");
    if(f == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    fseek(l, -(sizeof(local))*2, SEEK_END);
    fseek(f, -(sizeof(fechaArchivo))*2, SEEK_END);
    while(fread(&local, sizeof(Hypermarket), 1, l) != 0 && fread(&fechaArchivo, sizeof(Fecha), 1, f) != 0)
    {

        cout << "+========================+" << endl;
        cout << "Fecha del CierreZ: " << fechaArchivo.getDia() << "/" << fechaArchivo.getMes() << "/" << fechaArchivo.getAnio() << endl;
        cout << "Total recaudado: " << local.getVentasTotales() << endl;
        cout << "+========================+" << endl;

    }
    system("pause");
    system("cls");
    fclose(l);
    fclose(f);
}

Fecha ArchivoCierreZ::cambioDeFecha(int dia, int mes, int anio)
{

    Fecha fechaNueva(dia, mes, anio);
    return fechaNueva;

}
