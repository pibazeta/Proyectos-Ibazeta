#include <clsFAQ.h>
#include "clsCadenas.h"


void clsFAQ::MenuFaq(){
clsCadenas cad;


    bool salir=false;
    char op;

    while(!salir)
    {

        system("cls");
        cout<<"*--------------------MENU DE AYUDAS  --------------------*"<<endl;
        cout<<"* M)  AYUDA PARA OPERACIONES CON EL MENU MATERIAS        *"<<endl;
        cout<<"* A)  AYUDA PARA OPERACIONES CON EL MENU ALUMNOS         *"<<endl;
        cout<<"* C)  AYUDA PARA OPERACIONES CON EL ASIGNACIONES         *"<<endl;
        cout<<"* E)  EJEMPLOS DE LISTADOS CON DATOS CARGADOS            *"<<endl;
        cout<<"* S)  VOLVER AL MENU PRINCIPAL                           *"<<endl;
        cout<<"*--------------------------------------------------------*"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>op;
       // cin.ignore();

        switch(op)
        {

        case 'm' :
        case 'M':

        {

      AyudaMenuMateria();
     // cad.gotoxy(32,10);
      cout<<endl;
      system("pause");


        }
        break;

        case 'a':
        case 'A':

        AyudaMenuAlumno();
        system("pause");
        {



        }
        break;

        case 'c':
        case 'C':

        {
        AyudaMenuAsignacion();
        system("pause");
        }
        break;

        case 'e':
        case 'E':
        {
        EjemploListados();
     //   system("pause");
        }
        break;

        case 's':
        case 'S':

        {
            salir=true;
            //system("pause");

        }
        break;

        default:
        {
            cout<<"OPCION INCORRECTA!!!";

        }
        break;


        }

        //cin.get();

    }///CIERRE WHILE.





}

void clsFAQ::AyudaMenuMateria(){
system("cls");
    cout<<endl;

    clsCadenas posicion;

    posicion.gotoxy(4,2);
    cout<<"AYUDA PARA OPERACIONES CON EL MENU MATERIAS."<<endl;
    posicion.gotoxy(4,3);
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<endl;
    posicion.gotoxy(4,4);
    cout<<"*la opcion (nueva materia)"<<endl;
    posicion.gotoxy(4,6);
    cout<<"pedira el ingreso de datos nombre de materia y nombre de profesor."<<endl;
    posicion.gotoxy(4,8);
    cout<<"NOTA : LOS ID SON AUTONUMERICOS."<<endl;
    posicion.gotoxy(4,9);
    cout<<"---------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,11);
    cout<<"*la opcion (listar)"<<endl;
    posicion.gotoxy(4,13);
    cout<<"listara cuando se ingrese un nombre de materia o parte de su nombre,"<<endl;
    posicion.gotoxy(4,14);
    cout<<"se listaran los campos nombre de la materia y nombre de profesor."<<endl;
    posicion.gotoxy(4,16);
    cout<<"---------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,18);
    cout<<"*la opcion (eliminar)"<<endl;
    posicion.gotoxy(4,20);
    cout<<"pedira un ingreso de id materia y se dara de baja la materia"<<endl;
    posicion.gotoxy(4,21);
    cout<<"si existe el id materia en el sistema."<<endl;
    posicion.gotoxy(4,22);
    cout<<"---------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,24);
    cout<<"*la opcion (modificar)"<<endl;
    posicion.gotoxy(4,26);
    cout<<"pedira un ingreso de id materia y si existe permitira modificar sus campos."<<endl;
    posicion.gotoxy(4,28);
    cout<<"------------------------------------------------------"<<endl;
    posicion.gotoxy(4,30);
    cout<<"PARA VOLVER AL MENU ANTERIOR PRESIONE LA TECLA ENTER!!"<<endl;






}

