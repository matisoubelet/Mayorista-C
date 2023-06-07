#ifndef FECHA_H
#define FECHA_H


class Fecha{

   public:
      Fecha();
      Fecha(int dia, int mes, int anio);

      int getDia();
      int getMes();
      int getAnio();
      void agregarDias(int cantidadDias);
      std::string toString(std::string formatoFecha = "DD/MM/YYYY");

    private:
       int _dia, _mes, _anio;

       void establecerFechaPorDefecto();
       bool esBisiesto();
       void agregarDia();
};


#endif // FECHA_H
