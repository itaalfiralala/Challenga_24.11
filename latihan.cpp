#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Barang {
    int id;
    string nama;
    int stok;
    double harga;

    void tampilkan() const {
        cout << "\n========== DETAIL BARANG ==========\n";
        cout << left << setw(10) << "ID" << ": " << id << endl;
        cout << left << setw(10) << "Nama" << ": " << nama << endl;
        cout << left << setw(10) << "Stok" << ": " << stok << endl;
        cout << left << setw(10) << "Harga" << ": Rp" << fixed << setprecision(2) << harga << endl;
        cout << "===================================\n";
    }
};

void tambahBarang(vector<Barang>& daftarBarang) {
    Barang baru;
    cout << "\n=== Tambah Barang Baru ===\n";
    cout << "Masukkan ID      : ";
    cin >> baru.id;
    cin.ignore();
    cout << "Masukkan Nama    : ";
    getline(cin, baru.nama);
    cout << "Masukkan Stok    : ";
    cin >> baru.stok;
    cout << "Masukkan Harga   : ";
    cin >> baru.harga;

    daftarBarang.push_back(baru);
    cout << "\n>> Barang berhasil ditambahkan!\n";
}

void cariBarang(const vector<Barang>& daftarBarang) {
    int cariID;
    cout << "\n=== Cari Barang ===\n";
    cout << "Masukkan ID barang: ";
    cin >> cariID;

    for (const auto& barang : daftarBarang) {
        if (barang.id == cariID) {
            barang.tampilkan();
            return;
        }
    }

    cout << ">> Barang dengan ID " << cariID << " tidak ditemukan.\n";
}

void tampilkanSemua(const vector<Barang>& daftarBarang) {
    cout << "\n=== Daftar Semua Barang ===\n";

    if (daftarBarang.empty()) {
        cout << ">> Belum ada barang yang terdaftar.\n";
        return;
    }

    cout << left << setw(6) << "ID"
        << setw(20) << "Nama"
        << setw(10) << "Stok"
        << setw(15) << "Harga" << endl;

    cout << string(50, '-') << endl;

    for (const auto& barang : daftarBarang) {
        cout << left << setw(6) << barang.id
            << setw(20) << barang.nama
            << setw(10) << barang.stok
            << "Rp" << fixed << setprecision(2) << barang.harga << endl;
    }
}

int main() {
    vector<Barang> daftarBarang;
    int pilihan;

    do {
        cout << "\n=== MENU TOKO ELEKTRONIK PAK BEJO ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Barang Berdasarkan ID\n";
        cout << "3. Tampilkan Semua Barang\n";
        cout << "4. Keluar\n";
        cout << "--------------------------------------\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            tambahBarang(daftarBarang);
            break;
        case 2:
            cariBarang(daftarBarang);
            break;
        case 3:
            tampilkanSemua(daftarBarang);
            break;
        case 4:
            cout << "\n>> Terima kasih telah menggunakan sistem inventori.\n";
            break;
        default:
            cout << "\n>> Pilihan tidak valid, silakan coba lagi.\n";
        }

    } while (pilihan != 4);

    return 0;
}