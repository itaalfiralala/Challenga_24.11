#include <iostream>
using namespace std;

int main ()
{
	int a, *b;
	
	a = 5;
	b = &a;
	cout << "nilai a : " <<a;
	cout << "\nnilai yang ditunjukan oleh b : " <<*b;
	
	cout << "\nAlamat a : " <<&a;
	cout << "\nAlamat yang ditunjukan oleh b : " <<b;
	
	return 0;
}
