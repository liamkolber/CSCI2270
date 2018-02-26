#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

class cQueue {

	public:
		cQueue(int max);
		virtual ~cQueue();
		void enqueue(int value); 
		int getTail();
		void displayQueue();
	protected:
	private:
		int *c_array;
		int head;
		int tail;
		int size;

};

void cQueue::enqueue(int value) {
	head = 0;
	if (tail+1 < size) {
		c_array[tail+1] = value;
		size++;
		if (tail+1 == (size-1)) {
			tail = 0;
		}
		else {
			tail++;
		}
	}
	else {
		tail = 0;
		cout << "Queue Full"<< endl;
		return;
	}
}

int main() {
	return 0;
}