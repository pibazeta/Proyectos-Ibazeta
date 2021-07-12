#include "clsValidaciones.h"

bool clsValidaciones::IsNumber(char *cad){

///DEVUELVE TRUE SI ES NUMERICO.
    bool resultado=true;
    int i=0;

    while(cad[i]!='\0'){
        if(cad[i] <'0' || cad[i]>'9' ){

            resultado=false;  ///SI NO ES NUMERICO ES FALSE
        }
    i++;
    }

    return resultado;  ///SI ES NUMERICO SUIGUE ITERANDO.
}


void clsValidaciones::ValidarRequerido(char *texto,char *out,int tam){

///CON WHILE.
    bool reintentar=true;

    while(reintentar){

        int i=0;
        reintentar=true;

        cout<<texto;
        cin.getline(out,tam);

        while (out[i]!='\0'){

            if( (out[i]>= 'a' && out[i] <='z'  )  || (out[i]>='A' && out[i]<='Z')){

            reintentar=false;  ///SI ESTRA ACA DEJA EL CICLO.
            }
            i++;

        }


    }


}

void clsValidaciones::ValidarNumerico(char *texto,char *out,int tam){

///CON WHILE.
    bool reintentar=true;

    while(reintentar){

        int i=0;
        reintentar=true;

        cout<<texto;
        cin.getline(out,tam);

        reintentar= !IsNumber(out); ///SI NO ES NUMERICO ES FALSE.

    }


}


/*
///FUNCION EL EN DO WHILE.
void clsValidaciones::ValidarRequerido(char *texto,char *out,int tam){

    bool reintentar;

    do{

        int i=0;
        reintentar=true;

        cout<<texto;
        cin.getline(out,tam);

        while (out[i]!='\0'){

            if( (out[i]>= 'a' && out[i] <='z'  )  || (out[i]>='A' && out[i]<='Z')){

            reintentar=false;
            }
            i++;

        }


    }while(reintentar);


}
*/
