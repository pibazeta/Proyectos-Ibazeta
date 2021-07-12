#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

//REPORTE 1/////
void menuReporte1(analisis *,int);
//bool cargarFecha(analisis *,int ,int ,int,int);


int buscarFecha(analisis *,int ,int,int ,int);
//void listarFecha(analisis);
void listarFechas(analisis *,int ,int,int ,int);
void listarFechaXcodigo(analisis *,int);
//void listarFechas(analisis *,int);
//REPORTE 1////

//REPORTE 2///
void menuReporte2(analisis *,int);

int buscarDNI(analisis *,char *,int); //BUSCA EL NUMERO DE LA POSICION DENTRO DEL VECTOR vExt[i].dia Y DEVUELVE EL NUM EN I.
//COLESTEROL..
bool colesterol(analisis *,char *,int);//BUSCO SI ESTA O NO.
void listarFechayValorCol(analisis *,int ,char *,int);

//ESTAS FUNCIONES BUSCAN EL PROM,MAX,MIN SI COINCIDEN EL NUM DE DNI. (NO ES UN PROM,MAX,MIN,GENERAL DE LAS CARGAS).
float promedioColesterol(analisis *,int,char *);
int colesterolMaximo(analisis *,int,char * );
int colesterolMinimo(analisis *,int,char * );

//GLOBULOS ROJOS.
bool globRojos(analisis *,char *,int);
void listarFechayValorGlogR(analisis*,int ,char *,int);

float promedioGlobRojos(analisis *,int,char *);
float GlobRojosMaximo(analisis *,int,char *);
float GlobRojosMinimo(analisis *,int ,char *);
//GLOBULOS ROJOS.


//GLOBULOS BLANCOS.
bool globBlancos(analisis *,char *,int);
void listarFechayValorGlogbB(analisis*,int ,char *,int);

float promedioGlobBlancos(analisis *,int,char *);
float GlobBlancosMaximo(analisis *,int,char *);
float GlobBlancosMinimo(analisis *,int ,char *);
//GLOBULOS BLANCOS.


//REPORTE 3
void menuReporte3(analisis *,int);
//REPORTE 3


//REPORTE 4(LA MODIFICACION)
void menuReporte4(analisis *,int);

float promEdadPacientes(analisis*,int);
//REPORTE.

void menuReporte5(analisis *,int );


void menuReporte7(analisis *,int);

void menuReportes(analisis *vExt,int *cExt){
int opc;

while(true){
    borrar();
    cout<<"INFORMES "<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"1) REPORTE 1"<<endl;
    cout<<"2) REPORTE 2"<<endl;
    cout<<"3) REPORTE 3"<<endl;
    cout<<"4) REPORTE 4"<<endl;
    cout<<"5) REPORTE 5"<<endl;
    cout<<"7) REPORTE 7"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"0) VOLVER AL MENU ANTERIOR "<<endl;
    cout<<"INGRESE UNA OPCION: "<<endl;
    cin>>opc;

    switch(opc){

    case 1: menuReporte1(vExt,*cExt);
    break;

    case 2:menuReporte2(vExt,*cExt);
    break;

    case 3:menuReporte3(vExt,*cExt);
    break;

    case 4:menuReporte4(vExt,*cExt);
    break;

    case 5:menuReporte5(vExt,*cExt);
    break;


    case 7:menuReporte7(vExt,*cExt);
    break;

    case 0:
    return;
    break;
    }
}
}
//CIERRA MENUREPORTES().

/////////////**********************REPORTE 1****************************/////////////////////
void menuReporte1(analisis *vExt,int cExt){
int DIA,MES,ANIO;
   // if(cargarFecha(vExt,DIA,MES,ANIO,cExt)==true){


    cout<<"REPORTE 1: LISTADO DE EXTRACCIONES POR FECHA"<<endl;



       listarFechaXcodigo(vExt,cExt);


   // }

}
//CIERRA REPORTE 1.

//CIERRA CARGARFECHA().

int buscarFecha(analisis *vExt,int DIA,int MES,int ANIO,int cExt){

    for(int i=0;i<cExt;i++){
    if(vExt[i].FechaExt.dia==DIA && vExt[i].FechaExt.mes==MES && vExt[i].FechaExt.anio==ANIO){
    return i;
    }
    }
return -1;
}

