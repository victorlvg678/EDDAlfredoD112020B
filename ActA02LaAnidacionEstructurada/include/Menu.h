//Archivo Cabecera para gestión de Menú
//Guardias para evitar doble integración en compilado
#ifndef MENU_H
#define MENU_H
//En caso de que sea windows
#ifdef _WIN32
//Librería para COORD en Windows
#include <windows.h>
#include <iostream>
using namespace std;
//Clase para Gestionar Menú
class Menu{
    //Variables privadas
    private:
        //Coordenadas x,y
        COORD coord;
        //Cadenas para título
        const string Line1 ="  ----------------------------------------------------------------------------   ";
        const string Line2 =" |                          Sistema de Inventario                             |  ";
        const string Line3 =" |                                   Por                                      |  ";
        const string Line4 =" |       Valle Guerra Victor Leonardo(victorlvg678@gmail.com)                 |  ";
        const string Line5 =" |      Centro Universitario de Ciencias Exactas e Ingenierias                |  ";
        const string Line6 ="  ----------------------------------------------------------------------------   ";
        //Teclas
        char KEY_PAD;
        //Definir cursor
        char Cursor;
        //Delay para consola
        const int Delay=0;
        //Definir Colores
        const int Color_Verde=10;
        const int Color_Def=15;
        const int Color_Rojo=12;
        const int Color_Amarillo=14;
    //Métodos de Clase
    public:
        //Constructor
        Menu(void);
        //Constructor Copia
        Menu(const Menu &MenuOriginal);
        //Destructor
        ~Menu();
        //Función para cursor en pantalla
        void gotoxy(int x,int y);
        //Función para mostrar Título
        void Mostrar_Titulo(void);
        //Función para esperar opción
        int Esperar_Opcion(void);
        //Función para Mostrar Errores
        void Mostrar_Error(char *Puntero_Cadena, int Delay_Mostrar);
        //Setters
        //Set KEYPAD
        void setKEYPAD(char c);
        //Getters
        //Obtener Color Verde
        int getColorVerde(void);
        //Obtener Color Def
        int getColorDef(void);
        //Obtener KEYPAD
        char getKEYPAD(void);
        //Obtener Cursor
        char getCursor(void);
        
};
//En caso de ser linux
#elif __linux__
#include <iostream>
using namespace std;
//Clase para Gestionar Menú
class Menu{
    //Variables privadas
    private:
        //Valor coordenadas x,y
        int coordx;
        int coordy;
        //Cadenas para título
        const string Line1 ="  ----------------------------------------------------------------------------   ";
        const string Line2 =" |                          Sistema de Inventario                             |  ";
        const string Line3 =" |                                   Por                                      |  ";
        const string Line4 =" |       Valle Guerra Victor Leonardo(victorlvg678@gmail.com)                 |  ";
        const string Line5 =" |      Centro Universitario de Ciencias Exactas e Ingenierias                |  ";
        const string Line6 ="  ----------------------------------------------------------------------------   ";
        //Teclas
        char KEY_PAD;
        //Definir cursor
        char Cursor;
        //Delay para consola
        const int Delay=0;
        //Definir Colores
        const int Color_Verde=10;
        const int Color_Def=15;
        const int Color_Rojo=12;
        const int Color_Amarillo=14;
    //Métodos de Clase
    public:
        //Constructor
        Menu(void){
            coordx=0;
            coordy=0;
        };
        //Constructor Copia
        Menu(const Menu &MenuOriginal){
            coordx=MenuOriginal.coordx;
            coordy=MenuOriginal.coordy;
        };
        //Destructor
        ~Menu();
        //Función para cursor en pantalla
        void gotoxy(int x,int y);
        //Función para Mostrar Título
        void Mostrar_Titulo(void);
        //Función para esperar opción
        int Esperar_Opcion(void);
        //Getters
        //Obtener Color Verde
        int getColorVerde(void);
        //Obtener Color Def
        int getColorDef(void);
}
#endif
#endif