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
        public partial class FormDaftar : Form
        {
            public FormDaftar()
            {
                InitializeComponent();
            }

            // Tombol Proses Daftar (Kuning)
            private void btnProsesDaftar_Click(object sender, EventArgs e)
            {
                MessageBox.Show("Akun berhasil dibuat!");
                KembaliKeLogin();
            }

            // Tombol Masuk (Krem - Kembali ke Login)
            private void btnKembaliLogin_Click(object sender, EventArgs e)
            {
                KembaliKeLogin();
            }

            private void KembaliKeLogin()
            {
                // Memanggil Form1 (Halaman Login)
                Form1 halamanLogin = new Form1();
                halamanLogin.Show();
                this.Hide(); // Menyembunyikan Daftar
            }

        private void FormDaftar_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
    }



