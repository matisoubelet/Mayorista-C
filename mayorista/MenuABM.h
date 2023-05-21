#ifndef MENUABM_H_INCLUDED
#define MENUABM_H_INCLUDED
class MenuABM:public Menu {
public:
    void CargarMenuAdmin();
    void AltaEmpleado();
    int BuscarEmpleado(int dni);
    void BajaEmpleado(int dni);
    void ModificarEmpleado();
    void ListarVinculados();
    void ListarDesvinculados();

};


#endif // MENUABM_H_INCLUDED
