using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using Dominio;

namespace Negocio
{
    public class PokemonNegocio
    {

        //para el eliminar
       private AccesoDatos datos;

        //este listar no se usa en la ultima version se usa el listar3
        public List<Pokemon> listar2()
        {

            ////select Nombre, P.Descripcion, UrlImagen, T.Descripcion Tipo, D.Descripcion Debilidad from POKEMONS P, ELEMENTOS T, ELEMENTOS D Where P.IdTipo = T.Id and P.IdDebilidad = D.Id


            List<Pokemon> lista = new List<Pokemon>();
            SqlConnection conexion = new SqlConnection();
            SqlCommand comando = new SqlCommand();
            SqlDataReader lector;

            try
            {

                conexion.ConnectionString = "data source =.\\SQLEXPRESS; initial catalog = POKEDEX_DB; integrated security = sspi";
                comando.CommandType = System.Data.CommandType.Text;
                comando.CommandText = "select Numero, Nombre, P.Descripcion, UrlImagen, T.Descripcion Tipo, D.Descripcion Debilidad from POKEMONS P, ELEMENTOS T, ELEMENTOS D Where P.IdTipo = T.Id and P.IdDebilidad = D.Id";
                comando.Connection = conexion;


                conexion.Open();
                lector = comando.ExecuteReader();

                while (lector.Read())
                {

                    Pokemon aux = new Pokemon();
                    aux.Numero = (int)lector["Numero"];
                    aux.Nombre = (string)lector["Nombre"];
                    aux.Descripcion = lector.GetString(2);//otra manera de hacer lo de arriba
                    aux.UrlImagen = (string)lector["UrlImagen"];

                    aux.Tipo = new Elemento((string)lector["Tipo"]);
                    aux.Debilidad = new Elemento((string)lector["Debilidad"]);

                    lista.Add(aux);




                }

                return lista; ///fundamental para devolver la lista (si no se pone el listar2 no anda)

            }

            catch (Exception ex)
            {

                throw ex;
            }

        }//Fin listar2()


        public void agregar(Pokemon nuevo)
        {

            AccesoDatos datos = new AccesoDatos();

            try
            {

                //aca ponemos a mano en el botono agregar de esta forma, no tocamos la base en el ejemplo de maxi aca 
                //si no lo hacemos aca 
                //hacer despues el debilidad (por que maxi parcheo idDevilidad para que nascan con 1)
                string valores = "values("+ nuevo.Numero + ", '" +nuevo.Nombre + "', '" + nuevo.Descripcion + "', '"+ nuevo.UrlImagen + "', "+nuevo.Tipo.Id +" ,1 )";
                datos.setearConsulta("insert into POKEMONS(Numero, Nombre, Descripcion, UrlImagen, IdTipo, idDebilidad )" + valores);

                datos.ejecutarAccion();



            }
            catch (Exception ex)
            {

                throw ex;
            }


            finally
            {
                datos.cerrarConexion();
            }

        }//Cierra agregar

        public void modificar(Pokemon modificar)
        {

            AccesoDatos datos = new AccesoDatos();

            try
            {

                datos.setearConsulta("update POKEMONS set Nombre = @nombre , Descripcion = @descripcion ,UrlImagen = @urlImagen,Numero = @numero, IdTipo = @idTipo , IdDebilidad = 1 where Id = @id");
                datos.setearParametro("nombre", modificar.Nombre);
                datos.setearParametro("@descripcion" , modificar.Descripcion);
                datos.setearParametro("@urlImagen", modificar.UrlImagen);
                datos.setearParametro("@numero",modificar.Numero);
                datos.setearParametro("@idTipo",modificar.Tipo.Id);
                datos.setearParametro("@id",modificar.Id);

                datos.ejecutarAccion();

            }
            catch (Exception ex)
            {

                throw ex;
            }
            finally
            {
                datos.cerrarConexion();
            }



        }//Cierra modificar
        
        public void eliminar(int id)
        {
            //aca el profe para no crear la variable cada vez, la uso instanciada ,arriba esta
            //la propiedad

            datos = new AccesoDatos();

            try
            {
                datos.setearConsulta("Delete from POKEMONS where Id = " + id);
                datos.ejecutarAccion();
            }
            catch (Exception ex)
            {

                throw ex;
            }
            finally
            {
                datos.cerrarConexion();
                datos = null;
            }



        }//cierra eliminar



        public List<Pokemon> listar3()
        {

            ////select Nombre, P.Descripcion, UrlImagen, T.Descripcion Tipo, D.Descripcion Debilidad from POKEMONS P, ELEMENTOS T, ELEMENTOS D Where P.IdTipo = T.Id and P.IdDebilidad = D.Id


            List<Pokemon> lista = new List<Pokemon>();
            AccesoDatos datos = new AccesoDatos();


            try
            {

                datos.setearConsulta("select P.Id, Numero, Nombre, P.Descripcion, UrlImagen, T.Descripcion Tipo, D.Descripcion Debilidad, T.Id IdTipo ,D.Id IdDebilidad from POKEMONS P, ELEMENTOS T, ELEMENTOS D Where P.IdTipo = T.Id and P.IdDebilidad = D.Id");
                datos.ejecutarLectura();  
              
              

                while (datos.Lector.Read())
                {

                    Pokemon aux = new Pokemon();
                    aux.Id = (int)datos.Lector["Id"];
                    aux.Numero = (int)datos.Lector["Numero"];
                    aux.Nombre = (string)datos.Lector["Nombre"];
                    aux.Descripcion = datos.Lector.GetString(3);//otra manera de hacer lo de arriba
                    aux.UrlImagen = (string)datos.Lector["UrlImagen"];



                    aux.Tipo = new Elemento((string)datos.Lector["Tipo"]);
                    aux.Tipo.Id = (int)datos.Lector["IdTipo"];//para el modificar,leo los Id 

                    aux.Debilidad = new Elemento((string)datos.Lector["Debilidad"]);
                    aux.Debilidad.Id = (int)datos.Lector["IdDebilidad"];//para el modificar,leo los Id

                    lista.Add(aux);




                }

                return lista; ///fundamental para devolver la lista (si no se pone el listar2 no anda)

            }

            catch (Exception ex)
            {

                throw ex;
            }

            ///Bloque de excepciones
            finally
            {
                datos.cerrarConexion();
            }

        }//Fin listar3()


        }
}


