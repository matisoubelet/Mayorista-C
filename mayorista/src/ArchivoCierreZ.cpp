#include<iostream>
using namespace std;
#include "ArchivoCierreZ.h"

int ArchivoCierreZ::hacerCierreZ(Fecha fecha, float totalFondos){ // Aca faltaria agregar que verifique que la fecha no se repita

    FILE *p;
    Hypermarket local;
    Fecha fechaArchivo(fecha.getDia(), fecha.getMes(), fecha.getAnio());

    p = fopen("cierreZ.dat", "rb+");
    if(p == NULL){
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }

    local.setVentasTotales(totalFondos);

    fwrite(&local, sizeof(Hypermarket), 1, p);
    fwrite(&fechaArchivo, sizeof(Fecha), 1, p);

    fclose(p);
}

int ArchivoCierreZ::leerUltimoArchivo(){

    FILE *p;
    Hypermarket local;
    Fecha fechaArchivo;

    p = fopen("cierreZ.dat", "rb");
    if(p == NULL){
        cout << "No se ha podido abrir el archivo" << endl;
        return -1;
    }
    fseek(p, -(sizeof(local) + sizeof(fechaArchivo)), SEEK_END);
    while(fread(&local, sizeof(Hypermarket), 1, p) != 0 && fread(&fechaArchivo, sizeof(Fecha), 1, p) != 0){

        cout << "+========================+" << endl;
        cout << "Fecha del CierreZ: " << fechaArchivo.getDia() << "/" << fechaArchivo.getMes() << "/" << fechaArchivo.getAnio() << endl;
        cout << "Total recaudado: " << local.getVentasTotales() << endl;
        cout << "+========================+" << endl;

    }
    system("pause");
    system("cls");
    fclose(p);
}
