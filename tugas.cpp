#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
}

Node *headNode = NULL;
Node *currentNode = NULL;

bool isEmpty();
void insertNode(int data);
void insertNodeMiddle(int data);
void insertNodeEnd(int data);
void deleteFromFront();
void deleteFromMiddle();
void deleteFromEnd();
void deleteAll();
void printNode();

int main ()
{
	int pilihanMenu;
	int data;
	do 
	{
		cout << ">>> PILHAN MENU SINGLY LINGKED LIST <<<"<<endl<<endl;
		cout << "1. Tambah Awal" << endl;
		cout << "2. Tambah Tengah "<< endl;
		cout << "3. Tambah Akhir" << endl;
		cout << "4. Hapus Awal" << endl;
		cout << "5. Hapus Tengah" << endl;
		cout << "6. Hapus Akhir " << endl;
		cout << "7. Mengosongkan Node" << endl;
		cout << "8. Menampilkan Node" << endl;
		cout << "9. Selesai" << endl << endl;
		
		cout << "Masukkan pilihan Anda: " ; cin >> pilihanMenu;
		cout << endl;
		
		switch (pilihanMenu)
    {
        case 1: 
            cout << "Masukan data : "; cin >> data;
            insertNode(data);
        break;

        case 2: 
            if (isEmpty()) {
                cout <<"List masi kosong!!!" << endl << endl;
            }
            else {
                deleteFromFront();
            }
            break;

        case 3:
            if (isEmpty()){
                cout <<" list masi kosong!!!" << endl << endl;
            }
            else{
                deleteFromFrontEnd();
            }
            break;

        case 4:
            if (isEmpty()){
                cout << " list masih kosong!!!"<< endl << endl;
            }
            else{
                deleteAll();
            }
            break;
        
        case 5:
            if (isEmpty()){
                cout << "list masihb kosong!!!"<< endl << endl;
            }
            else{
                printNode();
            }
            break;
         case 6:
            break;
        default:
            cout <<"Menu yang anda piloubtidak terdaftar"<< endl << endl;
            break;
    } while(pilihanMenu != 6);
    cout << endl;
    system("pause");
    return 0;
}
bool isEmpty()
{
    return (headNode == NULL);
}
void insertNode (int data)
{
    Node *newNode = NULL;
    newNode = new Node;

    newNode->data = data ;
    if (isEmpty())
    {
        currentNode = newNode;
    }
    else 
    {
        currentNode->next =newNode;
    }
    currentNode = newNode;
    currentNode->next = NULL;
    cout << "Node berhasil di tambahkan"<< endl << endl;
}

void deleteFromFront(){
    if (!isEmpty()){
        Node *hapusNode = headNode;
        headNode = headNode->Node;

        delete hapusNode;
        cout << "Node berhasil di hapus"<< endl<<endl;
    }
}

void deleteFromEnd()
{
    if (headNode == currentNode)
    {
        headNode = NULL;
        currentNode = NULL;
        return;
    }
    Node *bantu =headNode;
    Node *hapusNode =currentNode;
    while (bantu->next != currentNode)
    {
        bantu = bantu ->next;
    }
    currentNode = bantu;
    currentNode->next = NULL;
    delete hapusNode;
    cout << "Node berhasil dihapus"<< endl <<endl;
}

void deleteAll 
{
    Node *bantu, *hapusNode;
    bantu =headNode;
    while  (bantu->next != currentNode)
    {
        hapusNode = bantu;
        bantu =bantu->next;
        delete hapusNode;
    }
    headNode = NULL;
    currentNode = NULL;
    cout << "Node berhasil dikosongkan"<<endl <<endl;
}

void printNode()
{
    Node *awalNode =headNode;
    int i = 1;
    while (awalNode != NULL)
    {
        cout <<"Data pada node #"<<i<<" = "<<awalNode->data<<endl;
        awalNode = awalNode->next;
        i++;
    }
    cout << endl;
}
	}
}