#ifndef EXTRACCIONES_H_INCLUDED
#define EXTRACCIONES_H_INCLUDED

bool cargarExtraccion(analisis *,int );
int  buscarCodExtraccion(analisis *,int ,int );
void listarExtraccion(analisis);
void listarExtracciones(analisis * ,int);

bool  editarExtraccion(analisis * ,int );
void listarExtraccionXcodigo(analisis *,int  );


void menuExtracciones (analisis *vExt, int *cExt){

int opc;

while(true){
borrar();
    cout<<"EXTRACCIONES ( "<<*cExt<< "de " <<15 << ")"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"1) CARGAR NUEVA EXTRACCION"<<endl;
    cout<<"2) EDITAR EXTRACCION "<<endl;
    cout<<"3) LISTAR TODAS LAS EXTRACCIONES "<<endl;
    cout<<"4) LISTAR EXTRACCION POR CODIGO "<<endl;

    cout<<"-------------------------------------------"<<endl;
    cout<<"0) VOLVER AL MENU ANTERIOR "<<endl;
    cout<<"INGRESE UNA OPCION: "<<endl;
    cin>>opc;

    switch(opc){
    case 1:

    if(*cExt+1<=15){
    if(cargarExtraccion(vExt,*cExt)== true) {
    *cExt=*cExt+1;
    cout<<"LA EXTRACCION SE CARGO CON EXITO";
    pausa();
    }
    else{
    cout<<"NO SE PUDO CARGAR LA EXTRACCION";pausa();
    }
    }
    else{
    cout<<"NO SE PUEDE CARGAR MAS EXTRACCIONES"; pausa();
    }
    break;

    case 2:
            if(*cExt>0){
           editarExtraccion(vExt,*cExt);
            }
            else{
            cout<<"NO SE PUEDO EDITAR.";  pausa();
            }

    break;

    case 3: if(*cExt > 0){
            listarExtracciones(vExt,*cExt);
            }
            else{
            cout<<"NO SE CARGARON EXTRACCIONES.";pausa();

            }

    break;
    case 4: if(*cExt>0){
            listarExtraccionXcodigo(vExt,*cExt);
            pausa();
            }


    case 0:return;
    break;
    }
}
}
//CIERRA MENU.

bool cargarExtraccion(analisis *vExt, int cant ){
borrar();
int pos,codExt;

    cout<<"CODIGO DE EXTRACCION: ";
    cin>>codExt;

    pos=buscarCodExtraccion(vExt,codExt,cant);

    if(pos>=0){
    cout<<"CODIGO DE EXTACCION REPETIDO.";pausa();return false;

    }


    vExt[cant].codExt=codExt;

    cout<<"DNI DEL PACIENTE: ";
    cin.ignore();
    cin.getline(vExt[cant].dni, 10);

    cout<<"APELLIDO DEL PACIENTE: ";
    cin.getline(vExt[cant].apellido,50);

    cout<<"NOMBRE DEL PACIENTE: ";
    cin.getline(vExt[cant].nombre,50);

    cout<<"EDAD DEL PACIENTE: ";
    cin>>vExt[cant].edad;

    if(vExt[cant].edad < 0  || vExt[cant].edad >100){
    cout<<"EDAD INVALIDA.";pausa();return false;
    }

    cout<<"FECHA DE LA EXTRACCION"<<endl;
    cout<<"DIA: ";
    cin>>vExt[cant].FechaExt.dia;
    cout<<"MES: ";
    cin>>vExt[cant].FechaExt.mes;
    cout<<"ANIO: ";
    cin>>vExt[cant].FechaExt.anio;

     if(vExt[cant].FechaExt.dia < 0 || vExt[cant].FechaExt.mes < 0 ||  vExt[cant].FechaExt.anio < 0){cout<<endl<<"LA FECHA ES INCORRECTA."; pausa(); return false;}
     if((vExt[cant].FechaExt.mes == 2 && vExt[cant].FechaExt.dia > 28) || vExt[cant].FechaExt.mes > 12 || vExt[cant].FechaExt.dia > 31 || vExt[cant].FechaExt.anio < 1500){cout<<endl<<"LA FECHA ES INCORRECTA."; pausa(); return false;}

     cout<<"TIPO DE ANALISIS: ";
     cin>>vExt[cant].tipoAnalisis;

     if( !(vExt[cant].tipoAnalisis>=1 && vExt[cant].tipoAnalisis <=3) ){   return false;}

     cout<<"NIVEL DE COLESTEROL: ";
     cin>>vExt[cant].nivelColesterol;
     if(vExt[cant].nivelColesterol <=0 ){
    cout<<"EL NIVEL DEL COLESTEROL DEBE SER MAYOR A CERO.";pausa();return false;
     }

     cout<<"NIVEL DE GLOBULOS ROJOS: ";
     cin>>vExt[cant].nivelGlobulosR;
    if(vExt[cant].nivelGlobulosR <=0 ){
    cout<<"EL NIVEL DE GLOBULOS ROJOS DEBE SER MAYOR A CERO.";pausa(); return false;
     }

    cout<<"NIVEL DE GLOBULOS BLANCOS: ";
    cin>>vExt[cant].nivelGlobulosB;
    if(vExt[cant].nivelGlobulosB <=0 ){
    cout<<"EL NIVEL DE GLOBULOS BLANCOS DEBE SER MAYOR A CERO.";pausa(); return false;
     }


return true;
}
//CIERRA CARGAREXTRACCION().

int buscarCodExtraccion(analisis *vExt,int codExt,int cant){

for(int i=0;i<cant;i++){
    if(vExt[i].codExt==codExt){
    return i;
    }
}
return -1;

}
//CIERRA BUSCARCODEXTRACCION().

