#include <iostream>
using namespace std;

int main() {
    int b;
    cout << "Masukkan jumlah kolom: ";
    cin >> b;
    int** array = new int*[2]; 
    for (int i = 0; i < 2; i++) {
        array[i] = new int[b];  
    }
    for (int a = 0; a < 2; a++) {
        for (int c = 0; c < b; c++) {
            cout << "Masukkan Array [" << a << "][" << c << "] : ";
            cin >> array[a][c];
        }
    }
    cout << "=======================" << endl;
    for (int a = 0; a < 2; a++) {
        for (int c = 0; c < b; c++) {
            cout << "Nilai Array [" << a << "][" << c << "] : " << array[a][c] << endl;
        }
    }
    for (int i = 0; i < 2; i++) {
        delete[] array[i]; 
    }
    delete[] array;
    return 0;
}
