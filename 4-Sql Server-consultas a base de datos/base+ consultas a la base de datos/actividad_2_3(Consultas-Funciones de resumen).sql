



---EJEMPLOS CON EL APUNTE DE YOUTUBE DE ANGEL NO ES LA ACTIVIDAD AUN. ESO HACERLA!!

--select *from Datos_Personales
--select count(*) as cantidad from Datos_Personales --cantidad de datos


/*
select count(*) as 'CANTIDAD 1990' from Datos_Personales as d
where year(Nacimiento) between 1990 and 1999  ---LISTA CON EL COUNT LA CANTIDAD, QUE COMPLEN LA CONDICION DEL WHERE
*/


/*
select  d.Genero ,count(*) as 'Cantidad' from Datos_Personales as d
group by d.Genero
*/



/*
select cat.Nombre ,count (cat.ID) from Categorias_x_Curso as cxc 
inner join Categorias as cat on cat.ID= cxc.IDCategoria
group by cat.Nombre

--Lista La cantidad de cursos que tiene cada categoria
*/


/*

select cat.ID, cat.Nombre, count (cxc.IDCurso) from Categorias_x_Curso as cxc 
inner join Categorias as cat on cat.ID= cxc.IDCategoria
group by cat.ID, cat.Nombre

--Lista La cantidad de cursos que tiene cada categoria

*/

/*
select c.ID, c.Nombre ,count(c.ID)  from Categorias as c
inner join Categorias_x_Curso as cxc on cxc.IDCategoria =c.ID
group by c.ID , c.Nombre

--LO DE ARRIBA PERO AL REVEZ.
*/




/*

select c.IDNivel, count(*) from Cursos as c
group by c.IDNivel
--CANTIDAD DE CURSOS POR NIVELES.
*/


/*
select i.ID, i.Nombre , count(ixc.IDCurso) as Cantidad from Idiomas_x_Curso as ixc
inner join Idiomas as i on i.ID = ixc.IDIdioma
group by i.ID , i.Nombre

--cuenta la cantidad de cursos, por IDCurso , IDIdioma
*/

/*
select i.IDIdioma ,count (i.IDCurso) as Cantidad from Idiomas_x_Curso as i

group by i.IDIdioma

--cuenta la cantidad de cursos, que tiene cada idioma 
*/



--count(DISTINCT)*************************************************************
/*

select  count( distinct i.IDUsuario) as Cantidad from Cursos as c
inner join Inscripciones as i on c.ID= i.IDCurso
where c.ID =10

--CANTIDAD DE USUARIOS EN EL CURSO EDAD MEDIA ,si no le pongo el distinct
--los usuariarios con IDUsuarios que aparezcan varias veces los va a contar igual
--no estaria bien por que el usuario podria haberse incripto de nuevo en otra fechas

*/




--MIRAR MAÑANAAAAAAAAAAAA





---aca en en la tabla de cursos hay cursos que no tienen nivel ASI que son NULL





/*
--COUNT (*) CUENTA NULL, COUNT(TABLA) NO CUENTA NULLS ,
---EJEMPLOS DE NULL NO REPRESENTATIVOS PERO SIRVEN COMO EJEMPLO



select  c.IDNivel ,c.Nombre from Cursos as c
left join Niveles as n on c.IDNivel =n.ID 


select  c.IDNivel,  count(*) as 'CANTIDAD NIVELES EN CURSO' from Cursos as c
inner join Niveles as n on c.IDNivel =n.ID 
group by c.IDNivel

--LISTA LA CANTIDAD DE NIVELES QUE HAY PARA CADA CURSO (INNER JOIN)



select  c.IDNivel,  count(*) as 'CANTIDAD NIVELES EN CURSO' from Cursos as c
left join Niveles as n on c.IDNivel =n.ID 
group by  c.IDNivel

																						--y (LEFT JOIN)
--LISTA ,aca dice que hay 4 cantidad de cursos, con nivel NULL (CUENTA LOS NULL ACA, por el count(*) )




select  c.IDNivel,  count(c.IDNivel) as 'CANTIDAD NIVELES EN CURSO' from Cursos as c
left join Niveles as n on c.IDNivel =n.ID 
group by  c.IDNivel

--Lista, los que tienen con el count(c.IDNivel) ,(ACA NO TIENE EN CUENTA LOS NULL)


select c.Nombre, count(*) from Cursos as c
group by c.Nombre


*/

