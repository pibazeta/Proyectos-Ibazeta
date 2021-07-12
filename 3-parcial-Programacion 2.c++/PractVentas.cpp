#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


class Vendedores{

private:

    char codVend[5];
    char nombre[30];
    int provincia;
    int calificacion;


public:

    const char * getCodVend(){ return codVend;}
    const char *getNombre(){return nombre;}
    bool leerDeDisco(int);

    //PUNTO C
    int getProvincia(){return provincia;}



};


bool Vendedores::leerDeDisco(int pos){

    FILE *p;
    p=fopen("vendedores.dat","rb");
    if(p==NULL){exit(1);}

    fseek(p,sizeof *this * pos,0);
    bool escribio=fread(this,sizeof *this ,1,p);
    fclose(p);
    return escribio;



}



///*******************************

class Ventas{

    private:
    int numCompra;
    char  codVendedor[5];
    int codUsuario;
    float importe;
    int dia;
    int mes;
    int anio;
    int tipoPago;



    public:
    //PUNTO A)
    const char * getCodVendedor(){return codVendedor;}
    int getAnio(){return anio;}
    bool leerDeDisco(int);

    //PUNTO C)
    int getMes(){return mes;}



};

bool Ventas::leerDeDisco(int pos){

 FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL){exit(1);}

    fseek(p,sizeof *this * pos,0);
    bool escribio=fread(this,sizeof *this ,1,p);
    fclose(p);
    return escribio;





}

///************

class NuevoArchivo{

private:

    char codVend[5];
    char nombre[30];

public:

    void setCodVend(const char *c){strcpy(codVend,c);}
    void setNombre(const char *n){strcpy(nombre,n);}
    bool grabarEnDisco();




};

bool NuevoArchivo::grabarEnDisco(){

    FILE *p;
    p=fopen("nuvoArchivo.dat","ab");
    if(p==NULL){exit(1);}

    bool escribio=fwrite(this,sizeof *this,1,p);
    fclose(p);
    return escribio;

}

///*********

class Usuarios{

private:

    char codUsuario[5];
    char nombre[30];
    int dni;
    int dia;
    int mes;
    int anio;

public:

    int getMes(){return mes;}
    int getAnio(){return anio;}
    bool leerDeDisco(int);



};

bool Usuarios::leerDeDisco(int pos){

FILE *p;

    p=fopen("usuarios.dat","rb");
    if(p==NULL){exit(1);}

    fseek(p,sizeof *this * pos,0);
    bool escribio=fread(this,sizeof *this ,1,p);
    fclose(p);
    return escribio;



}




///PUNTO A)
 bool buscarVendedor(const char* );
 void puntoA();

//PUNTO B)
void puntoB();
 void cantRegistrados(int *v);

 //PUNTO C)
 void puntoC();
 int buscarVendProv(const char *);

int main(){

puntoA();


return 0;
}


    void puntoA(){

    Vendedores reg;
    NuevoArchivo aux;
    int pos=0;
    bool vendedor=false;

    while(reg.leerDeDisco(pos++)){

        vendedor=buscarVendedor(reg.getCodVend()); //PODEMOS USAR LA FUNCION EN VEZ DE HACER UNA VARIABLE TAMBIEN
        if(vendedor==true){
        aux.setCodVend(reg.getCodVend());
        aux.setNombre(reg.getNombre());
        aux.grabarEnDisco();


        }

    }

    }



    ///PUNTO A)
    bool buscarVendedor(const char* c){
    ///SE PUEDE HACER QUE SEA CONT EN VEZ DE BOOL TAMBEIN
    Ventas  reg;
    int pos=0;

    while(reg.leerDeDisco(pos++)){

    if(strcmp(reg.getCodVendedor(),c)==0 && (reg.getAnio()==2015)){

    return true;

    }


    }

    return false;
    }



    void puntoB(){

    Usuarios reg;
    int pos=0;
    int vecMes[12];

    while(reg.leerDeDisco(pos++)){

    if(reg.getAnio()==2015){
    vecMes[reg.getMes()-1]++;
    }




    }
    cantRegistrados(vecMes);




    }

    ///PUNTO B)
    void cantRegistrados(int *v){

    for(int i=0;i<15;i++){

    cout<<"MES: "<<i+1<<endl;
    cout<<"CANTIDAD: "<<v[i]<<endl;

    }



    }



    void puntoC(){

    Ventas reg;
    int pos=0;
    int cant=0;

    while(reg.leerDeDisco(pos++)){

        if(reg.getMes()>=1 && reg.getMes() <=6 && reg.getAnio()==2015){

            cant=   buscarVendProv(reg.getCodVendedor());
            cout<<"cantitdad de ventas: "<<cant<<endl;
        }




    }



    }

    int buscarVendProv(const char *c){

    Vendedores reg;
    int pos=0;
    int cantidadVentas=0;

    while(reg.leerDeDisco(pos++)){
        if(strcmp(reg.getCodVend(),c)==0){
        if(reg.getProvincia()== 8  || reg.getProvincia()== 9 || reg.getProvincia()== 10){
        cantidadVentas++;
        }
        }


    }
    return cantidadVentas;

    }



