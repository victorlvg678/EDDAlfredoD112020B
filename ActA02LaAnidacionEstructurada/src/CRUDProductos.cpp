//Archivo con la implementación de las funciones de CRUDProductos
#include "../include/CRUDProductos.h"
#include "../include/OS.h"
#include "../include/Menu.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#ifdef _WIN32
#include <string.h>
#define Max_Carac 12
//Teclas para cursor
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80 
#define TECLA_IZQ 75
#define TECLA_DER 77
#define TECLA_ENTER 13
#define TECLA_ESC 27
#define Max_Chars 12
using namespace std;
//Función Constructor
CRUDProductos::CRUDProductos(void){
    ContadorInventario=0;
    Total_Inventario=0;
}
//Función Constructor Copia
CRUDProductos::CRUDProductos(const CRUDProductos &CRUDProductosOriginal){
    ContadorInventario=CRUDProductosOriginal.ContadorInventario;
    Total_Inventario=CRUDProductosOriginal.Total_Inventario;
    Inventario=CRUDProductosOriginal.Inventario;
}
//Función Destructor
CRUDProductos::~CRUDProductos(){

};
/********************************************************************
*                     Función: Nuevo_Producto                       *
* Argumentos de Entrada:                                            *
* -Ninguno.                                                         *
* Argumentos de Salida:                                             *
*- Valor entero solamente para indicar que la acción finalizó.      *
* Esta función agrega productos al registro del inventario.         *
********************************************************************/
int CRUDProductos::Nuevo_Producto()
{
    //Inicializando instancia de OS
    OS();
    OS os;
    //Inicializando instancia de Menú
    Menu();
    Menu mostrartitulo;
    //Iniciar Posición cursor
    int Cursor_PosY = 13;
    int Cursor_PosX = 29;
    //Variable para ciclos for
    int i;
    //Definir nombre
    char Nombre[Max_Carac];
    char Codigo[13];
    //Definir costo y precio
    float Costo = 0,Precio = 0;
    float Mayoreo=0,Menudeo=0;
    float Peso=0;
    char Ingreso[8];

    //Borrar pantalla
    os.BorrarConsola();
    //Mostrar Titulo
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(29,9);
    //Titulo
    cout << ">> NUEVO PRODUCTO <<" << endl;
    //Lado Izquierdo
    mostrartitulo.gotoxy(5,13);
    cout << "Codigo del Producto : " << endl;
    mostrartitulo.gotoxy(5,15);
    cout << "Nombre del Producto : " << endl;
    mostrartitulo.gotoxy(5,17);
    cout << "Coste del Producto : " << endl;
    mostrartitulo.gotoxy(5,19);
    cout << "P.Menudeo del Producto : " << endl;
    //Lado Derecho
    mostrartitulo.gotoxy(51,13);
    cout << "Fecha Ingreso del Producto : " << endl;
    mostrartitulo.gotoxy(51,15);
    cout << "Peso del Producto : " << endl;
    mostrartitulo.gotoxy(51,17);
    cout << "Precio del Producto : " << endl;
    mostrartitulo.gotoxy(51,19);
    cout << "P.Mayoreo del Producto : " << endl;
    //Final
    mostrartitulo.gotoxy(3,21);
    cout << "<< GUARDAR >> " << endl;
    mostrartitulo.gotoxy(1,23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MEN\xE9 PRINCIPAL" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),mostrartitulo.getColorDef());
    mostrartitulo.gotoxy(15,27);
    cout << "USA EL PANEL DIRECCIONAL PARA ELIGIR UNA OPCI\xE0N." << endl;

    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch (mostrartitulo.getKEYPAD())
            {
                case TECLA_ARRIBA:
                {
                    if(Cursor_PosY>13){
                        Cursor_PosY=Cursor_PosY-2;
                    }
                }
                break;

                case TECLA_ABAJO:
                {
                    if(Cursor_PosY<23){
                        Cursor_PosY=Cursor_PosY+2;
                    }
                }
                break;

                case TECLA_IZQ:
                {
                    if(Cursor_PosX>29){
                        Cursor_PosX=Cursor_PosX-52;
                    }
                }
                break;
                case TECLA_DER:
                {
                    if(Cursor_PosX<81){
                        Cursor_PosX=Cursor_PosX+52;
                    }
                }
                break;
                case TECLA_ENTER:
                {
                    switch(Cursor_PosX){
                        case 29:
                        {
                            switch (Cursor_PosY)
                            {
                                case 13:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    //cin.getline (Codigo,Max_Chars,'\n');
                                    fflush(stdin);
                                    cin >> Codigo;
                                    cin.clear();
                                    cin.ignore(13, '\n');
                                    fflush(stdin);
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 15:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    fflush(stdin);
                                    cin >> Nombre;
                                    cin.clear();
                                    cin.ignore(12, '\n');
                                    fflush(stdin);
                                    for (i=0;i<13;i++)
                                    {
                                        Nombre[i] = toupper(Nombre[i]);
                                        if(Nombre[i]=='\0'){
                                            break;
                                        }
                                    }
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 17:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    cin >> Costo;
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 19:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    cin >> Menudeo;
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 21:
                                    if (Peso == 0 || Mayoreo == 0 || Menudeo ==0 || Costo== 0 || Precio == 0 || Nombre[0] == '\0' || Codigo[0]=='\0')
                                    {
                                        mostrartitulo.Mostrar_Error((char *)"ERROR: DEBES INGRESAR TODOS LOS VALORES.  ", 1500);
                                    }
                                    else
                                    {
                                        //Ingresar nuevo producto a inventario
                                        Inventario.setCodigo(ContadorInventario,(char*)Codigo);
                                        fflush(stdin);
                                        Inventario.setNombre(ContadorInventario,Nombre);
                                        Inventario.setCosto(ContadorInventario,Costo);
                                        Inventario.setMenudeo(ContadorInventario,Menudeo);
                                        if(Ingreso[0]=='\0'){
                                            Inventario.setFechaIngreso(ContadorInventario,(char*)'\0');
                                        }else{
                                            Inventario.setFechaIngreso(ContadorInventario,(char*)Ingreso);
                                        }
                                        Inventario.setPeso(ContadorInventario,Peso);
                                        Inventario.setPrecio(ContadorInventario,Precio);
                                        Inventario.setMayoreo(ContadorInventario,Mayoreo);
                                        Inventario.setPiezas(ContadorInventario,0);
                                        ContadorInventario++;
                                        os.~OS();
                                        mostrartitulo.~Menu();
                                        return 0;
                                    }
                                    break;

                                case 23: 
                                    os.~OS();
                                    mostrartitulo.~Menu();
                                    return 0; 
                                    break;

                            }
                        }
                        break;

                        case 81:
                        {
                            switch (Cursor_PosY)
                            {
                                case 13:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    //cin.getline (Codigo,Max_Chars,'\n');
                                    fflush(stdin);
                                    cin >> Ingreso;
                                    cin.clear();
                                    cin.ignore(8, '\n');
                                    fflush(stdin);
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 15:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    cin >> Peso;
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 17:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    cin >> Precio;
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 19:
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << "                    ";
                                    mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
                                    cout << mostrartitulo.getCursor() << " ";
                                    cin >> Mayoreo;
                                    mostrartitulo.gotoxy(Cursor_PosX+15,Cursor_PosY);
                                    cout << "Listo";
                                    break;

                                case 21:
                                    if (Peso == 0 || Mayoreo == 0 || Menudeo ==0 || Costo== 0 || Precio == 0 || Nombre[0] == '\0' || Codigo[0]=='\0')
                                    {
                                        mostrartitulo.Mostrar_Error((char *)"ERROR: DEBES INGRESAR TODOS LOS VALORES.  ", 1500);
                                    }
                                    else
                                    {
                                        //Ingresar nuevo producto a inventario
                                        Inventario.setCodigo(ContadorInventario,(char*)Codigo);
                                        fflush(stdin);
                                        Inventario.setNombre(ContadorInventario,Nombre);
                                        Inventario.setCosto(ContadorInventario,Costo);
                                        Inventario.setMenudeo(ContadorInventario,Menudeo);
                                        if(Ingreso[0]=='\0'){
                                            Inventario.setFechaIngreso(ContadorInventario,(char*)'\0');
                                        }else{
                                            Inventario.setFechaIngreso(ContadorInventario,(char*)Ingreso);
                                        }
                                        Inventario.setPeso(ContadorInventario,Peso);
                                        Inventario.setPrecio(ContadorInventario,Precio);
                                        Inventario.setMayoreo(ContadorInventario,Mayoreo);
                                        Inventario.setPiezas(ContadorInventario,0);
                                        ContadorInventario++;
                                        os.~OS();
                                        mostrartitulo.~Menu();
                                        return 0;
                                    }
                                    break;

                                case 23: 
                                    os.~OS();
                                    mostrartitulo.~Menu();
                                    return 0; 
                                    break;

                            }
                        }
                        break;
                    }
                    
                    
                }
                break;
            }
            mostrartitulo.gotoxy(Cursor_PosX,Cursor_PosY);
        }
      }while (mostrartitulo.getKEYPAD()!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}

