#ifndef HYPERMARKET_H
#define HYPERMARKET_H
#include<iostream>
#include "Hypermarket.h"
#include "Menu.h"
#include "ArchivoHypermarket.h"
#include "ArchivoProveedor.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCierreZ.h"
#include "Fecha.h"

using namespace std;


class Hypermarket : public Menu
{
    public:

        void menu();
        bool comprar();
        bool vender();
        void pagos();
        int inventario();

        void cierreZ(bool mostrarOSumar, float venta = 0);
        void menuCierreZ(Fecha fecha);

        void setFondos(float fondos);
        float getVentasTotales();
        void setVentasTotales(float venta);

    private:

        float _ventasTotales = 0;

};

#endif // HYPERMARKET_H
