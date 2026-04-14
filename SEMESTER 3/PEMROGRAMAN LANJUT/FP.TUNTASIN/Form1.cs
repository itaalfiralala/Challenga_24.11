using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FP.TUNTASIN
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // Tombol Masuk/Login
        private void btnMasuk_Click(object sender, EventArgs e)
        {
            if (txtEmail.Text == "admin@mail.com" && txtPassword.Text == "12345")
            {
                MessageBox.Show("Login Berhasil!");
            }
            else
            {
                MessageBox.Show("Email atau Password salah!");
            }
        }

        // Tombol untuk pindah ke Form Daftar
        private void btnDaftar_Click(object sender, EventArgs e)
        {
            // Memanggil FormDaftar
            FormDaftar halamanDaftar = new FormDaftar();
            halamanDaftar.Show();
            this.Hide(); // Menyembunyikan Login
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
