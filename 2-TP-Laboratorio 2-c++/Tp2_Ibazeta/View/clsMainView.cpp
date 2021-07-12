#include "clsMainView.h"
#include "clsCadenas.h"





void clsMainView::Menu(){
    clsCadenas cad;

    char op;
    bool salir=false;

    while(!salir){

    system("cls");
    cout<<"*-------------------------------------------*"<<endl;
    cout<<"* M - MATERIAS                              *"<<endl;
    cout<<"* A - ALUMNOS                               *"<<endl;
    cout<<"* C - ASIGNACION                            *"<<endl;
    cout<<"* F - FAQ                                   *"<<endl;
    cout<<"* S - SALIR                                 *"<<endl;
    cout<<"*-------------------------------------------*"<<endl;
    cout<<"INGRESE UNA OPCION: ";
    cin>>op;
    cin.ignore();




    switch(op){

    case 'm':
    case 'M':
    {
        clsMateriaView matView;
        matView.Menu();
    }break;

    case 'a':
    case 'A':
    {
        clsAlumnoView aluView;
        aluView.MenuAlumo();
    }break;

    case 'c':
    case 'C':
    {


    clsMatXAlumView matXalu;
    matXalu.MenuMatXAlum();
    }break;

    case 'f':
    case 'F':
    {
    clsFAQ faq;
    faq.MenuFaq();


    }break;


    case 's':
    case 'S':
    {
    salir=true;
    cout<<endl;
    system("cls");
    cad.gotoxy(32,10);
    cout<<"HASTA LUEGO.";


    }break;

    default:
    {
    cout<<"OPCION INCORRECTA!!!";

    }break;




    }
    cin.get();


    }///CIERRE WHILE.





}
