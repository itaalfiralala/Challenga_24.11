#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

// ==== STRUCT ====
struct Pelanggan {
    string nama;
    string domisili;
    string noTelp;
};

struct Barang {
    string namaPenitip;
    string namaBarang;
    int harga;
    int jumlahBarang;
    int totalHarga;
    string kategori;
    Barang* next;
};

struct Kategori {
    string namaKategori;
    Barang* head;
    Kategori* next;
};

const int MAX_PELANGGAN = 100;
Pelanggan daftarPelanggan[MAX_PELANGGAN];
int jumlahPelanggan = 0;

const int MAX_QUEUE = 100;
Barang queueBarang[MAX_QUEUE];
int front = 0, rear = 0;

Kategori* daftarKategori = NULL;

void updateFileTXT();

bool isQueueEmpty() { return front == rear; }
bool isQueueFull() { return rear == MAX_QUEUE; }

void enqueue(Barang b) {
    if (!isQueueFull()) queueBarang[rear++] = b;
    else cout << "Antrian penuh!\n";
}

Barang dequeue() {
    if (!isQueueEmpty()) return queueBarang[front++];
    else {
        cout << "Antrian kosong!\n";
        Barang kosong; kosong.namaPenitip = "";
        return kosong;
    }
}

Kategori* cariKategori(string nama) {
    Kategori* temp = daftarKategori;
    while (temp != NULL) {
        if (temp->namaKategori == nama) return temp;
        temp = temp->next;
    }
    return NULL;
}

void tambahKategori(string nama) {
    if (cariKategori(nama) == NULL) {
        Kategori* baru = new Kategori{ nama, NULL, daftarKategori };
        daftarKategori = baru;
    }
}

void simpanKeKategori(Barang barang) {
    tambahKategori(barang.kategori);
    Kategori* kategori = cariKategori(barang.kategori);
    Barang* baru = new Barang(barang);
    baru->next = kategori->head;
    kategori->head = baru;
}

void tambahPelanggan(string nama, string domisili, string noTelp) {
    if (jumlahPelanggan < MAX_PELANGGAN) {
        daftarPelanggan[jumlahPelanggan++] = { nama, domisili, noTelp };
    }
}

void tambahTitipan() {
    system("cls");
    string nama, domisili, noTelp, namaBarang, kategori;
    int harga, jumlahBarang;

    cin.ignore();
    cout << "========== MASUKAN DATA PELANGGAN ==========\n";
    cout << "Nama Penitip       : "; getline(cin, nama);
    cout << "Domisili           : "; getline(cin, domisili);
    cout << "Nomor Telepon      : "; getline(cin, noTelp);
    cout << "Nama Barang        : "; getline(cin, namaBarang);
    cout << "Jumlah Barang      : "; cin >> jumlahBarang;
    cout << "Harga  Barang      : "; cin >> harga; cin.ignore();
    int totalHarga = harga * jumlahBarang;
    cout << "Total Harga        : " << totalHarga << endl;
    bool kategoriValid = false;
    do {
        cout << "Kategori (pakaian/makanan/minuman/elektronik): ";
        getline(cin, kategori);
        if (kategori == "pakaian" || kategori == "makanan" || kategori == "minuman" || kategori == "elektronik") kategoriValid = true;
        else cout << "Kategori tidak valid!\n";
    } while (!kategoriValid);

    Barang barang = { nama, namaBarang, harga, jumlahBarang, totalHarga, kategori, NULL };
    tambahPelanggan(nama, domisili, noTelp);
    enqueue(barang);
    simpanKeKategori(barang);
    updateFileTXT();
    cout << "\nBarang berhasil ditambahkan ke antrian.\n";
    system("pause");
}

