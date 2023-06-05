#include "Hypermarket.h"

<<<<<<< HEAD
void Hypermarket::setFondos(float fondos)
{
    _fondos = fondos;
}

float Hypermarket::getFondos()
{
    return _fondos;
}

void Hypermarket::menu()
{
    do
    {
=======

void Hypermarket::menu() {
    ArchivoEmpleados empleados;
    do {
>>>>>>> mayorista
        system("cls");
        cout << "+=====================+" << endl;
        cout << "|-----HYPERMARKET-----|" << endl;
        cout << "| 1 - COMPRAR         |" << endl;
        cout << "| 2 - VENDER          |" << endl;
        cout << "| 3 - PAGOS           |" << endl;
        cout << "| 4 - CIERRE Z        |" << endl;
        cout << "| 5 - EMPLEADOS       |" << endl;
        cout << "| 0 - SALIR           |" << endl;
        cout << "+=====================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR: "<< endl;
        cin >> opcion;
        cout << endl;

<<<<<<< HEAD
        while(opcion < '0' || opcion > '5')
        {
=======
        while(opcion < '0' || opcion > '5') {
>>>>>>> mayorista
            OpcionNoValida();
            cin >> opcion;
            cout << endl;
        }

<<<<<<< HEAD
        switch(opcion)
        {
=======
        switch(opcion) {
>>>>>>> mayorista
        case '1':
            while(Hypermarket::comprar());
            break;
        case '2':
            while(Hypermarket::vender());
            break;
        case '3':
            /// Hypermarket::pagos();
            break;

        case '4':
            /// Hypermarket::cierreZ();
            break;

        case '5':
            empleados.MenuAdmin();
            break;
<<<<<<< HEAD
        }
    }
    while(opcion != '0');
}

void Hypermarket::comprar()
{
    float fondos, precio;
    int idCompra, UoB, cantCompra;
    char mostrarMas = '0';
    Proveedor proveedor;
    ListadoProveedor listado;
    ListadoHypermarket local;

    proveedor.mostrar();

    cout << "Ingrese el ID del producto que desee comprar: ";
    cin >> idCompra;
    cout << endl;

    while(idCompra < 1 || idCompra > 10)
    {
        cout << "Ese ID no es valido, asegurese que se encuentre entre el 1 y el 10" << endl;
        cout << "Vuelva a ingresar el ID por favor: ";
        cin >> idCompra;
        cout << endl;
    }

    precio = listado.enseniarCompra(idCompra);
    fondos = local.mostrarFondos();
    cout << "FONDOS: " << fondos << endl;

    cout << "Desea comprar en unidades o en bultos (10 unidades): (Unidades: 1 | Bultos: 2): ";
    cin >> UoB;
    cout << endl;

    switch(UoB)
    {
    case 1:
        cout << "Cuantas unidades desea comprar?: ";
        cin >> cantCompra;
        cout << endl;
        precio *= cantCompra;
        break;
    case 2:
        cout << "Cuantos bultos desea comprar?: ";
        cin >> cantCompra;
        cout << endl;
        cantCompra *= 10;
        precio *= cantCompra;
        break;
    default:
        cout << "Opcion inexistente, la compra sera cancelada." << endl;
        break;
    }

    if(fondos-precio < 0)
    {
        cout << "La compra no puede realizarse por falta de fondos" << endl;
    }
    else
    {
        fondos -= precio;
        local.modificarFondos(fondos);
        local.modificarInventario(true, idCompra, opcion, cantCompra);
        cout << "Compra realizada!" << endl;
    }

    precio = 0;
    cantCompra = 0;

    cout << "Quiere ver mas productos? (Si = 1 | No = 0): ";
    cin >> mostrarMas,
        cout << endl;

    if(mostrarMas == '1')
    {
        proveedor.mostrar();
    }
}

void Hypermarket::inventario()
{
    int tipoProducto;
    ListadoHypermarket local;

=======


        case '0':
            return;
        }

    } while(opcion != '0');
}

bool Hypermarket::comprar() {

    int idCompra, cantCompra, tipoProd;
    char UoB;
    int bucle=0;
    bool continuar=false;
    ArchivoProveedor proveedor;
    ArchivoHypermarket archivoDelLocal;
    float fondos = archivoDelLocal.mostrarFondos();


    tipoProd = proveedor.mostrarProducto(); ///accede al menu de productos y devuelve el tipo de producto ingresado


    cout << "Ingrese el ID del producto que desee comprar: (1 a 10)"<< endl;
    cin >> idCompra;
    cout << endl;

    float precio = proveedor.precioProducto(idCompra, tipoProd);


    while (cin.fail() || idCompra<1 || idCompra>10) {
        cin.clear(); // Restablecer el estado de error
        cin.ignore(); // Ignorar el resto de la linea
        OpcionNoValida();
        cin >> idCompra;
        cout << endl;
    }

    cout << "FONDOS: " << fondos << endl;

    cout << "Desea comprar en unidades o en bultos (10 unidades): (Unidades: U | Bultos: B): "<< endl;
    cin >> UoB;
    cout << endl;
    do {
        switch(UoB) {
        case 'u':
        case 'U':
            cout << "Cuantas unidades desea comprar?: "<< endl;
            cin >> cantCompra;
            cout << endl;
            precio *= cantCompra;
            bucle = 0;
            break;
        case 'b':
        case 'B':
            cout << "Cuantos bultos desea comprar?: "<< endl;
            cin >> cantCompra;
            cout << endl;
            cantCompra *= 10;
            precio *= cantCompra;
            precio *= 0.85;
            bucle=0;
            break;
        default:
            OpcionNoValida();
            cin.clear(); // Restablecer el estado de error
            cin.ignore(); // Ignorar el resto de la linea
            cin >> UoB;
            bucle=1;
            break;
        }

    } while (bucle!=0);

    cout<<"Total de Compra : "<<precio<<endl;
    if(fondos-precio < 0) {
        cout << "La compra no puede realizarse por falta de fondos" << endl;
    } else {
        fondos -= precio;
        archivoDelLocal.modificarFondos(fondos);
        archivoDelLocal.modificarInventario(true, idCompra, tipoProd, cantCompra);
        cout << "Compra realizada!" << endl;
    }

    cout<<archivoDelLocal.mostrarFondos()<<endl;


    cout << "Quiere hacer otra compra? (Si = 1 | No = 0): "<< endl;
    cin >> continuar;
    if(continuar) {
        return true;
    } else {
        return false;
    }
}

int Hypermarket::inventario() {
    int tipoProducto;
    ArchivoHypermarket archivoDelLocal;

>>>>>>> mayorista
    system("cls");
    cout << "+=====================+" << endl;
    cout << "| 1 - BEBIDA          |" << endl;
    cout << "| 2 - ROPA            |"<< endl;
    cout << "| 3 - COMIDA          |" << endl;
    cout << "| 4 - ART. LIMPIEZA   |" << endl;
    cout << "| 0 - LISTA COMPLETA  |" << endl;
    cout << "+=====================+" << endl;
    cout << "Que tipo de producto esta buscando?: ";
    cin >> tipoProducto;

    while (cin.fail() || tipoProducto<0 || tipoProducto>4) {
        cin.clear(); // Restablecer el estado de error
        cin.ignore(); // Ignorar el resto de la linea
        OpcionNoValida();
        cin >> tipoProducto;
        cout << endl;
    }

    cout << endl << endl;
<<<<<<< HEAD
    local.listadoProductos(tipoProducto);
=======
    archivoDelLocal.listadoProductos(tipoProducto);
<<<<<<< HEAD
>>>>>>> mayorista
=======
    return tipoProducto;
>>>>>>> mayorista
}

bool Hypermarket::vender() {
    ArchivoHypermarket archivoDelLocal;

    float fondos = archivoDelLocal.mostrarFondos();

    int idCompra, cantCompra, tipoProd;
    bool continuar=false;


    tipoProd = inventario();


    cout << "Ingrese el ID del producto a vender: (1 a 10)"<< endl;
    cin >> idCompra;
    cout << endl;

    while (cin.fail() || idCompra<1 || idCompra>10) {
        cin.clear(); // Restablecer el estado de error
        cin.ignore(); // Ignorar el resto de la linea
        OpcionNoValida();
        cin >> idCompra;
        cout << endl;
    }


    float precio = archivoDelLocal.precioProducto(tipoProd, idCompra);
    fondos = archivoDelLocal.mostrarFondos();


    cout << "Unidades a vender: "<< endl;
    cin >> cantCompra;
    cout << endl;

    if(cantCompra>archivoDelLocal.stock(tipoProd, idCompra)) {
        cout<<"la venta no se pudo realizar por falta de stock"<<endl;
        return false;
    } else {
        precio *= cantCompra;
        cout<<"Total : "<<precio<<endl;
        cout<<"venta realizada con exito"<<endl;
    }


    fondos+=precio;


    archivoDelLocal.modificarFondos(fondos);
    archivoDelLocal.modificarInventario(false, idCompra, tipoProd, cantCompra);


    cout << "Desea hacer otra venta? (Si = 1 | No = 0): "<< endl;
    cin>>continuar;

    if(continuar) {
        return true;
    } else {
        return false;
    }

}
