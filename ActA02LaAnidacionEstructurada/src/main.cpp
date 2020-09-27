/*
Creado el Viernes 18 de Septiembre de 2020 a las 2:35:20
@autor: Victor Leonardo Valle Guerra
Actividad de Aprendizaje 02
La anidación estructurada
Valle Guerra Victor Leonardo - 215661917
Centro Universitario de Ciencias Exactas e Ingenierias - CUCEI
Maestro: Alfredo Gutiérrez Hernández
Estructura de Datos I
Sección:D11
18/09/20
***************************************************
*                                                 *
*                      Act.A02                    *
*                    18 Sep 2020                  *
*           -Victor Leonardo Valle Guerra         *
*                    215661917                    *
*              victorlvg678@gmail.com             *
*         Copyright ® All rights reserved         *
*                Derechos de Autor                *
*          Todos los Derechos Reservados          *
*                                                 *
***************************************************
  DDDM777Z
  NDDM777MDDN
   DDM778NDDDD
   NDM77MNDDDDN
 DDDNM7777MDDDD
DDDM777777MDDDN
DDM7777778MDDD
 NDM87777MDDDD
  NDNMMM77MDN
     DDM777MDN
    NDDM777NNDD
    DDDM7777MDDD
   NDDDM77777MDDD

      CUCEI
********************************************************************
*                         Sistema de Inventario                     *
*    Este es un programa con archivos de entrada y de salida        *
*                           Versión 1.0                             *
*      Valle Guerra Victor Leonardo(victorlvg678@gmail.com)         *
*      Centro Universitario de C.E.I 18/Septiembre/2020             *
*********************************************************************
*/
//Archivos de Cabecera/Librerías
#ifdef _WIN32
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include "../include/Menu.h"
#include "../include/CRUDProductos.h"
#include "../include/Productos.h"
#include "../include/OS.h"
#include "../include/Fecha.h"
#elif __linux__
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "../include/Menu.h"
#include "../include/CRUDProductos.h"
#include "../include/Productos.h"
#include "../include/OS.h"
#include "../include/Fecha.h"
#include <conio.h>
//Colores
#define Color_Rojo 12
#define Color_Amarillo 14
#define Max_Chars 12
#endif
using namespace std;

int main()
{
    //Instanciar Menú
    Menu();
    Menu menu;
    //Instanciar CRUDProductos
    CRUDProductos();
    CRUDProductos inventario;
    //Instanciar OS para banner inicial
    OS();
    OS os;
    int i;
    os.BorrarConsola();
    os.banner();
    for(i=0;i<99;i++){
        if(i%2==0){
            os.ColorCMD((char*)"Amarillo");
        }else{
            if(i%3==0){
                os.ColorCMD((char*)"Rojo");
            }else{
                os.ColorCMD((char*)"Verde");
            }
        }
    }
    os.Dormir(2000);
    os.BorrarConsola();
    os.~OS();
    //Ciclo infinito para Menú
    for(;;)
    {
        switch(menu.Esperar_Opcion())
        {
            case 1:
                inventario.Nuevo_Producto();
                break;

            case 2:
                inventario.Borrar_Producto();
                break;

            case 3:
                inventario.Comprar_Producto();
                break;

            case 4:
                inventario.Vender_Producto();
                break;

            case 5:
                inventario.Reportar_Producto();
                break;

            case 6:
                inventario.Guardar_Archivo();
                break;

            case 7:
                inventario.Cargar_Archivo();
                break;

            case 8:
                inventario.~CRUDProductos();
                menu.~Menu();
                return EXIT_SUCCESS;
                break;
        }
    }
}