/********************************************************************
*                   Función:  Borrar_Producto                       *
* Argumentos de Entrada:                                            *
* Ninguna: N/A                                                      *
* Argumentos de Salida:                                             *
*- Valor entero solamente para indicar que la función finalizó      *
* Esta función borra productos del registro del inventario.         *
********************************************************************/
int CRUDProductos::Borrar_Producto()
{
    //Instanciar OS
    OS();
    OS os;
    //Instanciar Menu
    Menu();
    Menu mostrartitulo;
    //Inicializar Cursor
    int Cursor_Pos = 20;
    //Variable para borrar registro
    int Borrar_Registro = 0;
    //Variable para Código
    char Borrar_Codigo[13];
    //Variable para ver donde se hallo el código
    int Posicion_Encontrado=0;
    //Variable para ver si se hallo el producto
    bool Existe_Producto=false;
    //Variable para ciclos for
    int j;

    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(27,9);
    cout << ">> BORRAR PRODUCTO <<" << endl;
    mostrartitulo.gotoxy(1,11);
    cout <<"------------------------------------------------------------------------------";
    cout <<"--------------------------------------------------------------";
    mostrartitulo.gotoxy(1,12);
    cout << "|Num.|";
    cout << "    CODIGO     |";
    cout << "   FECHA  |";
    cout << "    NOMBRE     |";
    cout << "   PESO  |";
    cout << "   COMPRA   |";
    cout << "    VENTA  |";
    cout << "  CANTIDAD  |";
    cout << "   MENUDEO   |";
    cout << "    MAYOREO  |";
    cout << "    VALOR    |";
    mostrartitulo.gotoxy(1,13);
    cout <<"------------------------------------------------------------------------------";
    cout <<"--------------------------------------------------------------";
    mostrartitulo.gotoxy(1,9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MEN\xE9";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),mostrartitulo.getColorDef());
    mostrartitulo.gotoxy(53,9);
    cout << "BORRAR> Num. Registro:" ;
    mostrartitulo.gotoxy(83,9);
    cout << "Cod:";

    for(j=0;j<ContadorInventario;j++)
    {
        mostrartitulo.gotoxy(3,14+j);
        cout << j+1;
        mostrartitulo.gotoxy(8,14+j);
        cout << Inventario.getCodigo(j);
        mostrartitulo.gotoxy(24,14+j);
        cout << Inventario.getFechaIngreso(j);
        mostrartitulo.gotoxy(36,14+j);
        cout << Inventario.getNombre(j);
        cout.precision(2);
        mostrartitulo.gotoxy(50,14+j);
        cout << fixed << Inventario.getPeso(j) << " kg";
        mostrartitulo.gotoxy(63,14+j);
        cout << fixed << Inventario.getCosto(j) << " MXN";
        mostrartitulo.gotoxy(74,14+j);
        cout << fixed << Inventario.getPrecio(j) << " MXN";
        mostrartitulo.gotoxy(88,14+j);
        cout << fixed << Inventario.getPiezas(j) << " Pz";
        mostrartitulo.gotoxy(100,14+j);
        cout << fixed << Inventario.getMenudeo(j) << " MXN";
        mostrartitulo.gotoxy(115,14+j);
        cout << fixed << Inventario.getMayoreo(j) << " MXN";
        mostrartitulo.gotoxy(128,14+j);
        cout << fixed << Inventario.getValor(j) << " MXN";
    }

    mostrartitulo.gotoxy(Cursor_Pos,9);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch(mostrartitulo.getKEYPAD())
            {
                case TECLA_IZQ:
                {
                    if (Cursor_Pos == 76){
                        Cursor_Pos = 20;
                    }else{
                        if(Cursor_Pos==88){
                            Cursor_Pos=76;
                        }
                    }

                }
                break;

                case TECLA_DER:
                {
                    if (Cursor_Pos == 20){
                        Cursor_Pos = 76;
                    }else{
                        if(Cursor_Pos==76){
                            Cursor_Pos=88;
                        }
                    }
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 76:
                            mostrartitulo.gotoxy(Cursor_Pos-1,9);
                            cout << mostrartitulo.getCursor();
                            cin >> Borrar_Registro;
                            if(Borrar_Registro>ContadorInventario)
                            {
                                mostrartitulo.Mostrar_Error((char *) "ERROR: NUMERO DE REGISTRO INVALIDO.", 1500);
                                Cursor_Pos = 20;
                            }
                            else
                            {
                                Inventario.setCodigo(Borrar_Registro-1,(char*)"\0");
                                Inventario.setNombre(Borrar_Registro-1,(char*)"\0");
                                Inventario.setFechaIngreso(Borrar_Registro-1,(char*)"00/00/00");
                                Inventario.setPeso(Borrar_Registro-1,0);
                                Inventario.setCosto(Borrar_Registro-1,0);
                                Inventario.setPrecio(Borrar_Registro-1,0);
                                Inventario.setMenudeo(Borrar_Registro-1,0);
                                Inventario.setMayoreo(Borrar_Registro-1,0);
                                Inventario.setPiezas(Borrar_Registro-1,0);
                                Inventario.setValor(Borrar_Registro-1,0);
                                ContadorInventario--;
                                //delete[] Pointer_Articles[Delete_Register-1];
                                mostrartitulo.gotoxy(22,9);
                                cout << "LISTO.";
                                Cursor_Pos = 20;
                            }
                        break;
                        
                        case 88:
                                mostrartitulo.gotoxy(Cursor_Pos-1,9);
                                cout << mostrartitulo.getCursor();
                                cin >> Borrar_Codigo;
                                for(j=0;j<ContadorInventario;j++){
                                    if(strcmp(Inventario.getCodigo(j),Borrar_Codigo)){
                                        Existe_Producto=true;
                                        Posicion_Encontrado=j;
                                        break;
                                    }
                                }
                                if(Existe_Producto)
                                {
                                    Inventario.setCodigo(Posicion_Encontrado,(char*)"\0");
                                    Inventario.setNombre(Posicion_Encontrado,(char*)"\0");
                                    Inventario.setFechaIngreso(Posicion_Encontrado,(char*)"00/00/00");
                                    Inventario.setPeso(Posicion_Encontrado,0);
                                    Inventario.setCosto(Posicion_Encontrado,0);
                                    Inventario.setPrecio(Posicion_Encontrado,0);
                                    Inventario.setMenudeo(Posicion_Encontrado,0);
                                    Inventario.setMayoreo(Posicion_Encontrado,0);
                                    Inventario.setPiezas(Posicion_Encontrado,0);
                                    Inventario.setValor(Posicion_Encontrado,0);
                                    ContadorInventario--;
                                    //delete[] Pointer_Articles[Delete_Register-1];
                                    mostrartitulo.gotoxy(22,9);
                                    cout << "LISTO.";
                                    Cursor_Pos = 20;
                                    
                                }else
                                {
                                    mostrartitulo.Mostrar_Error((char *) "ERROR: CODIGO INVALIDO.", 1500);
                                    Cursor_Pos = 20;
                                }
                                break;

                        case 20: os.~OS();mostrartitulo.~Menu();return 0; break;
                    }
                }
            }
            mostrartitulo.gotoxy(Cursor_Pos,9);
        }
      }while(mostrartitulo.getKEYPAD()!=27);

    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}


