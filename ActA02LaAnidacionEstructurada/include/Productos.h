//Archivo Cabeceras para definir struct de Productos
//Guardias para evitar doble integración en compilado
#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include "Fecha.h"
//Definir longitud de nombre de producto
#define Max_Length 12
#define Max_Productos 500
#define Max_Cod 13
//Clase para Definir Productos
class Productos{
    //Variables-Struct privadas
    private:
        //Struct para registro de Artículos
        struct Producto{
            //Datos de Producto
            char Codigo[Max_Cod];
            char Nombre[Max_Length]={'\0'};
            float Precio=0;
            float Costo=0;
            float Peso=0;
            float Mayoreo=0;
            float Menudeo=0;
            Fecha Ingreso;
            int Piezas=0;
            float Valor=0;
        };
        Producto NumeroArticulos[Max_Productos];
    //Métodos de Clase
    public:
        //Constructor
        Productos(void);
        //Constructor Copia
        Productos(const Productos &ProductosOriginal);
        //Destructor
        ~Productos();
        //Setters
        //Setter para Nombre del Producto
        void setNombre(int indice,char * NombreAsignado);
        //Setter para Precio del Producto
        void setPrecio(int indice,float PrecioAsignado);
        //Setter para Costo del Producto
        void setCosto(int indice,float CostoAsignado);
        //Setter para Piezas del Producto
        void setPiezas(int indice,int PiezasAsignadas);
        //Setter para Valor del Producto
        void setValor(int indice,float ValorAsignado);
        //Setter para Peso del Producto
        void setPeso(int indice,float PesoAsignado); 
        //Setter para Mayoreo del Producto
        void setMayoreo(int indice,float MayoreoAsignado); 
        //Setter para Menudeo del Producto
        void setMenudeo(int indice,float MenudeoAsignado);
        //Setter para Codigo del Producto
        void setCodigo(int indice,char * CodigoAsignado);
        //Setter para Fecha Ingreso del Producto
        void setFechaIngreso(int indice,char* FechaIngresoAsignada); 
        //Getters
        //Getter Nombre del Artículo
        char* getNombre(int indice);
        //Getter Precio del Artículo
        float getPrecio(int indice);
        //Getter Costo del Artículo
        float getCosto(int indice);
        //Getter Valor del Artículo
        float getValor(int indice);
        //Getter Piezas del Artículo
        int getPiezas(int indice);
        //Getter para Peso del Producto
        float getPeso(int indice); 
        //Getter para Mayoreo del Producto
        float getMayoreo(int indice); 
        //Getter para Menudeo del Producto
        float getMenudeo(int indice);
        //Getter para Codigo del Producto
        char* getCodigo(int indice);
        //Getter para Fecha Ingreso del Producto
        char* getFechaIngreso(int indice); 
};
#endif