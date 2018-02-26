#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main() {
	queue<int> myq;
	cout << myq.size() << endl;
	myq.push(3);
	myq.push(6);
	myq.push(5);
	cout << myq.size() << endl;
	while(!myq.empty()) {
		myq.pop();
	}
	cout << myq.size() << endl;
}