void listarFechaXcodigo(analisis *vExt,int cExt){
int pos,fechaBuscada;
int DIABUSCADO,MESBUSCADO,ANIOBUSCADO;

borrar();

    cout<<"DIA : ";
    cin>>DIABUSCADO;
    cout<<"MES : ";
    cin>>MESBUSCADO;
    cout<<"ANIO: ";
    cin>>ANIOBUSCADO;


   pos=buscarFecha(vExt,DIABUSCADO,MESBUSCADO,ANIOBUSCADO,cExt);

   if(pos>=0){

    listarFechas(vExt,DIABUSCADO,MESBUSCADO,ANIOBUSCADO,cExt);

   }
   else{
    cout<<"LA FECHA NO EXISTE";
   }

pausa();
}


void listarFechas(analisis *vExt,int DIA,int MES,int ANIO,int cExt ){

borrar();
    for(int i=0;i<cExt;i++){
    if(vExt[i].FechaExt.dia==DIA && vExt[i].FechaExt.mes==MES && vExt[i].FechaExt.anio==ANIO){

  //  listarFecha(vExt[i]);
    listarExtraccion(vExt[i]);

    }


    }
pausa();
}



//CIERRA FUNCION LISTARFECHAS().

/////////////**********************REPORTE 1****************************/////////////////////////////////////////////

/////////////**********************REPORTE 2****************************/////////////////////////////////////////////
void menuReporte2(analisis *vExt,int cExt){
borrar();

    char DNI[10],apellido[50],nombre[50];
    int maximoC,minimoC,edad, pos;
    float maximoGr=0.0,minimoGr,maximoGb=0.0,minimoGb;
    float promC,promGr,promGb;

    cout<<"REPORTE 2: DATOS DE UN PACIENTE"<<endl;
    cout<<"DNI: ";
    cin>>DNI;

    pos=buscarDNI(vExt,DNI,cExt);
   // if (pos<0){cout<<"EL DNI NO EXISTE!"; }
   if(pos>=0){
    gotoxy(0,0);
    cout<<endl<<"--------------------------------------------------------------------"<<endl;
    gotoxy(0,2);
    cout<<"APELLIDO: "<<vExt[pos].apellido<<endl;
    gotoxy(0,3);
    cout<<"NOMBRES : "<<vExt[pos].nombre<<endl;
    gotoxy(0,4);
    cout<<"EDAD    : "<<vExt[pos].edad<<endl;
    gotoxy(0,4);
    cout<<endl<<"--------------------------------------------------------------------"<<endl;

    colesterol(vExt,DNI,cExt);
    globRojos(vExt,DNI,cExt);
    globBlancos(vExt,DNI,cExt);

    //COLESTEROL..
     promC=promedioColesterol(vExt,cExt,vExt[pos].dni);
     maximoC=colesterolMaximo(vExt,cExt,vExt[pos].dni );
     minimoC=colesterolMinimo(vExt,cExt,vExt[pos].dni );
     //GLOB.ROJOS..
     promGr=promedioGlobRojos(vExt,cExt,vExt[pos].dni);
     maximoGr=GlobRojosMaximo(vExt,cExt,vExt[pos].dni);
     minimoGr=GlobRojosMinimo(vExt,cExt,vExt[pos].dni);
     //GLOB.BLANCOS..
     promGb=promedioGlobBlancos(vExt,cExt,vExt[pos].dni);
     maximoGb=GlobBlancosMaximo(vExt,cExt,vExt[pos].dni);
     minimoGb=GlobBlancosMinimo(vExt,cExt,vExt[pos].dni);

    gotoxy(0,40);
    cout<<"COLESTEROL";
    gotoxy(15,40);
    cout<<"PROMEDIO: ";
    gotoxy(30,40);
    cout<<"|";
    gotoxy(35,40);
    cout<<"MAXIMO: ";
    gotoxy(48,40);
    cout<<"|";
    gotoxy(55,40);
    cout<<"MINIMO: ";
    gotoxy(0,41);
    cout<<"GLOB. ROJOS";
    gotoxy(15,41);
    cout<<"PROMEDIO: ";
    gotoxy(30,41);
    cout<<"|";
    gotoxy(35,41);
    cout<<"MAXIMO: ";
    gotoxy(48,41);
    cout<<"|";
    gotoxy(55,41);
    cout<<"MINIMO: ";
    gotoxy(0,42);
    cout<<"GLOB. BLANCOS";
    gotoxy(15,42);
    cout<<"PROMEDIO: ";
    gotoxy(30,42);
    cout<<"|";
    gotoxy(35,42);
    cout<<"MAXIMO: ";
    gotoxy(48,42);
    cout<<"|";
    gotoxy(55,42);
    cout<<"MINIMO: ";
    gotoxy(25,40);
    cout<<promC;
    gotoxy(43,40);
    cout<<maximoC;
    gotoxy(65,40);
    cout<<minimoC;
    gotoxy(25,41);
    cout<<promGr;
    gotoxy(43,41);
    cout<<maximoGr;
    gotoxy(65,41);
    cout<<minimoGr;
    gotoxy(25,42);
    cout<<promGb;
    gotoxy(43,42);
    cout<<maximoGb;
    gotoxy(65,42);
    cout<<minimoGb;

pausa();
pausa();
pausa();
   }
   else{
    cout<<"EL DNI INGRESADO NO EXISTE.";pausa();
   }
}
//CIERRA MENUREPORTE2().

