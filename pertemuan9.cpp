#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* headNode = NULL;
Node* currentNode = NULL;

bool isEmpty();
void insertNode(int data);
void deleteFromFront();
void deleteFromEnd();
void deleteAll();
void printNode();

int main() {
    int pilihanMenu;
    int data;
    do {
        cout << ">>> PILIHAN MENU SINGLY LINKED LIST <<<" << endl << endl;
        cout << "1. Menambahkan Node dari Depan" << endl;
        cout << "2. Menghapus Node dari Depan" << endl;
        cout << "3. Menghapus Node dari Belakang" << endl;
        cout << "4. Mengosongkan Node" << endl;
        cout << "5. Menampilkan Node" << endl;
        cout << "6. Selesai" << endl;

        cout << "Masukkan pilihan Anda: ";
        cin >> pilihanMenu;
        cout << endl;

        switch (pilihanMenu) {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            insertNode(data);
            break;

        case 2:
            deleteFromFront();
            break;

        case 3:
            deleteFromEnd();
            break;

        case 4:
            deleteAll();
            break;

        case 5:
            printNode();
            break;

        case 6:
            break;

        default:
            cout << "Menu yang Anda pilih tidak terdaftar" << endl << endl;
            break;
        }
    } while (pilihanMenu != 6);

    return 0;
}

bool isEmpty() {
    return (headNode == NULL);
}

void insertNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        headNode = newNode;
    } else {
        currentNode->next = newNode;
    }
    currentNode = newNode;

    cout << "Node berhasil ditambahkan" << endl << endl;
}

void deleteFromFront() {
    if (isEmpty()) {
        cout << "List masih kosong ! ! !" << endl << endl;
        return;
    }

    Node* hapusNode = headNode;
    headNode = headNode->next;

    if (hapusNode == currentNode) {
        currentNode = NULL;
    }

    delete hapusNode;

    cout << "Node berhasil dihapus dari depan" << endl << endl;
}

void deleteFromEnd() {
    if (isEmpty()) {
        cout << "List masih kosong ! ! !" << endl << endl;
        return;
    }

    if (headNode == currentNode) {
        delete headNode;
        headNode = NULL;
        currentNode = NULL;
    } else {
        Node* bantu = headNode;
        while (bantu->next != currentNode) {
            bantu = bantu->next;
        }
        delete currentNode;
        currentNode = bantu;
        currentNode->next = NULL;
    }

    cout << "Node berhasil dihapus dari belakang" << endl << endl;
}

void deleteAll() {
    if (isEmpty()) {
        cout << "List masih kosong ! ! !" << endl << endl;
        return;
    }

    Node* bantu = headNode;
    Node* hapusNode;

    while (bantu != NULL) {
        hapusNode = bantu;
        bantu = bantu->next;
        delete hapusNode;
    }

    headNode = NULL;
    currentNode = NULL;

    cout << "Semua node berhasil dihapus" << endl << endl;
}

void printNode() {
    if (isEmpty()) {
        cout << "List masih kosong ! ! !" << endl << endl;
        return;
    }

    Node* temp = headNode;
    int i = 1;
    while (temp != NULL) {
        cout << "Data pada node #" << i << " = " << temp->data << endl;
        temp = temp->next;
        i++;
    }
    cout << endl;
}
