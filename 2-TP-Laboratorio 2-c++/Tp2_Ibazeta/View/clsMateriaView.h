#ifndef CLSMATERIAVIEW_H
#define CLSMATERIAVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMateriaDTO.h"
#include "../BL/clsMateriaBL.h"

#include "../Validaciones/clsValidaciones.h" ///USO LAS FUNCIONES DEL .H PARA VALIDAR TEXTO EN LOS VIEW.

using namespace std;

class clsMateriaView{



    public:
        void Menu();
        bool Insertar();

        void Listar();

        void Modificar();

        void EliminarListados();

        void ModificarMateria();



};

#endif // CLSMATERIAVIEW_H
