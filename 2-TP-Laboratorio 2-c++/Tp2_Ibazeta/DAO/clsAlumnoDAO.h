#ifndef CLSALUMNODAO_H
#define CLSALUMNODAO_H
#include <cstdio>
#include "../DTO/clsAlumnoDTO.h"  ///ESTE ES EL QUE TIENE LO QUE SE VA A PASAR POR PARAMETROS (CLSALUMNODTO).
#include "../Validaciones/clsCadenas.h"

const char ARCHIVO_ALUMNOS[]="ARCHIVOS_ALUMNOS.DAT";

class clsAlumnoDAO{

    public:
    bool Insertar(clsAlumnoDTO);
    void Eliminar(int);
    bool Modificar(int,char *,int,int,int);
    void Listar(clsAlumnoDTO *);

    int Count();

    void BuscarSub(clsAlumnoDTO *,char *);
    int BuscarSubCount(char *);

       ///PROBANDO
    bool DevuelveLegajoAlumno(int);
    bool LeerDeDisco(int);///BORRAR DESPUES.


};

#endif // CLSALUMNODAO_H
