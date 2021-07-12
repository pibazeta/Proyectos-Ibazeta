﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dominio
{
    public class Elemento
    {
        public int Id { get; set; }
        public string Nombre { get; set; }



        public Elemento (string nombre)
        {

            Nombre= nombre ;
        }

        public Elemento(int id ,string nombre)
        {

            Id = id;
            Nombre = nombre;
        }




        public override string ToString()
        {
            return Nombre;
        }



    }
}
