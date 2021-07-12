#include "clsMatXAlumDAO.h"
/// EN ESTA CAPA SE MANEJA LAS OPERACIONES CON ARCHIVOS .

bool clsMatXAlumDAO::Insertar(clsMatXAlumDTO dto)
{

    FILE *p;

    p=fopen(ARCHIVO_MATxALUM,"ab");
    if(p!=NULL)
    {

        fwrite(&dto,sizeof(clsMatXAlumDTO),1,p);
        fclose(p);

    }
}

bool clsMatXAlumDAO::Eliminar(int legajo)
{

    clsMatXAlumDTO dto;

    FILE *p;
    int pos=0;

    p=fopen(ARCHIVO_MATxALUM,"rb+");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMatXAlumDTO),1,p))
        {

            if(dto.GetLegajo()==legajo && !dto.GetEliminado())
            {

                dto.SetEliminado(true);  ///MODIFICO ESTADO QUE QUEDE ELIMINADO
                fseek(p,sizeof (clsMatXAlumDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMatXAlumDTO),1,p);  ///GRABO MODIFICACION
                break;

            }

            pos++;

        }
        fclose(p); ///TERMINO DE RECORRE EL WHILE Y CIERRO EL ARCHIVO.


    }

}


void clsMatXAlumDAO::Listar(clsMatXAlumDTO *dto)
{

    FILE *p;
    int pos=0;

    clsMatXAlumDTO dto_arch;

    p=fopen(ARCHIVO_MATxALUM,"rb");
    if(p!=NULL)
    {

        while(fread(&dto_arch,sizeof(clsMatXAlumDTO),1,p))
        {

            if( !dto_arch.GetEliminado())
            {

                dto[pos].Copy(dto_arch);
                pos++;


            }

        }
        fclose(p);

    }
}

int clsMatXAlumDAO::Count()
{

    FILE *p;
    int cant=0;

    clsMatXAlumDTO dto;

    p=fopen(ARCHIVO_MATxALUM,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMatXAlumDTO),1,p))
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


bool clsMatXAlumDAO::BuscarLejagoEnMateriaxAlumno(int legajo)
{

    clsMatXAlumDTO dto;
    FILE *p;


    p=fopen(ARCHIVO_MATxALUM,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMatXAlumDTO),1,p))
        {

            if(dto.GetLegajo()==legajo && !dto.GetEliminado())
            {

                fclose(p);

                return true;


            }


        }///CIERRA WHILE.
        fclose(p);
        return false;




    }

}



bool clsMatXAlumDAO::BuscarID_MateriaEnMateriaxAlumno(int id_materia)
{

    clsMatXAlumDTO dto;
    FILE *p;


    p=fopen(ARCHIVO_MATxALUM,"rb");
    if(p!=NULL)
    {

        while(fread(&dto,sizeof(clsMatXAlumDTO),1,p))
        {

            if(dto.GetId_Materia()==id_materia && !dto.GetEliminado())
            {

                fclose(p);

                return true;


            }


        }///CIERRA WHILE.
        fclose(p);
        return false;



    }

}///CIERRA FUNCION.

