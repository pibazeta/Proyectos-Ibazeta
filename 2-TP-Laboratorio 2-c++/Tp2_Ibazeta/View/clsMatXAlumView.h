#ifndef CLSMATXALUMVIEW_H
#define CLSMATXALUMVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMatXAlumDTO.h"
#include "../BL/clsMatXAlumBL.h"

#include "../DTO/clsAlumnoDTO.h"  ///ESTAS INCLUDE SIRVEN PARA EL MOMENTO DE DECLARAR LAS VALIABLES EN CLSMATXALUMVIEW LAS RECONOSCA.
#include "../BL/clsAlumnoBL.h"

#include "../DTO/clsMateriaDTO.h"
#include "../BL/clsMateriaBL.h"


using namespace std;

/// LAS VARIABLES DECLARADAS ACA ,SE USAN EN EL MENU ,SI NO SE DECLARAN ACA NO SE PUEDEN USAR LIBRE MENTE EN EL MENU MATXALU
///NOTA MIA XD

class clsMatXAlumView{

    public:
         void MenuMatXAlum();
         bool Insertar();

         void Listar();
         bool Eliminar();

        void ListarMateriaxAlumno();


};

#endif // CLSMATXALUMVIEW_H
