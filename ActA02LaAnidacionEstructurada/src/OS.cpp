//Archivo .cpp para funciones de OS
#include "../include/OS.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

//Función Constructor
OS::OS(void){

}
//Función Constructor Copia
/*OS::OS(const OS &OSOriginal){

}*/
//Función Destructor
OS::~OS(){

}
//Función para banner inicial
void OS::banner(){
    if(WINDOWS){
        printf("\n\n\n\n\n");
        //Primera linea parte superior
        printf("\t\t\t\t\t");
        printf("%c%c%c%c%c%c",ESQSIZQ,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c\n",HORIZONTAL,HORIZONTAL,HORIZONTAL,ESQSDER);
        //Cuerpo
        //-------|                            |-----------------------
        printf("\t\t\t\t\t");
        printf("%c                            %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c         Act. A02           %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c          CUCEI             %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c        Estructura          %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c            de              %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c          Datos I           %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c       Secci%cn D11          %c\n",VERTICAL,OMINACENTUADA,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c   Victor Leonardo Valle G. %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c         215661917          %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c  victorlvg678%cgmail.com    %c\n",VERTICAL,ARROBA,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c       Copyright %c          %c\n",VERTICAL,COPYRIGHT,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c     All rights reserved    %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c      Derechos de Autor     %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c    Todos los Derechos      %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c        Reservados          %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c                            %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c       18/Sep/2020          %c\n",VERTICAL,VERTICAL);
        printf("\t\t\t\t\t");
        printf("%c                            %c\n",VERTICAL,VERTICAL);
        //Ultima linea
        printf("\t\t\t\t\t");
        printf("%c%c%c%c%c%c",ESQIIZQ,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
        printf("%c%c%c%c\n",HORIZONTAL,HORIZONTAL,HORIZONTAL,ESQIDER);
        }else{
            if(LINUX){
                //Primera linea parte superior
                printf("%c%c%c%c%c%c",ESQSIZQ,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c\n",HORIZONTAL,HORIZONTAL,HORIZONTAL,ESQSDER);
                //Cuerpo
                //-------|                            |-----------------------
                printf("%c                            %c\n",VERTICAL,VERTICAL);
                printf("%c          \030[5mAct. A02          %c\n",VERTICAL,VERTICAL);
                printf("%c           CUCEI            %c\n",VERTICAL,VERTICAL);
                printf("%c          Estructura        %c\n",VERTICAL,VERTICAL);
                printf("%c             de             %c\n",VERTICAL,VERTICAL);
                printf("%c           Datos I          %c\n",VERTICAL,VERTICAL);
                printf("%c       Secci%cn D11          %c\n",VERTICAL,OMINACENTUADA,VERTICAL);
                printf("%c   Victor Leonardo Valle G. %c\n",VERTICAL,VERTICAL);
                printf("%c         215661917          %c\n",VERTICAL,VERTICAL);
                printf("%c  victorlvg678%cgmail.com    %c\n",VERTICAL,ARROBA,VERTICAL);
                printf("%c       Copyright %c          %c\n",VERTICAL,COPYRIGHT,VERTICAL);
                printf("%c     All rights reserved    %c\n",VERTICAL,VERTICAL);
                printf("%c      Derechos de Autor     %c\n",VERTICAL,VERTICAL);
                printf("%c    Todos los Derechos      %c\n",VERTICAL,VERTICAL);
                printf("%c        Reservados          %c\n",VERTICAL,VERTICAL);
                printf("%c                            %c\n",VERTICAL,VERTICAL);
                printf("%c       18/Sep/2020          %c\n",VERTICAL,VERTICAL);
                printf("%c                            %c\n",VERTICAL,VERTICAL);
                //Ultima linea
                printf("%c%c%c%c%c%c",ESQIIZQ,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                printf("%c%c%c%c\n",HORIZONTAL,HORIZONTAL,HORIZONTAL,ESQIDER);
                }else{
                    printf("Error 003:Incapaz de imprimir de una manera adecuada el banner.OS no");
                    printf(" identificado\n");
                    //Primera linea parte superior
                    //Primera linea parte superior
                    printf("%c%c%c%c%c%c",ESQSIZQ,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c\n",HORIZONTAL,HORIZONTAL,HORIZONTAL,ESQSDER);
                    //Cuerpo
                    //-------|                            |-----------------------
                    printf("%c                            %c\n",VERTICAL,VERTICAL);
                    printf("%c         Act. A02           %c\n",VERTICAL,VERTICAL);
                    printf("%c          CUCEI             %c\n",VERTICAL,VERTICAL);
                    printf("%c        Estructura          %c\n",VERTICAL,VERTICAL);
                    printf("%c            de              %c\n",VERTICAL,VERTICAL);
                    printf("%c          Datos I           %c\n",VERTICAL,VERTICAL);
                    printf("%c       Secci%cn D11          %c\n",VERTICAL,OMINACENTUADA,VERTICAL);
                    printf("%c   Victor Leonardo Valle G. %c\n",VERTICAL,VERTICAL);
                    printf("%c         215661917          %c\n",VERTICAL,VERTICAL);
                    printf("%c  victorlvg678%cgmail.com    %c\n",VERTICAL,ARROBA,VERTICAL);
                    printf("%c       Copyright %c          %c\n",VERTICAL,COPYRIGHT,VERTICAL);
                    printf("%c     All rights reserved    %c\n",VERTICAL,VERTICAL);
                    printf("%c      Derechos de Autor     %c\n",VERTICAL,VERTICAL);
                    printf("%c    Todos los Derechos      %c\n",VERTICAL,VERTICAL);
                    printf("%c        Reservados          %c\n",VERTICAL,VERTICAL);
                    printf("%c                            %c\n",VERTICAL,VERTICAL);
                    printf("%c       18/Sep/2020          %c\n",VERTICAL,VERTICAL);
                    printf("%c                            %c\n",VERTICAL,VERTICAL);
                    //Ultima linea
                    printf("%c%c%c%c%c%c",ESQIIZQ,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c%c",HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL,HORIZONTAL);
                    printf("%c%c%c%c\n",HORIZONTAL,HORIZONTAL,HORIZONTAL,ESQIDER);

                };
            };
}
//Función para borrar consola dependiendo del OS
void OS::BorrarConsola(){
    if(WINDOWS){
        system("cls");
    }else{
        if(LINUX){
            system("clear");
        }else{
            printf("Error 001:Imposible borrar pantalla(SO no identificado)\n");
        };
    };
}
//Función para cambiar de color consola dependiendo del OS
void OS::ColorCMD(char * Color){
    if(WINDOWS){
        if(strcmp(Color,(char *)"Verde")==0){
            system("color 0A");
        }else{
            if(strcmp(Color,(char*)"Rojo")==0){
                system("color 04");
            }else{
                if(strcmp(Color,(char*)"Amarillo")==0){
                    system("color 06");
                }
            }
        }
    }else{
        if(LINUX){
            if(strcmp(Color,(char*)"Verde")==0){
                //Terminal o CLI color verde en ANSI Escape character
                printf("\033[0;32m");
            }
        };
    };
}
//Función para pausar la consola dependiendo del OS
void OS::Pausa(){
    if(WINDOWS){
        system("pause");
    }else{
        if(LINUX){
            system("sleep 5");
        };
    };
}
//Función para poner un delay en terminal
void OS::Dormir(int dormir){
    if(WINDOWS){
        Sleep(dormir);
    }else{
        if(LINUX){
            system("sleep 0");
        }else{
            printf("Error:OS no identificado\n");
        }
    };
}