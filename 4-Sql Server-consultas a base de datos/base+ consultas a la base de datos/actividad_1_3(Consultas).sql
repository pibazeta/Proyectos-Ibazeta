--select getdate() --seria como un hola mundo es para verificar 
---que la base este conectada

/*
-- (1) Listado con nombre de usuario de todos los usuarios y sus respectivos nombres y apellidos.
--use MonkeyUniv

--TRAEMOS DATOS DE 2 TABLAS
select  u.NombreUsuario ,dat.Apellidos, dat.Nombres , dat.Email
from Usuarios as U
inner join Datos_Personales as dat on dat.ID = u.ID
*/

	
/*
Tip de angel
--PARA probar si NULL esta como string y no como dato NULL


where dat.Email is null  - esto listaria los mail con null 

--en el caso que no esten con NULL ,los puedo actualizar asi:
	update Datos_Personales set email= NULL
	where email like 'null' --condicion para que cambie solo a null los mail que no tienen el tipo de datos null

*/


/* Tip angel
-- Lo que realiza la cláusula join en memoria
--esto va a traer todo los de las 2 tablas.
select *
from Usuarios as u
inner join Datos_Personales as dat on u.ID = dat.ID
*/

/*****************************************************************************************

-- (3) Listado con nombre de usuario, apellidos, nombres, email o celular de todos los usuarios que vivan en un domicilio
-- cuyo nombre contenga el término 'Presidente' o 'General'. NOTA: Si no tiene email, obtener el celular.


select  u.NombreUsuario ,dat.Apellidos, dat.Nombres , ISNULL(dat.Email,dat.Celular) as 
InfoContacto , dat.Domicilio

from Usuarios as U
inner join Datos_Personales as dat on dat.ID = u.ID
where dat.Domicilio like '%Presidente%' or dat.Domicilio like '%Obispo%' 


 
--con el % quiere decir cuyo domicilio contenga la palabra presidente

--funcion isnull(),los parametros son
--primero la expresion , y luego cual seria el valor de remplazo ,en caso de que el 
--primer parametro sea null

	--resumiendo la funcion con esos parametros se podria leer como:
	--si tenes el mail trae el mail , si mail tiene NULL remplazalo por el celular.

	--podria ponerlo asi tambien
	--ISNULL(dat.Email,'0') --como cadena por que el email es una cadena

	********************************************************/








/***********************************************************************4 tablas ,order by

-- (5) Listado con apellido y nombres, nombre del curso y costo de la inscripción de todos los usuarios 
--inscriptos a cursos  NOTA: No deben figurar los usuarios que no se inscribieron a ningún curso.

---ASI ES COMO LO PIDE EL ENUNCIADO

select dat.Apellidos , dat.Nombres , c.Nombre , i.Costo
from Cursos as c
inner join Inscripciones as i on c.ID = i.IDCurso
inner join Usuarios as u on u.ID = i.IDUsuario --Inscripcion es Muchos A MUCHOS
inner join Datos_Personales as dat on dat.ID = u.ID


---Y ACA ES CON UN LAVADO DE CARA MAS PROLIJO

select c.Nombre , dat.Apellidos , dat.Nombres , i.Costo
from Cursos as c 
inner join Inscripciones as i on c.ID = i.IDCurso
inner join Usuarios as u on u.ID = i.IDUsuario --Inscripcion es Muchos A MUCHOS
inner join Datos_Personales as dat on dat.ID = u.ID
order by c.Nombre asc , dat.Apellidos asc , dat.Nombres asc

****/


/*--EJEMPLO DE UNION--une 2 listados de formas horizontales


select dat.Apellidos , dat.Nombres , 'Estudiante' as Rol  --EL ESTUDIANTE SE ESCRIBIO NO ESTA EN LA BASE DE DATOS
from Cursos as c
inner join Inscripciones as i on c.ID = i.IDCurso   ---aca estan los que incriptos los estudiantes
inner join Usuarios as u on u.ID = i.IDUsuario  
inner join Datos_Personales as dat on dat.ID = u.ID
where c.ID=11
Union all
select dat.Apellidos , dat.Nombres , 'Instructor' as Rol
from Cursos as c
inner join Instructores_x_Curso as ixc on ixc.IDCurso = c.ID   ---Tabla de instXcurso
inner join Usuarios as u on u.ID = ixc.IDUsuario
inner join Datos_Personales as dat on dat.ID = u.ID
where c.ID=11


*/









