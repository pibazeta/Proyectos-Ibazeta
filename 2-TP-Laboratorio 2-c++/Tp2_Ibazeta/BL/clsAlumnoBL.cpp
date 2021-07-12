#include "clsAlumnoBL.h"


bool clsAlumnoBL::Insertar(clsAlumnoDTO dto)
{

    clsAlumnoDAO dao;


    dto.SetEliminado(false);  ///SI ES FALSE ESTA ACTIVO .

    dao.Insertar(dto);

}

bool clsAlumnoBL::Eliminar(int legajo)
{

    clsAlumnoDAO dao;

    dao.Eliminar(legajo);


}

bool clsAlumnoBL::DevuelveLegajoAlumno(int legajo)
{

    clsAlumnoDAO dao;

    dao.DevuelveLegajoAlumno(legajo);



}

void clsAlumnoBL::Listar(clsAlumnoDTO *lista)
{

    clsAlumnoDAO dao;

    dao.Listar(lista);


}


int clsAlumnoBL::Count()
{

    clsAlumnoDAO dao;

    dao.Count();


}

bool clsAlumnoBL::Modificar(int legajo,char *nombre,int dia,int mes,int anio)
{

    clsAlumnoDAO dao;

    dao.Modificar(legajo,nombre,dia,mes,anio);

}

///BORRAR DESPUES

bool clsAlumnoBL::LeerDeDisco(int pos)
{

    clsAlumnoDAO dao;

    dao.LeerDeDisco(pos);

}

void clsAlumnoBL::BuscarSub(clsAlumnoDTO *lista,char *cond)
{

    clsAlumnoDAO dao;
    dao.BuscarSub(lista,cond);


}

int clsAlumnoBL::BuscarSubCount(char *cond)
{

    clsAlumnoDAO dao;

    return dao.BuscarSubCount(cond);


}


