#ifndef CLSMAINVIEW_H
#define CLSMAINVIEW_H
#include <iostream>
#include <cstdlib>
#include "clsMateriaView.h"   ///.H PARA LLAMAR AL MENU MATERIAVIEW. ///SI NO SE DECLARA NUNCA VA A LEVANTAR EL MENU ESPECIFICO.
#include "clsAlumnoView.h"
#include "clsMatXAlumView.h"
#include "clsFAQ.h"



using namespace std;

class clsMainView{

    public:

        void Menu();
        void MenuAlumo();
        void MenuMatXAlum();
        void MenuFaq();



};

#endif // CLSMAINVIEW_H
