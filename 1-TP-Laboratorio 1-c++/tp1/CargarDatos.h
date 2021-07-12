#ifndef CARGARDATOS_H_INCLUDED
#define CARGARDATOS_H_INCLUDED

void cargar(analisis *vExt,int *cExt){

vExt[0].codExt=100;
strcpy(vExt[0].dni,"1111");
strcpy(vExt[0].apellido,"Perez");
strcpy(vExt[0].nombre,"Lucas");
vExt[0].edad=21;
vExt[0].FechaExt.dia=10;
vExt[0].FechaExt.mes=1;
vExt[0].FechaExt.anio=2016;
vExt[0].tipoAnalisis=1;
vExt[0].nivelColesterol=140;
vExt[0].nivelGlobulosR=4.35;
vExt[0].nivelGlobulosB=10.5;


vExt[1].codExt=101;
strcpy(vExt[1].dni,"1111");
strcpy(vExt[1].apellido,"Perez");
strcpy(vExt[1].nombre,"Lucas");
vExt[1].edad=21;
vExt[1].FechaExt.dia=25;
vExt[1].FechaExt.mes=6;
vExt[1].FechaExt.anio=2016;
vExt[1].tipoAnalisis=1;
vExt[1].nivelColesterol=150;
vExt[1].nivelGlobulosR=4.39;
vExt[1].nivelGlobulosB=8.5;

vExt[2].codExt=102;
strcpy(vExt[2].dni,"1111");
strcpy(vExt[2].apellido,"Perez");
strcpy(vExt[2].nombre,"Lucas");
vExt[2].edad=21;
vExt[2].FechaExt.dia=21;
vExt[2].FechaExt.mes=7;
vExt[2].FechaExt.anio=2016;
vExt[2].tipoAnalisis=1;
vExt[2].nivelColesterol=180;
vExt[2].nivelGlobulosR=5.11;
vExt[2].nivelGlobulosB=7;

vExt[3].codExt=103;
strcpy(vExt[3].dni,"2222");
strcpy(vExt[3].apellido,"Gonzalez");
strcpy(vExt[3].nombre,"Maria");
vExt[3].edad=35;
vExt[3].FechaExt.dia=21;
vExt[3].FechaExt.mes=7;
vExt[3].FechaExt.anio=2016;
vExt[3].tipoAnalisis=2;
vExt[3].nivelColesterol=235;
vExt[3].nivelGlobulosR=4.12;
vExt[3].nivelGlobulosB=5.6;

vExt[4].codExt=104;
strcpy(vExt[4].dni,"2222");
strcpy(vExt[4].apellido,"Gonzalez");
strcpy(vExt[4].nombre,"Maria");
vExt[4].edad=35;
vExt[4].FechaExt.dia=10;
vExt[4].FechaExt.mes=8;
vExt[4].FechaExt.anio=2016;
vExt[4].tipoAnalisis=2;
vExt[4].nivelColesterol=255;
vExt[4].nivelGlobulosR=4.15;
vExt[4].nivelGlobulosB=4.3;


vExt[5].codExt=105;
strcpy(vExt[5].dni,"3333");
strcpy(vExt[5].apellido,"Martinez");
strcpy(vExt[5].nombre,"Juan");
vExt[5].edad=75;
vExt[5].FechaExt.dia=21;
vExt[5].FechaExt.mes=7;
vExt[5].FechaExt.anio=2016;
vExt[5].tipoAnalisis=3;
vExt[5].nivelColesterol=280;
vExt[5].nivelGlobulosR=4.8;
vExt[5].nivelGlobulosB=2.1;


*cExt=6;

}

#endif // CARGARDATOS_H_INCLUDED