/******************************************************************************
*                    Función: Comprar_Producto                                *
* Argumentos de Entrada:                                                      *
* Ninguno: N/A                                                                *
* Argumentos de salida:                                                       *
*- Valor entero únicamente para indicar que esta función finalizó.            *
* Esta función maneja la compra de productos en el registro del inventario.   *
******************************************************************************/
int CRUDProductos::Comprar_Producto()
{
    //Instancias Menu
    Menu();
    Menu mostrartitulo;
    //Instancias OS
    OS();
    OS os;
    //Iniciar cursor
    int Cursor_Pos = 13;
    //Variables para ciclos for
    int j;
    //Para Capturar Nombre
    char Nombre[Max_Chars];
    char Codigo[13];
    //Para indicar cantidad a comprar
    int Cantidad_Producto;
    //Para indicar si el producto existía
    bool Existe_Producto = false;
    //Variable para indicar indice donde se encontró el Producto
    int Posicion_Encontrado;

    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(25,9);
    cout << ">> COMPRAR PRODUCTO <<";
    mostrartitulo.gotoxy(3,13);
    cout << "Codigo del Producto :";
    mostrartitulo.gotoxy(3,15);
    cout << "Nombre del Producto :";
    mostrartitulo.gotoxy(3,17);
    cout << "Cantidad del Producto :";
    mostrartitulo.gotoxy(3,19);
    cout << "<< GUARDAR >> ";
    mostrartitulo.gotoxy(3,21);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MENU" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorDef());

    mostrartitulo.gotoxy(30,Cursor_Pos);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch(mostrartitulo.getKEYPAD())
            {
                case TECLA_ARRIBA:
                {
                    if(Cursor_Pos>13){ 
                        Cursor_Pos=Cursor_Pos-2;
                    }
                }
                break;

                case TECLA_ABAJO:
                {
                    if(Cursor_Pos<21){
                        Cursor_Pos=Cursor_Pos+2;
                    }
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            //cin.getline (Name,Max_Chars,'\n');
                            fflush(stdin);
                            cin >> Codigo;
                            cin.clear();
                            cin.ignore(13, '\n');
                            fflush(stdin);
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;

                        case 15:
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            cin >> Nombre;
                            for(j=0;j<Max_Chars;j++){
                                Nombre[j]=toupper(Nombre[j]);
                                if(Nombre[j]=='\0'){
                                    break;
                                }
                            }
                            cin.clear();
                            cin.ignore(10, '\n');
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;

                        case 17:
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            cin >> Cantidad_Producto;
                            cin.clear();
                            cin.ignore(10, '\n');
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;        
                         
                        case 19:
                            if (Cantidad_Producto == 0 || (Codigo[0] == '\0' && Nombre[0]== '\0'))
                            {
                                mostrartitulo.Mostrar_Error((char *) "ERROR: DEBES INTRODUCIR TODOS LOS VALORES.", 1500);
                            }
                            else
                            {
                                for(j=0;j<ContadorInventario;j++)
                                {
                                    if(stricmp(Inventario.getNombre(j),Nombre)==0 || stricmp(Inventario.getCodigo(j),Codigo)==0){
                                        Existe_Producto=true;
                                        Posicion_Encontrado=j;
                                    }
                                }

                                if(Existe_Producto)
                                {
                                    
                                    Inventario.setPiezas(Posicion_Encontrado,
                                    Inventario.getPiezas(Posicion_Encontrado)+Cantidad_Producto);
                                    Inventario.setValor(Posicion_Encontrado,
                                    Inventario.getPiezas(Posicion_Encontrado)*Inventario.getCosto(Posicion_Encontrado));
                                    os.~OS();
                                    mostrartitulo.~Menu();
                                    return 0;
                                }
                                else
                                {
                                    mostrartitulo.Mostrar_Error((char *) "ERROR: ARTICULO NO EXISTENTE EN EL INVENTARIO.", 1500);
                                }
                            }
                        break;

                        case 21: os.~OS();mostrartitulo.~Menu();return 0; break;
                    }
                }
            }
            mostrartitulo.gotoxy(30,Cursor_Pos);
        }
      }while(mostrartitulo.getKEYPAD()!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}