void clsFAQ::AyudaMenuAlumno(){
system("cls");
    cout<<endl;

    clsCadenas posicion;

    posicion.gotoxy(4,2);
    cout<<"AYUDA PARA OPERACIONES CON EL MENU ALUMNOS."<<endl;
    posicion.gotoxy(4,3);
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    posicion.gotoxy(4,4);
    cout<<"*La opcion (nueva alumno)"<<endl;
    posicion.gotoxy(4,6);
    cout<<"pedira el ingreso de datos : Legajo,Nombre,Fecha Dia,Mes,Anio."<<endl;
    posicion.gotoxy(4,8);
    cout<<"NOTA : LOS LEGAJOS SON SE REPITEN."<<endl;
    posicion.gotoxy(4,9);
    cout<<"---------------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,11);
    cout<<"*La opcion (listar)"<<endl;
    posicion.gotoxy(4,13);
    cout<<"listara cuando se ingrese un nombre de alumno o parte de su nombre,"<<endl;
    posicion.gotoxy(4,14);
    cout<<"se listaran los campos Legajo,Nombre del alumno y Fecha de nacimiento."<<endl;
    posicion.gotoxy(4,16);
    cout<<"----------------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,18);
    cout<<"*La opcion (eliminar)"<<endl;
    posicion.gotoxy(4,20);
    cout<<"pedira el ingreso numero de legajo y se dara de baja el alumno,"<<endl;
    posicion.gotoxy(4,21);
    cout<<"del sistema si existe ese legajo."<<endl;
    posicion.gotoxy(4,23);
    cout<<"-----------------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,24);
    cout<<"*La opcion (modificar)"<<endl;
    posicion.gotoxy(4,26);
    cout<<"pedira el ingreso de un numero de legajo y si existe el legajo."<<endl;
    posicion.gotoxy(4,27);
    cout<<"permitira modificar sus campos."<<endl;
    posicion.gotoxy(4,28);
    cout<<"------------------------------------------------------"<<endl;
    posicion.gotoxy(4,30);
    cout<<"PARA VOLVER AL MENU ANTERIOR PRESIONE LA TECLA ENTER!!"<<endl<<endl;



}

void clsFAQ::AyudaMenuAsignacion(){

system("cls");
    cout<<endl;

    clsCadenas posicion;

    posicion.gotoxy(4,2);
    cout<<"AYUDA PARA OPERACIONES CON EL MENU ASIGNACION."<<endl;
    posicion.gotoxy(4,3);
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    posicion.gotoxy(4,4);
    cout<<"*La opcion (asignar alumnos a materias)"<<endl;
    posicion.gotoxy(4,5);
    cout<<"pedira el ingreso de datos : ID Materia,Legajo, "<<endl;
    posicion.gotoxy(4,7);
    cout<<"(NOTA : si los ingresos de id materia y legajo no existen en el sistema. "<<endl;
    posicion.gotoxy(4,9);
    cout<<"la asignacion no sera dada de alta.)"<<endl;
    posicion.gotoxy(4,10);
    cout<<"-------------------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,11);
    cout<<"*La opcion (listar alumnos por materias)"<<endl;
    posicion.gotoxy(4,13);
   // cout<<"listara cuando se ingrese un nombre de alumno o parte de su nombre,"<<endl;
    //posicion.gotoxy(4,15);
    cout<<"listara todos los alumnos que fueron asignados a alguna materia "<<endl;
    posicion.gotoxy(4,15);
    cout<<"y listara los campos Legajo,Nombre del alumno y Nombre de la materia. "<<endl;

    posicion.gotoxy(4,16);
    cout<<"-------------------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,18);
    cout<<"*la opcion (listado de materias por alumnos)"<<endl;
    posicion.gotoxy(4,20);
    cout<<"listara los campos Nombre de materia,Nombre de Profesor,Nombre de Alumno."<<endl;
    posicion.gotoxy(4,22);
    cout<<"(una vez hecha la asignacion de alumnos por materia)"<<endl;
    posicion.gotoxy(4,23);
    cout<<"-------------------------------------------------------------------------"<<endl;
    posicion.gotoxy(4,25);
    cout<<"*la opcion (dar de baja un alumno a una materia)"<<endl;
    posicion.gotoxy(4,27);
    cout<<"pedira el ingreso de un numero de legajo y si existe el legajo del alumno "<<endl;
    posicion.gotoxy(4,29);
    cout<<"en el sistema este sera dado de baja."<<endl;
    posicion.gotoxy(4,30);
    cout<<"------------------------------------------------------"<<endl;
    posicion.gotoxy(4,31);
    cout<<"PARA VOLVER AL MENU ANTERIOR PRESIONE LA TECLA ENTER!!"<<endl<<endl;



}

