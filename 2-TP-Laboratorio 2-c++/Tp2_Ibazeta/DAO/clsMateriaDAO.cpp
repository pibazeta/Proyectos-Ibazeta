#include "clsMateriaDAO.h"


///ACLARACION DE ESTA CAPA
///*********************************************************************************************************//

///ESTA CAPA SE ENCARGA DE MANEJAR LOS ARCHIVOS.
///NO DEBERIA PEDIR AL USUARIO NADA ,NI TIENE QUE PASAR NADA POR PANTALA.
///*******************************************************************************************************************//

bool clsMateriaDAO::Insertar(clsMateriaDTO dto)   ///HACERLO BOOL DESPUES
{

    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"ab");
    if(p!=NULL)
    {

        fwrite(&dto,sizeof (clsMateriaDTO),1,p);
        fclose(p);

    }

}

void clsMateriaDAO::Eliminar(int  Id)
{



    FILE *p;

    clsMateriaDTO dto;
    int pos=0;

    p=fopen(ARCHIVO_MATERIAS,"rb+");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {


            if(dto.GetId()==Id  && !dto.GetEliminado())
            {


                dto.SetEliminado(true);
                fseek(p,sizeof (clsMateriaDTO)*pos,SEEK_SET);  //SEEK_SET=0;
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                break;




            }
            pos++;


        }
        fclose(p);


    }


}



void clsMateriaDAO::Modificar(int id,char *nombre,char *profesor)
{


    FILE *p;

    clsMateriaDTO dto_arch;

    int pos=0;

    int valor;
    p=fopen(ARCHIVO_MATERIAS,"rb+");
    if(p!=NULL)
    {

        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {

            if(dto_arch.GetId()==id )
            {


                dto_arch.SetNombre(nombre);
                dto_arch.SetProfesor(profesor);

                fseek(p,sizeof (clsMateriaDTO)*pos,SEEK_SET);  //SEEK_SET=0;


                fwrite(&dto_arch,sizeof(clsMateriaDTO),1,p);
                break;




            }
            pos++;


        }
        fclose(p);


    }




}

void clsMateriaDAO::Listar(clsMateriaDTO *dto)
{
///COPIA DENTRO DE LA LISTA.
    FILE *p;
    int pos=0;
    clsMateriaDTO dto_arch;   ///REGISTRO ENTERO ,PARA COPIAAR EN LA FUNCION COPY



    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {


        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {


            if(!dto_arch.GetEliminado() )
            {
                dto[pos].Copy(dto_arch);
                pos++;

            }

        }
        fclose(p);
    }

}

int clsMateriaDAO::Count()
{

    FILE *p;
    int cant=0;

    clsMateriaDTO dto;

    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof (clsMateriaDTO),1,p))
        {

            if( !dto.GetEliminado())
            {
                cant++;


            }

        }
        fclose(p);


    }

    return cant;
}


void clsMateriaDAO::BuscarSub(clsMateriaDTO *dto,char *cond)
{
///COPIA DENTRO DE LA LISTA.
    FILE *p;
    int pos=0;
    clsMateriaDTO dto_arch;   ///REGISTRO ENTERO ,PARA COPIAAR EN LA FUNCION COPY

    char nombre[50];
    clsCadenas cadenas;


    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {


        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {

            dto_arch.GetNombre(nombre); ///EN LA VARIABLE NOMBRE VA A CARGAR LO QUE CONTIENE EL DTO_ARCH


            if(!dto_arch.GetEliminado() && cadenas.strSub(nombre,cond) >=0 )
            {
                dto[pos].Copy(dto_arch);
                pos++;

            }

        }
        fclose(p);
    }

}

int clsMateriaDAO::BuscarSubCount(char *cond)   ///RECIBE CADENA
{

    FILE *p;
    int cant=0;
    char nombre[50];

    clsMateriaDTO dto;
    clsCadenas cadenas;

    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {



        while(fread(&dto,sizeof (clsMateriaDTO),1,p))
        {

            dto.GetNombre(nombre);

            if( !dto.GetEliminado() && cadenas.strSub(nombre,cond) >=0  )
            {
                cant++;


            }

        }
        fclose(p);


    }

    return cant;
}///CIERRA FUNCION.




bool clsMateriaDAO::DevuelveMateria(int id)
{

    clsMateriaDTO dto;
    FILE *p;


    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {

            if(dto.GetId()==id && !dto.GetEliminado() )
            {

                fclose(p);
                return true;


            }



        }///CIERRA WHILE
        fclose(p);
        return false;


    }


}///CIERRA FUNCION.



/*
int clsMateriaDAO::BuscarIdMateriaEnTrue(int id)
{

    clsMateriaDTO dto;
    FILE *p;


    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {

            if(dto.GetId()==id && !dto.GetEliminado() )
            {

                fclose(p);
                return dto.GetId();


            }



        }///CIERRA WHILE
        fclose(p);
        return -1;


    }


}///CIERRA FUNCION.

*/

int clsMateriaDAO::BuscarIdMateriaEnTrue()  ///ESTA FUNCION SIRVE PARA LISTAR LOS ID ,SIN EVALUAR EL CAMPO ELIMINADO CUENTA TODOS EL ARCHIVO.
{

    clsMateriaDTO dto;
    FILE *p;
        int cont=0;

    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {

           cont++;



        }///CIERRA WHILE
        fclose(p);
        return cont;


    }


}///CIERRA FUNCION.
