#ifndef CLSALUMNOBL_H
#define CLSALUMNOBL_H

#include "../DAO/clsAlumnoDAO.h"
#include "../DTO/clsAlumnoDTO.h"



class clsAlumnoBL{

    public:

    bool Insertar(clsAlumnoDTO);
    bool Eliminar(int);
    bool Modificar(int,char *,int,int,int);
    bool DevuelveLegajoAlumno(int);
    bool BuscarID_MateriaEnMateriaxAlumno(int);

    void Listar(clsAlumnoDTO *);

    int Count();
    void BuscarSub(clsAlumnoDTO *,char *);
    int BuscarSubCount(char *); ///CONDICION



    ///BORRAR DESPUES
     bool LeerDeDisco(int);



};

#endif // CLSALUMNOBL_H
