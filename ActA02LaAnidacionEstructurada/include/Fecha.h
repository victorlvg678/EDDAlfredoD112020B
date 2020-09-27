//Archivo de cabecera para manejo de fechas
#ifndef FECHA_H
#define FECHA_H
#define Max_Fecha 8
//Clase para Manejo de Fechas
class Fecha{
    //Variables de Clase
    private:
        char FechaC[Max_Fecha];
    //Métodos de Clase
    public:
        //Constructor
        Fecha(void);
        //Constructor Copia
        Fecha(const Fecha &FechaOriginal);
        //Destructor
        ~Fecha();
        //Setters
        //Función para establecer Fecha
        void setFecha(char* FechaAsignada);
        //Getters
        //Función para obtener Fecha
        char* getFecha(void);
};
#endif