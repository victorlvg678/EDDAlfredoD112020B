//Archivo con la implementación de los Métodos de Productos
#include "../include/Productos.h"
#include <iostream>
#include <cstring>
using namespace std;
//Función Constructor
Productos::Productos(void){

}
//Función Constructor Copia
Productos::Productos(const Productos &ProductosOriginal){
    memcpy(&NumeroArticulos,ProductosOriginal.NumeroArticulos,sizeof(NumeroArticulos));
}
//Función Destructor
Productos::~Productos(){
    
}
//Setters
//Función para establecer Nombre del Producto
void Productos::setNombre(int indice,char * NombreAsignado){
    //Variable para poder medir el Nombre a Asignar
    //Variable i para contador del ciclo for
    int LongitudCadena,i;
    LongitudCadena=sizeof(NombreAsignado);
    for(i=0;i<LongitudCadena;i++){
        NumeroArticulos[indice].Nombre[i] = NombreAsignado[i];
    }
}
//Función para establecer Costo del Producto
void Productos::setCosto(int indice,float CostoAsignado){
    NumeroArticulos[indice].Costo=CostoAsignado;
}
//Función para establecer Precio del Producto
void Productos::setPrecio(int indice,float PrecioAsignado){
    NumeroArticulos[indice].Precio=PrecioAsignado;
}
//Función para establecer Valor del Producto
void Productos::setValor(int indice,float ValorAsignado){
    NumeroArticulos[indice].Valor=ValorAsignado;
}
//Función para establecer Piezas del Producto
void Productos::setPiezas(int indice,int PiezasAsignadas){
    NumeroArticulos[indice].Piezas=PiezasAsignadas;
}
//Función para establecer Peso del Producto
void Productos::setPeso(int indice,float PesoAsignado){
    NumeroArticulos[indice].Peso=PesoAsignado;
}
//Función para establecer Mayoreo del Producto
void Productos::setMayoreo(int indice,float MayoreoAsignado){
    NumeroArticulos[indice].Mayoreo=MayoreoAsignado;
}
//Función para establecer Menudeo del Producto
void Productos::setMenudeo(int indice,float MenudeoAsignado){
    NumeroArticulos[indice].Menudeo=MenudeoAsignado;
}
//Función para establecer Código del Producto
void Productos::setCodigo(int indice,char* CodigoAsignado){
    //Variable para poder medir el Nombre a Asignar
    //Variable i para contador del ciclo for
    int LongitudCadena,i;
    LongitudCadena=sizeof(CodigoAsignado);
    for(i=0;i<LongitudCadena;i++){
        NumeroArticulos[indice].Codigo[i]=CodigoAsignado[i];
    }
}
//Función para establecer Fecha de Ingreso del Producto
void Productos::setFechaIngreso(int indice,char* FechaIngresoAsignada){
    NumeroArticulos[indice].Ingreso.setFecha(FechaIngresoAsignada);
}

//Getters
//Función para Obtener Nombre del Producto
char* Productos::getNombre(int indice){
    return NumeroArticulos[indice].Nombre;
}
//Función para Obtener Costo del Producto
float Productos::getCosto(int indice){
    return NumeroArticulos[indice].Costo;
}
//Función para Obtener Precio del Producto
float Productos::getPrecio(int indice){
    return NumeroArticulos[indice].Precio;
}
//Función para Obtener Valor del Producto
float Productos::getValor(int indice){
    return NumeroArticulos[indice].Valor;
}
//Función para Obtener Piezas del Producto
int Productos::getPiezas(int indice){
    return NumeroArticulos[indice].Piezas;
}
//Función para Obtener Peso del Producto
float Productos::getPeso(int indice){
    return NumeroArticulos[indice].Peso;
}
//Función para Obtener Mayoreo del Producto
float Productos::getMayoreo(int indice){
    return NumeroArticulos[indice].Mayoreo;
}
//Función para Obtener Menudeo del Producto
float Productos::getMenudeo(int indice){
    return NumeroArticulos[indice].Menudeo;
}
//Función para Obtener Código del Producto
char* Productos::getCodigo(int indice){
    return NumeroArticulos[indice].Codigo;
}
//Función para Obtener Fecha Ingreso del Producto
char* Productos::getFechaIngreso(int indice){
    return NumeroArticulos[indice].Ingreso.getFecha();
}