#ifndef CLSMATERIABL_H
#define CLSMATERIABL_H
#include "../DAO/clsMateriaDAO.h"
#include "../DTO/clsMateriaDTO.h"



class clsMateriaBL{

 public:
    bool Insertar(clsMateriaDTO);
    void Eliminar(int);
    void Modificar(int,char*,char*);
    void Listar(clsMateriaDTO *);
    int Count();

    void BuscarSub(clsMateriaDTO *,char *);
    int BuscarSubCount(char *); ///CONDICION

    void EliminarListados();
    bool DevuelveMateria(int);

    int BuscarIdMateriaEnTrue();


};

#endif // CLSMATERIABL_H
