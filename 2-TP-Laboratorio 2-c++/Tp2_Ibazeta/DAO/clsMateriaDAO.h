#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H
#include <cstdio>
#include "../DTO/clsMateriaDTO.h"  ///DESDE LA CARPETA DONDE ESTOY BAJO UN NIVEL(...) Y VOY A LA CARPETA DTO QUE TIENE EL .H
#include "../Validaciones/clsCadenas.h"


const char ARCHIVO_MATERIAS[]="ARCHIVOS_MATERIAS.DAT";

class clsMateriaDAO{

    public:
    bool Insertar(clsMateriaDTO);
    void Eliminar(int);
    void Modificar(int,char *,char *);
    void Listar(clsMateriaDTO *);

    int Count();

    void BuscarSub(clsMateriaDTO *,char *);
    int BuscarSubCount(char *); ///CONDICION

    bool DevuelveMateria(int);
    int BuscarIdMateriaEnTrue();  ///SE USA PARA QUE LISTE LOS ID EN EL LISTADO DE VIEW

};

#endif // CLSMATERIADAO_H
