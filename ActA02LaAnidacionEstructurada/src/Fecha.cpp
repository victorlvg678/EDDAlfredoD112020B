//Archivo de implementación de métodos de clase Fecha
#include "../include/Fecha.h"
#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

//Función Constructor
Fecha::Fecha(void){
    strcpy(FechaC,(char*)"00/00/00");
}
//Función Constructor Copia
Fecha::Fecha(const Fecha &FechaOriginal){
    strcpy(FechaC,FechaOriginal.FechaC);
}
//Función Destructor
Fecha::~Fecha(){
    
}
//Setters
//Función para establecer Fecha
void Fecha::setFecha(char* FechaAsignada){
    //Inicializar variable de ciclo for
    int i;
    //Verificar Longitud de FechaAsignada
    if(sizeof(FechaAsignada)==0 || FechaAsignada[0]=='\0'){
        //Iniciar variable de tiempo
        time_t tiempotemp;
        //Puntero a struct de tm de ctime
  	    struct tm * infotiempo;
        //Buffer para guardar posterior formato
	    char buffer[8];
        //Mandar time para tiemptemp
	    time (&tiempotemp);
        //localtime a timeinfo
 	    infotiempo = localtime (&tiempotemp);
	    //Establecer formato de tiempo y mandarlo a buffer
        strftime(buffer,80,"%d/%m/%y",infotiempo);
        //Asignar fecha de buffer a FechaC
        for(i=0;i<8;i++){
            FechaC[i]=buffer[i];
        }
    }else{
        //Comprobar longitud de 1 a 8
        if((sizeof(FechaAsignada)>0 && sizeof(FechaAsignada)<=8) && FechaAsignada[0]!='\0'){
            //Asignar FechaAsignada a FechaC
            for(i=0;i<8;i++){
                FechaC[i]=FechaAsignada[i];
            }
        }
    }
}
//Getters
//Función para obtener Fecha
char* Fecha::getFecha(){
    if(sizeof(FechaC)>0 || FechaC[0]!='\0'){
        return FechaC;
    }else{
        return (char*)"00/00/00";
    }
}