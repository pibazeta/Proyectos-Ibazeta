#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <windows.h>

void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

struct Fecha{
int dia,mes,anio;
};

struct analisis{

int codExt;
char  dni[10];
char apellido[50];
char nombre[50];
int edad;
Fecha FechaExt;
int tipoAnalisis;
int nivelColesterol;
float nivelGlobulosR;
float nivelGlobulosB;


};
#include "CargarDatos.h"
#include "Funciones.h"
#include "Extracciones.h"
#include "Reportes.h"

int main(){

setlocale(LC_ALL, "Spanish");
analisis vExt[15];
int cExt=0;

    //FUNCION PARA CARGAR LOS DATOS.
    cargar(vExt,&cExt);
    //SI NO LA QUIERO USAR LA COMENTO Y LISTO.

int opc;

while(true){

borrar();


    cout<<"MENU PRINCIPAL "<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1) EXTRACCIONES"<<endl;
    cout<<"2) REPORTES"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"0) SALIR DEL PROGRAMA"<<endl;

cout<<"INGRESE UNA OPCION: "<<endl;
cin>>opc;

    switch(opc){

case 1:
        menuExtracciones(vExt,&cExt);
break;

case 2: menuReportes(vExt,&cExt);
break;


case 0:return 0;


    }


}


}
