//Archivo para implementación de funciones de clase Menu de Menu.h
#include "../include/Menu.h"
#include "../include/OS.h"
#include <conio.h>
#include <iostream>
#ifdef _WIN32
#define DIV 1048576
#define WIDTH 7
//Teclas para cursor
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80 
#define TECLA_IZQ 75
#define TECLA_DER 77
#define TECLA_ENTER 13
#define TECLA_ESC 27
using namespace std;

//Función Constructor
Menu::Menu(void){
    //Ultima linea cambiada
    Cursor=175;
    coord={0,0};
    KEY_PAD=0;
}
//Función Constructor Copia
Menu::Menu(const Menu &MenuOriginal){
    Cursor=MenuOriginal.Cursor;
    coord=MenuOriginal.coord;
    KEY_PAD=MenuOriginal.KEY_PAD;
}
//Función Destructor
Menu::~Menu(){

}
/********************************************************************
*                       Función:  gotoxy                            *
* Argumentos de Entrada:                                            *
*- Enteros: Coordenadas X y Y en pantalla.                          *
* Argumentos de Salida:                                             *
* -----------------                                                 *
* Esta función mueve el cursor a coordenadas específicas            *
********************************************************************/
void Menu::gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/********************************************************************
*                       Función: Mostrar_Titulo                     *
* Argumentos de Entrada:                                            *
*- Ninguno: N/A.                                                    *
* Argumentos de Salida:                                             *
* -----------------                                                 *
* Esta función muestra el título durante el menú                    *
********************************************************************/
void Menu::Mostrar_Titulo(void)
{
    //Iniciar instancia OS
    OS();
    OS os;
    //Iniciar instancia Menú
    Menu();
    Menu movercursor;
    //Valores iniciales para pasar a gotoxy
    int X = 0;
    int Y = 0;
    //Limpiar pantalla
    os.BorrarConsola();
    //Colocar atributos para formato de texto en consola
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
    //Colocar en posicion X,Y+2
    movercursor.gotoxy(X,Y+2);
    cout << Line1;
    os.Dormir(Delay);
    //Colocar en posicion X,Y+3
    movercursor.gotoxy(X,Y+3);
    cout << Line2;
    os.Dormir(Delay);
    //Colocar en posicion X,Y+4
    movercursor.gotoxy(X,Y+4);
    cout << Line3;
    os.Dormir(Delay);
    //Colocar en posicion X,Y+5
    movercursor.gotoxy(X,Y+5);
    cout << Line4;
    os.Dormir(Delay);
    //Colocar en posicion X,Y+6
    movercursor.gotoxy(X,Y+6);
    cout << Line5;
    os.Dormir(Delay);
    //Colocar en posicion X,Y+7
    movercursor.gotoxy(X,Y+7);
    cout << Line6;
    os.Dormir(Delay);
    //Set atributo de consola Color_Def
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    os.~OS();
    movercursor.~Menu();
}

