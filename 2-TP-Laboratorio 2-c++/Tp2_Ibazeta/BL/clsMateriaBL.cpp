#include "clsMateriaBL.h"





bool clsMateriaBL::Insertar(clsMateriaDTO dto)
{

    clsMateriaDAO dao;


   // int id = dao.Count()+1;
int id=dao.BuscarIdMateriaEnTrue()+1;

    dto.SetId(id);   ///ID AUTONUMERICO

    dto.SetEliminado(false);  ////SI ES FALSE QUIERE DECIR QUE NO ESTA ELIMINADO,


    dao.Insertar(dto);


}

void clsMateriaBL::Eliminar(int id)
{

    clsMateriaDAO dao;
    dao.Eliminar(id);

}

void clsMateriaBL::Modificar(int id,char *nuevoNombre,char *nuevoProfesor)
{

    clsMateriaDAO dao;



    dao.Modificar(id,nuevoNombre,nuevoProfesor);


}

void clsMateriaBL::Listar(clsMateriaDTO *lista)
{

    clsMateriaDAO dao;
    dao.Listar(lista);


}

int clsMateriaBL::Count()
{

    clsMateriaDAO dao;

    return dao.Count();


}


void clsMateriaBL::BuscarSub(clsMateriaDTO *lista,char *cond)
{

    clsMateriaDAO dao;
    dao.BuscarSub(lista,cond);


}

int clsMateriaBL::BuscarSubCount(char *cond)
{

    clsMateriaDAO dao;

    return dao.BuscarSubCount(cond);


}



bool clsMateriaBL::DevuelveMateria(int id)
{


    clsMateriaDAO dao;


    dao.DevuelveMateria(id);


}


int clsMateriaBL::BuscarIdMateriaEnTrue()
{


    clsMateriaDAO dao;


    dao.BuscarIdMateriaEnTrue();


}





