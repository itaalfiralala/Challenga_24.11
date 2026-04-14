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

        //menyimpan semua laporan yang masuk
        public List<LaporanModel> DaftarLaporan = new List<LaporanModel>();
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
        public class LaporanModel
        {
            public string Judul { get; set; }
            public string Kategori { get; set; }
            public string Lokasi { get; set; }
            public string Kronologi { get; set; }
            public DateTime Waktu { get; set; }
        }


        // --- NAVIGASI PANEL ---
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
            // Pastikan panel kategori aktif saat search dipakai
            pnlPostTerbaru.Visible = false;
            pnlKategoriIcon.Visible = true;
            pnlKategoriIcon.BringToFront();

            txtKategori.ForeColor = Color.Gold;
            txtTerbaru.ForeColor = Color.White;

            string kataKunci = txtSearch.Text.ToLower();

            foreach (Control ikon in pnlKategoriIcon.Controls)
            {
                // Jika search kosong → tampilkan SEMUA ikon
                if (string.IsNullOrWhiteSpace(kataKunci))
                {
                    ikon.Visible = true;
                }
                else
                {
                    ikon.Visible =
                        ikon.Name.ToLower().Contains(kataKunci) ||
                        ikon.Text.ToLower().Contains(kataKunci);
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

            pnlKecelakaan.Visible = false;
            pnlKriminalitas.Visible = false;
            pnlPembulian.Visible = false;
            pnlPelecehan.Visible = false;

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

                // pilihan kategori
                case "Kecelakaan":
                    pnlKecelakaan.Visible = true;
                    pnlKecelakaan.BringToFront();
                    break;

                case "Kriminalitas":
                    pnlKriminalitas.Visible = true;
                    pnlKriminalitas.BringToFront();
                    break;

                case "Pembulian":
                    pnlPembulian.Visible = true;
                    pnlPembulian.BringToFront();
                    break;

                case "Pelecehan":
                    pnlPelecehan.Visible = true;
                    pnlPelecehan.BringToFront();
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
        private void UpdateTampilanBeranda()
        {
            // Cek jika ada laporan
            if (DaftarLaporan.Count > 0)
            {
                // Ambil laporan terakhir yang dikirim
                var laporanTerbaru = DaftarLaporan[DaftarLaporan.Count - 1];

                // label di pnlPostTerbaru bernama 'lblJudulPost' dan 'lblLokasiPost'
                // lblJudulPost.Text = laporanTerbaru.Judul;
                // lblLokasiPost.Text = laporanTerbaru.Lokasi;

                // Catatan: perlu menyesuaikan nama Label yang ada di desain pnlPostTerbaru
            }
        }

        private void pnlInfoDasar_Paint(object sender, PaintEventArgs e)
        {

        }

        private void picKecelakaan_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Kecelakaan");
        }

        private void picKriminalitas_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Kriminalitas");
        }

        private void picPembulian_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Pembulian");
        }

        private void picPelecehan_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Pelecehan");
        }

        private void btnKecelakaan_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Kecelakaan");
        }

        private void btnKriminalitas_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Kriminalitas");
        }

        private void btnPembulian_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Pembulian");
        }

        private void btnPelecehan_Click(object sender, EventArgs e)
        {
            TampilkanKonten("Pelecehan");
        }

        //POSTINGAN PELAPOR
        private void btnKirim_Click(object sender, EventArgs e)
        {
            // 1. Ambil data dari inputan pengguna
            string judul = txtJudul.Text;
            string kategori = cbKategori.SelectedItem?.ToString(); // Mengambil pilihan dari ComboBox
            string lokasi = txtLokasi.Text;
            string kronologi = txtKronologi.Text;
            string kategoriTerpilih = cbKategori.SelectedItem.ToString();

            if (string.IsNullOrWhiteSpace(txtJudul.Text) || string.IsNullOrWhiteSpace(txtLokasi.Text))
            {
                MessageBox.Show("Judul dan Lokasi wajib diisi!");
                return;
            }

            // masukkan data ke dalam model
            LaporanModel laporanBaru = new LaporanModel
            {
                Judul = txtJudul.Text,
                Kategori = cbKategori.SelectedItem?.ToString() ?? "Umum",
                Lokasi = txtLokasi.Text,
                Kronologi = txtKronologi.Text,
                Waktu = DateTime.Now
            };

            // simpan ke database list
            DaftarLaporan.Add(laporanBaru);

            // beri notifikasi
            MessageBox.Show("Laporan Anda telah berhasil terkirim dan akan muncul di Beranda.", "Berhasil");

            // 4. Bersihkan form dan pindah ke Beranda
            BersihkanFormLaporan();
            TampilkanKonten("Beranda");

            // Panggil fungsi untuk refresh tampilan di panel Terbaru
            UpdateTampilanBeranda();
        }

        private void BersihkanFormLaporan()
        {
            txtJudul.Clear();
            txtLokasi.Clear();
            txtKronologi.Clear();
            if (cbKategori.Items.Count > 0) cbKategori.SelectedIndex = 0;
        }

        private void btnUnggah_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                {
                    // Membatasi hanya file gambar yang bisa dipilih
                    ofd.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";
                    ofd.Title = "Pilih Bukti Foto Laporan";

                    if (ofd.ShowDialog() == DialogResult.OK)
                    {
                        // 2. Memasukkan file yang dipilih ke dalam PictureBox
                        // Kita gunakan Image.FromFile untuk mengambil file dari folder komputer
                        picPreview1.Image = Image.FromFile(ofd.FileName);

                        MessageBox.Show("Foto berhasil diunggah: " + ofd.SafeFileName);
                    }
                }
            }
        }
        
        private void btnUnggah2_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog ofd = new OpenFileDialog())
            {
                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    picPreview2.Image = Image.FromFile(ofd.FileName); // Masuk ke kotak 2
                }           
            }
        }
    }
}