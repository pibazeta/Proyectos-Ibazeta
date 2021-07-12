using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dominio;

namespace Negocio
{
 public class ElementoNegocio
    {

        public List<Elemento> listar()
        {

            List<Elemento> lista = new List<Elemento>();
            AccesoDatos datos = new AccesoDatos();

            try
            {

                datos.setearConsulta("select id, descripcion from ELEMENTOS");
                datos.ejecutarLectura();

                while (datos.Lector.Read())
                {
                    //otra forma de hacer lo que hacemos lo de pokemon.cs con aux
                    //no hace falta el aux aca,creamos un elemento y le pasamos 2 atributos
                    //y lo asignamos a add

                    lista.Add(new Elemento((int)datos.Lector["id"], (string)datos.Lector["descripcion"]));
                }



                return lista;
            }


            catch (Exception ex)
            {

                throw ex;
            }

            finally
            {
                datos.cerrarConexion();
            }


        }//Ceirra listar


    }
}
