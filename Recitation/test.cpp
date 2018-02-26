#include <iostream>
using namespace std;


void isPrime(int n){
	for (int i=2; i<(n/2); i++){
		if ((n % i) == 0) {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
}

int main(){
	isPrime(23);
	isPrime(8);
	isPrime(41);
	isPrime(35);
	return 0;
}