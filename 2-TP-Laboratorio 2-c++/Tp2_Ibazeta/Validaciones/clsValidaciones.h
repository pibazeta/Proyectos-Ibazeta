#ifndef CLSVALIDACIONES_H
#define CLSVALIDACIONES_H

#include <iostream>
using namespace std;


class clsValidaciones
{
    public:

        bool IsNumber(char *);
        void ValidarRequerido(char *,char *,int);
        void ValidarNumerico(char *,char *,int);

};

#endif // CLSVALIDACIONES_H
