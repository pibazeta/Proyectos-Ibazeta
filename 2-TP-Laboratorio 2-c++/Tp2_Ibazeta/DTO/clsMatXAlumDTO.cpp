#include "clsMatXAlumDTO.h"

clsMatXAlumDTO::clsMatXAlumDTO()
{
    this->Eliminado=false;
}

void clsMatXAlumDTO::Copy(clsMatXAlumDTO dto){

this->Id_Materia=dto.GetId_Materia();
this->Legajo=dto.GetLegajo();


}
