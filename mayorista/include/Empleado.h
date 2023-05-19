#ifndef EMPLEADO_H
#define EMPLEADO_H


class Empleado
{
        private:
        char _nombre[30];
        char _apellido[30];
        int _dni;
        int _legajo;
        float _sueldo;
        char _tareas[100];
        char _permisos[100];
        bool _estado;

   public:

        ///DNI
        void setDni(int dni);
        int getDni();

        ///NOMBRE
        void setNombre(const char* nombre);
        const char *getNombre();

        ///APELLIDO
        void setApellido(const char* apellido);
        const char *getApellido();

        ///LEGAJO
        void setLegajo(int legajo);
        int getLegajo();

        ///SUELDO
        void setSueldo(float sueldo);
        float getSueldo();

        ///TAREAS
        void setTareas(const char* tareas);
        const char *getTareas();

        ///PERMISOS
        void setPermisos(const char* permisos);
        const char *getPermisos();

        ///ACTIVO
        void setEstado(bool act);
        bool GetEstado();

        ///CARGAR
        void Cargar();
        ///MOSTRAR
        void Mostrar();

};

#endif // EMPLEADO_H