void clsFAQ::EjemploListados(){



    system("cls");
    cout<<endl;

    clsCadenas posicion;

    posicion.gotoxy(4,2);
    cout<<"EJEMPLOS DE DIFERENTES TIPOS DE LISTADOS."<<endl;
    posicion.gotoxy(4,3);
    cout<<"-----------------------------------------------"<<endl;
    posicion.gotoxy(4,5);
    cout<<"(VAMOS A USAR COMO REFERECIA ESTOS DATOS PARA LAS CARGAS)."<<endl;
    posicion.gotoxy(4,6);
    cout<<"*Ejemplo para la carga de datos para Materia."<<endl;
    posicion.gotoxy(4,8);
    cout<<"ID MATERIA"<<endl;
    posicion.gotoxy(4,10);
    cout<<"1"<<endl;
    posicion.gotoxy(4,11);
    cout<<"2"<<endl;
    posicion.gotoxy(19,8);
    cout<<"NOMBRE"<<endl;
    posicion.gotoxy(19,10);
    cout<<"laboratorio"<<endl;
    posicion.gotoxy(19,11);
    cout<<"programacion"<<endl;
    posicion.gotoxy(35,8);
    cout<<"PROFESOR"<<endl;
    posicion.gotoxy(35,10);
    cout<<"saul"<<endl;
    posicion.gotoxy(35,11);
    cout<<"saul"<<endl;
    posicion.gotoxy(4,12);
    cout<<"----------------------------------------------------"<<endl;
    posicion.gotoxy(4,14);
    cout<<"*Ejemplo para la carga de datos para Alumno."<<endl;
    posicion.gotoxy(4,16);
    cout<<"LEGAJO"<<endl;
    posicion.gotoxy(4,18);
    cout<<"18599"<<endl;
    posicion.gotoxy(4,19);
    cout<<"18599"<<endl;
    posicion.gotoxy(19,16);
    cout<<"NOMBRE"<<endl;
    posicion.gotoxy(19,18);
    cout<<"agustin"<<endl;
    posicion.gotoxy(19,19);
    cout<<"maxi"<<endl;
    posicion.gotoxy(30,16);
    cout<<"DIA/MES/ANIO"<<endl;
    posicion.gotoxy(30,18);
    cout<<"18/3/1995"<<endl;
    posicion.gotoxy(30,19);
    cout<<"1/3/1990"<<endl;
    posicion.gotoxy(4,20);
    cout<<"------------------------------------------------------"<<endl;
    posicion.gotoxy(4,22);
    cout<<"*Ejemplo para la carga de datos en la Asignacion."<<endl;
    posicion.gotoxy(4,24);
    cout<<"ID MATERIA"<<endl;
    posicion.gotoxy(4,26);
    cout<<"1"<<endl;
    posicion.gotoxy(4,27);
    cout<<"2"<<endl;
    posicion.gotoxy(4,28);
    cout<<"1"<<endl;
    posicion.gotoxy(19,24);
    cout<<"LEGAJO"<<endl;
    posicion.gotoxy(19,26);
    cout<<"18599"<<endl;
    posicion.gotoxy(19,27);
    cout<<"18599"<<endl;
    posicion.gotoxy(19,28);
    cout<<"1234"<<endl;
    posicion.gotoxy(4,29);
    cout<<"------------------------------------------------------"<<endl;
    posicion.gotoxy(4,32);
    cout<<"*UNA VEZ HECHA TODAS LAS CAGAR DE LOS MENUS MATERIAS,ALUMNO,ASIGNACION."<<endl;
    posicion.gotoxy(4,34);
    cout<<"veremos como se mostraran los listados."<<endl;
    posicion.gotoxy(4,36);
    cout<<"CASO 1:"<<endl;
    posicion.gotoxy(4,38);
    cout<<"visualizaremos el Listado por materia y el Listado por alumno"<<endl;
    posicion.gotoxy(4,39);
    cout<<"sin que no hagamos ningun tipo de baja (id materia ,legajo)."<<endl;
    posicion.gotoxy(4,41);
    cout<<"(LISTADO DE ALUMNOS POR MATERIA)"<<endl;
    posicion.gotoxy(4,42);
    cout<<"LEGAJO"<<endl;
    posicion.gotoxy(4,44);
    cout<<"18599"<<endl;
    posicion.gotoxy(4,45);
    cout<<"18599"<<endl;
    posicion.gotoxy(4,46);
    cout<<"1234"<<endl;
    posicion.gotoxy(19,42);
    cout<<"NOMBRE"<<endl;
    posicion.gotoxy(19,44);
    cout<<"agustin"<<endl;
     posicion.gotoxy(19,45);
    cout<<"agustin"<<endl;
     posicion.gotoxy(19,46);
    cout<<"maxi"<<endl;
    posicion.gotoxy(30,42);
    cout<<"MATERIA"<<endl;
    posicion.gotoxy(30,44);
    cout<<"laboratorio"<<endl;
    posicion.gotoxy(30,45);
    cout<<"programacion"<<endl;
    posicion.gotoxy(30,46);
    cout<<"laboratorio"<<endl;
      posicion.gotoxy(4,48);
    cout<<"(LISTADO DE MATERIAS POR ALUMNOS)"<<endl;
    posicion.gotoxy(4,50);
    cout<<"MATERIA"<<endl;
    posicion.gotoxy(4,52);
    cout<<"laboratorio"<<endl;
    posicion.gotoxy(4,53);
    cout<<"programacion"<<endl;
    posicion.gotoxy(4,54);
    cout<<"laboratorio"<<endl;
    posicion.gotoxy(19,50);
    cout<<"PROFESOR"<<endl;
    posicion.gotoxy(19,52);
    cout<<"saul"<<endl;
     posicion.gotoxy(19,53);
    cout<<"saul"<<endl;
     posicion.gotoxy(19,54);
    cout<<"saul"<<endl;
    posicion.gotoxy(30,50);
    cout<<"Nombre de alumno"<<endl;
    posicion.gotoxy(30,52);
    cout<<"agustin"<<endl;
    posicion.gotoxy(30,53);
    cout<<"agustin"<<endl;
    posicion.gotoxy(30,54);
    cout<<"maxi"<<endl;
    posicion.gotoxy(4,57);
    cout<<"CASO 2: "<<endl;
    posicion.gotoxy(4,58);
    cout<<"EN EL CASO QUE VALLAMOS A LOS ELIMINADOS DEL MENU MATERIAS Y MENU ALUMNOS."<<endl;
    posicion.gotoxy(4,59);
    cout<<"Y ELIMINEMOS DEL MENU MATERIA EL ID MATERIA: 1"<<endl;
    posicion.gotoxy(4,60);
    cout<<"Y ELIMINEMOS DEL MENU ALUMNOS EL LEGAJO: 18599"<<endl;
    posicion.gotoxy(4,62);
    cout<<"a la hora de la visializacion no se listara ningun campo"<<endl;
    posicion.gotoxy(4,63);
    cout<<"cuando vallamos al menu asignacion y ultilizemos los listados. "<<endl;
    posicion.gotoxy(4,66);
    cout<<"CASO 3: "<<endl;
    posicion.gotoxy(4,68);
    cout<<"EN EL CASO QUE VALLAMOS A LOS ELIMINADOS DEL MENU MATERIAS Y MENU ALUMNOS."<<endl;
     posicion.gotoxy(4,69);
    cout<<"Y ELIMINEMOS DEL MENU MATERIA EL ID MATERIA: 2"<<endl;
    posicion.gotoxy(4,70);
    cout<<"Y ELIMINEMOS DEL MENU ALUMNOS EL LEGAJO: 1234"<<endl;
    posicion.gotoxy(4,72);
    cout<<"EN ESTE CASO SI NOS LISTARA."<<endl;
    posicion.gotoxy(4,73);
    cout<<"-----------------------------------------------------"<<endl;
    posicion.gotoxy(4,74);
    cout<<"*(LISTAR ALUMNOS POR MATERIAS)"<<endl;
    posicion.gotoxy(4,76);
    cout<<"mostrara como resultado estos datos."<<endl;
    posicion.gotoxy(4,79);
    cout<<"LEGAJO"<<endl;
    posicion.gotoxy(4,81);
    cout<<"18599"<<endl;
    posicion.gotoxy(19,79);
    cout<<"NOMBRE DE ALUMNO"<<endl;
    posicion.gotoxy(19,81);
    cout<<"agustin"<<endl;
    posicion.gotoxy(40,79);
    cout<<"NOMBRE DE LA MATERIA"<<endl;
    posicion.gotoxy(40,81);
    cout<<"laboratorio"<<endl;
    posicion.gotoxy(4,83);
    cout<<"*(LISTADO DE MATERIAS POR ALUMNOS)"<<endl;
    posicion.gotoxy(4,85);
    cout<<"MATERIA"<<endl;
    posicion.gotoxy(4,87);
    cout<<"laboratorio"<<endl;
    posicion.gotoxy(19,85);
    cout<<"PROFESOR"<<endl;
    posicion.gotoxy(19,87);
    cout<<"saul"<<endl;
    posicion.gotoxy(30,85);
    cout<<"ALUMNO"<<endl;
    posicion.gotoxy(30,87);
    cout<<"agustin"<<endl;

    posicion.gotoxy(4,90);
    cout<<"------------------------------------------------------"<<endl;
    posicion.gotoxy(4,91);
    cout<<"PARA VOLVER AL MENU ANTERIOR PRESIONE LA TECLA ENTER!!"<<endl<<endl;

    posicion.gotoxy(4,95);
    system("pause");



}

