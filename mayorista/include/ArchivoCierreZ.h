#ifndef ARCHIVOCIERREZ_H
#define ARCHIVOCIERREZ_H
#include "Hypermarket.h"
#include "Fecha.h"

class ArchivoCierreZ
{
    private:


    public:

        int hacerCierreZ(Fecha fecha, float totalFondos);
        int leerUltimoArchivo();
        int leerUltimaSemana();

        Fecha cambioDeFecha(int dia, int mes, int anio);
};

#endif // ARCHIVOCIERREZ_H