void listarExtraccion(analisis reg){
    cout << "-----------------------" << endl;
    cout << "CODIGO DE EXTRACCION     : "<<reg.codExt<<endl;
    cout << "DNI DEL PACIENTE         : "<<reg.dni<<endl;
    cout << "APELLIDO DEL PACIENTE    : "<<reg.apellido<<endl;
    cout << "NOMBRE DEL PACIENTE      : "<<reg.nombre<<endl;
    cout << "EDAD                     : "<<reg.edad<<endl;
    cout << "FECHA DE EXTRACCION      : "<<reg.FechaExt.dia << "/" << reg.FechaExt.mes << "/" << reg.FechaExt.anio<<endl;
    cout << "TIPO DE ANALISIS         : "<<reg.tipoAnalisis<<endl;
    cout << "NIVEL DE COLESTEROL      : "<<reg.nivelColesterol<<endl;
    cout << "NIVEL DE GLOBULOS ROJOS  : "<<reg.nivelGlobulosR<<endl;
    cout << "NIVEL DE GLOBULOS BLANCOS: "<<reg.nivelGlobulosB<<endl;
    cout << "-----------------------" << endl;
}
//CIRRRA LISTAREXTRACCION().

void listarExtracciones(analisis *vExt, int cant){
borrar();
for(int i=0;i<cant;i++){
listarExtraccion(vExt[i]);
}
pausa();
}
//CIERRA LISTAREXTRACCIONES().


bool  editarExtraccion(analisis *vExt,int cant){

int codExt,pos;


    cout<<"INGRESE CODIGO DE EXTRACCION: ";
    cin>>codExt;

    pos=buscarCodExtraccion(vExt,codExt,cant);

    if(pos<0){cout<<"EL CODIGO DE EXTRACCION NO EXISTE.";pausa();}

    if(pos>=0){ listarExtraccion(vExt[pos]);pausa();   }

     int TIPOANALISIS;

    cout<<"TIPO DE ANALISIS: ";
    cin>>TIPOANALISIS;

    if ( !(TIPOANALISIS>=1 && TIPOANALISIS<=3 )){ cout<<"TIPO DE ANALISIS INCORECTO."; pausa();  return false;
   }
    else{
    vExt[pos].tipoAnalisis=TIPOANALISIS;
    }

    int NIVELCOLESTEROL;
    cout<<"NIVEL DE COLESTEROL: ";
    cin>>NIVELCOLESTEROL;

    if(NIVELCOLESTEROL<=0){return false;
    }
    else{
    vExt[pos].nivelColesterol=NIVELCOLESTEROL;
    }

    int NIVELGLOBULOSR;
    cout<<"NIVEL DE GLOBULOS ROJOS: ";
    cin>>NIVELGLOBULOSR;

    if(NIVELGLOBULOSR<=0){return false;
    }
    else{
    vExt[pos].nivelGlobulosR=NIVELGLOBULOSR;
    }

    int NIVELGLOBULOSB;
    cout<<"NIVEL DE GLOBULOS BLANCOS: ";
    cin>>NIVELGLOBULOSB;

    if(NIVELGLOBULOSR<=0){return false;
    }
    else{
    vExt[pos].nivelGlobulosR=NIVELGLOBULOSR;
    }

    int DIA,MES,ANIO;
    cout<<"FECHA DE LA EXTRACCION"<<endl;
    cout<<"DIA : ";
    cin>>DIA;
    cout<<"MES : ";
    cin>>MES;
    cout<<"ANIO: ";
    cin>>ANIO;

    if(DIA<0 || MES <0 || ANIO <0 ){
    cout<<endl<<"LA FECHA ES INCORECTA";  pausa(); return false;
    }
    if( (MES==2 && DIA>28) || MES>12 || DIA>31 || ANIO<1500  ){
    cout<<endl<<"LA FECHA ES INCORECTA";pausa();return false;}

    vExt[pos].FechaExt.dia=DIA;
    vExt[pos].FechaExt.mes=MES;
    vExt[pos].FechaExt.anio=ANIO;

    char DNI[10];

    cout<<"DNI: ";
    cin>>DNI;
    cin.ignore();
    cin.getline(vExt[pos].dni, 10);
    strcpy(vExt[pos].dni,DNI);

    //  cin.ignore();

    char APELIIDO[50];

    cout<<"APELLIDO: ";
    cin>>APELIIDO;
    cin.getline(vExt[pos].apellido,50);
    strcpy(vExt[pos].apellido,APELIIDO);

    char NOMBRE[50];

    cout<<"NOMBRE: ";
    cin>>NOMBRE;
    cin.getline(vExt[pos].nombre,50);
    strcpy(vExt[pos].nombre,NOMBRE);

    int EDAD;

    cout<<"EDAD: ";
    cin>>EDAD;

    vExt[pos].edad=EDAD;


return true;
}
//CIERRA FUNCION EDITAREXTRACCION();

void listarExtraccionXcodigo(analisis *vExt,int cant){
int pos,codextBuscado;

borrar();

cout<<"INGRESE CODIGO DE EXTRACCION: ";
cin>>codextBuscado;

pos=buscarCodExtraccion(vExt,codextBuscado,cant);

    if(pos>=0){
    listarExtraccion(vExt[pos]);
    }
    else{
    cout<<"EL CODIGO DE EXTRACCION NO EXISTE"<<endl;

    }

pausa();

}
//CIERRA FUNCION LISTAREXTRACCIONPORCODIGO();



#endif // EXTRACCIONES_H_INCLUDED