int buscarDNI(analisis *vExt, char *DNI,int cExt){

    for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI) == 0){
        return i;
        }
    }
    return -1;
}
//CIERRA BUSCARDNI.

bool  colesterol(analisis *vExt,char *DNI,int cExt ){
 bool band=false;

    int y=10;

    for(int i=0;i<cExt;i++){

        if (strcmp(vExt[i].dni,DNI )== 0 ){
            y++;
            listarFechayValorCol(vExt,cExt,vExt[i].dni,y);  ///SE MANDA vExt[i].dni POR q es CHAR.

            band=true;

        }
        }//CIERRA FOR.
    return band;
}


float promedioColesterol(analisis *vExt,int cExt,char *DNI){
    bool  condicion=colesterol(vExt,DNI,cExt);
    float acum=0.0;
    int cont=0;

    for(int i=0;i<cExt;i++){
    if(strcmp(vExt[i].dni,DNI )== 0 ){
    if(condicion>0){
    if(vExt[i].nivelColesterol >0){
    cont++;
    acum+=vExt[i].nivelColesterol;
    }
    }
    }
    }//CIERRRA FOR.
    return acum/cont;
}

int colesterolMaximo(analisis *vExt,int cExt,char *DNI){
    bool  condicion=colesterol(vExt,DNI,cExt);

    int colesterol=0,pos;
    int maximo=0;

    for(int i=0;i<cExt;i++){
    if(strcmp(vExt[i].dni,DNI )== 0  ){
    if(condicion>0){
    colesterol=vExt[i].nivelColesterol;
    if(colesterol>maximo){
    maximo=colesterol;
    pos=i;
    }
    }
    }
    }//CIERRA FOR.
    return maximo;
}

int colesterolMinimo(analisis *vExt,int cExt,char *DNI){
    bool  condicion=colesterol(vExt,DNI,cExt);
    int colesterol=0,pos,minimo,contneg=0;

    for(int i=0;i<cExt;i++){
    if(strcmp(vExt[i].dni,DNI )== 0 ){
    if(condicion>0){
    colesterol=vExt[i].nivelColesterol;
    contneg++;
    if(contneg==1){
    minimo=colesterol;
    pos=i;
    }
    else{
        if(colesterol<minimo){
        minimo=colesterol;
        pos=i;
        }
        }
        }
        }
        }//CIERRA FOR.
return minimo;
}

void listarFechayValorCol(analisis *vExt,int cExt,char *DNI,int y){

    gotoxy(0,7);
    cout<<"COLESTEROL"<<endl;
    gotoxy(10,7);
    cout<<endl<<"---------------------"<<endl;
    gotoxy(0,9);
    cout<<"FECHA";
    gotoxy(15,9);
    cout<<"VALOR";
    gotoxy(0,9);
    cout<<endl<<"---------------------"<<endl;

    for(int i=0;i<cExt;i++){
        if(vExt[i].dni==DNI){

            gotoxy(0,y);
            cout<<vExt[i].FechaExt.dia << "/" << vExt[i].FechaExt.mes << "/" << vExt[i].FechaExt.anio <<endl;
            gotoxy(15,y);
            cout<<vExt[i].nivelColesterol<<endl;

            }
            }
pausa();
}

bool globRojos(analisis *vExt,char *DNI,int cExt){
bool band=false;

    int y=20;
    for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI )== 0  ){
        y++;
        listarFechayValorGlogR(vExt,cExt,vExt[i].dni,y);

        band=true;
            }
            }
return band;
}

