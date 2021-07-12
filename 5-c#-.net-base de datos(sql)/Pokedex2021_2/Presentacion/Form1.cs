using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Dominio;
using Negocio;

namespace Presentacion
{
    public partial class Form1 : Form
    {

        private List<Pokemon> listaPokemons;  //el listar pokemons




        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {


            cargarGrilla();


        }


        private void cargarGrilla()
        {

            System.Net.ServicePointManager.SecurityProtocol = System.Net.SecurityProtocolType.Tls12;

            PokemonNegocio pokemonNegocio = new PokemonNegocio();



            try
            {
                listaPokemons = pokemonNegocio.listar3(); //aca llamamos a donde tenemos todo lo de sql
                dgvPokemons.DataSource = listaPokemons;

                //dgvPokemons.Columns["Id"].Visible = false;
                //dgvPokemons.Columns["Ficha"].Visible = false;
                //dgvPokemons.Columns["Descripcion"].Visible = false;
                //dgvPokemons.Columns["UrlImagen"].Visible = false;
                //dgvPokemons.Columns["Evolucion"].Visible = false;


                //esto son los campos de arriba en una funcion , para el filtro
                ocultarColumnas();

                RecargarImg(listaPokemons[0].UrlImagen);




            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.ToString());
            }


        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            frmPokemon agregar = new frmPokemon();
            agregar.ShowDialog();
            cargarGrilla();
        }

        private void RecargarImg(string img)
        {

            pbxPokemon.Load(img);

        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void dgvPokemons_MouseClick(object sender, MouseEventArgs e)
        {
            Pokemon seleccionado = (Pokemon)dgvPokemons.CurrentRow.DataBoundItem;//seleciono
            RecargarImg(seleccionado.UrlImagen);//llamo al recargar ,esto para que la imagen se cambie

        }


        private void ocultarColumnas()
        {


            dgvPokemons.Columns["Id"].Visible = false;
            dgvPokemons.Columns["Ficha"].Visible = false;
            dgvPokemons.Columns["Descripcion"].Visible = false;
            dgvPokemons.Columns["UrlImagen"].Visible = false;
            dgvPokemons.Columns["Evolucion"].Visible = false;


        }

        private void pbxPokemon_MouseClick(object sender, MouseEventArgs e)
        {
            //Pokemon seleccionado = (Pokemon)dgvPokemons.CurrentRow.DataBoundItem;
            //RecargarImg(seleccionado.UrlImagen);
        }

        //esta no hace falta
        private void btnAgregarElemento_Click(object sender, EventArgs e)
        {
            frmElemento elemento = new frmElemento();
            elemento.ShowDialog();
        }


        private void btnModificar_Click(object sender, EventArgs e)
        {

            Pokemon seleccionado = (Pokemon)dgvPokemons.CurrentRow.DataBoundItem;




            frmPokemon modificar = new frmPokemon(seleccionado);
            modificar.ShowDialog();

            

        }//Cierra modificar

        private void btnEliminar_Click(object sender, EventArgs e)
        {
            Pokemon seleccionado = (Pokemon)dgvPokemons.CurrentRow.DataBoundItem;
            PokemonNegocio negocio = new PokemonNegocio();

            try
            {
                //este if tira el cartelito cuando vas eliminarlo
                if(MessageBox.Show("Estas seguro de eliminarlo?", "Eliminadoo", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                {
                    negocio.eliminar(seleccionado.Id);
                    cargarGrilla();
                }
                
            }
            catch (Exception ex)

            {

                MessageBox.Show(ex.Message);
            }



        }//Cierra eliminar

        private void btnBuscar_Click(object sender, EventArgs e)
        {


            busqueda();

        }


        //Evento en el txtFiltro
        //esto esta buenisimo por que en el buscar, mientras escribir se filtra enseguida
        private void txtFiltro_KeyUp(object sender, KeyEventArgs e)
        {
            busqueda();

        }


        private void busqueda()
        {

            //txtFiltro
            //filtro en memoria

            List<Pokemon> listaFiltrada;


            //si tiene algo cargado pokemones traigo el listado original (cuando apretamos el buscar vacio)
            //si no va a el else y en el buscador en txtFiltro, hace la busqueda de lo que escribimos

            if (txtFiltro.Text != "")//vacio
            {
                //filtro que pasa todo a mayuscula a la hora de buscar con el ToUpper
                //filtra tambien por nombre de pokemons y tambien por Tipo 

                listaFiltrada = listaPokemons.FindAll(PEPE => PEPE.Nombre.ToUpper().Contains(txtFiltro.Text.ToUpper()) || PEPE.Tipo.Nombre.ToUpper().Contains(txtFiltro.Text.ToUpper()));

                dgvPokemons.DataSource = null;
                dgvPokemons.DataSource = listaFiltrada;

            }
            else
            {
                dgvPokemons.DataSource = null;
                dgvPokemons.DataSource = listaPokemons;
            }

        }//Cierra busqueda




    }
}
