#ifndef CLSMATXALUMDTO_H
#define CLSMATXALUMDTO_H


class clsMatXAlumDTO
{
    public:
        clsMatXAlumDTO();

        int GetId_Materia() { return Id_Materia; }
        void SetId_Materia(int val) { Id_Materia = val; }
        int GetLegajo() { return Legajo; }
        void SetLegajo(int val) { Legajo = val; }
        bool GetEliminado() { return Eliminado; }
        void SetEliminado(bool val) { Eliminado = val; }

        void Copy(clsMatXAlumDTO);

    private:
        int Id_Materia;
        int Legajo;
        bool Eliminado;
};

#endif // CLSMATXALUMDTO_H
