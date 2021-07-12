/*

esto es lo que se vio en clase 04
aca lo que estamos haciendo es seleccion de datos,
esto lo que va a permitir el SELECT es que cuando tengamos datos,
en una base y una aplicacion que se conecte a la base . con los select
vamos a poder traer informacion a su aplicacion  y mostrarla,procesarla
exportarla lo que necesiten .
-----------------------------------------------------------------------

esto hay que ver los apuntes y el video que subio el profe en el campus
en cambio update,delete e insert sirven para modificar,eliminar registros
el delete ,para modificar el update para insertar nuevo el insert 
y con eso tendriamos basicamente el alta,baja ,la modificacion y los listados
resueltos.
*/

/*
--use MonkeyUniv

*/

/*
select *from Cursos*****************
trae de una tabla,todas las columnas
*/

/*
--trae las columnas que le endique separado por como.
--de la tabla Cursos 
select Nombre,CostoCurso,CostoCertificacion from Cursos
*/

/*
--aca sumo el costocurso+costocertificacion
--nota: pero el resultado de la suma, de deja la columna sin nombre
--con el comando de abajo se soluciona

select Nombre,CostoCurso,CostoCertificacion,CostoCurso+CostoCertificacion from Cursos

*/

/*
	CON EL AS********************
esto permite poner el nombre a la columa que dio como resultado la suma
y tambiar cambiar el nombres de los demas filas de la tabla no de forma fisica,
seria en la visualizacion digamos



select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,CostoCurso+CostoCertificacion as Total from Cursos
*/ 

/*
a una suma puedo hacerle una operacion matematica
por ejemplo a la promo un 10% de descuento 
nota: separar en terminos

--Consulta 1 ACTIVIDAD

select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,
(CostoCurso+CostoCertificacion) * 0.9 as Promo from Cursos

*/



/*SELECT TOP 1**********************
--Esto trae un solo curso de la tabla 
select top 1 Nombre ,CostoCurso from Cursos
*/


/*ORDER BY desc 20,10  , asc 10,20**************
Orden de abajo para arriba
trae el listado ordenado del costo del curso, del mas caro al mas barato ej 200,100 etc


select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,
(CostoCurso+CostoCertificacion) * 0.9 as Promo,Estreno from Cursos
order by CostoCurso desc
*/

/*
esto es lo mismo que arriba pero del mas barato al mas caro ej: 100,200

select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,
(CostoCurso+CostoCertificacion) * 0.9 as Promo,Estreno from Cursos
order by CostoCurso asc 

*/


/*
--esto es lo mismo que arriba pero con la logica del abecedario (alfanumericamente)ej: ajedrez ,b, c etc


select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,
(CostoCurso+CostoCertificacion) * 0.9 as Promo,Estreno from Cursos
order by Nombre asc 
*/


/*
--esto es lo mismo que arriba pero con ordenamiento del tipo fecha,
al ser creciente la fecha mas antigua primero

select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,
(CostoCurso+CostoCertificacion) * 0.9 as Promo,Estreno from Cursos
order by Estreno asc

*/ 

/*
--Esto trae el curso mas caro en este caso 50000
select top 1 Nombre,CostoCurso from Cursos
order by CostoCurso desc
*/

/*
--El curso fecha mas antigua en este caso ajedrez
nota: esto no contempla que alla empate entre los registos. 
select top 1 Nombre,CostoCurso from Cursos
order by Estreno asc 
*/

--Top******************
/*with ties**************************
--este es como el de arriba pero si contempla los empates,
--si hay empates trae todos  los que empaten

select top 1 with ties Nombre, CostoCurso from Cursos
order by Estreno asc  
*/

/*
--trae todas las fechas en donde huvo estreno 
nota: pero los trae repetidos 
select Estreno from Cursos
*/

/*
distinct ******************************
esto es lo mismo que lo de arriba pero no duplica las fechas de estreno en este caso

select distinct Estreno from Cursos
*/


/*
1) hacer la bases de datos
2) cargar datos a las bases
3) hacer las seleccion

si hay problemas borrar la base de datos y hacer los
mismos 3 pasos
use master
go
drop database MonkeyUniv
*/