float promedioGlobRojos(analisis *vExt,int cExt,char *DNI){
    float acum=0.0;
    int cont=0;
    for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI )== 0  ){
        if(vExt[i].nivelGlobulosR > 0){
        cont++;
        acum+=vExt[i].nivelGlobulosR;
        }
        }
        }
        return (float)acum/cont;
}

float GlobRojosMaximo(analisis *vExt,int cExt,char *DNI){
    bool  condicion= globRojos( vExt,DNI,cExt);
    int pos;
    float globRojo=0.0,maximo=0.0;

        for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI )== 0  ){
        if(condicion>0){

        globRojo=vExt[i].nivelGlobulosR;
        if(globRojo>maximo){
        maximo=globRojo;
        pos=i;
        }
        }
        }
        }
    return maximo;
}

float GlobRojosMinimo(analisis *vExt,int cExt,char *DNI){
int pos,contneg=0;
float globRojo=0.0,minimo;
    for(int i=0;i<cExt;i++){
    if(strcmp(vExt[i].dni,DNI )== 0 ){
    globRojo=vExt[i].nivelGlobulosR;
    contneg++;
    if(contneg==1){
    minimo=globRojo;
    pos=i;
    }
    else{
        if(globRojo<minimo){
        minimo=globRojo;
        pos=i;
        }
        }
        }
        }
return minimo;
}

void listarFechayValorGlogR(analisis *vExt,int cExt,char *DNI,int y){

    gotoxy(0,18);
    cout<<"GLOBULOS ROJOS"<<endl;
    gotoxy(15,18);
    cout<<endl<<"---------------------"<<endl;
    gotoxy(0,20);
    cout<<"FECHA";
    gotoxy(15,20);
    cout<<"VALOR";
    gotoxy(0,9);
    cout<<endl<<"---------------------"<<endl;

    for(int i=0;i<cExt;i++){
        if(vExt[i].dni==DNI){

            gotoxy(0,y);
            cout<<vExt[i].FechaExt.dia << "/" << vExt[i].FechaExt.mes << "/" << vExt[i].FechaExt.anio <<endl;
            gotoxy(15,y);
            cout<<vExt[i].nivelGlobulosR<<endl;
            }
            }
pausa();
}

bool globBlancos(analisis *vExt, char *DNI, int cExt){
bool band=false;
int y=29;
        for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI)==0){
        y++;

        listarFechayValorGlogbB(vExt,cExt,vExt[i].dni,y);
        band=true;
        }
        }

return band;
}

float promedioGlobBlancos(analisis *vExt,int cExt,char *DNI){
    float acum=0.0;
    int cont=0;
    for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI )== 0  ){
        if(vExt[i].nivelGlobulosB > 0){
        cont++;
        acum+=vExt[i].nivelGlobulosB;
        }
        }
        }
    return (float)acum/cont;
}



float GlobBlancosMaximo(analisis *vExt,int cExt,char *DNI){
    int pos;
    float globBlanco=0.0,maximo=0.0;
    for(int i=0;i<cExt;i++){
        if(strcmp(vExt[i].dni,DNI )== 0  ){
        globBlanco=vExt[i].nivelGlobulosB;

        if(globBlanco>maximo){
        maximo=globBlanco;
        pos=i;
        }
        }
        }
    return maximo;
}


float GlobBlancosMinimo(analisis *vExt,int cExt,char *DNI){
int pos,contneg=0;
float globBlanco=0.0,minimo;
    for(int i=0;i<cExt;i++){
    if(strcmp(vExt[i].dni,DNI )== 0 ){
    globBlanco=vExt[i].nivelGlobulosB;
    contneg++;
    if(contneg==1){
    minimo=globBlanco;
    pos=i;
    }
    else{
        if(globBlanco<minimo){
        minimo=globBlanco;
        pos=i;
        }
    }

    }
    }
return minimo;
}

void listarFechayValorGlogbB(analisis *vExt,int cExt,char *DNI,int y){

    gotoxy(0,25);
    cout<<"GLOBULOS BLANCOS"<<endl;
    gotoxy(28,25);
    cout<<endl<<"---------------------"<<endl;
    gotoxy(0,27);
    cout<<"FECHA";
    gotoxy(15,27);
    cout<<"VALOR";
    gotoxy(0,27);
    cout<<endl<<"---------------------"<<endl;

    for(int i=0;i<cExt;i++){
        if(vExt[i].dni==DNI){

            gotoxy(0,y);
            cout<<vExt[i].FechaExt.dia << "/" << vExt[i].FechaExt.mes << "/" << vExt[i].FechaExt.anio <<endl;
            gotoxy(15,y);
            cout<<vExt[i].nivelGlobulosB<<endl;

        }
    }
pausa();

}

