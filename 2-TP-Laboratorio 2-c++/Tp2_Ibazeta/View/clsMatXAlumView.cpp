#include "clsMatXAlumView.h"



///EN ESTA CAPAS NO HACE FALTA PONER PARAMETROS EN LAS FUNCIONES POR QUE YA FUERON DECLARADAS EN OTRAS CAPAS


void clsMatXAlumView::MenuMatXAlum()
{

    char op;
    bool salir=false;

    while(!salir)
    {

        system("cls");
        cout<<"*--------------------MENU DE ASIGNACION -----------------*"<<endl;
        cout<<"* A - ASIGNAR ALUMNOS A MATERIAS.                        *"<<endl;
        cout<<"* L - LISTAR ALUMNOS POR MATERIAS.                       *"<<endl;
        cout<<"* B - LISTADO DE MATERIAS POR ALUMNOS.                   *"<<endl;
        cout<<"* E - DAR DE BAJA UN ALUMNO A UNA MATERIA.               *"<<endl;
        cout<<"* S - SALIR.                                             *"<<endl;
        cout<<"*--------------------------------------------------------*"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>op;
        cin.ignore();




        switch(op)
        {

        case 'a':
        case 'A':
        {
            if( Insertar() ==true )
            {

                cout<<endl<<endl;  ///USAR GOTOXI.
                cout<<"EXITO AL GRABAR"<<endl;
                system("pause");
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

            if( Eliminar()==true )
            {

                cout<<endl<<endl;  ///USAR GOTOXI.
                cout<<"EXITO AL ELIMINAR"<<endl;
                system("pause");


            }

            //EliminarListados();
        }
        break;



        case 'b':
        case 'B':
        {
            ListarMateriaxAlumno();
            cout<<endl;
            system("pause");

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


bool clsMatXAlumView::Insertar()
{

    clsMatXAlumDTO dto;  ///DECLACARION PARA USAR LOS SET. DE ALUMNOS POR MATERIAS
    clsMatXAlumBL bl;

    clsMateriaBL blMateria;
    clsAlumnoBL blAlumno;

    int id_materia;
    int legajo;


    system("cls");
    cout<<"--------------NUEVO ALUMNO A MATERIA----------------"<<endl;


    cout<<"INGRESE ID MATERIA: ";
    cin>>id_materia;

    bool valor=blMateria.DevuelveMateria(id_materia);   ///BUSCA QUE EXISTA EL ID MATERIA EN EL ARCHIVO MATERIAS.dat

    bool AsigRepMat= bl.BuscarID_MateriaEnMateriaxAlumno(id_materia); ///BUSCA SI YA SE INGRESO EN EL ARCHIVO MATXALU ,PARA QUE NO REPETIR LA ASIGNACION.



    if(valor==false)   ///SI LA FUNCION DEVUELVE FALSE ,NO ENCONTRO EL ID MATERIA EN ARCHIVO MATERIAS.DAT Y NO ME VOY DE LA CARGA.
    {
        cout<<endl;
        cout<<"EL ID MATERIA INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        system("pause");
        return false;
    }



    cout<<"INGRESE UN LEGAJO: ";
    cin>>legajo;

    bool valorLegajo=blAlumno.DevuelveLegajoAlumno(legajo);

    if(valorLegajo==false)
    {
        cout<<endl;
        cout<<"EL LEGAJO INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        system("pause");
        return false;

    }

    bool AsigRepLeg=bl.BuscarLejagoEnMateriaxAlumno(legajo);


    if( AsigRepMat==true && AsigRepLeg==true )    ///VERIFICO SI LA ASIGNACION YA SE HIZO ASI NO SE DUPLICA EN EL ARCHIVO MATXAlUMNO.
    {
        cout<<endl<<endl;
        cout<<"LA ASIGNACION YA FUE HECHA EN EL SISTEMA!"<<endl;
        system("pause");
        return false;
    }


    dto.SetId_Materia(id_materia);
    dto.SetLegajo(legajo);

    bl.Insertar(dto);    ///UNA VEZ PASADA TODAS LAS CONDICIONES GRABO EN EL ARCHIVO.


    return true;


}///CIERRA FUNCION.

///*********************FUNCION clsAlumnoDTO BuscarNombreAlumno*********************************


clsAlumnoDTO BuscarNombreAlumno(int legajo)     ///ESTA FUNCION DEVUELBE EL REGISTRO COMPLETO DE LA CLASE.
{

    clsAlumnoDTO dto;
    FILE *p;

    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {

            if(dto.GetLegajo()==legajo && !dto.GetEliminado())
            {
                fclose(p);
                return dto;    ///RETORNA EL REEGISTO COMPLETO.


            }

        }

    }

}///CIERRA FUNCION.




///*********************FUNCION clsMateriaDTO BuscarNombreMateria*********************************
clsMateriaDTO BuscarNombreMateria(int id_materia)     ///ESTA FUNCION DEVUELBE EL REGISTRO COMPLETO DE LA CLASE.
{


    clsMateriaDTO dto;
    FILE *p;

    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {

            if(dto.GetId()==id_materia && !dto.GetEliminado())
            {
                fclose(p);
                return dto;    ///RETORNA EL REEGISTO COMPLETO DE LA CLASE MATERIA.


            }

        }///CIERRA WHILE



    }


}///CIERRA FUNCION.






void clsMatXAlumView::Listar()
{
    ///OPCION L)


    clsMatXAlumBL bl;  ///SE DECLARA PARA USAR LA FUNCIONES DE SU RESPECTIVO BL. (LAS FUNCIONES HECHAS EN EL DAO.)



    clsAlumnoBL blAlumno;

    clsMateriaBL blMateria;


    clsAlumnoDTO alu,aux;


    clsMateriaDTO mat,auxMat;





    system("cls");

    cout <<"---------------------------LISTADO DE ALUMNOS POR MATERIAS---------------------"<<endl;

    int c = bl.Count();     ///CONTADOR DEl ARCHIVO MATXALUMNOS.DAT

    int contAlumno= blAlumno.Count();

    int contMateria=blMateria.Count();



    clsMatXAlumDTO * lista = (clsMatXAlumDTO*)malloc(sizeof(clsMatXAlumDTO)*c);
    bl.Listar(lista);


    clsAlumnoDTO * listaAlu = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*contAlumno);
    blAlumno.Listar(listaAlu);


    clsMateriaDTO *listaMateria = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*contMateria);
    blMateria.Listar(listaMateria);



    int legajo;
    int id_materia;
    char nombre[50];
    char nombreMateria[50];

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout <<"|"<<setw(10)<<left<< "LEGAJO"<<"|"<<setw(30)<<"NOMBRE DEL ALUMNO"<<"|"<<setw(30)<<"NOMBRE DE LA MATERIA"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    for(int x =0; x<c; x++)
    {



        bool CondicionMateria= blMateria.DevuelveMateria(lista[x].GetId_Materia()); ///BUSCO EL ID MATERIA QUE NO ESTE
        bool CondicionAlumno=  blAlumno.DevuelveLegajoAlumno(lista[x].GetLegajo());
        ///ELIMINADO EN EL ARCHIVO MATX ALU Y EL MATERIA.DAT PARA QUE NO SE LISTEN LOS REGISTRO ELIMINADOS


         if(CondicionMateria==true && CondicionAlumno==true){  ///SI LOS REGISTROS NO ESTAN ELIMINADOS LISTO TODO LOS TRUE
        listaAlu[x].GetNombre(nombre);
        listaMateria[x].GetNombre(nombreMateria);



        int valor=lista[x].GetLegajo();   ///GUARDO EL LEGAJO DEL ALUMNO EN LA VARIABLE VALOR

        alu=BuscarNombreAlumno(valor);    ///PASO POR PARAMETRO EL LEGAJO ALUMNO GUARDADO EN VALOR PARA QUE BUSQUE EL ARCHIVO_MATERIAS
        ///UNA VEZ ENCONTRADO EL VALOR ME GUARDO EL REGISTO ENTERO .



        aux=alu;
        aux.GetNombre(nombre);               /// Y USO AUX PARA GUARDARME EL NOMBRE DEL LEGAJO ENCONTRADO.


        int valorMateria=lista[x].GetId_Materia();


        mat=BuscarNombreMateria(valorMateria);

        auxMat=mat;

        auxMat.GetNombre(nombreMateria);



        cout <<"|"<<setw(10)<<right<< lista[x].GetLegajo()<<"|"<<setw(30)<<left<<nombre<<"|"<<setw(30)<<nombreMateria<<"|"<<endl;


    }///IF BOOL.


  }///CIERRA FOR.


}  ///CIERRA FUNCION.

/*****************************************************************************/

void clsMatXAlumView::ListarMateriaxAlumno()
{
///OPCION B)



    clsMatXAlumBL bl;  ///SE DECLARA PARA USAR LA FUNCIONES DE SU RESPECTIVO BL. (LAS FUNCIONES HECHAS EN EL DAO.)


    clsAlumnoBL blAlumno;

    clsMateriaBL blMateria;


    clsAlumnoDTO alu,aux;


    clsMateriaDTO mat,auxMat;



    system("cls");
    cout <<"----------------------LISTADO DE MATERIAS POR ALUMNOS-------------------"<<endl;

    int c = bl.Count();     ///CONTADOR DEl ARCHIVO MATXALUMNOS.DAT

    int contAlumno= blAlumno.Count();

    int contMateria=blMateria.Count();



    clsMatXAlumDTO * lista = (clsMatXAlumDTO*)malloc(sizeof(clsMatXAlumDTO)*c);
    bl.Listar(lista);


    clsAlumnoDTO * listaAlu = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*contAlumno);
    blAlumno.Listar(listaAlu);


    clsMateriaDTO *listaMateria = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*contMateria);
    blMateria.Listar(listaMateria);



    int legajo;
    int id_materia;
    char nombre[50];
    char nombreMateria[50];

    char nombreProfesor[50];

    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout <<"|"<<setw(15)<<left<< "MATERIA"<<"|"<<setw(20)<<"PROFESOR"<<"|"<<setw(20)<<"ALUMNO"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    for(int x =0; x<c; x++)
    {


       bool CondicionMateria= blMateria.DevuelveMateria(lista[x].GetId_Materia()); ///BUSCO EL ID MATERIA QUE NO ESTE
        bool CondicionAlumno=  blAlumno.DevuelveLegajoAlumno(lista[x].GetLegajo());
         if(CondicionMateria==true && CondicionAlumno==true){

        listaAlu[x].GetNombre(nombre);     ///ASIGNANDO LAS VARIABLES DECLARADAS A LOS GETS
        listaMateria[x].GetNombre(nombreMateria);
        listaMateria[x].GetProfesor(nombreProfesor);



        int valor=lista[x].GetId_Materia();   ///GUARDO EL ID MATERIA  EN LA VARIABLE VALOR

        mat=BuscarNombreMateria(valor);    ///PASO POR PARAMETRO EL ID MATERIA QUE ENCUENTRO EN LA CLASE  GUARDADO EN VALOR PARA QUE BUSQUE
        ///EL NUMERO DE LEGAJO EN LA FUNCION Y SI ENCUENTRA ME TRAIGO EL REGISTRO ENTERO.

        auxMat=mat;                         ///GUARDO EL REGISTO ENTERO DEL  clsMateriaDTO  ,PARA USAR SUS GETS.


        auxMat.GetNombre(nombreMateria);    ///USO CON EL AUXMAT LOS GETS DEL REGISTO ENTERO ENCONTRADO EN BuscarNombreMateria(valor);

        auxMat.GetProfesor(nombreProfesor);


        int valorAlumno=lista[x].GetLegajo();


        alu=BuscarNombreAlumno(valorAlumno);

        aux=alu;

        aux.GetNombre(nombre);





        cout <<"|"<<setw(15)<<right<<nombreMateria<<"|"<<setw(20)<<left<<nombreProfesor<<"|"<<setw(20)<<nombre<<"|"<<endl;




    }///CIERRA IF BOOL.


} ///CIERRA FOR.

}///CIERRA FUNCION.





