using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
using System.Data.SQLite;
using PerpustakaanAppMVC.Model.Entity;
using System.Security.Policy;

namespace PerpustakaanAppMVC.Model.Context
{

    public class DbContext : IDisposable
    {
        // deklarasi private variabel / field 
        private SQLiteConnection _conn;

        // deklarasi property Conn (connection), untuk menyimpan objek koneksi 
        public SQLiteConnection Conn
        {
            get { return _conn ?? (_conn = GetOpenConnection()); }
        }

        // Method untuk melakukan koneksi ke database 
        private SQLiteConnection GetOpenConnection()
        {
            SQLiteConnection conn = null; // deklarasi objek connection 

            try // penggunaan blok try-catch untuk penanganan error 
            {
                // atur ulang lokasi database yang disesuaikan dengan 
                // lokasi database perpustakaan Anda 
                string dbName = @"D:\Database\DbPerpustakaan.db";

            // deklarasi variabel connectionString, ref: 
            https://www.connectionstrings.com/ 
                string connectionString = string.Format("Data Source  ; FailIfMissing = True", dbName);


                conn = new SQLiteConnection(connectionString); // buat objek connection
                conn.Open(); // buka koneksi ke database 
            }
            // jika terjadi error di blok try, akan ditangani langsung oleh blok  catch
            catch (Exception ex)
            {
                System.Diagnostics.Debug.Print("Open Connection Error: {0}",
    ex.Message);
            }

            return conn;
        }

        // Method ini digunakan untuk menghapus objek koneksi dari memory sudah tidak digunakan
        public void Dispose()
        {
            if (_conn != null)
            {
                try
                {
                    if (_conn.State != ConnectionState.Closed) _conn.Close();
                }
                finally
                {
                    _conn.Dispose();
                }
            }

            GC.SuppressFinalize(this);
     
        public List<Mahasiswa> ReadByNama(string nama)
        {
            // membuat objek collection untuk menampung objek mahasiswa 
            List<Mahasiswa> list = new List<Mahasiswa>();

            try
            {
                // deklarasi perintah SQL 
                string sql = @"select npm, nama, angkatan  
                        from mahasiswa  
                        where nama like @nama 
                        order by nama";

                // membuat objek command menggunakan blok using 
                using (SQLiteCommand cmd = new SQLiteCommand(sql, _conn))
                {
                    // mendaftarkan parameter dan mengeset nilainya 
                    cmd.Parameters.AddWithValue("@nama", string.Format("%{0}%",
        nama));

                    // membuat objek dtr (data reader) untuk menampung result (hasil perintah SELECT) 
                    using (SQLiteDataReader dtr = cmd.ExecuteReader())
                    {
                        // panggil method Read untuk mendapatkan baris dari reset
                        while (dtr.Read())
                        {
                            // proses konversi dari row result set ke object 
                            Mahasiswa mhs = new Mahasiswa();
                            mhs.Npm = dtr["npm"].ToString();
                            mhs.Nama = dtr["nama"].ToString();
                            mhs.Angkatan = dtr["angkatan"].ToString();

                            // tambahkan objek mahasiswa ke dalam collection 
                            list.Add(mhs);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.Print("ReadByNama error: {0}",
        ex.Message);
            }

            return list;
        }
    }
}

