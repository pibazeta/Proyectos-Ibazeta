#ifndef CLSMATXALUMDAO_H
#define CLSMATXALUMDAO_H
#include <cstdio>
#include "../DTO/clsMatXAlumDTO.h"


const char ARCHIVO_MATxALUM[]="ARCHIVOS_MATXALU.DAT";

class clsMatXAlumDAO{

    public:
    bool Insertar(clsMatXAlumDTO);
    bool Eliminar(int);

    void Listar(clsMatXAlumDTO * );


    int Count();

    bool BuscarLejagoEnMateriaxAlumno(int);  ///DEVUELVE TRUE/FALSE SI CONICIDI CON EL PARAMETRO LEGAJO

    bool BuscarID_MateriaEnMateriaxAlumno(int); ///DEVUELVE TRUE/FALSE SI CONICIDI CON EL PARAMETRO ID_MATERIA



};

#endif // CLSMATXALUMDAO_H
