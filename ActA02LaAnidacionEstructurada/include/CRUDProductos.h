//Archivo de cabecera para gestión de CRUD de Productos
//C - Create/Crear
//R - Read/Retrieve - Leer/Reclamar
//U - Update/Actualizar
//D - Delete/Borrar
//Guardias para evitar doble integración en compilado
#ifndef CRUDPRODUCTOS_H
#define CRUDPRODUCTOS_H
//Incluir librería de productos para usar dentro de la Clase
#include "Productos.h"
//Clase para Manejo de Permisos CRUD de Productos
class CRUDProductos{
    //Variables Privadas
    private:
        //Registro de Productos por puntero
        Productos Inventario;
        //Permite contar cuantos productos se han registrado
        int ContadorInventario;
        float Total_Inventario;
    //Métodos de Clase
    public:
        //Constructor
        CRUDProductos(void);
        //Constructor Copia
        CRUDProductos(const CRUDProductos &CRUDProductosOriginal);
        //Destructor
        ~CRUDProductos();
        //Gestor de Permisos de Creación/Create
        int Nuevo_Producto();
        //Gestor de Permisos de Eliminación/Delete
        int Borrar_Producto();
        //Función de Compra de Productos
        int Comprar_Producto();
        //Función de Venta de Productos 
        int Vender_Producto();
        //Función de Reporte de Productos
        int Reportar_Producto();
        //Función para Cargar Archivo
        int Cargar_Archivo();
        //Función para Guardar Archivo
        int Guardar_Archivo();
};
#endif