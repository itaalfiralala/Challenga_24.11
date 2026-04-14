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
    public partial class FormDaftar : Form
    {
        public FormDaftar()
        {
            InitializeComponent();
        }
        private void txtDaftar_Click(object sender, EventArgs e)
        {

            string namaInput = txtNama.Text;
            string emailInput = txtEmail.Text;
            string passwordInput = txtPassword.Text;

            // 2. Ambil data yang sudah tersimpan sebelumnya di memori
            string emailTersimpan = Properties.Settings.Default.SavedEmail;

            //memastikan semua kolom diisi

            if (string.IsNullOrWhiteSpace(txtNama.Text) ||
            string.IsNullOrWhiteSpace(txtTTL.Text) ||
            string.IsNullOrWhiteSpace(txtNoTelp.Text) ||
            string.IsNullOrWhiteSpace(txtEmail.Text) ||
            string.IsNullOrWhiteSpace(txtPassword.Text))
            {
                MessageBox.Show("Semua data harus diisi lengkap!");
                return;
            }

            //cek duplikat email
            if (emailInput == emailTersimpan)
            {
                MessageBox.Show("Email ini sudah terdaftar! Silakan gunakan email lain atau langsung Login.",
                                "Pendaftaran Gagal", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {

                // 2. Simpan SEMUA data ke Settings
                Properties.Settings.Default.SavedNama = txtNama.Text;
                Properties.Settings.Default.SavedTTL = txtTTL.Text;
                Properties.Settings.Default.SavedNomorTelepon = txtNoTelp.Text;
                Properties.Settings.Default.SavedEmail = txtEmail.Text;
                Properties.Settings.Default.SavedPassword = txtPassword.Text;

                Properties.Settings.Default.Save();

                // 2. Beri tahu user bahwa pendaftaran sukses
                MessageBox.Show("Akun berhasil dibuat! Silakan masuk.");

                // 3. Pindah ke halaman login
                FormMasuk masuk = new FormMasuk();
                masuk.Show();
                this.Close();

                Properties.Settings.Default.NamaUser = txtNama.Text;
                Properties.Settings.Default.Save();

            }
        }
        private void FormDaftar_Load(object sender, EventArgs e)
        {
          
        }
    }
}
