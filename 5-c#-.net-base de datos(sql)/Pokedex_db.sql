
--use master
--drop database POKEDEX_DB

create database POKEDEX_DB
go
use POKEDEX_DB
go

create table ELEMENTOS(
	
	Id int primary key IDENTITY(1,1) NOT NULL,
	Descripcion varchar(50) NULL

)
go
create table POKEMONS(
	Id int primary key IDENTITY(1,1) NOT NULL,
	Numero int NULL,
	Nombre varchar(50) NULL,
	Descripcion varchar(50) NULL,
	UrlImagen varchar(300) NULL,
	IdTipo int NULL foreign key references ELEMENTOS(ID),
	IdDebilidad int NULL foreign key references ELEMENTOS(ID),
	IdEvolucion int NULL 
	--IdEvolucion int NULL foreign key references POKEMONS(ID)--ACA se relaciona con id de la tabla de pokemon


)



go


insert into POKEMONS values(1, 'Bulbasaur', 'Este Pokémon nace con una semilla en el lomo.', 'https://assets.pokemon.com/assets/cms2/img/pokedex/full/001.png', null, null, null)
insert into POKEMONS values(2, 'Ivysaur', 'Cuando le crece bastante el bulbo del lomo.', 'https://assets.pokemon.com/assets/cms2/img/pokedex/full/002.png', null, null, null)
insert into POKEMONS values(3, 'Venusaur', 'La planta florece cuando absorbe energía solar.', 'https://assets.pokemon.com/assets/cms2/img/pokedex/full/003.png', null, null, null)

go
insert into ELEMENTOS values ('Planta')
insert into ELEMENTOS values ('Fuego')
insert into ELEMENTOS values ('Agua')


go
-- actualiza tipo y debilidad a los pokemons
update pokemons set IdTipo = 1
update pokemons set IdDebilidad = 2

---

--select Numero,Nombre,Descripcion,UrlImagen from POKEMONS

/*
--Manera de joiniar
select Nombre , P.Descripcion , UrlImagen , T.Descripcion Tipo 

from POKEMONS P ,ELEMENTOS T
where P.IdTipo = T.Id
*/

-----otra forma de hacer lo de arriba
--este seria como un inner join (va al visual esta consulta)

--select Nombre , P.Descripcion , UrlImagen , T.Descripcion Tipo from POKEMONS P , ELEMENTOS T , ELEMENTOS D where P.IdTipo =T.Id and P.IdDebilidad = D.Id




select Numero, Nombre, P.Descripcion, UrlImagen, T.Descripcion Tipo, D.Descripcion Debilidad from POKEMONS P, ELEMENTOS T, ELEMENTOS D Where P.IdTipo = T.Id and P.IdDebilidad = D.Id


select id, descripcion from ELEMENTOS 

select *from POKEMONS
select *from ELEMENTOS

---el agregar, no hace falta ejecutar esto aca

/*
insert into POKEMONS values(111 , '', '', '', 111, 111, 111)

insert into POKEMONS (Numero, Nombre, Descripcion, UrlImagen , IdTipo)values(111, '', '', '', 111)
*/

---consulta para que traiga id tip en el modificar
select Numero, Nombre, P.Descripcion, UrlImagen, T.Descripcion Tipo, D.Descripcion Debilidad, T.Id IdTipo ,D.Id IdDebilidad from POKEMONS P, ELEMENTOS T, ELEMENTOS D Where P.IdTipo = T.Id and P.IdDebilidad = D.Id


--para setear en el modificar(va en pokemonNegocio , en modificar)

select * from POKEMONS
--si seleccionamos esto aca no afenca a ninguno por que el id 999 no existe
--esta consulta despues en el c# es cambiana por los @
update POKEMONS set Nombre = ' ' , Descripcion = '' ,UrlImagen = '', IdTipo = 999 , IdDebilidad = 999 where Id = 999