void menuReporte3(analisis *vExt,int cExt){
borrar();
int tipo,edad;
//EDAD 0 A 9
int dec0_tip1_0_9=0,dec0_tip2_0_9=0,dec0_tip3_0_9=0;
//EDAD 10 A 19.
int dec1_tipo1_10_19=0,dec1_tipo2_10_19=0,dec1_tipo3_10_19=0;
//EDAD 20 A 29.
int dec2_tipo1_20_29=0,dec2_tipo2_20_29=0,dec2_tipo3_20_29=0;
//EDAD 30 A 39.
int dec3_tipo1_30_39=0,dec3_tipo2_30_39=0,dec3_tipo3_30_39=0;
//EDAD 40 A 49.
int dec4_tipo1_40_49=0,dec4_tipo2_40_49=0,dec4_tipo3_40_49=0;
//EDAD 50 A 59.
int dec5_tipo1_50_59=0,dec5_tipo2_50_59=0,dec5_tipo3_50_59=0;
//EDAD 60 A 69.
int dec6_tipo1_60_69=0,dec6_tipo2_60_69=0,dec6_tipo3_60_69=0;
//EDAD 70 A 79.
int dec7_tipo1_70_79=0,dec7_tipo2_70_79=0,dec7_tipo3_70_79=0;
//EDAD 80 A 89.
int dec8_tipo1_80_89=0,dec8_tipo2_80_89=0,dec8_tipo3_80_89=0;
//EDAD 90 A 99.
int dec9_tipo1_90_99=0,dec9_tipo2_90_99=0,dec9_tipo3_90_99=0;


///ancho , alto
//columna fila.

    for(int i=0;i<cExt;i++){

    tipo=vExt[i].tipoAnalisis;
    edad=vExt[i].edad;


    switch(tipo ){

    case 1: if( (edad >=0 && edad <=9) && tipo==1 ){dec0_tip1_0_9++;}
            if( (edad >=10 && edad <=19 ) && tipo==1){dec1_tipo1_10_19++; }
            if( (edad >=20 && edad <=29 )&& tipo == 1){ dec2_tipo1_20_29++;   }
            if( (edad >=30 && edad <=39 )&& tipo ==1 ){dec3_tipo1_30_39++; }
            if( (edad >=40 && edad <=49 )&& tipo ==1 ){dec4_tipo1_40_49++; }
            if( (edad >=50 && edad <=59 )&& tipo ==1 ){dec5_tipo1_50_59++; }
            if( (edad >=60 && edad <=69 )&& tipo ==1 ){dec6_tipo1_60_69++; }
            if( (edad >=70 && edad <=79 )&& tipo ==1 ){dec7_tipo1_70_79++; }
            if( (edad >=80 && edad <=89 )&& tipo ==1 ){dec8_tipo1_80_89++; }
            if( (edad >=90 && edad <=99 )&& tipo ==1 ){dec9_tipo1_90_99++; }
    break;

    case 2: if( (edad  >=0 && edad  <=9 )&& tipo== 2 ){  dec0_tip2_0_9++;  }
            if( (edad >=10 && edad <=19 )&& tipo== 2){ dec1_tipo2_10_19++ ; }
            if( (edad >=20 && edad <=29 )&& tipo== 2){dec2_tipo2_20_29++;  }
            if( (edad >=30 && edad <=39 )&& tipo ==2 ){dec3_tipo2_30_39++; }
            if( (edad >=40 && edad <=49 )&& tipo ==2 ){dec4_tipo2_40_49++; }
            if( (edad >=50 && edad <=59 )&& tipo ==2 ){dec5_tipo2_50_59++; }
            if( (edad >=60 && edad <=69 )&& tipo ==2 ){dec6_tipo2_60_69++; }
            if( (edad >=70 && edad <=79 )&& tipo ==2 ){dec7_tipo2_70_79++; }
            if( (edad >=80 && edad <=89 )&& tipo ==2 ){dec8_tipo2_80_89++; }
            if( (edad >=90 && edad <=99 )&& tipo ==2 ){dec9_tipo2_90_99++; }
    break;

    case 3: if( (edad >=0 && edad <=9 ) && tipo == 3){dec0_tip3_0_9++;     }
            if( (edad >=10 && edad <=19 ) && tipo==3){dec1_tipo3_10_19++;  }
            if( (edad >=20 && edad <=29 )&& tipo == 3){dec2_tipo3_20_29++; }
            if( (edad >=30 && edad <=39 )&& tipo ==3 ){dec3_tipo3_30_39++; }
            if( (edad >=40 && edad <=49 )&& tipo ==3 ){dec4_tipo3_40_49++; }
            if( (edad >=50 && edad <=59 )&& tipo ==3 ){dec5_tipo3_50_59++; }
            if( (edad >=60 && edad <=69 )&& tipo ==3 ){dec6_tipo3_60_69++; }
            if( (edad >=70 && edad <=79 )&& tipo ==3 ){dec7_tipo3_70_79++; }
            if( (edad >=80 && edad <=89 )&& tipo ==3 ){dec8_tipo3_80_89++; }
            if( (edad >=90 && edad <=99 )&& tipo ==3 ){dec9_tipo3_90_99++; }

    break;
    }

    }
    gotoxy(0,2);
    cout<<"REPORTE 3: CANTIDAD DE ANALISIS POR TIPO Y DECADA";
    gotoxy(0,3);
    cout<<"------------------------------------------------";
    gotoxy(0,5);
    cout<<"DECADA/TIPO";
    gotoxy(0,7);
    cout<<"0 (0 a 9 AÑOS)";
    gotoxy(0,8);
    cout<<"------------------------------------------------";
    gotoxy(0,9);
    cout<<"1 (10 a 19 AÑOS)";
    gotoxy(0,10);
    cout<<"------------------------------------------------";
    gotoxy(0,11);
    cout<<"2 (20 a 29 AÑOS)";
    gotoxy(0,12);
    cout<<"------------------------------------------------";
    gotoxy(0,13);
    cout<<"3 (30 a 39 AÑOS)";
    gotoxy(0,14);
    cout<<"------------------------------------------------";
    gotoxy(0,15);
    cout<<"4 (40 a 49 AÑOS)";
    gotoxy(0,16);
    cout<<"------------------------------------------------";
    gotoxy(0,17);
    cout<<"5 (50 a 59 AÑOS)";
    gotoxy(0,18);
    cout<<"------------------------------------------------";
    gotoxy(0,19);
    cout<<"6 (60 a 69 AÑOS)";
    gotoxy(0,20);
    cout<<"------------------------------------------------";
    gotoxy(0,21);
    cout<<"7 (70 a 79 AÑOS)";
    gotoxy(0,22);
    cout<<"------------------------------------------------";
    gotoxy(0,23);
    cout<<"8 (80 a 89 AÑOS)";
    gotoxy(0,24);
    cout<<"------------------------------------------------";
    gotoxy(0,25);
    cout<<"9 (90 a 99 AÑOS)";
    gotoxy(0,26);
    cout<<"------------------------------------------------";
    gotoxy(20,5);
    cout<<"TIPO 1";
    gotoxy(30,5);
    cout<<"TIPO 2";
    gotoxy(40,5);
    cout<<"TIPO 3";
    gotoxy(0,6);
    cout<<"------------------------------------------------";


   gotoxy(20,7);
   cout<<dec0_tip1_0_9;
   gotoxy(30,7);
   cout<<dec0_tip2_0_9;
   gotoxy(40,7);
   cout<<dec0_tip3_0_9;


   gotoxy(20,9);
   cout<<dec1_tipo1_10_19;
   gotoxy(30,9);
   cout<<dec1_tipo2_10_19;
   gotoxy(40,9);
   cout<<dec1_tipo3_10_19;

   gotoxy(20,11);
   cout<<dec2_tipo1_20_29;
   gotoxy(30,11);
   cout<<dec2_tipo2_20_29;
   gotoxy(40,11);
   cout<<dec2_tipo3_20_29;

   gotoxy(20,13);
   cout<<dec3_tipo1_30_39;
   gotoxy(30,13);
   cout<<dec3_tipo2_30_39;
   gotoxy(40,13);
   cout<<dec3_tipo3_30_39;

   gotoxy(20,15);
   cout<<dec4_tipo1_40_49;
   gotoxy(30,15);
   cout<<dec4_tipo2_40_49;
   gotoxy(40,15);
   cout<<dec4_tipo3_40_49;

   gotoxy(20,17);
   cout<<dec5_tipo1_50_59;
   gotoxy(30,17);
   cout<<dec5_tipo2_50_59;
   gotoxy(40,17);
   cout<<dec5_tipo3_50_59;

   gotoxy(20,19);
   cout<<dec6_tipo1_60_69;
   gotoxy(30,19);
   cout<<dec6_tipo2_60_69;
   gotoxy(40,19);
   cout<<dec6_tipo3_60_69;

   gotoxy(20,21);
   cout<<dec7_tipo1_70_79;
   gotoxy(30,21);
   cout<<dec7_tipo2_70_79;
   gotoxy(40,21);
   cout<<dec7_tipo3_70_79;

   gotoxy(20,23);
   cout<<dec8_tipo1_80_89;
   gotoxy(30,23);
   cout<<dec8_tipo2_80_89;
   gotoxy(40,23);
   cout<<dec8_tipo3_80_89;

   gotoxy(20,25);
   cout<<dec9_tipo1_90_99;
   gotoxy(30,25);
   cout<<dec9_tipo2_90_99;
   gotoxy(40,25);
   cout<<dec9_tipo3_90_99;

pausa();
}




