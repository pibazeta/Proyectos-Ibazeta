#include "clsMateriaView.h"


void clsMateriaView::Menu()
{
    clsMateriaDAO dao;

    bool valor=false;
    char op;
    bool salir=false;

    while(!salir)
    {

        system("cls");
        cout<<"*--------------------MENU MATERIAS ----------------------*"<<endl;
        cout<<"* N - NUEVA MATERIA                                      *"<<endl;
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
                cout<<"LA OPCION SE REALIZO CORRECTAMENTE."<<endl;
            }  ///COMO ES UN METODO DE ESTA CLASE EN LA PARTE ESTE DEL MENU SE PUEDE LLAMAR ASI
            ///ES LO MISMO  this->Insertar();
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
            EliminarListados();
        }
        break;



        case 'm':
        case 'M':
        {
            Modificar();
            // system("pause");

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

bool clsMateriaView::Insertar()
{



    char nombre[50];
    char profesor[50];

    clsMateriaDTO dto;
    clsMateriaBL bl;
    clsValidaciones val;

    system("cls");
    cout<<"--------------NUEVA MATERIA----------------"<<endl;

    cout<<endl;
    val.ValidarRequerido("INGRESE NOMBRE DE LA MATERIA: ",nombre,50);  ///MANDA A VALIDAR QUE SE INGRESE SOLO TEXTO.

    cout<<endl;
    val.ValidarRequerido("INGRESE NOMBRE DEL PROFESOR: ",profesor,50);



    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);

    return true;

}


void clsMateriaView::Listar()
{


    clsMateriaBL bl;
    clsValidaciones val;



    char condicion[50];



    system("cls");
    cout<<endl;
    cout<<"---------------------LISTADO DE MATERIAS------------------"<<endl;

    cout<<endl;
    val.ValidarRequerido("INGRESE NOMBRE DE LA MATERIA: ",condicion,50);
    cout<<endl;



    int c=  bl.BuscarSubCount(condicion);




    clsMateriaDTO* lista = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO) *c  ) ;  ///VECTOR DINAMICO DE Nª ELEMENTOS



    bl.BuscarSub(lista,condicion);

    char nombre[50];
    char profesor[50];

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout <<"|"<<setw(15)<<left<< "ID MATERIA"<<"|"<<setw(30)<<"NOMBRE DE LA MATERIA"<<"|"<<setw(30)<<"NOMBRE DEL PROFESOR"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;

    for(int x=0 ; x <c ; x++)
    {
   //  bool CondicionMateria= bl.DevuelveMateria(lista[x].GetId());

  //  if(CondicionMateria==true){
// int ValorID=bl.BuscarIdMateriaEnTrue(lista[x].GetId());

      ///  if(ValorID!=-1){
        lista[x].GetNombre(nombre);
        lista[x].GetProfesor(profesor);




        cout <<"|"<<setw(15)<<right<<lista[x].GetId()<<"|"<<setw(30)<<left<<nombre<<"|"<<setw(30)<<profesor<<"|"<<endl;



//}

    }
}


void clsMateriaView::EliminarListados()
{

    clsMateriaBL bl;

    bool valor=true;
    int id;

    system("cls");
    cout <<"---------------------------ELIMINAR----------------------------------"<<endl;
    cout<<endl;
    cout<<"INGRESE ID MATERIA A ELIMINAR: ";
    cin>>id;

    valor= bl.DevuelveMateria(id);

    if(valor ==true )
    {

        bl.Eliminar(id);

        cout<<endl<<endl;
        cout<<"ID MATERIA ELIMINADO CON EXITO."<<endl;
        system("pause");
    }
    else
    {

        cout<<endl<<endl;
        cout<<"EL ID INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        cout<<endl<<endl;
        system("pause");
    }




}

void clsMateriaView::Modificar()
{


    clsMateriaDTO dto;
    clsMateriaBL bl;

    clsValidaciones val;

    char nombre[50];
    char profesor[50];
    int id;

    int valor=true;


    system("cls");

    cout <<"---------------------------MODIFICAR-------------------------------"<<endl;
    cout<<endl;
    cout<<"INGRESE ID MATERIA A MODIFICAR: ";
    cin>>id;

    valor=bl.DevuelveMateria(id);

    if(valor==true)
    {


        cout<<endl;
        val.ValidarRequerido("INGRESE NOMBRE DE LA MATERIA: ",nombre,50);

        cout<<endl;
        val.ValidarRequerido("INGRESE NOMBRE DEL PROFESOR: ",profesor,50);


        dto.SetNombre(nombre);
        dto.SetProfesor(profesor);


        bl.Modificar(valor,nombre,profesor);
        cout<<"EXITO AL MODIFICAR MATERIA."<<endl;
        cout<<endl;
        system("pause");

    }
    else
    {

        cout<<endl;
        cout<<"EL ID INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        cout<<endl;
        system("pause");
    }



}///CIERRA FUNCION.







