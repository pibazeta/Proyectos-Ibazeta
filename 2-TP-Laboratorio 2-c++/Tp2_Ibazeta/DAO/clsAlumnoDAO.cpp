#include "clsAlumnoDAO.h"

bool clsAlumnoDAO::Insertar(clsAlumnoDTO dto )
{

    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"ab");
    if(p!=NULL)
    {

        fwrite(&dto,sizeof (clsAlumnoDTO),1,p);
        fclose(p);


    }

}

bool clsAlumnoDAO::DevuelveLegajoAlumno(int legajo)
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
                return true;


            }

        }
        fclose(p);
        return false;

    }

}///CIERRA FUNCION.


void clsAlumnoDAO::Eliminar(int legajo )
{

    clsAlumnoDTO dto;
    FILE *p;
    int pos=0;
    p=fopen(ARCHIVO_ALUMNOS,"rb+");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {

            if(dto.GetLegajo()==legajo   && !dto.GetEliminado())
            {

                dto.SetEliminado(true);
                fseek(p,sizeof (clsAlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
                break;


            }
            pos++; ///EL CONTADOR SE PONE ACA POR Q VA A TENER LA POSICION DEL LEGAJO EN EL ARCHIVO
            ///UNA VEZ QUE SE CUMPLIO EL IF.


        }///CIERRA WHILE
        fclose(p);

    }


}///CIERRA FUNCION.

void clsAlumnoDAO::Listar(clsAlumnoDTO *dto)
{

    FILE *p;
    int pos=0;

    clsAlumnoDTO dto_arch;

    p=fopen(ARCHIVO_ALUMNOS,"rb");

    if(p!=NULL)
    {

        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
        {

            /// SI EL GET ESTA EN TRUE ESTA ELIMINADO.
            if( !dto_arch.GetEliminado())
            {

                dto[pos].Copy(dto_arch);
                pos++;


            }

        } ///CIERRA WHILE.
        fclose(p);

    }

}///CIERRA FUNCION.


int clsAlumnoDAO::Count()
{
    ///CUENTA CANTIDAD DE REGISTROS ALUMNOS QUE ESTAN ACTIVOS EN EL ARCHIVO.

    FILE *p;
    int cant=0;

    clsAlumnoDTO dto;

    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {

            if( !dto.GetEliminado() )
            {
                cant++;
            }


        }
        fclose(p); ///UNA VEZ QUE CONTO TODOS LOS REGISTROS QUE NO ESTAN ELIMINADOS DEJO DE LEER EL ARCHIVO.
    }

    return cant;
}///CIERRA FUNCION.


bool clsAlumnoDAO::Modificar(int legajo,char *nombre,int dia,int mes,int anio)
{

    clsAlumnoDTO dto;
    int pos=0;

    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"rb+");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {

            if(dto.GetLegajo()==legajo)
            {

                dto.SetNombre(nombre);
                dto.SetDia_Nac(dia);
                dto.SetMes_Nac(mes);
                dto.SetAnio_Nac(anio);

                fseek(p,sizeof (clsAlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
                break;

            }
            pos++;


        }
        fclose(p);

    }



}///CIERRA FUNCION.


/// BORRAR ESTO DESPUES

bool clsAlumnoDAO::LeerDeDisco(int pos)
{
    FILE *p;
    clsAlumnoDTO dto;
    bool leyo;
    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {
        fseek(p,sizeof(clsAlumnoDTO)*pos,0);
        leyo= fread(&dto,sizeof(clsAlumnoDTO),1,p);
        fclose(p);
        return true;


    }
    return false;

}

void clsAlumnoDAO::BuscarSub(clsAlumnoDTO *dto,char *cond)
{
///COPIA DENTRO DE LA LISTA.
    FILE *p;
    int pos=0;
    clsAlumnoDTO dto_arch;   ///REGISTRO ENTERO ,PARA COPIAAR EN LA FUNCION COPY

    char nombre[50];
    clsCadenas cadenas;


    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {


        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
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

}///CIERRA FUNCION.



int clsAlumnoDAO::BuscarSubCount(char *cond)   ///RECIBE CADENA
{

    FILE *p;
    int cant=0;
    char nombre[50];

    clsAlumnoDTO dto;
    clsCadenas cadenas;

    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {



        while(fread(&dto,sizeof (clsAlumnoDTO),1,p))
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
}