/*****************************************************************************
*                    Función:  Esperar_Opcion                                *
* Argumentos de Entrada:                                                     *
* Ninguno: N/A.                                                              *
* Argumentos de Salida:                                                      *
*- Valor tipo entero relacionado con la selección en el menú                 *
* Esta función se mantiene en espera hasta que el usuario eliga una opción.  *
*****************************************************************************/
int Menu::Esperar_Opcion(void)
{
    //Iniciar instancia de OS
    OS();
    OS os;
    //Iniciar instancia Menú para mostrar titulo
    Menu();
    Menu mostrartitulo;
    //Variable para iniciar posición de Cursor
    int Cursor_Pos = 14;
    //Para ciclos for
    int i;
    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(27,10);
    cout << "SELECCIONA UNA OPCI\xE0N.";

    mostrartitulo.gotoxy(5,14);
    cout << "(1) NUEVO PRODUCTO.";

    mostrartitulo.gotoxy(5,16);
    cout << "(2) BORRAR PRODUCTO.";

    mostrartitulo.gotoxy(5,18);
    cout << "(3) COMPRAR PRODUCTO.";

    mostrartitulo.gotoxy(5,20);
    cout << "(4) VENDER PRODUCTO.";

    mostrartitulo.gotoxy(5,22);
    cout << "(5) MOSTRAR REPORTE.";

    mostrartitulo.gotoxy(5,24);
    cout << "(6) GUARDAR REPORTE.";

    mostrartitulo.gotoxy(5,26);
    cout << "(7) CARGAR REPORTE.";

    mostrartitulo.gotoxy(5,28);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
    cout << "(8) SALIR." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    mostrartitulo.gotoxy(1,30);
    cout << "USA EL PANEL DIRECCIONAL PARA SELECCIONAR ";
    cout << "UNA OPCI\xE0N O PRESIONA ESC PARA SALIR." << endl;

    mostrartitulo.gotoxy(3,Cursor_Pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
    cout << mostrartitulo.getCursor();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    mostrartitulo.gotoxy(64,30);

    do{
        if (kbhit())
        {
            mostrartitulo.KEY_PAD = getch();

            switch (mostrartitulo.KEY_PAD)
            {
                case TECLA_ARRIBA:
                {
                    if(Cursor_Pos>=16){
                        Cursor_Pos=Cursor_Pos-2;
                    }
                }
                break;

                case TECLA_ABAJO:
                {
                    if(Cursor_Pos<=26){
                        Cursor_Pos=Cursor_Pos+2;
                    }
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 14: os.~OS();mostrartitulo.~Menu();return 1; break;
                        case 16: os.~OS();mostrartitulo.~Menu();return 2; break;
                        case 18: os.~OS();mostrartitulo.~Menu();return 3; break;
                        case 20: os.~OS();mostrartitulo.~Menu();return 4; break;
                        case 22: os.~OS();mostrartitulo.~Menu();return 5; break;
                        case 24: os.~OS();mostrartitulo.~Menu();return 6; break;
                        case 26: os.~OS();mostrartitulo.~Menu();return 7; break;
                        case 28: os.~OS();mostrartitulo.~Menu();return 8; break;
                    }
                }
                break;

                case TECLA_ESC: os.~OS();mostrartitulo.~Menu();return 8; break;

            }

            for(i=0;i<16;i+=2)
            {
                mostrartitulo.gotoxy(3,14+i);
                cout << (char) 0;
            }

            mostrartitulo.gotoxy(3,Cursor_Pos);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
            cout << mostrartitulo.getCursor();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
            mostrartitulo.gotoxy(64,30);
        }
    }while (mostrartitulo.KEY_PAD!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 8;
}

/*****************************************************************************
*                     Función:  Mostrar_Error                                *
* Argumentos de Entrada:                                                     *
*- Puntero hacia una cadena o string,interalimentación del tiempo de pausa   *
* o descanso de función general o programa.                                  *      
* Argumentos de Salida:                                                      *
* Ninguno: N/A                                                               *
* Esta función muestra una advertencia o señal de error en caso de haberlo   *
* o necesitarlo.                                                             *
*****************************************************************************/
void Menu::Mostrar_Error(char *Puntero_Cadena, int Delay_Mostrar)
{
    //Instancia para OS
    OS();
    OS os;
    //Instancia para Mostrar error
    Menu();
    Menu mostrarerror;
    //Variable para medir longitud de cadena
    int LongitudCadena = sizeof(Puntero_Cadena);
    //Variable para ciclos for
    int i;
    mostrarerror.gotoxy(23,25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Rojo);
    for (i=0;i<=LongitudCadena;i++)
    {
        cout << *(Puntero_Cadena+i);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    os.Dormir(Delay_Mostrar);
    mostrarerror.gotoxy(23,25);
    for(i=0;i<=LongitudCadena;i++)
    {
        cout << ' ';
    }
    os.~OS();
    mostrarerror.~Menu();
}
//Función para obtener Color Verde
int Menu::getColorVerde(void){
    return Color_Verde;
}
//Función para obtener Color Def
int Menu::getColorDef(){
    return Color_Def;
}
//Función para obtener el valor de KEY_PAD
char Menu::getKEYPAD(){
    return KEY_PAD;
}
//Función para obtener el valor del Cursor
char Menu::getCursor(void){
    return Cursor;
}
//Función para definir valor a KEY_PAD
void Menu::setKEYPAD(char c){
    KEY_PAD=c;
}

#elif __linux__
//Teclas para cursor
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_IZQ 75
#define TECLA_DER 77
#define TECLA_ENTER 13
#define TECLA_ESC 27
/********************************************************************
*                       Función:  gotoxy                            *
* Argumentos de Entrada:                                            *
*- Enteros: Coordenadas X y Y en pantalla.                          *
* Argumentos de Salida:                                             *
* -----------------                                                 *
* Esta función mueve el cursor a coordenadas específicas            *
********************************************************************/
void Menu::gotoxy(int x,int y)
{
    this->coordx=x;
    this->coordy=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Menu::Mostrar_Titulo(void)
{
    int X = 0;
    int Y = 0;

    system("cls");

    char Line1[] = {"  ----------------------------------------------------------------------------   "};
    char Line2[] = {" |                          Sistema de Inventario                             |  "};
    char Line3[] = {" |                                   Por                                      |  "};
    char Line4[] = {" |       Valle Guerra Victor Leonardo(victorlvg678@gmail.com)                 |  "};
    char Line5[] = {" |                      Escuela Politecnica Guadalajara                       |  "};
    char Line6[] = {"  ----------------------------------------------------------------------------   "};


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
    gotoxy (X,Y+2);
    for (unsigned int i= 0; i < sizeof(Line1); i++)
    {
        cout << Line1[i];
        Sleep(Delay);
    }
    gotoxy (X,Y+3);
    for (unsigned int i= 0; i < sizeof(Line2); i++)
    {
        cout << Line2[i];
        Sleep(Delay);
    }
    gotoxy (X,Y+4);
    for (unsigned int i= 0; i < sizeof(Line3); i++)
    {
        cout << Line3[i];
        Sleep(Delay);
    }
    gotoxy (X,Y+5);
    for (unsigned int i= 0; i < sizeof(Line4); i++)
    {
        cout << Line4[i];
        Sleep(Delay);
    }
    gotoxy (X,Y+6);
    for (unsigned int i= 0; i < sizeof(Line5); i++)
    {
        cout << Line5[i];
        Sleep(Delay);
    }
    gotoxy (X,Y+7);
    for (unsigned int i= 0; i < sizeof(Line6); i++)
    {
        cout << Line6[i];
        Sleep(Delay);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/*****************************************************************************
*                    Funcion:  Wait_Option                                   *
* Argumentos de Entrada:                                                     *
*                                                                            *
* Argumentos de Salida:                                                      *
*- Integrar valor relacionado con la seleccion en el menu                    *
* Esta funcion se mantiene en espera hasta que el usuario eliga una opcion.  *
*****************************************************************************/
int Menu::Esperar_Opcion(void)
{
    int Cursor_Pos = 14;

    system("cls");
    Show_Title ();

    gotoxy(27,10);
    cout << "SELECCIONA UNA OPCI\xE0N.";

    gotoxy(5,14);
    cout << "(1) NUEVO PRODUCTO.";

    gotoxy(5,16);
    cout << "(2) BORRAR PRODUCTO.";

    gotoxy(5,18);
    cout << "(3) COMPRAR PRODUCTO.";

    gotoxy(5,20);
    cout << "(4) VENDER PRODUCTO.";

    gotoxy(5,22);
    cout << "(5) MOSTRAR REPORTE.";

    gotoxy(5,24);
    cout << "(6) GUARDAR REPORTE.";

    gotoxy(5,26);
    cout << "(7) CARGAR REPORTE.";

    gotoxy(5,28);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
    cout << "(8) SALIR." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(1,30);
    cout << "Usa El Panel Direccional Para Seleccionar Una Opcion O Presiona ESC Para SALIR. " << endl;

    gotoxy(3,Cursor_Pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
    cout << (char)Cursor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    gotoxy(64,30);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case TECLA_ARRIBA:
                {
                    if (Cursor_Pos >= 16) Cursor_Pos = Cursor_Pos - 2;
                }
                break;

                case TECLA_ABAJO:
                {
                    if (Cursor_Pos <= 26) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 14: return 1; break;
                        case 16: return 2; break;
                        case 18: return 3; break;
                        case 20: return 4; break;
                        case 22: return 5; break;
                        case 24: return 6; break;
                        case 26: return 7; break;
                        case 28: return 8; break;
                    }
                }
                break;

                case TECLA_ESC: return 8; break;

            }

            for (int i = 0; i<16 ; i+=2)
            {
                gotoxy(3,14+i);
                cout << (char) 0;
            }

            gotoxy(3,Cursor_Pos);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Verde);
            cout << (char)Cursor;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
            gotoxy(64,30);
        }
    }while (KEY_PAD!=27);

    return 8;
}
//Función para obtener Color Verde
int Menu::getColorVerde(void){
    return Color_Verde;
}
//Función para obtener Color Def
int Menu::getColorDef(){
    return Color_Def;
}
//Función para obtener el valor de KEY_PAD
char Menu::getKEYPAD(){
    return KEY_PAD;
}
//Función para obtener el valor del Cursor
char Menu::getCursor(void){
    return Cursor;
}
//Función para definir valor a KEY_PAD
void Menu::setKEYPAD(char c){
    KEY_PAD=c;
}
#endif