/* WHERE *********
APARTIR DE ACA SE VE LO DE LA CLASE DE ZOOM CLASE 04 PARTE 3 
****************************

-- 5	Listado con ID, nombre, costo de inscripción e ID de nivel de todos los cursos cuyo
-- costo de certificación sea mayor a $ 1200.



select ID,Nombre,CostoCurso,IDNivel  from Cursos where CostoCertificacion > 1200

*/

/*
select ID,Nombre,CostoCurso,IDNivel from Cursos 
where CostoCertificacion > 1200 and CostoCertificacion < 5000
 */


 /*
 -- 7	Listado con nombre, número y duración de todas las clases del curso con ID número 10.

 ***NOTA: AHORA EN FROM ES DE LA TABLA CLASES


 esto si
 si existe puede traer: muchas,alguna, y si no existe no trae ninguna


 select Nombre,Numero,Duracion from Clases where IDCurso =10 

 */


 /*
 select Nombre,Numero,Duracion from Clases where IDCurso !=10 
 --esto seria tambien como el !
 

  select Nombre,Numero,Duracion from Clases where IDCurso <>10

  */ 

  /*
  con esto se puede ordenar por otro criterio mas si hay empate
  en el primer criterio
  
   
   si se pone con esto de abajo se muestra asi:

   1 nombre Ajedrez costo 7000 certificacion 700 promo 6930 estreno 2008-04-11
   1 nombre Go costo 7000 certificacion 700 promo 6930 estreno 2008-04-11


   se soluciona poniendo asi :
   cuando el primer criterio tiene empate en este caso estreno ,
   se evalua por el segundo criterio en este case nombre

   

select Nombre, CostoCurso as Costo ,CostoCertificacion as Certificacion,
(CostoCurso+CostoCertificacion) * 0.9 as Promo,Estreno from Cursos
order by Estreno asc, Nombre desc
   */

/*   IN  ***************
-- 10	Listado con nombre, fecha de estreno y costo del curso de todos aquellos cuyo ID de nivel sea 1, 5, 6 o 7

select Nombre,Estreno,CostoCurso ,IDNivel from Cursos
where IDNivel = 1 or IDNivel = 5 or IDNivel = 6 or IDNivel = 7 or IDNivel=3

--ESTO ES SERIA COMO EL OR el IN ,pero como si vuera una especie de vector. 
select Nombre,Estreno,CostoCurso ,IDNivel from Cursos
where IDNivel in (1,5,6,7,3)

select Nombre,Estreno,CostoCurso ,IDNivel from Cursos
where Nombre in ('pixel art','python 101')

*/



/*
-- 12	Listado con nombre, duración y costo del curso de todos aquellos cuyo ID de nivel no sean 1, 5, 9 y 10.

el operador este <> seria el !=

select Nombre,Estreno,CostoCurso ,IDNivel from Cursos
where IDNivel <> 1 and IDNivel <> 5 and IDNivel <> 9 and IDNivel <>10

*/

/*
-- con el IN y tambien el NOT IN ***************

--esto seria como lo de arriba pero de una manera mas corta con el INT NEGADO (NOT IN)
select Nombre,Estreno,CostoCurso ,IDNivel from Cursos
where IDNivel  not in (1,5,9,10)

lista esto 1 nombre Bordado estreno 2018-07-03 costoCurso 5000.00 id nivel 3

si no lo niego y lo pongo asi where IDNivel (1,5,9,10)
--lista esto : 1 nombre Lenguague c estreno 2015-10-10 costoCurso 14000 idnivel = 5
--			1 nombre Python 101 estreno 2017-07-07 costoCurso 13000 idnivel = 5

*/

--FECHAS************************

-- 13	Listado con nombre y fecha de estreno de todos los cursos cuya fecha de estreno haya sido en el primer semestre del año 2019.

-- 14	Listado de cursos cuya fecha de estreno haya sido en el año 2020.

/*
set dateformat 'DMY'
select *from Cursos where Estreno >= '1/1/2020' and Estreno <= '31/12/2020'
*/

/*
--YEAR
select *from Cursos where year(Estreno) = 2020
*/

