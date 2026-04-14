#include <iostream>
#include <conio.h>
using namespace std;

int main (void) {
	int a[5] = {5, 4, 3, 2, 1};
	int *p;
	int i;
	
	cout <<"akses array menggunakan index\n";
	for (i = 0; i < 5; i++) {
		cout <<"elemen a ke-"<<i<<" : " <<a[i];
		cout <<"\n";
	}
	cout <<"akses array menggunakan pointer\n";
	p = &a[0];
	for (i = 0; i < 5; i++) {
		cout <<"elemen a ke-"<<i<<" : " <<*p;
		p++;
		cout <<"\n";
	}
	getch();
}