/*

----ESTA FUI MI VERSION LA DE ANGEL ES MAS EFICAZ del ejercicio 5)


yo arranque NO ES MALA IDEA PERO LA DE ANGEL ES MEJOR
POR QUE EL PRIMERO BUSCA LA TABLA DIGAMOS QUE LE PASA LAS COSAS A LA TABLA QUE TIENE COMO RELACION

Y NO ASI FALTA HACER UN WHERE. por que el inner join es la que controla que existan las relaciones 
entre las tablas . (es la que se ocupa de verificar que cada tabla este relacionada)


select  dat.Apellidos , dat.Nombres ,cu.Nombre , INS.Costo
from Datos_Personales as dat 
inner join Usuarios as Us on us.ID= dat.ID
inner join Inscripciones as INS on INS.IDUsuario = Us.ID
inner join Cursos as Cu on Cu.ID = INS.IDCurso
where INS.IDUsuario = us.ID









**********************************************************/



/*
-- (12) Listado con nombre de idioma, código de curso y código de tipo de idioma. 
--Listar todos los idiomas indistintamente si no tiene cursos relacionados.

--ASI ES COMO PIDE EL ENUNCIADO
select i.Nombre, ixc.IDCurso ,ixc.IDTipo
from Idiomas as i
left join Idiomas_x_Curso as ixc on i.ID= ixc.IDIdioma  

*/


/*
-- 13 Listado con nombre de idioma de todos los idiomas que no tienen cursos relacionados.
select i.Nombre, ixc.IDCurso ,ixc.IDTipo
from Idiomas as i
left join Idiomas_x_Curso as ixc on i.ID= ixc.IDIdioma  
where ixc.IDCurso is null

*/


/*
-- (15) Listado con nombres y apellidos de todos los usuarios y el nombre del país en el que nacieron.
-- Listar todos los países indistintamente si no tiene usuarios relacionados.

select  dat.Apellidos ,dat.Nombres , p.Nombre as Pais
from Datos_Personales as dat
right join Paises as p on p.ID = dat.IDPais

*/

--use MonkeyUniv


---FIN DE LAS CLASE DE ANGEL

---practicando 03/09/2020


/*
-- 2 Listado con apellidos, nombres, fecha de nacimiento y nombre del país de nacimiento.


select Dat.Apellidos , Dat.Nombres ,Dat.Nacimiento , p.Nombre
from Datos_Personales as Dat
right join Paises as P on p.ID = Dat.IDPais

**********************/

/*
-- 4 Listado con nombre de usuario, apellidos, nombres, email o celular o domicilio como
-- 'Información de contacto'.  NOTA: Si no tiene email, obtener el celular y si no posee celular obtener el domicilio.


select u.NombreUsuario  ,dat.Apellidos , dat.Nombres ,ISNULL(dat.Email,dat.Celular) as InfoContacto
,ISNULL(dat.Celular,dat.Domicilio) as InfoContacto
from Usuarios as u 
inner join Datos_Personales as dat on dat.ID = u.ID 

*/


/*

-- 6 Listado con nombre de curso, nombre de usuario y mail de todos los inscriptos 
--a cursos que se hayan estrenado en el año 2020.


select c.ID, c.Nombre, c.IDNivel ,i.IDCurso,i.Fecha, dat.Email
from Cursos as c
inner join Inscripciones as i on c.ID = i.IDCurso 
inner join Usuarios as u on i.IDUsuario = u.ID
inner join Datos_Personales as dat on i.IDUsuario = dat.ID
where year (i.Fecha)=2020

*/



/*

-- 7 Listado con nombre de curso, nombre de usuario, apellidos y nombres, fecha de inscripción, 
--costo de inscripción, fecha de pago e importe de pago. Sólo listar información de aquellos 
--que hayan pagado.

select c.Nombre ,u.NombreUsuario ,dat.Apellidos , dat.Nombres ,i.Fecha as FechaIncripcion , 
i.Costo as CostoIncripcion ,p.Fecha as FechaPago ,p.Importe as ImportePago
from Cursos as c  
inner join Inscripciones as i on i.IDCurso = c.ID
inner join Pagos as p on p.IDInscripcion = i.ID
inner join Usuarios as u on u.ID = i.IDUsuario 
inner join Datos_Personales as dat on dat.ID = u.ID


*/


