using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace fp_tuntasin
{
    public partial class FormMasuk : Form
    {
        public FormMasuk()
        {
            InitializeComponent();
        }

        private void btnDaftar_Click(object sender, EventArgs e)
        {
            // Membuka FormDaftar
            FormDaftar formDaftar = new FormDaftar();
            formDaftar.Show();
            this.Hide();
        }

        private void btnMasuk_Click(object sender, EventArgs e)
        {
            // Ambil data yang tersimpan di Settings
            string emailTerdaftar = Properties.Settings.Default.SavedEmail;
            string passTerdaftar = Properties.Settings.Default.SavedPassword;
             
            // Cek apakah TextBox Email & Password sama dengan data yang disimpan
            if (txtEmail.Text == emailTerdaftar && txtPassword.Text == passTerdaftar)
            {
                MessageBox.Show(" Selamat Datang ! ");
                FormBeranda beranda = new FormBeranda();
                beranda.Show();
                this.Hide();
            }
            else
            {
                // Tips: Tampilkan data yang tersimpan di MessageBox untuk tes/debugging
                MessageBox.Show("Gagal! Email terdaftar: " + emailTerdaftar);
            }
        }

        private void FormMasuk_Load(object sender, EventArgs e)
        {

        }
    }
}