-----SUM-------------------------------------

select Cursos.CostoCurso from Cursos

select sum(c.CostoCurso) from Cursos as c


select sum(i.Costo) from Inscripciones as i



--total facturada de cursos por la cantidad de inscripost que hay en cada curso



select sum(i.Costo)
from Inscripciones as i


select u.NombreUsuario , sum(i.Costo) as 'Costo Curso' from Inscripciones as i 
inner join Usuarios as u on u.ID = i.IDUsuario
group by u.NombreUsuario




select  u.NombreUsuario, sum(i.Costo)  as 'Costo Curso' from Inscripciones as i 
right join Usuarios as u on   i.IDUsuario = u.ID
group by u.NombreUsuario

--LISTA LOS USUARIOS Y EL COSTO QUE PAGO POR EL CURSO AL INSCRIBIRSE
--LOS QUE NO PAGARON NADA TIENEN NULL


select  u.NombreUsuario, isnull (sum (i.Costo), 0)   as 'Costo Curso' from Inscripciones as i 
right join Usuarios as u on   i.IDUsuario = u.ID
group by u.NombreUsuario

--LISTA LOS USUARIOS Y EL COSTO QUE PAGO POR EL CURSO AL INSCRIBIRSE
--LOS QUE NO PAGARON NADA , SE LE PONE CERO CON LA FUNCION ISNULL( SUM(),0 )



------------**************************Count()*******************

select u.ID , u.NombreUsuario ,count(*)
from Inscripciones as i
right join Usuarios as u on u.ID = i.IDUsuario
group by u.ID ,u.NombreUsuario

--order by count(i.IDUsuario ) asc
--quiero saber la cantidad de  inscripciones que tiene cada usuario a cursos
--VA A CONTAR LOS NULL ACA

select  u.ID , u.NombreUsuario ,count(i.IDUsuario)
from Inscripciones as i
right join Usuarios as u on u.ID = i.IDUsuario
group by u.ID ,u.NombreUsuario
--order by count(i.IDUsuario ) asc
--quiero saber la cantidad de  inscripciones que tiene cada usuario a cursos
--VA A CONTAR NO CUENTA LOS NULL

-------------------------------------SUM**************-----------------------------------------

select   i.IDUsuario ,i.Fecha ,I.Costo, u.ID , u.NombreUsuario 
from Inscripciones as i
right join Usuarios as u on u.ID = i.IDUsuario
--WHERE u.NombreUsuario like '%blanco%'

-----------------------SELECCION PARA VER DATOS

select u.NombreUsuario , sum(i.Costo) as Costo
from Inscripciones as i
right join Usuarios as u on u.ID = i.IDUsuario
--WHERE u.NombreUsuario like '%blanco%'
group by u.NombreUsuario

--aca los que no pagaron van a tener NULL ,por que como costo tenian un valor 0 
--y sum () sin datos devuelve NULL.

---------------SELECCION PARA VER QUE SUM() SIN DATOS DEVUELVE NULL.
 
select u.NombreUsuario ,isnull (sum(i.Costo),0 )as Costo
from Inscripciones as i
right join Usuarios as u on u.ID = i.IDUsuario
--WHERE u.NombreUsuario like '%blanco%'
group by u.NombreUsuario

---A LOS QUE TENIAN NULL CON LA FUNCION ISNULL (SUM), SE SUSTITUYE POR 0 LOS NULL.
--POR QUE SUM SIN DATOS(OSEA QUE TENGAN NULL EN ESTE CASO) DEVUELVE NULL

--------------SELECCION PARA SOLUCIONAR LOS NULL SIN DATOS DE SUMA Y PONERLE 0

----------------------******************************************************************************

