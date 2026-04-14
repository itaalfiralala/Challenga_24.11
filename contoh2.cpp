#include <iostream>
#include <conio.h>
using namespace std;

int main (void)
{
	int var1, var2, *var3, *var4;
	
	var1 = 3;
	
	var3 = &var1;
	var4 = var3;
	
	cout << "var1 : " <<var1;
	cout << "\nalamat yang ditunjukan var3 : " <<var3;
	cout << "\nalamat yang ditunjukan var4 : " <<var4;
	
	var2 = var1 + (*var4);
	cout << "\nvar2 : " <<var2;
	
	var3++;
	cout << "\nalamat yang ditunjukan var3 : " <<var3;
	cout << "\nnilai yang ditunjukan ver3  : " <<var3;
	
	getch ();
}