/***********************************************************************
*                    Función: Vender_Producto                          *
* Argumentos de Entrada:                                               *
* Ninguno: N/A                                                         *
* Argumentos de Salida:                                                *
*- Valor entero solamente para indicar finalización de dicha función.  *
* Esta función maneja las ventas del registro del inventario.          *
***********************************************************************/
int CRUDProductos::Vender_Producto()
{
    //Instanciar OS
    OS();
    OS os;
    //Instanciar Menú
    Menu();
    Menu mostrartitulo;
    //Inicializar Cursor
    int Cursor_Pos = 13;
    //Para capturar nombre
    char Nombre[Max_Chars];
    char Codigo[13];
    char PrecioVender[8];
    //Variable para cantidad a vender
    int Cantidad_Producto;
    //Variable para verificar si está registrado
    bool Existe_Producto = false;
    //Variables para ciclos for
    int j;
    //Variable para guardar posición donde se econtró el Producto
    int Posicion_Encontrado;

    //Borrar pantalla
    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(25,9);
    cout << ">> VENDER PRODUCTO <<" << endl;
    mostrartitulo.gotoxy(3,13);
    cout << "Codigo del Producto :";
    mostrartitulo.gotoxy(3,15);
    cout << "Nombre del Producto :";
    mostrartitulo.gotoxy(3,17);
    cout << "Cantidad del Producto :";
    mostrartitulo.gotoxy(3,19);
    cout << "Precio a Vender(E/Men/May) :";
    mostrartitulo.gotoxy(3,21);
    cout << "<< GUARDAR >> ";
    mostrartitulo.gotoxy(3,23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MENU" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorDef());

    mostrartitulo.gotoxy(30,Cursor_Pos);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch(mostrartitulo.getKEYPAD())
            {
                case TECLA_ARRIBA:
                {
                    if(Cursor_Pos>13){
                        Cursor_Pos=Cursor_Pos-2;
                    }

                }
                break;

                case TECLA_ABAJO:
                {
                    if(Cursor_Pos<23){
                        Cursor_Pos=Cursor_Pos+2;
                    }
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            //cin.getline (Name,Max_Chars,'\n');
                            fflush(stdin);
                            cin >> Codigo;
                            cin.clear();
                            cin.ignore(10, '\n');
                            fflush(stdin);
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;

                        case 15:
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            //cin.getline (Name,Max_Chars,'\n');
                            fflush(stdin);
                            cin >> Nombre;
                            for(j=0;j<Max_Chars;j++){
                                Nombre[j]=toupper(Nombre[j]);
                                if(Nombre[j]=='\0'){
                                    break;
                                }
                            }
                            cin.clear();
                            cin.ignore(10, '\n');
                            fflush(stdin);
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;

                        case 17:
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(29,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            cin >> Cantidad_Producto;
                            cin.clear();
                            cin.ignore(10, '\n');
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;

                        case 19:
                            mostrartitulo.gotoxy(31,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(31,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            //cin.getline (Name,Max_Chars,'\n');
                            fflush(stdin);
                            cin >> PrecioVender;
                            for(j=0;j<Max_Chars;j++){
                                PrecioVender[j]=toupper(PrecioVender[j]);
                                if(PrecioVender[j]=='\0'){
                                    break;
                                }
                            }
                            cin.clear();
                            cin.ignore(10, '\n');
                            fflush(stdin);
                            mostrartitulo.gotoxy(44,Cursor_Pos);
                            cout << "Listo";
                        break;

                        case 21:
                            if (PrecioVender[0]=='\0' || Cantidad_Producto == 0 || (Nombre[0] == '\0' && Codigo[0]=='\0'))
                            {
                                mostrartitulo.Mostrar_Error((char *) "ERROR: DEBES INTRODUCIR TODOS LOS VALORES.",1500);
                            }
                            else
                            {
                                
                                for(j=0;j<ContadorInventario;j++)
                                {
                                    if(stricmp(Inventario.getNombre(j),Nombre)==0 || stricmp(Inventario.getCodigo(j),Codigo)==0){
                                        Existe_Producto=true;
                                        Posicion_Encontrado=j;
                                    }
                                }

                                if(Existe_Producto)
                                {
                                    if (Cantidad_Producto <= Inventario.getPiezas(Posicion_Encontrado))
                                    {
                                        Inventario.setPiezas(Posicion_Encontrado,
                                        Inventario.getPiezas(Posicion_Encontrado)-Cantidad_Producto);
                                        Inventario.setValor(Posicion_Encontrado,
                                        Inventario.getPiezas(Posicion_Encontrado)*Inventario.getCosto(Posicion_Encontrado));
                                        if(stricmp((char*)"E",PrecioVender)==0 || stricmp((char*)"ESTANDAR",PrecioVender)==0){
                                            Total_Inventario=Total_Inventario+(Cantidad_Producto*Inventario.getPrecio(Posicion_Encontrado));
                                        }else{
                                            if(stricmp((char*)"MEN",PrecioVender)==0 || stricmp((char*)"MENUDEO",PrecioVender)==0){
                                                Total_Inventario=Total_Inventario
                                                +(Cantidad_Producto*Inventario.getMenudeo(Posicion_Encontrado));
                                            }else{
                                                if(stricmp((char*)"MAY",PrecioVender)==0 || stricmp((char*)"MAYOREO",PrecioVender)==0){
                                                    Total_Inventario=Total_Inventario
                                                    +(Cantidad_Producto*Inventario.getMayoreo(Posicion_Encontrado));
                                                }else{
                                                    mostrartitulo.Mostrar_Error((char *) "ERROR: PRECIO A VENDER NO VALIDO.",1500);
                                                }
                                            }
                                        }
                                        os.~OS();
                                        mostrartitulo.~Menu();
                                        return 0;
                                    }
                                    else
                                    {
                                        mostrartitulo.Mostrar_Error((char *) "ERROR: LA CANTIDAD DE ARTICULOS EXCEDE LA EXISTENCIA.",1500);
                                    }
                                }
                                else
                                {
                                    mostrartitulo.Mostrar_Error((char *) "ERROR: ARTICULO NO EXISTENTE EN EL INVENTARIO.",1500);
                                }
                            }
                        break;

                        case 23: os.~OS();mostrartitulo.~Menu();return 0; break;
                    }
                }
            }
            mostrartitulo.gotoxy(30,Cursor_Pos);
        }
      }while(mostrartitulo.getKEYPAD()!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}

/**************************************************************************
*                    Función: Reportar_Producto                           *
* Argumentos de Entrada:                                                  *
* Ninguno: N/A                                                            *
* Argumentos de Salida:                                                   *
*- Valor entero únicamente para puntualizar el cierre de dicha función.   *
* Esta función muestra el reporte o registro del inventario.              *
**************************************************************************/
int CRUDProductos::Reportar_Producto()
{   
    //Instanciar OS
    OS();
    OS os;
    //Instanciar Menu
    Menu();
    Menu mostrartitulo;
    //Incializar variable para Total
    float Total = 0;
    //Variables para ciclos for
    int i,j;

    //Borrar terminal
    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(24,9);
    cout << ">> REPORTE DE PRODUCTOS <<" << endl;
    mostrartitulo.gotoxy(1,11);
    cout <<"------------------------------------------------------------------------------";
    cout <<"--------------------------------------------------------------";
    mostrartitulo.gotoxy(1,12);
    cout << "|Num.|";
    cout << "    CODIGO     |";
    cout << "   FECHA  |";
    cout << "    NOMBRE     |";
    cout << "   PESO  |";
    cout << "   COMPRA   |";
    cout << "    VENTA  |";
    cout << "  CANTIDAD  |";
    cout << "   MENUDEO   |";
    cout << "    MAYOREO  |";
    cout << "    VALOR    |";
    mostrartitulo.gotoxy(1,13);
    cout <<"------------------------------------------------------------------------------";
    cout <<"--------------------------------------------------------------";
    mostrartitulo.gotoxy(1,9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MEN\xE9";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorDef());

    for(j=0;j<ContadorInventario;j++)
    {
        mostrartitulo.gotoxy(3,14+j);
        cout << j+1;
        mostrartitulo.gotoxy(8,14+j);
        cout << Inventario.getCodigo(j);
        mostrartitulo.gotoxy(24,14+j);
        cout << Inventario.getFechaIngreso(j);
        mostrartitulo.gotoxy(36,14+j);
        cout << Inventario.getNombre(j);
        cout.precision(2);
        mostrartitulo.gotoxy(50,14+j);
        cout << fixed << Inventario.getPeso(j) << " kg";
        mostrartitulo.gotoxy(63,14+j);
        cout << fixed << Inventario.getCosto(j) << " MXN";
        mostrartitulo.gotoxy(74,14+j);
        cout << fixed << Inventario.getPrecio(j) << " MXN";
        mostrartitulo.gotoxy(88,14+j);
        cout << fixed << Inventario.getPiezas(j) << " Pz";
        mostrartitulo.gotoxy(100,14+j);
        cout << fixed << Inventario.getMenudeo(j) << " MXN";
        mostrartitulo.gotoxy(115,14+j);
        cout << fixed << Inventario.getMayoreo(j) << " MXN";
        mostrartitulo.gotoxy(128,14+j);
        cout << fixed << Inventario.getValor(j) << " MXN";
    }

    mostrartitulo.gotoxy(1, 15+j);
    cout <<"------------------------------------------------------------------------------";
    mostrartitulo.gotoxy(57, 16+j);
    cout << "TOTAL : ";
    mostrartitulo.gotoxy(70, 16+j);

    for (i=0;i<ContadorInventario;i++)
    {
        Total += Inventario.getValor(i);
    }
    cout << Total;

    mostrartitulo.gotoxy(39, 17+j);
    cout << "REPORTE ULTIMA GANANCIA : ";
    mostrartitulo.gotoxy(70, 17+j);
    cout << Total_Inventario;

    mostrartitulo.gotoxy(22,9);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch(mostrartitulo.getKEYPAD())
            {
                case TECLA_ENTER:
                {
                    os.~OS();
                    mostrartitulo.~Menu();
                    return 0;
                }
            }
            //gotoxy(22,Cursor_Pos);
        }
      }while(mostrartitulo.getKEYPAD()!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}


/********************************************************************
*                       Función: Guardar_Archivo                    *
* Argumentos de Entrada:                                            *
* Ninguno: N/A                                                      *
* Argumentos de Salida:                                             *
*- Valor entero solamente para indicar el fin de esta función.      *
* Esta función guarda el registro dentro de un archivo.             *
********************************************************************/
int CRUDProductos::Guardar_Archivo()
{
    //Instanciar OS
    OS();
    OS os;
    //Instanciar Menu
    Menu();
    Menu mostrartitulo;
    //Inicializar Cursor
    int Cursor_Pos = 13;
    //Variable para total;
    float Total = 0;
    //Nombre de Archivo que se guardará
    char Nombre_Archivo[Max_Chars];
    //Variables para ciclos for
    int i,j;

    //Borrar terminal
    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(22,9);
    cout << ">> GUARDAR REPORTE <<" << endl;
    mostrartitulo.gotoxy(3,13);
    cout << "NOMBRE ARCHIVO :   " << Nombre_Archivo <<endl;
    mostrartitulo.gotoxy(3,15);
    cout << "<< GUARDAR >>" << endl;
    mostrartitulo.gotoxy(3,17);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MEN\xE9" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mostrartitulo.getColorDef());

    mostrartitulo.gotoxy(25,Cursor_Pos);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch(mostrartitulo.getKEYPAD())
            {
                case TECLA_ARRIBA:
                {
                    if(Cursor_Pos>13){
                        Cursor_Pos=Cursor_Pos-2;
                    }
                }
                break;

                case TECLA_ABAJO:
                {
                    if(Cursor_Pos<17){
                        Cursor_Pos=Cursor_Pos+2;
                    }
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            mostrartitulo.gotoxy(24,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(24,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";
                            //cin.getline (Name,Max_Chars,'\n');

                            cin >> Nombre_Archivo;
                            cin.clear();
                            cin.ignore(10, '\n');
                            mostrartitulo.gotoxy(39,Cursor_Pos);
                            cout << "Listo";

                            for (int i = 0 ; i<Max_Chars ; i++)
                            {
                                Nombre_Archivo[i] = toupper(Nombre_Archivo[i]);
                                if(Nombre_Archivo[i]=='\0'){
                                    break;
                                }
                            }
                        break;

                        case 15:
                            if (Nombre_Archivo[0] == '\0')
                            {
                                mostrartitulo.Mostrar_Error((char *) "ERROR: INTRODUCE EL NOMBRE PRIMERO.", 1500);
                            }
                            else
                            {
                                ofstream file (Nombre_Archivo);
                                if (file.is_open())
                                {
                                    file << "                            >> REPORTE PRODUCTOS <<                               " << endl;
                                    file << " ------------------------------------------------------------------------------ " << endl;
                                    file << "|\tNum.\t|\tNOMBRE\t|\tCOMPRA\t|\tVENTA\t|\tCANTIDAD\t|\t VALOR\t|" << endl;
                                    file << " ------------------------------------------------------------------------------ " << endl;
                                    file << endl;


                                    for(j=0;j<ContadorInventario;j++)
                                    {
                                        file << "#\t" << j+1 << "\t\t";
                                        file << Inventario.getNombre(j);
                                        file << setprecision(2);
                                        file << "\t\t" << fixed << Inventario.getCosto(j);
                                        file << "\t\t" << fixed << Inventario.getPrecio(j);
                                        file << "\t\t" << fixed << Inventario.getPiezas(j);
                                        file << "\t\t" << fixed << Inventario.getValor(j)<< endl;
                                    }

                                    file << endl;
                                    file <<"------------------------------------------------------------------------------" << endl;
                                    file << "\t\t\t\t\t\t\t\t\t\tTOTAL $ ";

                                    for (i=0;i<ContadorInventario;i++)
                                    {
                                        Total += Inventario.getValor(i);
                                    }
                                    file << Total;

                                    file.close();
                                    mostrartitulo.gotoxy(25,25);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                    mostrartitulo.getColorVerde());
                                    cout << "ARCHIVO GUARDADO CORRECTAMENTE.";
                                    os.Dormir(1500);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
                                    mostrartitulo.getColorDef());
                                    os.~OS();
                                    mostrartitulo.~Menu();
                                    return 0;
                                }
                                else
                                {
                                    mostrartitulo.Mostrar_Error((char *) "ERROR: ARCHIVO NO GUARDADO.", 1500);
                                    os.~OS();
                                    mostrartitulo.~Menu();
                                    return 0;
                                }
                            }
                        break;

                        case 17:
                            os.~OS();
                            mostrartitulo.~Menu();
                            return 0;
                        break;
                    }
                }
            }
            mostrartitulo.gotoxy(25,Cursor_Pos);
        }
      }while(mostrartitulo.getKEYPAD()!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}

