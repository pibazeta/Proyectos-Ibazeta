#ifndef CLSALUMNODTO_H
#define CLSALUMNODTO_H

#include <cstring>

class clsAlumnoDTO
{
    public:
        clsAlumnoDTO();

        int GetLegajo() { return Legajo; }
        void SetLegajo(int val) { Legajo = val; }

        void GetNombre(char *val){ strcpy(val,Nombre);}
        void SetNombre(char *val){ strcpy(Nombre,val);}


        int GetDia_Nac() { return Dia_Nac; }
        void SetDia_Nac(int val) { Dia_Nac = val; }

        int GetMes_Nac() { return Mes_Nac; }
        void SetMes_Nac(int val) { Mes_Nac = val; }

        int GetAnio_Nac() { return Anio_Nac; }
        void SetAnio_Nac(int val) { Anio_Nac = val; }

        bool GetEliminado() { return Eliminado; }
        void SetEliminado(bool val) { Eliminado = val; }


        void Copy(clsAlumnoDTO);



    private:
        int Legajo;
        char Nombre[50];
        int Dia_Nac;
        int Mes_Nac;
        int Anio_Nac;
        bool Eliminado;
};

#endif // CLSALUMNODTO_H