/*
-- 7 Listado con nombre de curso, nombre de usuario, apellidos y nombres, fecha de inscripción, 
--costo de inscripción, fecha de pago e importe de pago. 
---ESTO QUERIA PROBAR YO NO ESTABA EN ACTIVIDADES A HACER
--PARA PROBAR HICE QUE FIGUREN TAMBIEN LOS USUARIOS QUE NO NO PAGARON (CON EL LEFT JOIN)

select c.Nombre ,u.NombreUsuario ,dat.Apellidos , dat.Nombres ,i.Fecha as FechaIncripcion , 
i.Costo as CostoIncripcion ,p.Fecha as FechaPago ,p.Importe as ImportePago
from Cursos as c  
inner join Inscripciones as i on i.IDCurso = c.ID
left join Pagos as p on p.IDInscripcion = i.ID
inner join Usuarios as u on u.ID = i.IDUsuario 
inner join Datos_Personales as dat on dat.ID = u.ID

*/

/*
-- 8 Listado con nombre y apellidos, genero, fecha de nacimiento, mail, 
--nombre del curso y fecha de certificación de todos aquellos usuarios que se hayan certificado.


---ACA SOLO VA A LISTAR TODOS LOS QUE SE CERTIFICARON-
---estos agregados fueron mmios no los pide la actividad
select c.Nombre,dat.Nombres ,dat.Apellidos , dat.Genero ,dat.Nacimiento ,dat.Email ,i.IDUsuario ,ctf.Fecha 
from Cursos as c 
inner join Inscripciones as i on c.ID = i.IDCurso
inner join Certificaciones as ctf on ctf.IDInscripcion = i.ID  
inner join Usuarios as u on u.ID = i.IDUsuario
inner join Datos_Personales as dat on dat.ID = u.ID


*/

/*

select c.Nombre,dat.Nombres ,dat.Apellidos , dat.Genero ,dat.Nacimiento ,dat.Email ,i.IDUsuario ,ctf.Fecha 
from Cursos as c 
inner join Inscripciones as i on c.ID = i.IDCurso
left join Certificaciones as ctf on ctf.IDInscripcion = i.ID  ---con esto le agrego NULL a los que no se certificaron
inner join Usuarios as u on u.ID = i.IDUsuario
inner join Datos_Personales as dat on dat.ID = u.ID


*/
--PRACTICANDO GUIA JOINS 08/09
--1&

/*
-- 16 Listado con nombre de curso, fecha de estreno y nombres de usuario de todos los inscriptos.
-- Listar todos los nombres de usuario indistintamente si no se inscribieron a ningún curso.

select c.Nombre as NombreCurso , c.Estreno as FechaEstreno , u.NombreUsuario
from Cursos as c
inner join Inscripciones as i on c.ID = i.IDCurso 
right join Usuarios as u on u.ID = i.IDUsuario

*/

/*
 ESTA ESTA MUY BUENA A TENER EN CUENTA , 
si hay un pk y fk relacionado entre las tablas, si con algun right no existe que tengan relacion los pk y fk
le va a meter nulls al joins l/r contrario que de la tabla que seleccione
 
-- 17 Listado con nombre de usuario, apellido, nombres, género, fecha de nacimiento 
--y mail de todos los usuarios que no cursaron ningún curso.


select u.NombreUsuario, d.Apellidos, d.Nombres ,d.Genero ,d.Nacimiento ,d.Email  
from Cursos as c
inner join Inscripciones as i on i.IDCurso = c.ID
right join Usuarios as u on i.IDUsuario = u.ID  --right me traigo todos los usuarios ,si no hay relacion a la tabla
												--Inscripciones se le van a ponel los NULL,y con eso me alcanza para
												--saber que el usuario no esta incripto a ningun curso.
													
inner join Datos_Personales as d on d.ID = u.ID

where i.IDCurso is null --CON ESTO FILTRO para que aparezcan los usuarios que no cursaron ningun curso.
							--como hay pk y fk si no escuentra relacion inmediatemente la tabla contiene NULL
							--por el right join 


*/




/*
--11 Listado con nombre y apellido de todos los usuarios que hayan cursado algún curso cuya categoría sea 'Historia'.


  --ESTA BIEN PERO EL DE ABAJO ESTA CON ORDENAMIENTO Y CON EL DISTINC PARA QUE NO ME TRAIGA LOS USUARIOS REPETIDOS
select  distinct d.Nombres , d.Apellidos 
from Datos_Personales as d
inner join Usuarios as u on u.ID = d.ID  
inner join Inscripciones as i on i.IDUsuario = u.ID
inner join Cursos as c on i.IDCurso = c.ID
inner join Categorias_x_Curso as cxc on c.ID = cxc.IDCurso 
inner join Categorias as cat on cxc.IDCategoria = cat.ID
where cat.Nombre = 'Historia'
order by d.Apellidos



--Version Angel  TIENE ORDER BY Y EL DISTINCT buenardoo
Select distinct DAT.Apellidos, DAT.Nombres From Datos_Personales as DAT
Inner Join Usuarios as U ON U.ID = DAT.ID
Inner Join Inscripciones as I ON U.ID = I.IDUsuario
Inner Join Cursos as C ON C.ID = I.IDCurso
Inner Join Categorias_x_Curso as CxC on C.ID = CxC.IDCurso
Inner Join Categorias as CAT ON CAT.ID = CxC.IDCategoria
Where CAT.Nombre = 'Historia'
Order by DAT.Apellidos
*/

