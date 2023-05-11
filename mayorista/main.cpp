#include <iostream>
#include "Hypermarket.h"
using namespace std;

int main()
{
   /*
   instancia Proveedor
   cargamos todo lo necesario del proovedor a mano o usando la libreria random


   instancia de nuestro local
   se le pide por el constructor los productos al proveedor, en caso que no tenga lo que le pedimos, que sea
   por un constructor default
   */

   Hypermarket local;

   local.menu();

    return 0;
}