void menuReporte4(analisis *vExt,int cExt){

  ////////////************************************/////////////////////////////
  //EN ESTA FUNCION SOLO SE MUESTRA LOS QUE SI CUMPLEN LA CONDICION.
  ////////////************************************/////////////////////////////
    borrar();

float globR;
int mes,col,pos,edad;
int vMes[12];

float res=promEdadPacientes(vExt,cExt);
   // para cada mes del año 2016,
//informar el (protocolo) codigo de extracion que dio bien el colesterol y mal el glob rojos.

//int num;

   cout<<endl<<endl;
   cout<<"PUNTO 1."<<endl;
   for(int i=0;i<cExt;i++){
    if(vExt[i].FechaExt.anio==2016){
      col=vExt[i].nivelColesterol;
    globR=vExt[i].nivelGlobulosR;
    mes=vExt[i].FechaExt.mes;
    edad=vExt[i].edad;

    //num=vExt[i].codExt;

    if(( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && !(globR>=4.32 && globR<=5.66) ){

    vMes[mes-1]=mes;
    pos=i;


    cout<<"MES: " <<mes<<" .EXTRACCION: "<<vExt[pos].codExt<<endl;
    //cout<<"MES: "<<mes<<" EXT: "<<num<<endl;
    }
   }
   }



cout<<endl;

cout<<"PUNTO 2."<<endl;
cout<<endl;
cout<<"PROMEDIO DE EDAD ENTRE TODOS LOS PACIENTES: "<<res<<endl;

pausa();


}

float promEdadPacientes(analisis *vExt,int cExt){

float acum=0.0;
int cont=0;


for(int i=0;i<cExt;i++){
if(vExt[i].codExt>0   && vExt[i].FechaExt.anio==2016){
cont ++;
acum+=vExt[i].edad;

}
}
return (float)acum/cont;




}

void menuReporte5(analisis *vExt,int cExt){
borrar();
//ESTA FUNCION HACE LO MISMO QUE LA FUNCION 7. SOLO QUE ESTA NO TIENE EL VECTOR CONTADOR Y SE HACE MAS LARGO TODO.

int mes,mes1=0,mes2=0,mes3=0,mes4=0,mes5=0,mes6=0,mes7=0,mes8=0,mes9=0,mes10=0,mes11=0,mes12=0;
int col,edad;
float globB,globR;
for(int i=0;i<cExt;i++){


    if( (vExt[i].FechaExt.anio==2016) ){

          mes=vExt[i].FechaExt.mes;
          edad=vExt[i].edad;
          col=vExt[i].nivelColesterol;
          globR=vExt[i].nivelGlobulosR;
          globB=vExt[i].nivelGlobulosB;

        //TODOS LOS PARAMETROS NORMALES.
        switch(mes){

        case 1:    if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) )    {mes1++;}

        break;

        case 2:   if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes2++;}

        break;

        case 3:  if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes3++;   }

        break;

        case 4:  if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ) {mes4++; }

        break;

        case 5: if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes5++; }
        break;

        case 6: if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes6++; }
        break;

        case 7: if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes7++; }

        break;

        case 8:if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes8++; }
        break;

        case 9:if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes9++; }
        break;

        case 10: if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ) {mes10++; }
        break;

        case 11: if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ) {mes11++; }
        break;

        case 12: if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) ){mes12++; }
        break;

        }//CIERRA SWITCH
    }

}//CIERRA FOR.


    gotoxy(0,5);
    cout<<"MES";
    gotoxy(15,5);
    cout<<"CANTIDAD";
    gotoxy(0,6);
    cout<<"-----------------------------------------------";
    gotoxy(0,7);
    cout<<"1";
    gotoxy(0,8);
    cout<<"------------------------------------------------";
    gotoxy(0,9);
    cout<<"2";
    gotoxy(0,10);
    cout<<"------------------------------------------------";
    gotoxy(0,11);
    cout<<"3";
    gotoxy(0,12);
    cout<<"------------------------------------------------";
    gotoxy(0,13);
    cout<<"4";
    gotoxy(0,14);
    cout<<"------------------------------------------------";
    gotoxy(0,15);
    cout<<"5";
    gotoxy(0,16);
    cout<<"------------------------------------------------";
    gotoxy(0,17);
    cout<<"6";
    gotoxy(0,18);
    cout<<"------------------------------------------------";
    gotoxy(0,19);
    cout<<"7";
    gotoxy(0,20);
    cout<<"------------------------------------------------";
    gotoxy(0,21);
    cout<<"8";
    gotoxy(0,22);
    cout<<"------------------------------------------------";
    gotoxy(0,23);
    cout<<"9";
    gotoxy(0,24);
    cout<<"------------------------------------------------";
    gotoxy(0,25);
    cout<<"10";
    gotoxy(0,26);
    cout<<"------------------------------------------------";
    gotoxy(0,27);
    cout<<"11";
    gotoxy(0,28);
    cout<<"------------------------------------------------";
    gotoxy(0,29);
    cout<<"12";
    gotoxy(0,30);
    cout<<"------------------------------------------------";

    gotoxy(15,7);
    cout<<mes1<<endl;
    gotoxy(15,9);
    cout<<mes2<<endl;
    gotoxy(15,11);
    cout<<mes3<<endl;
    gotoxy(15,13);
    cout<<mes4<<endl;
    gotoxy(15,15);
    cout<<mes5<<endl;
    gotoxy(15,17);
    cout<<mes6<<endl;
    gotoxy(15,19);
    cout<<mes7<<endl;
    gotoxy(15,21);
    cout<<mes8<<endl;
    gotoxy(15,23);
    cout<<mes9<<endl;
    gotoxy(15,25);
    cout<<mes10<<endl;
    gotoxy(15,27);
    cout<<mes11<<endl;
    gotoxy(15,29);
    cout<<mes12<<endl;

