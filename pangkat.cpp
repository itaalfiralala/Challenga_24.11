#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
	for (int i = 1; i <= 10; i++) {
		cout << i << " pangkat " << i << " = " << fixed << setprecision(0) << pow(i, i) << endl;
	}
	return 0;
}
	