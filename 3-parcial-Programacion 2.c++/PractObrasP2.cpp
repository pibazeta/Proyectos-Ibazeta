#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;



class Obras{

    private:

    int codObra;
    int codProv;
    char codEmpresa[5];
    int dia;
    int mes;
    int anio;
    float cantMetros;
    float inversion;


    public:

    int getAnio(){return anio;}
    int getInversion(){return inversion;}
    bool leerDeDisco(int);


    ///PUNTO B)
    int getCodProv(){return codProv;}
    int getMes(){return mes;}


    ///PUNTO C)
    const char *getCodEmpresa(){return codEmpresa;}

};

bool Obras::leerDeDisco(int pos){

    Obras reg;
    FILE *p;
    p=fopen("obras.dat","rb");

    if(p==NULL){exit(1);}

    fseek(p,sizeof(reg),0);
    bool leyo= fread(this,sizeof *this, 1,p);
    fclose(p);

    return leyo;




}

///*************************************

class Provincias{


    private:

    int codProv;
    char nombre[20];
    int codZona;

    public:

    int getCodProv(){return codProv;}
    int getcodZona(){return codZona;}

    bool leerDeDisco(int);


};

bool Provincias::leerDeDisco(int pos){

    FILE *p;
    p=fopen("provincias.dat","rb");
    if(p==NULL){exit(1);}

    fseek(p,sizeof this,0);
    bool leyo= fread(this,sizeof *this,1,p);
    return leyo;



}

///*************************************


class Empresas{

    private:

    char codEmp[5];
    char nombre[30];
    char direccion[50];
    int tipo;


    public:
    const char *getCodEmp(){return codEmp;}
    bool leerDeDisco(int);

    ///PUNTO C)
    const char *getNomb(){return nombre;}



};

bool Empresas::leerDeDisco(int pos){

    FILE *p;
    p=fopen("empresas.dat","rb");
    if(p==NULL){exit(1);}


    fseek(p,sizeof this,0);
    bool leyo= fread(this,sizeof *this,1,p);

    return leyo;


}
///*************************************

class NuevoArchivo{

    private:


    char codEmp[5];
    char nombre[30];
    int  cantConst;

    public:
    const char *getCodEmp(){return codEmp;}
    void setCodEmp(const char *c ){strcpy(codEmp,c);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setCantConst(int cant){cantConst=cant;}


    /// bool leerDeDisco(int); no la use por que creamos un archivo nuevo directamente
    bool grabarEnDisco();





};


bool NuevoArchivo::grabarEnDisco(){


    FILE *p;
    p=fopen("nuevo2013.dat","ab");
    if(p==NULL){exit(1);}

    bool escribio=fwrite(this,sizeof *this,1,p);
    fclose(p);
    return escribio;

}



///***********PUNTO A)***************
void puntoA();
int MenorInversion(float *);



///***********PUNTO B)***************
void puntoB();
int buscarZona(int );
void MostrarMatriz(float Matriz[12][4]);
void PonerCeroMatriz(float Matriz[12][4]);


///***********PUNTO C)***************
void puntoC();
void PonerCeroVec(float *);
int CantConst2013(const char *); //SE PUEDE TENER UN RETORNO INT Y UN PARAMETRO CHAR.

///*************************************


int main(){

 puntoA();
 puntoB();
 puntoC();


return 0;
}


    void puntoA(){

    Obras reg;
    int pos=0;
    int anio=0;
    float vAnio[15];///POSICIONES POR QUE 2000-2014= 14 +1 por el 0.

    while(reg.leerDeDisco(pos++)){


    vAnio[reg.getAnio()-2000]+=reg.getInversion();


    }

    anio=MenorInversion(vAnio);
    cout<<"EL ANIO DE MENOR INVERSION FUE : "<<anio+2000<<endl;



    }


    //PUNTO A)
    int MenorInversion(float *v){

    int posMin=0;
    for(int i=0;i<15;i++){

        if(v[posMin] < v[i] ){ ////MENOR INVERSION (BUSCA LA POSICION DEL MENOR) ANIO
            //v[i]=v[posMin];
            posMin=i;
        }


    }
    return posMin;
    }

    //PUNTO A)
    void PonerCeroVec(float *v){

     for(int i=0;i<15;i++){
        v[i]=0;

    }
    }


    ///PUNTO B)
    void puntoB(){

    Obras reg ; ///LEEMOS EL ARCHIVO OBRAS POR QUE ES EL QUE MAS COSAS TIENE PARA TRAER.
    ///Provincias regProv; NO SE USA.


    int pos=0;
    int zona=0;
    float Matriz[12][4];

    while(reg.leerDeDisco(pos++)){

        if(reg.getAnio() == 2013){

           zona=buscarZona(reg.getCodProv()); ///BUSCAMOS LA ZONA EN EL ARCHIVO DE PROVINCIAS.
            Matriz[reg.getMes()-1][zona-1]+=reg.getInversion();

        }

    }
    MostrarMatriz(Matriz);





    }

    //PUNTO B)
    int buscarZona(int codProv){ ///PARAMETRO QUE VIENE COMO REFERENCIA DEL ARCHIVO OBRAS

    Provincias reg;
    int pos=0;
    int zona=0;

    while(reg.leerDeDisco(pos++)){

       if( codProv = reg.getCodProv()){ ///BUSCO EN EL ARCHIVO DE PROVINCIA,LA COINCIDENCIA-

        zona=reg.getcodZona(); ///DEVUELVO LA ZONA PARA LA MATRIZ


    }

    }

    return zona ;

    }

    //PUNTO B)
   void MostrarMatriz(float Matriz[12][4]){

   for (int i=0; i<12; i++){

    cout<<"MES: "<<i+1<<endl;

    for(int j=0 ;j<4 ; j++){

    cout<<"ZONA: "<<j+1<<endl;
    cout<<"TOTAL: "<<Matriz[i][j];

    }
   }

   }

   //PUNTO B)
   void PonerCeroMatriz(float Matriz[12][4]){

    for (int i=0; i<12; i++){


    for(int j=0 ;j<4 ; j++){

    Matriz[i][j]=0;

    }
    }


   }


   void puntoC(){


   Empresas reg;
   NuevoArchivo aux; ///PARA CREAR NUEVO ARCHIVO.
    int pos=0;
    int cantConstruciones=0;


    while(reg.leerDeDisco(pos++)){

    aux.setCodEmp(reg.getCodEmp());
    aux.setNombre(reg.getNomb());

    cantConstruciones=CantConst2013(reg.getCodEmp()); ///buscamos la cant en el archivo Obras.
    aux.setCantConst(cantConstruciones);

    aux.grabarEnDisco(); ///GRABAMOS.



    }

   }



   int CantConst2013(const char * codEmp){


   Obras reg ;
   int pos=0;
   int cantidad=0;

   while(reg.leerDeDisco(pos++)){

   if(reg.getAnio()==2013){
   if(strcmp(codEmp,reg.getCodEmpresa()) ==0 ){

   cantidad ++;


   }

   }


   }
   return cantidad;
   }






