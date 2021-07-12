#ifndef CLSALUMNOVIEW_H
#define CLSALUMNOVIEW_H

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "../DTO/clsAlumnoDTO.h"
#include "../BL/clsAlumnoBL.h"

#include "../Validaciones/clsValidaciones.h"  ///USO LAS FUNCIONES DEL .H PARA VALIDAR TEXTO EN LOS VIEW.

using namespace std;


class clsAlumnoView{

    public:
        void MenuAlumo();
        bool Insertar();

        void Eliminar();

        void Listar();

        bool Modificar();

};

#endif // CLSALUMNOVIEW_H
