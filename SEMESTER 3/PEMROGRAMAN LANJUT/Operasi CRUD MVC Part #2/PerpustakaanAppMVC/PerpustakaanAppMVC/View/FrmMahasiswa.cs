using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PerpustakaanAppMVC.Model.Entity;
using PerpustakaanAppMVC.Controller;

namespace PerpustakaanAppMVC.View
{
    public partial class FrmMahasiswa : Form
    {
        private List<Mahasiswa> list0fMahasiswa = new List<Mahasiswa>();

        
        private MahasiswaController controller;
        private List<Mahasiswa> listOfMahasiswa;
        private object lvmMahasiswa;

        private void Form1_Load(object sender, EventArgs e)
        {
            InitializeComponent();

            controller = new MahasiswaController();

            InisialisasiListView();
            LoadDataMahasiswa();
        }


        // method untuk menampilkan semua data mahasiswa 
        private void LoadDataMahasiswa()
        {
            // kosongkan listview
            lvmMahasiswa.Items.Clear();

            // ambil data dari controller
            List<Mahasiswa> listOfMahasiswa = controller.ReadAll();

            int noUrut = 1;

            foreach (var mhs in listOfMahasiswa)
            {
                ListViewItem item = new ListViewItem(noUrut.ToString());
                item.SubItems.Add(mhs.Npm);
                item.SubItems.Add(mhs.Nama);
                item.SubItems.Add(mhs.Angkatan);

                lvmMahasiswa.Items.Add(item);
                noUrut++;
            }
        }


        private void InisialisasiListView()
        {
            lvmMahasiswa.View = View.Details;
            lvmMahasiswa.FullRowSelect = true;
            lvmMahasiswa.GridLines = true;

            lvmMahasiswa.Columns.Clear();
            lvmMahasiswa.Columns.Add("No.", 40, HorizontalAlignment.Center);
            lvmMahasiswa.Columns.Add("NPM", 100, HorizontalAlignment.Center);
            lvmMahasiswa.Columns.Add("Nama", 200, HorizontalAlignment.Left);
            lvmMahasiswa.Columns.Add("Angkatan", 90, HorizontalAlignment.Center);
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