select u.NombreUsuario ,I.Fecha,isnull( sum(i.Costo),0 )
from Inscripciones as i
right join Usuarios as u on u.ID = i.IDUsuario
where i.IDUsuario is null
group by u.NombreUsuario , i.Fecha
order by i.Fecha asc

--LISTO GENTE QUE ES USUARIA PERO QUE NO PERTENECE A NINGUN, CURSO POR ESO NO FIGURAN LOS PAGOS

---------------------------------------------------------------------
select u.NombreUsuario  ,d.Apellidos, d.Nombres, count (i.IDUsuario)
from Usuarios as u
right join Inscripciones as i on i.IDUsuario = u.ID
right join Datos_Personales as d on u.ID = d.ID
group by u.NombreUsuario,d.Apellidos,d.Nombres--lista (cuenta cuantos cursos hizo cada usuario inscripto)

-------------------------------------------------------------------------------

select u.NombreUsuario ,d.Apellidos , isnull (sum(i.Costo), 0 )
from Usuarios as u
right join Inscripciones as i on i.IDUsuario = u.ID
right join Datos_Personales as d on u.ID = d.ID 
group by u.NombreUsuario , d.Apellidos
order by u.NombreUsuario ,d.Apellidos asc--lista (muestra la suma de cada cursos que se incribio los usuarios)













-- 9  Listado con la cantidad de cursos de nivel principiante.

select n.Nombre , count (c.IDNivel) as Cantidada
from Cursos as c
left join Niveles as n on n.ID= c.IDNivel
where n.Nombre like 'Principiante'
group by  n.Nombre


-- 10  Listado con la suma total de todos los pagos realizados en 2019.
--ver despues como arreglarlo.

select p.Fecha ,sum(p.Importe)
from Pagos as p 
where year (p.Fecha)= 2019
--where year(p.Fecha ) > 1/1/2019  and year(p.Fecha ) < 1/1/2020 
group by p.Fecha


-- 12  Listado con la cantidad de usuarios distintos que se hayan certificado.


select i.IDUsuario ,count(  i.IDUsuario)  from Inscripciones as i
left join Certificaciones as c on c.IDInscripcion=i.ID
group by i.IDUsuario




select i.IDUsuario , i.Fecha
from Inscripciones as i
left join Certificaciones as c on c.IDInscripcion = i.ID
where i.IDUsuario=13





-- (13)  Listado con el nombre del país y la cantidad de usuarios de cada país.
select P.Nombre, count(DAT.ID) as Cantidad from Paises as P
left join Datos_Personales as DAT
on P.ID = DAT.IDPais
group by P.Nombre
order by 2 desc



-- 15  Listado con el apellido y nombres de usuario y el importe más costoso de curso al cual se haya inscripto.

select  dat.Apellidos ,dat.Nombres, i.IDUsuario , max(i.Costo)
from Usuarios as u
right join Inscripciones as i on i.IDUsuario = u.ID
right join Datos_Personales as dat on dat.ID = u.ID
where u.ID is not null
group by dat.Nombres ,dat.Apellidos, i.IDUsuario 
order by dat.Apellidos , dat.Nombres asc

-- 17  Listado con el nombre del curso y cantidad de contenidos registrados. 
--Sólo listar aquellos cursos que tengan más de 10 contenidos registrados.

--select c.Nombre , cla.Nombre , con.IDTipo 


select c.Nombre ,count (con.ID)
from Cursos as c
left join Clases as cla on cla.IDCurso = c.ID
left join Contenidos as con on con.IDClase=cla.ID
group by c.Nombre 
having count(con.ID)>10


----

Select Cursos.Nombre as Curso, count(Contenidos.ID) as Cant_Contenido
From Cursos
Inner Join Clases on Cursos.ID=Clases.IDCurso
Inner Join Contenidos on Clases.ID=Contenidos.IDClase
Group by Cursos.Nombre
Having count(Contenidos.ID)>10  --version de jero compañero utn

-----

select c.Nombre ,cla.Nombre ,cla.Numero, cla.IDCurso,cla.Duracion , con.IDClase
from Cursos as c
left join Clases as cla on cla.IDCurso= c.ID
left join Contenidos as con on con.IDClase=cla.ID


