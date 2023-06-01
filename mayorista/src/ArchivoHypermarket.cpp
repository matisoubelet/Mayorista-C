#include "ArchivoHypermarket.h"

void ArchivoHypermarket::cargarProducto() {
    FILE *p;
    bool cargOtro = true;

    p = fopen("listadoHypermarket.dat", "ab");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    while(cargOtro) {
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

void ArchivoHypermarket::listadoProductos(int tipoDeProducto ) {
    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return ;
    }

    if(tipoDeProducto==0) {
        while(fread(&producto, sizeof(Producto), 1, p) != 0) {
            producto.Mostrar();
            cout<<"------------"<<endl;
        }
    } else {
        while(fread(&producto, sizeof(Producto), 1, p) != 0) {
            if(producto.getTipoDeProducto() == tipoDeProducto) {
                producto.Mostrar();
            }
        }
    }


    cout << "Fondos: " << mostrarFondos() << endl;
    system("pause");

    fclose(p);
    return ;
}

void ArchivoHypermarket::modificarFondos(float monto) {

    FILE *p;

    p = fopen("fondosHypermarket.dat", "rb+");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo fondosHypermarket." << endl;
        fclose(p);
        return;
    }

    fseek(p, ftell(p)-sizeof(float),SEEK_SET);
    fwrite(&monto, sizeof(float), 1, p);
    fclose(p);
}

float ArchivoHypermarket::mostrarFondos() {

    FILE *p;
    float fondos;

    p = fopen("fondosHypermarket.dat", "rb");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return -1;
    }

    fread(&fondos, sizeof (float), 1, p);
    fclose(p);
    return fondos;
}

void ArchivoHypermarket::modificarInventario(bool aumentar, int idProducto, int tipoProducto, int cant) {

    Producto producto;
    FILE *p;
    int aux;

    p = fopen("listadoHypermarket.dat", "rb+");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo." << endl;
        fclose(p);
        return;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0) {
        if(producto.getTipoDeProducto() == tipoProducto && producto.getID() == idProducto) {
            aux = producto.getCantidad();

            producto.setCantidad(aux);


            if(aumentar == true) { /// Si es Bool es verdadero, suma la cantidad de ese producto en la cantidad
                aux += cant;
            } else {                 /// Si el bool es falso, resta la cantidad de ese producto en la cantidad.
                aux -= cant;
            }

            fseek(p, ftell(p)-sizeof(Producto),SEEK_SET);
            fwrite(&producto, sizeof (Producto), 1, p);
        }
    }

    fclose(p);
}


float ArchivoHypermarket::precioProducto(int idCompra, int tipoProd) {

    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo listadoHypermarket." << endl;
        fclose(p);
        return -1;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0) {
        if(producto.getTipoDeProducto()==tipoProd) {
            if(idCompra == producto.getID()) {
                producto.Mostrar();
                fclose(p);
                return producto.getPrecio();
            }
        }
    }
    fclose(p);
    return -2;
}


int ArchivoHypermarket::stock(int idCompra, int tipoProd) {


    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL) {
        cout << "No se ha podido abrir el archivo listadoHypermarket." << endl;
        fclose(p);
        return -1;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0) {
        if(producto.getTipoDeProducto()==tipoProd) {
            if(idCompra == producto.getID()) {
                producto.Mostrar();
                fclose(p);
                return producto.getCantidad();
            }
        }
    }

    fclose(p);
    return -2;
}