bool clsMatXAlumView::Eliminar()
{



    clsMatXAlumBL bl;
    clsAlumnoBL blAlumno;
    clsMateriaBL blMateria;

    int legajo;
    int id_materia;


    bool ValorMateria=true;


    system("cls");

    cout <<"----------------------ELIMINAR-------------------"<<endl;
    cout<<"INGRESE LEGAJO DEL ALUMNO: ";
    cin>>legajo;

    bool valorLegajo=blAlumno.DevuelveLegajoAlumno(legajo);

    /// Valor= bl.BuscarLejagoEnMateriaxAlumno(legajo);

    if(valorLegajo==false)
    {
        cout<<endl;
        cout<<"EL LEGAJO INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        system("pause");
        return false;

    }


    cout<<"INGRESE ID MATERIA: ";
    cin>>id_materia;

    bool valor=blMateria.DevuelveMateria(id_materia);

    /// bool AsigRepMat= bl.BuscarID_MateriaEnMateriaxAlumno(id_materia);

    if(valor==false)   ///SI LA FUNCION DEVUELVE FALSE ,NO ENCONTRO EL ID MATERIA EN ARCHIVO MATERIAS.DAT Y NO ME VOY DE LA CARGA.
    {
        cout<<endl;
        cout<<"EL ID MATERIA INGRESADO NO EXISTE EN EL SISTEMA."<<endl;
        system("pause");
        return false;
    }

    bl.Eliminar(legajo);
    return true;




}///CIERRA FUNCION.