--INVESTIGAR ESTO DIJO EL PROFE.
--DATEPART 
--DATEDIFF y DATEADD



/*--BETWEEN ************************
-- 16	Listado de clases cuya duración se encuentre entre 15 y 90 minutos.

funciona con valores de fecha y valores de texto ademas de los valores numericos

select *from Clases where Duracion between 15 and 90

*/

/*--********ACA TRABAJAMOS CON LOS NULL
-- 18	Listado de cursos que no posean ID de nivel.

select Nombre,IDNivel from Cursos
where IDNivel is null

--ESTO ME TRAE EN ESTE CASO TODOS LOS QUE TIENEN el id NULL

*/

/******is not null
esto seria lo opuesto de lo de arriba
aca con esto me traen los que no sean null Negand

select Nombre,IDNivel from Cursos where IDNivel is not null
*/

--  30/08/2020*********************
---VIDEOOO   (consultas de seleccion -Parte 1B (video youtube angel)
--use MonkeyUniv


--OPERADORES RELACIONALES
--select *from Cursos
--select Nombre from Cursos where IDNivel = 5
--select *from Cursos where year(Estreno) > 2010 
--select *from Cursos where IDNivel <> 5
--OPERADOR NOT

--select *from Cursos where not  IDNivel = 5 


--select *from Cursos

--select *from Cursos where year(Estreno)=2017 and Nombre ='Python 101'

--select *from Cursos where IDNivel = 2 or IDNivel = 3 or IDNivel = 4

---************************************---------------------
--OPERADOR IN (seria el or en sql)

--select *from Cursos where IDNivel in(2,3,4)

--select *from Cursos -TRABAJANDO CON LA FECHA 
--ME TRAE LOS ESTRENOS DEL CURSO DE ESAS FECHAS 
--select *from Cursos where year (Estreno) in(2015,2018,2019)


--si quiero que me traiga las fechas solicitadas y tambien ordenado: de formas ascendeste 
--select  *from Cursos where year (Estreno) in(2015,2018,2019) order by Estreno asc   

--****************************------------------------------
--OPERADOR BETWEEN 
--select *from Cursos where CostoCertificacion >= 4000 and CostoCertificacion <=7000 
--con el between simplifico lo de arriba

--select *from Cursos where CostoCertificacion between 4000 and 7000

--LISTA LOS QUE ESTAN DENTRO DE ESE RANGO EN EL ABECEDARIO
--select *from Cursos where Nombre between 'L' and 'P'


--set dateformat 'DMY'


--select *from Cursos where Estreno between '1/1/2017' AND '1/1/2019'

--TRABAJAR CON LOS VALORES NULL
--select *from Cursos

--Lista los idnivel que tengan null
--select *from Cursos where IDNivel is null

--select *from Cursos
--IS NULL , IS NOT NULL
--select *from Cursos where IDNivel is null and Nombre is not null


--Operador Like (MANEJO DE CADENAS)
--totalidad de la cadena
--select *from Cursos
--select *from Cursos where Nombre = 'Ajedrez'

--LO MISMO PERO CON EL OPERADOR LIKE
--select *from Cursos where Nombre like 'Ajedrez'


--Obtener un listado de cursos cuyo nombre contengan los caracteres 'ci'

--select *from Cursos where Nombre like '%ci%'
--lista cocina,introduccion,preparacion


--select *from Cursos where Nombre like '%as'
--lista los nombres que termines en as,lista damas etc.


--select *from Cursos
--obtener un listado cuyo nombre contenga una 'r' como tercer letra
--select *from Cursos where nombre like '__r%'

--Lista bordado lo de arriba

--VOCALES EN EL SEGUNDO CARACTER
--select *from Cursos where Nombre like '_[AEIOU]%'
--lista todos los nombres cuyo segundo caracter sea una vocal

--obtener un listado de cursos cuya nombre no contenga ningun numero

--select  *from Cursos where Nombre not like '%[0-9]%'









----************************************REVISAR**********************************
--mmmm dudoso verificacar con clase por zoom
--31/08/2020


--CLASE 05 joins practica
--use MonkeyUniv

--select *from Cursos

--select *from Clases
