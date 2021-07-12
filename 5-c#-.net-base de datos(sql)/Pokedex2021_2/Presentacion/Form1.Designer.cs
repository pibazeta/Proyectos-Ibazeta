namespace Presentacion
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.txtFiltro = new System.Windows.Forms.TextBox();
            this.btnBuscar = new System.Windows.Forms.Button();
            this.btnAgregar = new System.Windows.Forms.Button();
            this.btnModificar = new System.Windows.Forms.Button();
            this.btnEliminar = new System.Windows.Forms.Button();
            this.btnDetalle = new System.Windows.Forms.Button();
            this.dgvPokemons = new System.Windows.Forms.DataGridView();
            this.pbxPokemon = new System.Windows.Forms.PictureBox();
            this.btnAgregarElemento = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvPokemons)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPokemon)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Filtro";
            // 
            // txtFiltro
            // 
            this.txtFiltro.Location = new System.Drawing.Point(104, 24);
            this.txtFiltro.Name = "txtFiltro";
            this.txtFiltro.Size = new System.Drawing.Size(183, 20);
            this.txtFiltro.TabIndex = 1;
            this.txtFiltro.KeyUp += new System.Windows.Forms.KeyEventHandler(this.txtFiltro_KeyUp);
            // 
            // btnBuscar
            // 
            this.btnBuscar.Location = new System.Drawing.Point(348, 16);
            this.btnBuscar.Name = "btnBuscar";
            this.btnBuscar.Size = new System.Drawing.Size(88, 34);
            this.btnBuscar.TabIndex = 2;
            this.btnBuscar.Text = "Buscar";
            this.btnBuscar.UseVisualStyleBackColor = true;
            this.btnBuscar.Click += new System.EventHandler(this.btnBuscar_Click);
            // 
            // btnAgregar
            // 
            this.btnAgregar.Location = new System.Drawing.Point(12, 253);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(75, 34);
            this.btnAgregar.TabIndex = 3;
            this.btnAgregar.Text = "Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
            // 
            // btnModificar
            // 
            this.btnModificar.Location = new System.Drawing.Point(104, 253);
            this.btnModificar.Name = "btnModificar";
            this.btnModificar.Size = new System.Drawing.Size(75, 34);
            this.btnModificar.TabIndex = 4;
            this.btnModificar.Text = "Modificar";
            this.btnModificar.UseVisualStyleBackColor = true;
            this.btnModificar.Click += new System.EventHandler(this.btnModificar_Click);
            // 
            // btnEliminar
            // 
            this.btnEliminar.Location = new System.Drawing.Point(212, 253);
            this.btnEliminar.Name = "btnEliminar";
            this.btnEliminar.Size = new System.Drawing.Size(75, 34);
            this.btnEliminar.TabIndex = 5;
            this.btnEliminar.Text = "Eliminar";
            this.btnEliminar.UseVisualStyleBackColor = true;
            this.btnEliminar.Click += new System.EventHandler(this.btnEliminar_Click);
            // 
            // btnDetalle
            // 
            this.btnDetalle.Location = new System.Drawing.Point(313, 253);
            this.btnDetalle.Name = "btnDetalle";
            this.btnDetalle.Size = new System.Drawing.Size(75, 34);
            this.btnDetalle.TabIndex = 6;
            this.btnDetalle.Text = "Detalle";
            this.btnDetalle.UseVisualStyleBackColor = true;
            // 
            // dgvPokemons
            // 
            this.dgvPokemons.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.ColumnHeader;
            this.dgvPokemons.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvPokemons.Location = new System.Drawing.Point(71, 76);
            this.dgvPokemons.Name = "dgvPokemons";
            this.dgvPokemons.Size = new System.Drawing.Size(317, 150);
            this.dgvPokemons.TabIndex = 7;
            this.dgvPokemons.MouseClick += new System.Windows.Forms.MouseEventHandler(this.dgvPokemons_MouseClick);
            // 
            // pbxPokemon
            // 
            this.pbxPokemon.Location = new System.Drawing.Point(517, 31);
            this.pbxPokemon.Name = "pbxPokemon";
            this.pbxPokemon.Size = new System.Drawing.Size(134, 195);
            this.pbxPokemon.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbxPokemon.TabIndex = 8;
            this.pbxPokemon.TabStop = false;
            this.pbxPokemon.Click += new System.EventHandler(this.pictureBox1_Click);
            this.pbxPokemon.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pbxPokemon_MouseClick);
            // 
            // btnAgregarElemento
            // 
            this.btnAgregarElemento.Location = new System.Drawing.Point(414, 253);
            this.btnAgregarElemento.Name = "btnAgregarElemento";
            this.btnAgregarElemento.Size = new System.Drawing.Size(101, 34);
            this.btnAgregarElemento.TabIndex = 9;
            this.btnAgregarElemento.Text = "Agregar Elemento";
            this.btnAgregarElemento.UseVisualStyleBackColor = true;
            this.btnAgregarElemento.Click += new System.EventHandler(this.btnAgregarElemento_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(679, 347);
            this.Controls.Add(this.btnAgregarElemento);
            this.Controls.Add(this.pbxPokemon);
            this.Controls.Add(this.dgvPokemons);
            this.Controls.Add(this.btnDetalle);
            this.Controls.Add(this.btnEliminar);
            this.Controls.Add(this.btnModificar);
            this.Controls.Add(this.btnAgregar);
            this.Controls.Add(this.btnBuscar);
            this.Controls.Add(this.txtFiltro);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Pokemon";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseClick);
            ((System.ComponentModel.ISupportInitialize)(this.dgvPokemons)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPokemon)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtFiltro;
        private System.Windows.Forms.Button btnBuscar;
        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.Button btnModificar;
        private System.Windows.Forms.Button btnEliminar;
        private System.Windows.Forms.Button btnDetalle;
        private System.Windows.Forms.DataGridView dgvPokemons;
        private System.Windows.Forms.PictureBox pbxPokemon;
        private System.Windows.Forms.Button btnAgregarElemento;
    }
}