-----------------------------***********************************-------------

--domingo 13/09/2020
-- 16  Listado con el nombre del curso, nombre del nivel, 
--cantidad total de clases y duración total del curso en minutos.
--mia

select c.Nombre , n.Nombre,sum(cl.Duracion),count(cl.IDCurso)
from Cursos as c 
inner join Clases as cl on cl.IDCurso=c.ID
left join Niveles as n on n.ID = c.IDNivel
group by c.Nombre ,n.Nombre

--compa

select Cursos.Nombre as Curso,Niveles.Nombre as Nivel, count(Clases.ID)as CantidadDeClases, Sum(Clases.Duracion) as duracionDelCurso
From  Cursos 
left Join Niveles on Cursos.IDNivel=Niveles.ID
left Join Clases on Cursos.ID = Clases.IDCurso
Group by Cursos.Nombre,Niveles.Nombre



-- 18  Listado con nombre del curso, nombre del idioma y cantidad de tipos de idiomas.

---mia
select c.Nombre  ,idi.Nombre ,count(t.ID)
from Cursos as c
inner join Idiomas_x_Curso as ixc on ixc.IDCurso = c.ID
inner join Idiomas as idi on idi.ID = ixc.IDIdioma
left join TiposIdioma as t on t.ID = ixc.IDTipo
group by c.Nombre , idi.Nombre
order by c.Nombre asc

--compa
Select c.Nombre as Curso ,i.Nombre as Idioma,COUNT(ixc.IDTipo) as Cant_Tipo_Idiomas 
From Cursos as C 
inner join Idiomas_x_Curso as IxC on C.ID=IxC.IDCurso
Inner join Idiomas as I on IxC.IDIdioma=I.ID
Inner Join TiposIdioma as T on IxC.IDTipo=T.ID
Group By  C.Nombre,I.Nombre
order by c.Nombre asc

-- 19  Listado con el nombre del curso y cantidad de idiomas distintos disponibles.

select c.Nombre  ,count(distinct ixc.IDIdioma)
from Cursos as c
inner join Idiomas_x_Curso as ixc on ixc.IDCurso = c.ID
Group By  C.Nombre 
order by c.Nombre asc


-- 20  Listado de categorías de curso y cantidad de cursos asociadas 
--a cada categoría. Sólo mostrar las categorías con más de 5 cursos.


--VERSION MIA

select cat.Nombre ,count(cxt.IDCurso)
from Categorias as cat
inner join Categorias_x_Curso as cxt on cxt.IDCategoria = cat.ID
group by cat.Nombre
having count(cxt.IDCurso) > 5


---VERSION COMPA
Select Cat.Nombre as Categoria,count(cxc.IDCategoria)
from Categorias as Cat
inner join Categorias_x_Curso as cxc on Cat.ID=cxc.IDCategoria
inner join Cursos As c on cxc.IDCurso=c.ID
Group by cat.Nombre
having count(cxc.IDCategoria)>5



-- 21  Listado con tipos de contenido y la cantidad de contenidos asociados a 
--cada tipo. Mostrar aquellos tipos que no hayan registrado contenidos con cantidad 0.

--Version mia
select t.ID,t.Nombre ,count(con.IDTipo)
from TiposContenido as t
left join Contenidos as con on con.IDTipo = t.ID
group by t.ID , t.Nombre

--version compa
Select t.Nombre as Nombre, Count(c.ID) as cantContenido
From TiposContenido as t
inner join Contenidos as c on T.ID=c.IDTipo 
Group By T.Nombre



-- 22  Listado con Nombre del curso, nivel, año de estreno y el total recaudado en concepto de inscripciones. 
--Listar aquellos cursos sin inscripciones con total igual a $0.

select c.Nombre ,n.Nombre, year(c.Estreno) ,sum(inc.Costo)
from Cursos as c
left join Inscripciones as inc on inc.IDCurso= c.ID
left join Niveles as n on n.ID =c.IDNivel
group by c.Nombre, n.Nombre ,c.Estreno