pausa();

}
void ponerceromes(int *);
void menuReporte7(analisis *vExt,int cExt){
borrar();

///POR CADA MES MES DEL AÑO DEL 2016,LA CANTIDAD DE PERSONAS QUE TIENEN TODOS LOS ITEMS DEL ANALISIS COL,GROJOS,GBLANCOS,
///DENTRO DE LOS PARAMETROS NORMALES
///PARA METROS NORMALES...

/***
Colesterol
EDAD(HASTA )        VALORES ACEPTABLES(HASTA)

18                  170

99                  240
**/

/**
Globulos Rojos
Minimo              Maximo

4.32                5.66
**/

/**
Globulos Blancos
Minimo              Maximo

3.7                 9.5
**/

int col,edad,cont=0,mes;

float globB,globR;

int vMes[12];

int valor;
int cant;
ponerceromes(vMes);

cont=0;
for(int i=0;i<cExt;i++){

          mes=vExt[i].FechaExt.mes;
          edad=vExt[i].edad;
          col=vExt[i].nivelColesterol;
          globR=vExt[i].nivelGlobulosR;
          globB=vExt[i].nivelGlobulosB;

if (( (edad <=18 && col<=170 )   || (edad<=99 && col<=240) )  && (globR>=4.32 && globR<=5.66) && (globB >=3.7 && globB<=9.5) )  {
    vMes[vExt[i].FechaExt.mes-1]++;

}
}

for(int i=0;i<12;i++){
if(vMes[i]!=0 || vMes[i]==0){

    cout<<"MES: "<<i+1 << " CANTIDAD: "<<vMes[i]<<endl;

}
cout<<endl;
}
pausa();
}

void ponerceromes(int *vmes){
for(int j=0;j<12;j++){
    vmes[j]=0;
}
}
#endif // REPORTES_H_INCLUDED
