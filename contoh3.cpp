#include <iostream>
#include <conio.h>
using namespace std;

int main (void)
 {
	int tgl_lahir[] = { 29,3,2006 };
	int *ptgl;
	ptgl = tgl_lahir; /* ptgl berisi alamat array */
	cout << "Diakses dengan pointer\n ";
	cout << "Tanggal = " << *ptgl;
	cout << " \nBulan = " << *(ptgl + 1) ;
	cout << " \nTahun = " << *(ptgl + 2) ;
	cout << " \nDiakses dengan array biasa\n ";
	cout << "Tanggal = " << tgl_lahir[0];
	cout << " \nBulan = " << tgl_lahir[1];
	cout << " \nTahun = " << tgl_lahir[2];
	getch();
}