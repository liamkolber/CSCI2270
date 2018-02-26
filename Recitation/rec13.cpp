#include <iostream>

using namespace std;

int divint(int, int);

int main() {
	int x = 5, y = 2;
	cout << divint(x, y); x =3;
	y = 0;
	cout << divint(x, y); return 0;
}

int divint(int a, int b) { 
	return a / b;
}

/*
to debug:

gdb ./sol

break 3

next

step

next

next

next

step

next ***ERROR***

l will pull up list

where to show history of error
*/