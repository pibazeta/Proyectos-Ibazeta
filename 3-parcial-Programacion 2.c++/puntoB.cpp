# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;


struct fecha{
  int dia, mes, anio;
};


struct musico{
  int dni;
  char nombreMusico[30];
  char apellidoMusico[30];
  char email[40];
  char telefono[20];
  int claustro, instrumento, tipoMusica;
  fecha fechaInscripcion;
  bool estado;
};


struct sesion{
  int numeroSesion;
  fecha fechaSesion;
  int horaInicio, horaFin;
  int instrumento;
  char url[45];
  int dniCoordinador;
  bool estado;
};

struct inscripcion{
  int dni;
  int numeroSesion;
  int tipoParticipacion;
  bool estado;
};

struct sesionCordinador{

 int numeroSesion;
  fecha fechaSesion;
  int horaInicio, horaFin;
  int instrumento;
  char url[45];
  int dniCoordinador;
  bool estado;



};

//Generar un archivo con las sesiones cuyo coordinador pertenezca al claustro de alumnos


void puntoB();
bool buscarCordinador(int);
void grabarRegistroNuevo(struct sesionCordinador aux );

int main(){



puntoB();



return 0;
}



void puntoB(){

    struct sesion reg;
    struct sesionCordinador aux;

    FILE *p;

    p=fopen("seccion.dat","rb");
    if(p==NULL){return;}


    while(fread(&reg,sizeof reg,1,p)){

        if(buscarCordinador(reg.dniCoordinador) ==true){


        aux.numeroSesion=reg.numeroSesion;
        aux.fechaSesion.dia=reg.fechaSesion.dia;
        aux.fechaSesion.mes=reg.fechaSesion.mes;
        aux.fechaSesion.anio=reg.fechaSesion.anio;
        aux.horaInicio=reg.horaInicio;
        aux.horaFin=reg.horaFin;
        aux.instrumento=reg.instrumento;
        strcpy(aux.url,reg.url);
        aux.dniCoordinador=reg.dniCoordinador;
        aux.estado=reg.estado;

        grabarRegistroNuevo(aux);


        }


    }
    fclose(p);

}

bool buscarCordinador(int dni ){

    struct musico reg;

    FILE *p;

    p=fopen("musico.dat","rb");
    if(p==NULL){return false;}

    while(fread(&reg,sizeof reg,1,p)==1){


    if(reg.dni==dni && reg.claustro==2){

    fclose(p);
    return true;
    }

    }
    fclose(p);
    return false;

}



void grabarRegistroNuevo(struct sesionCordinador aux){
  FILE *p;
  p=fopen("sesionCordinador.dat", "ab");
  if(p==NULL)return;
  fwrite(&aux, sizeof aux, 1, p);
  fclose(p);
}















