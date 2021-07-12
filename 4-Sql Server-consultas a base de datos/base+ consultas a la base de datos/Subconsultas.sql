



--Subconsultas - en la clause Where
--Obtener aquellos alumnos que no hayan realizano ningun curso


---CON VIDEO TUTORIAL
--Subconsultas - en la clause Where
--Obtener aquellos alumnos que no hayan realizano ningun curso
select *from Usuarios where ID not in (
	select distinct IDUsuario from Inscripciones 
)


--ALL
--Obtener aquellos cursos que sean mas caros que CUALQUIER curso de IDNIVEL 5
--ALL
select *from cursos where CostoCurso > all (
	select CostoCurso from Cursos where IDNivel = 5
)

select *from Cursos

--ANY
--obtener aquellos cursos que sean mas caros que AL MENOS un curso de IDNIVEL 2

---MEJORAS ESTO DESPUES CON OTRA COSA QUE NO SEA IDNIVEL
	
	select * from Cursos where CostoCurso > any (
	select CostoCurso from Cursos where IDNivel= 2
	)  

--SUBCONSULTAS
--en la lista de columnas

--obtener todas las categorias y para cada una de ellas el costo del curso mas barato que le corresponda

select *from Categorias_x_Curso
select *from Categorias



--MEJORAAR ESTO.,
select cxc.idcategoria, (
	select min(c.CostoCurso) from Cursos as c where c.ID = cxc.IDCurso

)as 'COSTO MAS BAJO'
from Categorias_x_Curso as cxc





--from Categorias as cat




 



----------------------





--actividad de consultas 

-- (1)  Listado con apellidos y nombres de los usuarios que no se hayan inscripto a cursos durante el año 2019.