void tampilkanSemuaKategori() {
    system("cls");
    Kategori* kategori = daftarKategori;
    while (kategori != NULL) {
        cout << "\nKategori: " << kategori->namaKategori << endl;
        cout << "+----------------------+--------+------------+--------------+----------------------+\n";
        cout << "| Nama Barang          | Jumlah |   Harga    | Total Harga  | Nama Penitip         |\n";
        cout << "+----------------------+--------+------------+--------------+----------------------+\n";
        Barang* barang = kategori->head;
        while (barang != NULL) {
            printf("| %-20s | %6d | Rp%-8d | Rp%-10d | %-20s |\n",
                barang->namaBarang.c_str(), barang->jumlahBarang, barang->harga,
                barang->totalHarga, barang->namaPenitip.c_str());
            barang = barang->next;
        }
        cout << "+----------------------+--------+------------+--------------+----------------------+\n";
        kategori = kategori->next;
    }
    system("pause");
}

void sortingHarga() {
    Barang semuaBarang[100];
    int jumlah = 0;
    for (Kategori* kategori = daftarKategori; kategori != NULL; kategori = kategori->next)
        for (Barang* barang = kategori->head; barang != NULL; barang = barang->next)
            semuaBarang[jumlah++] = *barang;

    for (int i = 0; i < jumlah - 1; i++)
        for (int j = 0; j < jumlah - i - 1; j++)
            if (semuaBarang[j].harga > semuaBarang[j + 1].harga)
                swap(semuaBarang[j], semuaBarang[j + 1]);

    cout << "\nBarang setelah diurutkan berdasarkan harga:\n";
    cout << "+----------------------+------------+----------------------+--------------+\n";
    cout << "| Nama Barang          | Harga      | Nama Penitip         | Kategori     |\n";
    cout << "+----------------------+------------+----------------------+--------------+\n";
    for (int i = 0; i < jumlah; i++)
        printf("| %-20s | Rp%-8d | %-20s | %-12s |\n",
            semuaBarang[i].namaBarang.c_str(), semuaBarang[i].harga,
            semuaBarang[i].namaPenitip.c_str(), semuaBarang[i].kategori.c_str());
    cout << "+----------------------+------------+----------------------+--------------+\n";
    system("pause");
}

void cariPelanggan() {
    system("cls");
    cin.ignore();
    string cari;
    cout << "Masukkan nama pelanggan yang dicari: "; getline(cin, cari);
    bool ketemu = false;
    for (int i = 0; i < jumlahPelanggan; i++) {
        if (daftarPelanggan[i].nama == cari) {
            ketemu = true;
            cout << "\nDitemukan:\n";
            cout << "Nama: " << daftarPelanggan[i].nama
                << "\nDomisili: " << daftarPelanggan[i].domisili
                << "\nNomor Telepon: " << daftarPelanggan[i].noTelp << endl;
        }
    }
    if (!ketemu) cout << "Pelanggan tidak ditemukan.\n";
    system("pause");
}

void hapusPelanggan() {
    system("cls");
    cin.ignore();
    string nama;
    cout << "Masukkan nama pelanggan yang ingin dihapus : "; getline(cin, nama);

    char konfirmasi;
    cout << "Apakah Anda yakin ingin menghapus pelanggan '" << nama << "' beserta semua titipannya? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi != 'y' && konfirmasi != 'Y') {
        cout << "Penghapusan dibatalkan.\n";
        system("pause");
        return;
    }

    bool ketemu = false;
    for (int i = 0; i < jumlahPelanggan; i++) {
        if (daftarPelanggan[i].nama == nama) {
            ketemu = true;
            for (int j = i; j < jumlahPelanggan - 1; j++)
                daftarPelanggan[j] = daftarPelanggan[j + 1];
            jumlahPelanggan--;

            for (Kategori* kategori = daftarKategori; kategori != NULL; kategori = kategori->next) {
                Barang* prev = NULL;
                Barang* barang = kategori->head;
                while (barang != NULL) {
                    if (barang->namaPenitip == nama) {
                        cout << "\n[Data yang dihapus:]\n";
                        cout << "Kategori: " << kategori->namaKategori
                            << ", Nama Barang: " << barang->namaBarang
                            << ", Jumlah: " << barang->jumlahBarang
                            << ", Harga: Rp" << barang->harga
                            << ", Total: Rp" << barang->totalHarga
                            << ", Penitip: " << barang->namaPenitip << endl;

                        if (prev == NULL) kategori->head = barang->next;
                        else prev->next = barang->next;
                        delete barang;
                        break;
                    }
                    prev = barang;
                    barang = barang->next;
                }
            }

            updateFileTXT();
            cout << "Pelanggan dan semua titipannya berhasil dihapus.\n";
            break;
        }
    }
    if (!ketemu) cout << "Pelanggan tidak ditemukan.\n";
    system("pause");
}