/*
---PROBANDO CURSOS SIN RESEÑAS POR DIFERENTES USARIOS

select distinct   c.Nombre ,c.Estreno as EstrenoCurso , i.IDUsuario ,i.Fecha as FechaInscripto, r.Observaciones
from Cursos as c
inner join Inscripciones as i on c.ID = i.IDCurso
left join Reseñas as r on i.ID = r.IDInscripcion
where r.Observaciones is null

*/


/*
-- 17 Listado con nombre de usuario, apellido, nombres, género, fecha de nacimiento 
--y mail de todos los usuarios que no cursaron ningún curso
--esta bien pero no hace falta ir a cursos por que de cursos no quiero listar nada


select  u.NombreUsuario , d.Apellidos ,d.Nombres
from Cursos as c
inner join Inscripciones as i on c.ID = i.IDCurso
right join Usuarios as u on i.IDUsuario = u.ID  
inner join Datos_Personales as d on u.ID = d.ID

where i.IDCurso is null --cualquir valor de la tabla que elije va a tener null en este caso por el right join


/*


*/
--COPIAR ESTE EJERCICIO AL CUADERNO.
-- 17 Listado con nombre de usuario, apellido, nombres, género, fecha de nacimiento 
--y mail de todos los usuarios que no cursaron ningún curso
--esta bien pero no hace falta ir a cursos por que de cursos no quiero listar nada

--17 ) MEJORADO no hace falta que valla a la tabla cursos por que de ahi no me piden ningun dato a traer
--directamente en la tabla de inscripcion tengo los datos de la gente que esta inscripta a cursos,no hace falta
--hacer la relacion en este caso.

select u.NombreUsuario ,d.Apellidos,d.Nombres ,d.Genero ,d.Nacimiento , d.Email ,i.IDCurso  
from Inscripciones as i 
right join Usuarios as u on i.IDUsuario = u.ID  --izquiera 
inner join Datos_Personales as d on u.ID = d.ID 
where i.IDCurso is null --cualquir valor de la tabla que elije va a tener null en este caso por el right join

order by u.NombreUsuario asc

*/


/*
--9) Listados de Cursos con Nombre ,costo de cursado y certificacion ,costo total (cursado + certificado)
--con 10% de todos los cursos de Nivel principiante
select c.Nombre  , c.CostoCurso , c.CostoCertificacion ,n.Nombre , (c.CostoCurso+c.CostoCertificacion) *0.9 as CostoTotal
from Cursos as c
inner join Niveles as n on c.IDNivel= n.ID
where n.ID= 5 

*/

