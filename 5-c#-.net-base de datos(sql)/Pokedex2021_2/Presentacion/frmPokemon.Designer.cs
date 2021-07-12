namespace Presentacion
{
    partial class frmPokemon
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.txtDescripcion = new System.Windows.Forms.TextBox();
            this.txtUrlImagen = new System.Windows.Forms.TextBox();
            this.cboTipo = new System.Windows.Forms.ComboBox();
            this.btnCancelar = new System.Windows.Forms.Button();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.pbxPokemon = new System.Windows.Forms.PictureBox();
            this.numNumero = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPokemon)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numNumero)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Nombre";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 90);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Numero";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 148);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Descripcion";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(24, 205);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(58, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Url Imagen";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(24, 255);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(28, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Tipo";
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(128, 27);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(120, 20);
            this.txtNombre.TabIndex = 5;
            // 
            // txtDescripcion
            // 
            this.txtDescripcion.Location = new System.Drawing.Point(128, 141);
            this.txtDescripcion.Name = "txtDescripcion";
            this.txtDescripcion.Size = new System.Drawing.Size(120, 20);
            this.txtDescripcion.TabIndex = 6;
            // 
            // txtUrlImagen
            // 
            this.txtUrlImagen.Location = new System.Drawing.Point(128, 205);
            this.txtUrlImagen.Name = "txtUrlImagen";
            this.txtUrlImagen.Size = new System.Drawing.Size(120, 20);
            this.txtUrlImagen.TabIndex = 7;
            this.txtUrlImagen.TextChanged += new System.EventHandler(this.txtUrlImagen_TextChanged);
            // 
            // cboTipo
            // 
            this.cboTipo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboTipo.FormattingEnabled = true;
            this.cboTipo.Location = new System.Drawing.Point(128, 255);
            this.cboTipo.Name = "cboTipo";
            this.cboTipo.Size = new System.Drawing.Size(127, 21);
            this.cboTipo.TabIndex = 8;
            // 
            // btnCancelar
            // 
            this.btnCancelar.Location = new System.Drawing.Point(229, 310);
            this.btnCancelar.Name = "btnCancelar";
            this.btnCancelar.Size = new System.Drawing.Size(75, 29);
            this.btnCancelar.TabIndex = 10;
            this.btnCancelar.Text = "Cancelar";
            this.btnCancelar.UseVisualStyleBackColor = true;
            this.btnCancelar.Click += new System.EventHandler(this.btnCancelar_Click);
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(46, 310);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(75, 29);
            this.btnAceptar.TabIndex = 11;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // pbxPokemon
            // 
            this.pbxPokemon.Location = new System.Drawing.Point(339, 53);
            this.pbxPokemon.Name = "pbxPokemon";
            this.pbxPokemon.Size = new System.Drawing.Size(133, 192);
            this.pbxPokemon.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbxPokemon.TabIndex = 12;
            this.pbxPokemon.TabStop = false;
            // 
            // numNumero
            // 
            this.numNumero.Location = new System.Drawing.Point(128, 83);
            this.numNumero.Name = "numNumero";
            this.numNumero.Size = new System.Drawing.Size(120, 20);
            this.numNumero.TabIndex = 13;
            // 
            // frmPokemon
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(494, 367);
            this.Controls.Add(this.numNumero);
            this.Controls.Add(this.pbxPokemon);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.btnCancelar);
            this.Controls.Add(this.cboTipo);
            this.Controls.Add(this.txtUrlImagen);
            this.Controls.Add(this.txtDescripcion);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "frmPokemon";
            this.Text = "Agregar Pokemon";
            this.Load += new System.EventHandler(this.frmPokemon_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pbxPokemon)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numNumero)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.TextBox txtDescripcion;
        private System.Windows.Forms.TextBox txtUrlImagen;
        private System.Windows.Forms.ComboBox cboTipo;
        private System.Windows.Forms.Button btnCancelar;
        private System.Windows.Forms.Button btnAceptar;
        private System.Windows.Forms.PictureBox pbxPokemon;
        private System.Windows.Forms.NumericUpDown numNumero;
    }
}