/********************************************************************************************
*                       Función:  Cargar_Archivo                                            *
* Argumentos de Entrada:                                                                    *
* Ninguno: N/A                                                                              *
* Argumentos de Salida:                                                                     *
*- Valor entero solamente para indicar o puntualizar la finalización de dicha función.      *
* Esta función carga un registro previamente guardado en un archivo.                        *
********************************************************************************************/
int CRUDProductos::Cargar_Archivo()
{
    //Instanciar OS
    OS();
    OS os;
    //Instanciar Menú
    Menu();
    Menu mostrartitulo;
    //Inicializar Cursor
    int Cursor_Pos = 13;
    //Variable para medir la fila de la Cadena
    char Fila_Cadena[50];
    char Nombre_Archivo[Max_Chars];
    //Variable para Nombre
    char Nombre[Max_Chars];
    //Variable para iniciar Costo y Precio
    float Costo = 0, Precio = 0;
    //Variables para valor y piezas
    int Piezas;
    float Valor;
    //Variables para ciclos for
    int i;

    //Borrar terminal
    os.BorrarConsola();
    mostrartitulo.Mostrar_Titulo();
    mostrartitulo.gotoxy(23,9);
    cout << ">> CARGAR REPORTE <<" << endl;
    mostrartitulo.gotoxy(3,13);
    cout << "Nombre Archivo : " << endl;
    mostrartitulo.gotoxy(3,15);
    cout << "<< CARGAR >>" << endl;
    mostrartitulo.gotoxy(3,17);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
    mostrartitulo.getColorVerde());
    cout << " << REGRESAR A MENU" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
    mostrartitulo.getColorDef());

    mostrartitulo.gotoxy(25,Cursor_Pos);

    do{
        if (kbhit())
        {
            mostrartitulo.setKEYPAD(getch());

            switch(mostrartitulo.getKEYPAD())
            {
                case TECLA_ARRIBA:
                {
                    if(Cursor_Pos>13){
                        Cursor_Pos=Cursor_Pos-2;
                    }
                }
                break;

                case TECLA_ABAJO:
                {
                    if(Cursor_Pos<17){
                        Cursor_Pos=Cursor_Pos+2;
                    }
                }
                break;

                case TECLA_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            mostrartitulo.gotoxy(24,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << "                    ";
                            mostrartitulo.gotoxy(24,Cursor_Pos);
                            cout << mostrartitulo.getCursor() << " ";

                            cin >> Nombre_Archivo;
                            cin.clear();
                            cin.ignore(10, '\n');
                            mostrartitulo.gotoxy(39,Cursor_Pos);
                            cout << "Listo";

                            for(i=0;i<Max_Chars;i++)
                            {
                                Nombre_Archivo[i] = toupper(Nombre_Archivo[i]);
                                if (Nombre_Archivo[i]=='\0'){
                                    break;
                                }
                            }
                        break;

                        case 15:
                            if (Nombre_Archivo[0] == '\0')
                            {
                                mostrartitulo.Mostrar_Error((char *) "ERROR: INTRODUCE EL NOMBRE PRIMERO.", 1500);
                            }
                            else
                            {
                                ifstream file (Nombre_Archivo);
                                if (file.is_open())
                                {
                                    while(!file.eof())
                                    {
                                        file >> Fila_Cadena;

                                        if (Fila_Cadena[0] == '#')
                                        {
                                            file >> Fila_Cadena;
                                            file >> Nombre;
                                            file >> Costo;
                                            file >> Precio;
                                            file >> Piezas;
                                            file >> Valor;

                                            if (Nombre[0] != '\0')
                                            {
                                                
                                                
                                                Inventario.setNombre(ContadorInventario,Nombre);
                                                Inventario.setCosto(ContadorInventario,Costo);
                                                Inventario.setPrecio(ContadorInventario,Precio);
                                                Inventario.setValor(ContadorInventario,Valor);
                                                Inventario.setPiezas(ContadorInventario,0);

                                                ContadorInventario++;
                                            }
                                        }
                                        if (Fila_Cadena[0] == '$') file >> Total_Inventario;
                                    }

                                    if (ContadorInventario == 0)
                                    {
                                        mostrartitulo.Mostrar_Error((char *) "EL ARCHIVO NO PUEDE CARGAR LA INFORMACION.", 1500);
                                        file.close();
                                        os.~OS();
                                        mostrartitulo.~Menu();
                                        return 0;
                                    }
                                    else
                                    {
                                        mostrartitulo.gotoxy(25,25);
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                        mostrartitulo.getColorVerde());
                                        cout << "ARCHIVO CARGADO CON \x90XITO.";
                                        os.Dormir(1500);
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                        mostrartitulo.getColorDef());
                                        file.close();
                                        os.~OS();
                                        mostrartitulo.~Menu();
                                        return 0;
                                    }

                                }
                                else
                                {
                                    mostrartitulo.Mostrar_Error((char *) "ERROR: EL ARCHIVO NO SE ABRIO.", 1500);
                                    os.~OS();
                                    mostrartitulo.~Menu();
                                    return 0;
                                }
                            }
                        break;

                        case 17:
                            os.~OS();
                            mostrartitulo.~Menu();
                            return 0;
                        break;
                    }
                }
            }
            mostrartitulo.gotoxy(25,Cursor_Pos);
        }
      }while (mostrartitulo.getKEYPAD()!=27);
    os.~OS();
    mostrartitulo.~Menu();
    return 0;
}
#elif __linux__
#define TEST 2
#endif