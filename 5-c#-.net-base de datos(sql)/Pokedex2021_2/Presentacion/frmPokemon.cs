using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Negocio;
using Dominio;

namespace Presentacion
{
    public partial class frmPokemon : Form
    {

        //Para el modificar

        private Pokemon pokemon = null;




        public frmPokemon()
        {
            InitializeComponent();
        }

        //Constructor
        public frmPokemon(Pokemon pokemon)
        {
            InitializeComponent();
            this.pokemon = pokemon;
            Text = "Modificar Pokemon"; //cambia el nombre a la ventana del modificar

        }

        private void frmPokemon_Load(object sender, EventArgs e)
        {
            System.Net.ServicePointManager.SecurityProtocol = System.Net.SecurityProtocolType.Tls12;

            ElementoNegocio elementoNegocion = new ElementoNegocio();

            try
            {

                cboTipo.DataSource = elementoNegocion.listar();
                cboTipo.ValueMember = "Id";
                cboTipo.DisplayMember = "Nombre";


                //el modificar
                if(pokemon != null)
                {
                    txtNombre.Text = pokemon.Nombre;
                    txtDescripcion.Text = pokemon.Descripcion;
                    txtUrlImagen.Text = pokemon.UrlImagen;
                    RecargarImg(txtUrlImagen.Text); //se pone aca asi en este formulario aparezla la imagen tambien
                    numNumero.Value = pokemon.Numero;

                    //con esto leo para que me traiga el nombre de la marca de lo leido arriba
                    cboTipo.SelectedValue = pokemon.Tipo.Id;


                }
          


            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {

            ///para la imagen
            System.Net.ServicePointManager.SecurityProtocol = System.Net.SecurityProtocolType.Tls12;


           // Pokemon nuevo = new Pokemon();
            PokemonNegocio pokemonNegocio = new PokemonNegocio();

            try
            {

                if (pokemon == null) //si pokemon esta en null quiere decir que no hay un pokemon cargado
                                 
                pokemon = new Pokemon();//creando instancia


                pokemon.Nombre = txtNombre.Text;
                pokemon.Descripcion = txtDescripcion.Text;
                pokemon.Numero = (int)numNumero.Value;
                pokemon.UrlImagen = txtUrlImagen.Text;
                //objeto tipo elemento
                pokemon.Tipo = (Elemento)cboTipo.SelectedItem;


                if(pokemon.Id == 0)
                {
                    pokemonNegocio.agregar(pokemon);
                    MessageBox.Show("Agregado sin problema");
                }
                else
                {
                    pokemonNegocio.modificar(pokemon);
                    MessageBox.Show("Modificado sin problema");

                }


                
                Close();

            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }


        }//cierra btnAceptar

        private void btnCancelar_Click(object sender, EventArgs e)
        {
            Close();
        }


        private void RecargarImg(string img)
        {
            try
            {
                pbxPokemon.Load(img);
                
            }
            catch (Exception ex)
            {

                MessageBox.Show("URL Imagen Invalida");
            }
            

        }

        //evento
        //esta muy bueno por que cuando ponemos en el campo urlimagen una url vacia , tira un carter,
        //si ponemos una correcta la cambia, muy buena validacion
        private void txtUrlImagen_TextChanged(object sender, EventArgs e)
        {

            RecargarImg(txtUrlImagen.Text);
        }
    }
}
