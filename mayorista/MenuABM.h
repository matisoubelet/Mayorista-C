#ifndef MENUABM_H_INCLUDED
#define MENUABM_H_INCLUDED
class MenuABM:public Menu {
public:
    void CargarMenuAdmin();
    void AltaEmpleado();
    int BuscarEmpleado(int dni);
    int BajaEmpleado(int legajo);
    void ModificarEmpleado();
    bool ListarEmpleadosActivos();
    bool ListarEmpleadosInactivos();

};


#endif // MENUABM_H_INCLUDED
