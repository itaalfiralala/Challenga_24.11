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
    public partial class FormBeranda : Form
    {
        public string NamaUser;

        public FormBeranda()
        {
            InitializeComponent();
        }

        private void FormBeranda_Load(object sender, EventArgs e)
        {
            txtNamaPengguna.Text = string.IsNullOrEmpty(
                Properties.Settings.Default.SavedNama)
                ? "Pengguna"
                : Properties.Settings.Default.SavedNama;

            TampilkanKonten("Beranda");
        }


        // --- FUNGSI NAVIGASI PANEL ---
        private void TampilkanPanelTerbaru()
        {
            pnlPostTerbaru.Visible = true;
            pnlKategoriIcon.Visible = false;
            pnlPostTerbaru.BringToFront();

            // Menggunakan Color.Gold agar lebih mewah seperti desain Anda
            txtTerbaru.ForeColor = Color.Gold;
            txtKategori.ForeColor = Color.White;
        }

        private void TampilkanPanelKategori()
        {
            pnlKategoriIcon.Visible = true;
            pnlPostTerbaru.Visible = false;
            pnlKategoriIcon.BringToFront();

            txtKategori.ForeColor = Color.Gold;
            txtTerbaru.ForeColor = Color.White;
        }

        // --- EVENT HANDLERS ---

        private void txtTerbaru_Click(object sender, EventArgs e)
        {
            TampilkanPanelTerbaru();
        }

        private void txtKategori_Click(object sender, EventArgs e)
        {
            TampilkanPanelKategori();
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtSearch.Text))
            {
                // Paksa pindah ke tampilan kategori agar GridView bisa terlihat
                TampilkanPanelKategori();

                // TODO: Tambahkan logika pencarian data di sini
            }
        }

        private void txtSearch_TextChanged(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtSearch.Text))
            {
                TampilkanPanelTerbaru();
            }
            else
            {
                // Pindah ke mode kategori untuk mencari ikon
                pnlPostTerbaru.Visible = false;
                pnlKategoriIcon.Visible = true;
                pnlKategoriIcon.BringToFront();

                txtKategori.ForeColor = Color.Gold;
                txtTerbaru.ForeColor = Color.White;

                string kataKunci = txtSearch.Text.ToLower();
                foreach (Control ikon in pnlKategoriIcon.Controls)
                {
                    // Pastikan kita mengecek teks pada label di dalam ikon
                    ikon.Visible = ikon.Name.ToLower().Contains(kataKunci) || ikon.Text.ToLower().Contains(kataKunci);
                }
            }
        }

        private void label21_Click(object sender, EventArgs e)
        {

        }

        // Buat fungsi ini untuk mengatur perpindahan sub-menu Beranda
        private void AktifkanSubMenu(string mode)
        {
            // Tulisan harus selalu kelihatan
            txtTerbaru.Visible = true;
            txtKategori.Visible = true;

            if (mode == "Terbaru")
            {
                txtTerbaru.ForeColor = Color.Gold;
                txtKategori.ForeColor = Color.White;
                pnlPostTerbaru.Visible = true;        
                pnlKategoriIcon.Visible = false; 
            }
            else
            {
                txtTerbaru.ForeColor = Color.White;
                txtKategori.ForeColor = Color.Gold;
                pnlPostTerbaru.Visible = false;
                pnlKategoriIcon.Visible = true;
            }
        }

        // --- NAVIGASI SIDEBAR ---
        private void SembunyikanSemuaKonten()
        {
            // Masukkan semua nama panel konten Anda di sini
            pnlPostTerbaru.Visible = false;
            pnlKategoriIcon.Visible = false;
            pnlLaporan.Visible = false;    
            pnlNotifikasi.Visible = false;
        }

        private void btnMenuLaporan_Click(object sender, EventArgs e)
        {
            SembunyikanSemuaKonten();
            pnlLaporan.Visible = true;
            pnlLaporan.BringToFront();
        }

        private void btnMenuNotifikasi_Click(object sender, EventArgs e)
        {
            SembunyikanSemuaKonten();
            pnlNotifikasi.Visible = true;
            pnlNotifikasi.BringToFront();
        }

        private void txtNamaPengguna_Click(object sender, EventArgs e)
        {
           
        }

        private void pnlTuntasin_Paint(object sender, PaintEventArgs e)
        {
            int koordinatX = (pnlTuntasin.Width / 2) - (txtNamaPengguna.Width / 2);
            txtNamaPengguna.Location = new Point(koordinatX, txtNamaPengguna.Location.Y);
        }

        //--- MENU PANEL TUNTASIN ---
        private void TampilkanKonten(string halaman)
        {
            // SEMBUNYIKAN SEMUA PANEL KONTEN
            pnlPostTerbaru.Visible = false;
            pnlKategoriIcon.Visible = false;
            pnlNotifikasi.Visible = false;
            pnlTandaiDibaca.Visible = false;
            pnlViralUpdate.Visible = false;
            pnlLaporan.Visible = false;

            // RESET WARNA LABEL
            lblBeranda.ForeColor = Color.White;
            lblNotifikasi.ForeColor = Color.White;
            lblBuatLaporan.ForeColor = Color.White;

            // PILIH HALAMAN
            switch (halaman)
            {
                case "Beranda":
                    pnlSearch.Visible = true;
                    pnlPostTerbaru.Visible = true;
                    pnlSearch.BringToFront();
                    pnlPostTerbaru.BringToFront();
                    lblBeranda.ForeColor = Color.Gold;

                    txtTerbaru.ForeColor = Color.Gold;
                    txtKategori.ForeColor = Color.White;
                    break;

                case "Notifikasi":
                    pnlNotifikasi.Visible = true;
                    pnlTandaiDibaca.Visible = true;
                    pnlViralUpdate.Visible = true;

                    pnlNotifikasi.BringToFront();
                    pnlTandaiDibaca.BringToFront();
                    pnlViralUpdate.BringToFront();

                    lblNotifikasi.ForeColor = Color.Gold;
                    break;

                case "Laporan":
                    pnlLaporan.Visible = true;
                    pnlPostinganPelapor.Visible = true;
                    pnlPostinganPelapor.BringToFront();
                    pnlLaporan.BringToFront();
                    lblBuatLaporan.ForeColor = Color.Gold;
                    break;
            }
        }

        private void lblNotifikasi_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Notifikasi");
        }

        private void lblBuatLaporan_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Laporan");
        }

        private void lblBeranda_Click(object sender, EventArgs e)
        {
            txtSearch.Clear();
            TampilkanKonten("Beranda");
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {

        }

        private void pnlPostTerbaru_Paint(object sender, PaintEventArgs e)
        {

        }

        private void pnlInfoDasar_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}