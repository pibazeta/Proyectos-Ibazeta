#include "clsMateriaDTO.h"

///libreria agregada el 15/11
#include "clsMateriaBL.h"

clsMateriaDTO::clsMateriaDTO(){

    this->Eliminado=false;

}

void clsMateriaDTO::Copy(clsMateriaDTO dto){

    clsMateriaBL bl;
    char nombre[50];  ///SE DECLARAN LAS NUEVAS VARIABLES CHAR,PARA LA COPIA.
    char profesor[50];




    this->Id= dto.GetId();

    dto.GetNombre(nombre);  ///CON EL dto.GETNombre TOMO EL NOMBRE QUE FUE ASIGNADO EN LA VARIABLE NOMBRE ,Y LO COPIO EN nombre.
    strcpy(this->Nombre,nombre);  ///UNA VEZ COPIADO LO COPIO EN NOMBRE.

    dto.GetProfesor(profesor);
    strcpy(this->Profesor,profesor);








}
