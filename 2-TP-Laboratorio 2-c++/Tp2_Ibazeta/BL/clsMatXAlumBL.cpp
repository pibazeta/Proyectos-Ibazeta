#include "clsMatXAlumBL.h"

///ES ESTA CAPA ES LA INSERCION DE LO QUE SE TRABAJO EN LAS FUNCIONES QUE MANIPULARON ARCHIVOS
/// TODAS ESAS FUNCIONES QUE MANEJAN ARCHIVOS SE LAS PASA AL DAO. PARA IMPLEMENTAR EL TRABAJO QUE HICIERON.

///UNA VEZ HECHO ESO SE TRABAJA CON EL BL (ESTA CAPA ) EN LA PARTE DE LAS CAPAS VIEW.//
bool clsMatXAlumBL::Insertar(clsMatXAlumDTO dto)
{

    clsMatXAlumDAO dao;

    dto.SetEliminado(false);

    dao.Insertar(dto);



}

bool clsMatXAlumBL::Eliminar(int legajo)
{

    clsMatXAlumDAO dao;

    dao.Eliminar(legajo);



}

void clsMatXAlumBL::Listar(clsMatXAlumDTO *lista)
{

    clsMatXAlumDAO dao;

    dao.Listar(lista);


}


int clsMatXAlumBL::Count()
{

    clsMatXAlumDAO dao;

    dao.Count();


}

bool clsMatXAlumBL::BuscarLejagoEnMateriaxAlumno(int legajo)
{

    clsMatXAlumDAO dao;

    dao.BuscarLejagoEnMateriaxAlumno(legajo);


}


bool clsMatXAlumBL::BuscarID_MateriaEnMateriaxAlumno(int id_materia)
{

    clsMatXAlumDAO dao;

    dao.BuscarID_MateriaEnMateriaxAlumno(id_materia);


}