--Version compa

Select C.Nombre as Curso,N.Nombre as Nivel,year(C.Estreno) as AñoEstreno, sum(i.Costo) as TotalRecaudado
From Cursos as c
left join Niveles as N on C.IDNivel=n.ID
left join Inscripciones as i on c.ID=i.IDCurso
group by C.Nombre,n.Nombre,c.Estreno

-- LA OPCION QUE CREEMOS CORRECTA
Select C.Nombre as Curso,N.Nombre as Nivel,year(C.Estreno) as AñoEstreno,sum(case when p.importe is null then 0 else p.Importe end) as TotalRecaudado
From Cursos as c
left join Niveles as N on C.IDNivel=n.ID
left join Inscripciones as i on c.ID=i.IDCurso
Left join Pagos as p on i.ID=p.IDInscripcion
group by C.Nombre,n.Nombre,c.Estreno



-- 23  Listado con Nombre del curso, costo de cursado y certificación y cantidad de usuarios distintos
-- inscriptos cuyo costo de cursado sea menor a $10000 y cuya cantidad de usuarios inscriptos sea menor a 5
-- . Listar aquellos cursos sin inscripciones con cantidad 0

--Version mia

select c.Nombre ,c.CostoCurso ,c.CostoCertificacion ,count(distinct i.IDUsuario)
from Cursos as c
left join Inscripciones as i on i.IDCurso = c.ID
group by c.Nombre , c.CostoCurso , c.CostoCertificacion 
having c.CostoCurso < 10000 and count(distinct i.IDUsuario) < 5




--Version compa
Select c.Nombre as Curso,c.CostoCurso as CostoCursado, c.CostoCertificacion as CostoCertificacion,
case when c.CostoCurso < 10000 then count (distinct I.idusuario) end as CantUsuarios
From Cursos as c
left join Inscripciones as i on C.ID=i.IDCurso
Group by c.Nombre, c.CostoCurso,c.CostoCertificacion
having c.CostoCurso < 10000 and count( distinct I.idusuario)<5





-- 29  Listado con Apellidos y nombres, mail y duración total en concepto de clases de cursos a los que 
--se haya inscripto. Sólo listar información de aquellos registros cuya duración total supere los 400 minutos.

---Version mia
select dat.Apellidos , dat.Nombres , dat.Email ,sum(cla.Duracion)
from Datos_Personales as dat
inner join Usuarios as u on u.ID = dat.ID
inner join Inscripciones as inc on u.ID = inc.IDUsuario
inner join Cursos as c on inc.IDCurso = c.ID
inner join Clases as cla on cla.IDCurso = c.ID
group by dat.Apellidos , dat.Nombres , dat.Email 
having  sum(cla.Duracion) <400


--version compa
Select dat.Apellidos as Apellidos,dat.Nombres as Nombres ,dat.Email as Email,sum(Cla.Duracion) as Duracion
From Datos_Personales as dat
Inner Join Usuarios as U on Dat.ID=U.ID
Inner Join Inscripciones as i on U.ID =I.IDUsuario
Inner Join Cursos as C on I.IDCurso = C.ID
inner join Clases as Cla on C.ID=Cla.IDCurso
group by dat.Apellidos,dat.Nombres,dat.Email

having sum(Cla.Duracion)<400


-- 30  Listado con nombre del curso y recaudación total. La recaudación total consiste en la sumatoria
-- de costos de inscripción y de certificación. Listarlos ordenados de mayor a menor por recaudación.



--version mia  (ESTA MAL)

select c.Nombre, sum(c.CostoCurso+c.CostoCertificacion)
from Cursos as c
group by c.Nombre
order by sum(c.CostoCurso+c.CostoCertificacion) desc 


--version compa

SElect  C.Nombre as Curso, Sum(i.Costo + cer.Costo) as RecaudacionTotal
from Cursos as c
 inner join Inscripciones as i on c.ID=i.IDCurso
 inner join Certificaciones as cer on i.ID=cer.IDInscripcion
group by C.Nombre
order by Sum(i.Costo + cer.Costo) desc

select *from Cursos