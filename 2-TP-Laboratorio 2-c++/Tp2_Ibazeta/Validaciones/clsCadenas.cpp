#include "clsCadenas.h"

int clsCadenas::strSub(char *c, char *s){

    char cad[100];
    char sub[100];
    strcpy(cad,c);
    strcpy(sub,s);
    strToupper(cad);
    strToupper(sub);

    int ic=0, is, TamSub;

    TamSub= strlen(sub);

    while(cad[ic]!='\0'){

    int icAux = ic;
    is=0;

    while(sub[is]==cad[icAux] && sub[is]!='\0' ){

        icAux++;
        is++;

    }

    if(TamSub == is){

        return ic;

    }

    ic++;
    }

    return -1;




}


void clsCadenas::strToupper(char *cad){

int i=0;


while(cad[i]!='\0'){

    if  ( cad[i]>='a' && cad[i]<='z' ) {


      strupr(cad);

    }
    i++;

}



}

void clsCadenas::gotoxy(int x,int y){


 HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);


}
