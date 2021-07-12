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

//Listar los músicos del claustro docente que toquen guitarra


void puntoA();

int main(){



puntoA();



return 0;
}


void puntoA(){

struct musico reg;

    FILE *p;
    p=fopen("musico.dat","rb");
    if(p==NULL){return;}

    while(fread(&reg,sizeof reg,1,p)){


    if(reg.claustro==1 && reg.instrumento==2){

    cout<<"NOMBRE: "<<reg.nombreMusico<<endl;
    cout<<"APELLIDO : "<<reg.apellidoMusico<<endl;
    cout<<"DNI      : " <<reg.dni<<endl;

    }



    }
    fclose(p);

}























