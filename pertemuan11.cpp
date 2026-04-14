#include <iostream>
#include <iomanip> // Untuk setw
using namespace std;

// Struktur Node BST
struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

// Fungsi tambah node ke dalam tree
Node* tambahNode(Node* root, int databaru) {
    if (root == NULL) {
        Node* baru = new Node();
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        cout << "Data bertambah!\n";
        return baru;
    } else {
        if (databaru < root->data) {
            root->kiri = tambahNode(root->kiri, databaru);
        } else if (databaru > root->data) {
            root->kanan = tambahNode(root->kanan, databaru);
        } else {
            cout << "Data sudah ada!\n";
        }
        return root;
    }
}

// Fungsi pre-order traversal
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

// Fungsi in-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

// Fungsi post-order traversal
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

// Fungsi visualisasi pohon secara teks
void tampilkanPohon(Node* root, int spasi = 0, int jarak = 4) {
    if (root == NULL)
        return;

    spasi += jarak;

    tampilkanPohon(root->kanan, spasi);

    cout << endl;
    for (int i = jarak; i < spasi; i++)
        cout << " ";
    cout << root->data << "\n";

    tampilkanPohon(root->kiri, spasi);
}

// Main program
int main() {
    Node* root = NULL;
    int pilihan, data;

    do {
        cout << "\n==== PROGRAM TREE C++ ====\n";
        cout << "1. Tambah\n";
        cout << "2. Tampilkan Pre-Order\n";
        cout << "3. Tampilkan In-Order\n";
        cout << "4. Tampilkan Post-Order\n";
        cout << "5. Tampilkan Pohon (Visual)\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data baru: ";
                cin >> data;
                root = tambahNode(root, data);
                break;
            case 2:
                cout << "Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Visualisasi pohon:\n";
                tampilkanPohon(root);
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 6);

    return 0;
}