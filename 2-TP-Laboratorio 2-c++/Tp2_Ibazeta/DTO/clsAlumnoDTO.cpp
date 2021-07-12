#include "clsAlumnoDTO.h"
#include "clsAlumnoDAO.h"

clsAlumnoDTO::clsAlumnoDTO(){

    this->Eliminado=false;
}


void clsAlumnoDTO::Copy(clsAlumnoDTO dto){


    char nombre[50];


   this->Legajo=dto.GetLegajo();

    dto.GetNombre(nombre);
    strcpy(this->Nombre,nombre);

    this->Dia_Nac=dto.GetDia_Nac();
    this->Mes_Nac=dto.GetMes_Nac();
    this->Anio_Nac=dto.GetAnio_Nac();


}

