#include "ArchivoProveedor.h"


void ArchivoProveedor::cargarProducto()
{
    FILE *p;
    bool cargOtro = true;

    p = fopen("listadoProductos.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo ListadoProductos." << endl;
        fclose(p);
        return;
    }

    while(cargOtro){
        Producto producto;
        producto.Cargar();
        cout << "========================" << endl;
        fwrite(&producto, sizeof(Producto), 1, p);
        cout << "¡Se ha guardado el producto exitosamente!" << endl;
        cout << "¿Quiere cargar otro producto? (Si = 1 | No = 0): ";
        cin >> cargOtro;
        cout << endl;
        cout << "========================" << endl;
    }
    fclose(p);
}

void ArchivoProveedor::listadoProductos(int tipoDeProducto){

    Producto producto;
    FILE *p;

    p = fopen("listadoProductos.dat", "rb");
    if(p == NULL)
        {
            cout << "No se ha podido abrir el archivo ListadoProductos." << endl;
            fclose(p);
            return;
        }

    while(fread(&producto, sizeof(Producto), 1, p) != 0){

        if(producto.getTipoDeProducto() == tipoDeProducto){
            producto.Mostrar();
        }

    }

    fclose(p);
}

float ArchivoProveedor::precioProducto(int idCompra){

    Producto producto;
    FILE *p;

    p = fopen("listadoProductos.dat", "rb");
    if(p == NULL)
        {
            cout << "No se ha podido abrir el archivo ListadoProductos." << endl;
            fclose(p);
            return -1;
        }

    while(fread(&producto, sizeof(Producto), 1, p) != 0){

        if(idCompra == producto.getID()){
            producto.Mostrar();
            fclose(p);
            return producto.getPrecio();
        }
    }

    return -2;
}

void ArchivoProveedor::mostrarProducto()
{
    int tipoDeProducto;
    char mostrarMas='0';

    do
    {
        system("cls");
        cout << "+=====================+" << endl;
        cout << "| 1 - BEBIDA          |" << endl;
        cout << "| 2 - ROPA            |"<< endl;
        cout << "| 3 - COMIDA          |" << endl;
        cout << "| 4 - ART. LIMPIEZA   |" << endl;
        cout << "+=====================+" << endl;
        cout << "Que tipo de producto esta buscando?: ";
        cin >> opcion;
        cout << endl << endl;

        if(opcion>'0' && opcion<'5')
        {
            tipoDeProducto=isdigit(opcion);
            listadoProductos(tipoDeProducto);
            mostrarMas = '0';
        }
        else
        {
            OpcionNoValida();
            mostrarMas ='1';
        }
    }
    while(mostrarMas == '1');
}


