#include "clsAlumnoView.h"

void clsAlumnoView::MenuAlumo()
{



    clsAlumnoDAO dao;

    bool salir=false;
    char op;

    while(!salir)
    {

        system("cls");
        cout<<"*--------------------MENU ALUMNOS  ----------------------*"<<endl;
        cout<<"* N - NUEVO ALUMNO                                       *"<<endl;
        cout<<"* L - LISTAR                                             *"<<endl;
        cout<<"* E - ELIMINAR                                           *"<<endl;
        cout<<"* M - MODIFICAR                                          *"<<endl;
        cout<<"* S - SALIR                                              *"<<endl;
        cout<<"*--------------------------------------------------------*"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>op;
        cin.ignore();

        switch(op)
        {

        case 'n':
        case 'N':
        {
            if( Insertar() ==true )
            {

                cout<<endl<<endl;
                cout<<"OPERACION REALIZADA CON EXITO."<<endl; ///COMO ES UN METODO DE ESTA CLASE EN LA PARTE ESTE DEL MENU SE PUEDE LLAMAR ASI
                ///ES LO MISMO  this->Insertar();
                system("pause");
            }
            else
            {
                cout<<endl<<endl;
                cout<<"EL LEGAJO YA SE ENCUENTRA EN EL SISTEMA."<<endl;
                system("pause");

            }
        }
        break;

        case 'l':
        case 'L':
        {

            Listar();
            cout<<endl;
            system("pause");

        }
        break;

        case 'e':
        case 'E':
        {
            Eliminar();
            system("pause");
//   EliminarListados();
        }
        break;



        case 'm':
        case 'M':
        {
            Modificar();


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

        cin.get();

    }///CIERRE WHILE.

}


bool clsAlumnoView::Insertar()
{

    clsAlumnoDTO dto;
    clsAlumnoBL bl;

    clsValidaciones val;  ///OBJ PARA VALIDAR TEXTO.

    int legajo;
    char nombre[50];
    int dia_nac;
    int mes_nac;
    int anio_nac;


    system("cls");
    cout<<"--------------NUEVO ALUMNO----------------"<<endl;
    cout<<endl;
    cout<<"INGRESE UN LEGAJO: ";
    cin>>legajo;

    bool valor= bl.DevuelveLegajoAlumno(legajo);

    if(valor==true)
    {

        return false;

    }

    cin.ignore();
    val.ValidarRequerido("INGRESE NOMBRE DEL ALUMNO: ",nombre,50);



    cout<<"INGRESE DIA DE NACIMIENTO: ";
    cin>>dia_nac;

    if(dia_nac < 1 || dia_nac > 31)
    {
        cout<<"ERROR EL DIA TIENE QUE SER VALIDO."<<endl;
        cout<<"INGRESE NUEVAMENTE."<<endl;
        cout<<endl;

        while(dia_nac < 1 || dia_nac> 31)
        {

            cout<<"INGRESE DIA DE NACIMIENTO: ";
            cin>>dia_nac;
        }
    }

    cout<<"INGRESE MES DE NACIMIENTO: ";
    cin>>mes_nac;

    if(mes_nac < 1 || mes_nac > 12)
    {
        cout<<"ERROR EL MES TIENE QUE SER VALIDO."<<endl;
        cout<<"INGRESE NUEVAMENTE."<<endl;
        cout<<endl;

        while(mes_nac < 1 || mes_nac > 12)
        {
            cout<<"INGRESE MES DE NACIMIENTO: ";
            cin>>mes_nac;
        }
    }

    cout<<"INGRESE ANIO DE NACIMIENTO: ";
    cin>>anio_nac;

    if(anio_nac < 1920 || anio_nac > 2019)
    {

        cout<<"ERROR EL ANIO TIENE QUE SER ENTRE (1920 Y 2019)"<<endl;
        cout<<"INGRESE NUEVAMENTE"<<endl;
        cout<<endl;

        while(anio_nac < 1920 || anio_nac > 2019)
        {
            cout<<"INGRESE ANIO DE NACIMIENTO: ";
            cin>>anio_nac;
        }
    }

    cout<<endl;

    dto.SetLegajo(legajo);
    dto.SetNombre(nombre);
    dto.SetDia_Nac(dia_nac);
    dto.SetMes_Nac(mes_nac);
    dto.SetAnio_Nac(anio_nac);

    bl.Insertar(dto);

    return true;


}


void clsAlumnoView::Listar()
{

    clsAlumnoBL bl;
    clsValidaciones val;

    char condicion[50];

    system("cls");
    cout<<endl;
    cout <<"---------------------------LISTADO DE ALUMNOS----------------------------------"<<endl;


    val.ValidarRequerido("INGRESE NOMBRE DEL ALUMNO: ",condicion,50);



    int c = bl.BuscarSubCount(condicion);


    clsAlumnoDTO* lista = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*c);


    bl.BuscarSub(lista,condicion);


    char nombre[50];


    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout <<"|"<<setw(10)<<left<< "LEGAJO"<<"|"<<setw(30)<<"NOMBRE DEL ALUMNO"<<"|"<<setw(1)<<"DIA DE NACIMIENTO"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(int x =0; x<c; x++)
    {



        lista[x].GetNombre(nombre);

        cout<<endl;
        cout <<"|"<<setw(10)<<right<< lista[x].GetLegajo()<<"|"<<setw(30)<<left<<nombre<<"|"<<setw(1)<<lista[x].GetDia_Nac()<<"/"<<lista[x].GetMes_Nac()<<"/"<<lista[x].GetAnio_Nac()<<"|"<<endl;



    }


}


void clsAlumnoView::Eliminar()
{

    clsAlumnoBL bl;

    bool valor=true;
    int legajo;

    system("cls");

    cout <<"---------------------------ELIMINAR----------------------------------"<<endl;
    cout<<"INGRESE LEGAJO: ";
    cin>>legajo;

    valor=bl.DevuelveLegajoAlumno(legajo);

    if(valor==true)
    {

        bl.Eliminar(legajo);

        cout<<endl<<endl;  ///USAR GOTOXI
        cout<<"LEGAJO ELIMINADO."<<endl;

    }
    else
    {
        cout<<endl<<endl; ///USAR GOTOXI
        cout<<"NO SE PUEDO ELIMINAR EL LEGAJO."<<endl;

    }




}


bool clsAlumnoView::Modificar()
{


    clsAlumnoDTO dto;

    clsAlumnoBL bl;

    clsValidaciones val;

    int legajo;
    int dia_nac,mes_nac,anio_nac;

    char nombre[50];

    system("cls");
    cout <<"---------------------------MODIFICACION----------------------------------"<<endl;

    cout<<"INGRESE LEGAJO A MODIFICAR: ";
    cin>>legajo;


    bool  valor=bl.DevuelveLegajoAlumno(legajo);
    if(valor==true)
    {

        cin.ignore();
        val.ValidarRequerido("INGRESE NOMBRE DEL ALUMNO: ",nombre,50);


        cout<<"INGRESE DIA DE NACIMIENTO: ";
        cin>>dia_nac;

        if(dia_nac < 1 || dia_nac > 31)
        {
            cout<<"ERROR EL DIA TIENE QUE SER VALIDO."<<endl;
            cout<<"INGRESE NUEVAMENTE."<<endl;
            cout<<endl;

            while(dia_nac < 1 || dia_nac> 31)
            {

                cout<<"INGRESE DIA DE NACIMIENTO: ";
                cin>>dia_nac;
            }
        }

        cout<<"INGRESE MES DE NACIMIENTO: ";
        cin>>mes_nac;

        if(mes_nac < 1 || mes_nac > 12)
        {
            cout<<"ERROR EL MES TIENE QUE SER VALIDO."<<endl;
            cout<<"INGRESE NUEVAMENTE."<<endl;
            cout<<endl;

            while(mes_nac < 1 || mes_nac > 12)
            {
                cout<<"INGRESE MES DE NACIMIENTO: ";
                cin>>mes_nac;
            }
        }

        cout<<"INGRESE ANIO DE NACIMIENTO: ";
        cin>>anio_nac;

        if(anio_nac < 1920 || anio_nac > 2019)
        {

            cout<<"ERROR EL ANIO TIENE QUE SER ENTRE (1920 Y 2019)"<<endl;
            cout<<"INGRESE NUEVAMENTE"<<endl;
            cout<<endl;

            while(anio_nac < 1920 || anio_nac > 2019)
            {
                cout<<"INGRESE ANIO DE NACIMIENTO: ";
                cin>>anio_nac;
            }
        }


        dto.SetNombre(nombre);

        dto.SetDia_Nac(dia_nac);

        dto.SetMes_Nac(mes_nac);

        dto.SetAnio_Nac(anio_nac);

        bl.Modificar(legajo,nombre,dia_nac,mes_nac,anio_nac);

        cout<<"EXITO AL MODIFICAR ALUMNO."<<endl;
        system("pause");
    }
    else
    {
        cout<<"EL LEGAJO INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        cout<<endl;
        system("pause");
    }




//return true;
}