void editBarang() {
    system("cls");
    cin.ignore();
    string namaPenitip, namaBarang;
    cout << "Masukkan nama penitip: "; getline(cin, namaPenitip);
    cout << "Masukkan nama barang : "; getline(cin, namaBarang);
    bool ketemu = false;
    for (Kategori* kategori = daftarKategori; kategori != NULL; kategori = kategori->next)
        for (Barang* barang = kategori->head; barang != NULL; barang = barang->next)
            if (barang->namaPenitip == namaPenitip && barang->namaBarang == namaBarang) {
                ketemu = true;
                cout << "Barang ditemukan.\n";
                cout << "Nama: " << barang->namaBarang << ", Harga: Rp" << barang->harga
                    << ", Jumlah: " << barang->jumlahBarang << ", Total: Rp" << barang->totalHarga << endl;
                cout << "Masukkan nama barang baru     : "; getline(cin, barang->namaBarang);
                cout << "Masukkan jumlah barang baru   : "; cin >> barang->jumlahBarang;
                cout << "Masukkan harga  barang baru   : "; cin >> barang->harga; cin.ignore();
                barang->totalHarga = barang->harga * barang->jumlahBarang;
                cout << "Barang berhasil diperbarui!\n";
                updateFileTXT();
                system("pause");
                return;
            }
    if (!ketemu) cout << "Barang tidak ditemukan.\n";
    system("pause");
}

void updateFileTXT() {
    ofstream file("data_jasa_titip.txt");
    for (int i = 0; i < jumlahPelanggan; i++) {
        string namaPelanggan = daftarPelanggan[i].nama;
        string domisili = daftarPelanggan[i].domisili;
        string noTelp = daftarPelanggan[i].noTelp;
        for (Kategori* kategori = daftarKategori; kategori != NULL; kategori = kategori->next)
            for (Barang* barang = kategori->head; barang != NULL; barang = barang->next)
                if (barang->namaPenitip == namaPelanggan)
                    file << "Kategori: " << kategori->namaKategori
                    << ", Nama Barang: " << barang->namaBarang
                    << ", Jumlah: " << barang->jumlahBarang
                    << ", Harga: Rp" << barang->harga
                    << ", Total: Rp" << barang->totalHarga
                    << ", Penitip: " << barang->namaPenitip
                    << ", Domisili: " << domisili
                    << ", No. Telp: " << noTelp << "\n";
    }
    file.close();
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== SISTEM JASA TITIP BELI BARANG ONLINE ===\n";
        cout << "1. Tambah Titipan\n";
        cout << "2. Tampilkan Semua Barang\n";
        cout << "3. Urutkan Barang Berdasarkan Harga\n";
        cout << "4. Cari Data Pelanggan\n";
        cout << "5. Hapus Pelanggan\n";
        cout << "6. Edit Data Barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
        case 1: tambahTitipan(); break;
        case 2: tampilkanSemuaKategori(); break;
        case 3: sortingHarga(); break;
        case 4: cariPelanggan(); break;
        case 5: hapusPelanggan(); break;
        case 6: editBarang(); break;
        case 0: cout << "Terima kasih program selesai.\n"; break;
        default: cout << "Pilihan tidak valid.\n"; system("pause"); break;
        }
    } while (pilihan != 0);
    return 0;
}