/*
--10 ) Listado con Nombre y Apellido de todos los instructores . sin Repetir

select distinct dat.Nombres ,dat.Apellidos 
from Instructores_x_Curso as ixc 
inner join Usuarios as u on ixc.IDUsuario = u.ID
inner join Datos_Personales as dat on u.ID = dat.ID
 
 */

 /*
 --14) Listado con Nombres (Revisar con lo del campus de los compañeros)

 select distinct idi.Nombre as NombreIdioma
 
 from Idiomas as idi
 inner join Idiomas_x_Curso as ixc on idi.ID = ixc.IDIdioma  
 inner join TiposIdioma as t on ixc.IDTipo = t.ID
 where t.ID = 2

 */

 /*
 --18 )

 select dat.Nombres, dat.Apellidos ,c.Nombre as NombreCurso , r.Puntaje , r.Observaciones
 from Cursos as c 
 inner join Inscripciones as i on c.ID = i.IDCurso 
 inner join Reseñas as r on i.ID = r.IDInscripcion
 inner join Usuarios as u on i.IDUsuario = u.ID
 inner join Datos_Personales as dat on u.ID = dat.ID

 where r.Inapropiada = 1
 */


 /*
 19)

 select  c.Nombre ,c.CostoCurso ,c.CostoCertificacion , c.Estreno , idi.Nombre as NombreIdioma, t.Nombre as TipoIdioma
 from Cursos as c
 inner join Idiomas_x_Curso as ixc on c.ID = ixc.IDCurso
 inner join Idiomas as idi on ixc.IDIdioma = idi.ID
 inner join TiposIdioma as t on ixc.IDTipo= t.ID
 where year(c.Estreno) < 2020
 order by c.Nombre asc ,t.Nombre asc

 */


 
 /* 20)
 select c.Nombre , p.Importe
 from Cursos as c
 inner join Inscripciones as i on c.ID = i.IDCurso
 inner join Pagos as p on i.ID = p.IDInscripcion
 order by c.Nombre asc

 */









 --los hizo angel en la clase del lunes 14/09/2020

 -- (14)  Listado con el apellido y nombres del usuario y el importe más costoso 
 --abonado como pago. Sólo listar aquellos que hayan abonado más de $7500.

 select dat.Apellidos ,dat.Nombres , max(p.Importe) 
 from Datos_Personales as dat
 inner join Usuarios as u on u.ID=dat.ID
 inner join Inscripciones as i on i.IDUsuario = u.ID
 inner join Pagos as p on p.IDInscripcion = i.ID
 group by dat.Apellidos , dat.Nombres 
 having  max(p.Importe) > 7500 --filtro para que traiga el maximo pago de cada usuario


 -- 22  Listado con Nombre del curso, nivel, año de estreno y el total recaudado en concepto 
 --de inscripciones. Listar aquellos cursos sin inscripciones con total igual a $0.

 select c.Nombre , n.Nombre ,year(c.Estreno) as Año, isnull (sum(i.Costo),0 ) as Rec
 from Cursos as c
 left join Niveles as n on n.ID = c.IDNivel
 left join Inscripciones as i on i.IDCurso =c.ID
 group by c.Nombre ,n.Nombre ,year(c.Estreno)


 -- 23  Listado con Nombre del curso, costo de cursado y certificación y cantidad 
 --de usuarios distintos inscriptos cuyo costo de cursado sea menor a $10000 y cuya cantidad
 --de usuarios inscriptos sea menor a 5. Listar aquellos cursos sin inscripciones con cantidad 0


 select c.Nombre , c.CostoCurso ,c.CostoCertificacion ,count(distinct i.IDUsuario)as 'Usuarios distintos'
 from Cursos as c
 left join Inscripciones as i on i.IDCurso = c.ID
 where i.Costo < 10000
 group by c.Nombre , c.CostoCurso ,c.CostoCertificacion
 having count(distinct i.IDUsuario) < 5



 -- 24  Listado con Nombre del curso, fecha de estreno y nombre del nivel del curso que más recaudó en 
 --concepto de certificaciones.

 select top 1 c.Nombre , year (c.Estreno) , n.Nombre 
 from Cursos as c
 left join Niveles as n on n.ID = c.IDNivel
 inner join Inscripciones as i on i.IDCurso = c.ID
 inner join Certificaciones as cer on cer.IDInscripcion = i.ID
 group by c.Nombre , year (c.Estreno) , n.Nombre 
 order by sum(cer.Costo) desc


 /* A TENER EN CUENTA MAX NO SE AGRUPA SE AGREGA A LA TABLA COMO COUT,SUM,MAX,MIN etc
 select  c.Nombre , year (c.Estreno) , n.Nombre ,max (cer.Costo)
 from Cursos as c
 left join Niveles as n on n.ID = c.IDNivel
 inner join Inscripciones as i on i.IDCurso = c.ID
 inner join Certificaciones as cer on cer.IDInscripcion = i.ID
 group by c.Nombre , year (c.Estreno) , n.Nombre
 
 
 */

-- 25  Listado con Nombre del idioma del idioma más utilizado como subtítulo.




select top 1 i.Nombre , count(*)
from Idiomas as i
inner join Idiomas_x_Curso as ixc on i.ID = ixc.IDIdioma
inner join TiposIdioma as ti on ti.ID = ixc.IDTipo
where ti.Nombre like 'Subtítulo'
group by i.Nombre


-- 26  Listado con Nombre del curso y promedio de puntaje de reseñas apropiadas.

select c.Nombre , avg(r.Puntaje)
from Cursos as c
inner join Inscripciones as i on i.IDCurso = c.ID
inner join Reseñas as r on r.IDInscripcion = i.ID
where r.Inapropiada = 0
group by c.Nombre


--27  Listado con Nombre de usuario y la cantidad de reseñas inapropiadas que registró.

select u.NombreUsuario ,count(r.IDInscripcion)
from Usuarios as u
left join Inscripciones  as inc on inc.IDUsuario = u.ID
left join Reseñas as r on r.IDInscripcion = inc.ID
where r.Inapropiada = 1 or r.Inapropiada is null
group by u.NombreUsuario




