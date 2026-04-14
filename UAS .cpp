#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h> // untuk mengatur warna teks

using namespace std;

// Fungsi untuk mengatur warna teks
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Struct untuk menyimpan data barang
struct Barang {
    string id;
    string namaPenitip;
    string domisili;
    string namaBarang;
    int harga;
    string kategori;
    string status;
    Barang* next;
};

// Pointer head & tail untuk linked list + antrian
Barang* head = NULL;
Barang* tail = NULL;
int jumlahTitipan = 0;

// Fungsi untuk membuat ID barang otomatis
string buatID() {
    string prefix = "BRG";
    int urutan = jumlahTitipan + 1;
    string id = prefix + (urutan < 10 ? "00" : (urutan < 100 ? "0" : "")) + to_string(urutan);
    return id;
}

// Tambah barang baru ke antrian (linked list)
void tambahBarang() {
    system("cls");
    Barang* baru = new Barang;
    baru->id = buatID();
    cout << "======Masukkan Data Pelanggan======\n";
    cout << " Nama Penitip      : ";
    getline(cin, baru->namaPenitip);
    cout << " Domisili          : ";
    getline(cin, baru->domisili);
    cout << " Nama Barang       : ";
    getline(cin, baru->namaBarang);
    cout << " Harga Barang      : ";
    cin >> baru->harga;
    cin.ignore();
    cout << " Kategori Barang   : ";
    getline(cin, baru->kategori);
    baru->status = "Belum Dibeli";
    baru->next = NULL;

    if (head == NULL) {
        head = tail = baru;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
    jumlahTitipan++;
    cout << "\nBarang berhasil ditambahkan ke antrian!\n";
    system("pause");
}

// Tampilkan semua barang titipan
void tampilkanBarang() {
    system("cls");
    if (head == NULL) {
        cout << "Belum ada titipan barang.\n";
    }
    else {
        Barang* bantu = head;
        cout << "Daftar Barang Titipan:\n";
        while (bantu != NULL) {
            cout << "----------------------------------\n";
            cout << "ID Barang     : " << bantu->id << endl;
            cout << "Nama Penitip  : " << bantu->namaPenitip << endl;
            cout << "Domisili      : " << bantu->domisili << endl;
            cout << "Nama Barang   : " << bantu->namaBarang << endl;
            cout << "Harga         : " << bantu->harga << endl;
            cout << "Kategori      : " << bantu->kategori << endl;

            // Tampilkan status dengan warna
            if (bantu->status == "Sudah Dibeli") {
                setColor(10); // Hijau
                cout << "Status        : " << bantu->status << endl;
            }
            else {
                setColor(12); // Merah
                cout << "Status        : " << bantu->status << endl;
            }
            setColor(7); // Reset warna
            bantu = bantu->next;
        }
    }
    system("pause");
}

// Cari barang berdasarkan nama penitip
void cariBarang() {
    system("cls");
    if (head == NULL) {
        cout << "Belum ada titipan.\n";
    }
    else {
        string cari;
        cout << "Masukkan Nama Penitip yang Dicari: ";
        getline(cin, cari);
        Barang* bantu = head;
        bool ketemu = false;
        while (bantu != NULL) {
            if (bantu->namaPenitip == cari) {
                ketemu = true;
                cout << "\n--- Ditemukan ---\n";
                cout << "ID Barang   : " << bantu->id << endl;
                cout << "Nama Barang : " << bantu->namaBarang << endl;
                cout << "Harga       : " << bantu->harga << endl;

                // Warna status
                if (bantu->status == "Sudah Dibeli") {
                    setColor(10);
                    cout << "Status      : " << bantu->status << endl;
                }
                else {
                    setColor(12);
                    cout << "Status      : " << bantu->status << endl;
                }
                setColor(7);
            }
            bantu = bantu->next;
        }
        if (!ketemu)
            cout << "Tidak ditemukan barang dari penitip tersebut.\n";
    }
    system("pause");
}

// Hapus barang berdasarkan ID
void hapusBarang() {
    system("cls");
    if (head == NULL) {
        cout << "Belum ada titipan.\n";
    }
    else {
        string idHapus;
        cout << "Masukkan ID Barang yang ingin dihapus: ";
        getline(cin, idHapus);

        Barang* hapus = head;
        Barang* prev = NULL;

        while (hapus != NULL && hapus->id != idHapus) {
            prev = hapus;
            hapus = hapus->next;
        }

        if (hapus == NULL) {
            cout << "ID tidak ditemukan.\n";
        }
        else {
            if (hapus == head) {
                head = head->next;
                if (head == NULL) tail = NULL;
            }
            else {
                prev->next = hapus->next;
                if (hapus == tail) tail = prev;
            }
            delete hapus;
            jumlahTitipan--;
            cout << "Barang berhasil dihapus.\n";
        }
    }
    system("pause");
}

// Ubah status barang jadi "Sudah Dibeli"
void tandaiDibeli() {
    system("cls");
    if (head == NULL) {
        cout << "Belum ada titipan.\n";
    }
    else {
        cout << "Daftar Barang Titipan:\n";
        Barang* bantu = head;
        while (bantu != NULL) {
            cout << "----------------------------------\n";
            cout << "ID Barang     : " << bantu->id << endl;
            cout << "Nama Penitip  : " << bantu->namaPenitip << endl;
            cout << "Nama Barang   : " << bantu->namaBarang << endl;
            cout << "Harga         : " << bantu->harga << endl;

            // Tampilkan status dengan warna
            if (bantu->status == "Sudah Dibeli") {
                setColor(10);
                cout << "Status        : " << bantu->status << endl;
            }
            else {
                setColor(12);
                cout << "Status        : " << bantu->status << endl;
            }
            setColor(7);
            bantu = bantu->next;
        }

        cout << "\nMasukkan ID Barang yang ingin ditandai sudah dibeli: ";
        string idUbah;
        getline(cin, idUbah);

        bantu = head;
        bool ketemu = false;
        while (bantu != NULL) {
            if (bantu->id == idUbah) {
                bantu->status = "Sudah Dibeli";
                ketemu = true;
                cout << "\nStatus barang berhasil diubah.\n";
                break;
            }
            bantu = bantu->next;
        }
        if (!ketemu) {
            cout << "\nID tidak ditemukan.\n";
        }
    }
    system("pause");
}


// Urutkan barang berdasarkan harga (bubble sort)
void urutkanBerdasarkanHarga() {
    system("cls");
    if (head == NULL || head->next == NULL) {
        cout << "Data kosong atau hanya 1 data. Tidak perlu diurutkan.\n";
    }
    else {
        bool swapped;
        do {
            swapped = false;
            Barang* curr = head;
            while (curr->next != NULL) {
                if (curr->harga > curr->next->harga) {
                    swap(curr->id, curr->next->id);
                    swap(curr->namaPenitip, curr->next->namaPenitip);
                    swap(curr->domisili, curr->next->domisili);
                    swap(curr->namaBarang, curr->next->namaBarang);
                    swap(curr->harga, curr->next->harga);
                    swap(curr->kategori, curr->next->kategori);
                    swap(curr->status, curr->next->status);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
        cout << "Barang berhasil diurutkan berdasarkan harga dari termurah ke termahal.\n";
    }
    system("pause");
}

// Menu utama
int main() {
    int pilih;
    do {
        system("cls");
        cout << "=== SISTEM JASA TITIP BELI BARANG ===\n";
        cout << "1. Tambah Barang Titipan\n";
        cout << "2. Tampilkan Semua Barang\n";
        cout << "3. Cari Barang Berdasarkan Nama Penitip\n";
        cout << "4. Hapus Barang Titipan\n";
        cout << "5. Tandai Barang Sudah Dibeli\n";
        cout << "6. Urutkan Barang Berdasarkan Harga\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
        case 1: tambahBarang(); break;
        case 2: tampilkanBarang(); break;
        case 3: cariBarang(); break;
        case 4: hapusBarang(); break;
        case 5: tandaiDibeli(); break;
        case 6: urutkanBerdasarkanHarga(); break;
        case 7: cout << "Terima kasih telah menggunakan sistem jasa titip.\n"; break;
        default: cout << "Pilihan tidak valid.\n"; system("pause");
        }
    } while (pilih != 7);

    return 0;
}