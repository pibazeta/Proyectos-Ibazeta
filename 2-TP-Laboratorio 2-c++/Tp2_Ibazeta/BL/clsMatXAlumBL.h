#ifndef CLSMATXALUMBL_H
#define CLSMATXALUMBL_H
#include "../DAO/clsMatXAlumDAO.h"
#include "../DTO/clsMatXAlumDTO.h"


class clsMatXAlumBL{

    public:
       bool Insertar(clsMatXAlumDTO);
       bool Eliminar(int);
       void Listar(clsMatXAlumDTO *);

       int Count();

        bool BuscarLejagoEnMateriaxAlumno(int);
        bool BuscarID_MateriaEnMateriaxAlumno(int);

};

#endif // CLSMATXALUMBL_H
