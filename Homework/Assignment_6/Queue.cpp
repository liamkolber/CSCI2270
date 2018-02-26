#include "Queue.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
Queue::Queue(int qs) {
     queueSize = qs;
     arrayQueue = new string[queueSize];
     queueHead = 0;
     queueTail = 0;
     queueCount = 0;
}
//--------------------------------------------------------------------------
Queue::~Queue() {
	//dtor
}
//--------------------------------------------------------------------------
void Queue::enqueue(string word) { //this places the input in the next open space in the queue
	if (!queueIsFull()) { //only do this when there is space in the queue
		arrayQueue[queueTail] = word;
		queueTail++;
		if (queueTail == queueSize) { //move the tail to the beginning of the queue if it reaches end
			queueTail=0;
		}
		queueCount++;
		cout << "E: " << word << endl;
		cout << "H: " << queueHead << endl;
		cout << "T: " << queueTail << endl;	
	}
	else {
		cout << "Queue is full." << endl;
	}
}
//--------------------------------------------------------------------------
void Queue::dequeue() { //removes the word at the beginning of the queue and moves the head
	if (!queueIsEmpty()) { //only do this when there is actually something in there (duh)
		string removed = arrayQueue[queueHead];
		if (queueHead == queueSize-1) { //if the head reaches the end push it to the beginning
			queueHead = 0;
		}
		else {
			queueHead++;
		}
		cout << "H: " << queueHead << endl;
		cout << "T: " << queueTail << endl;
		cout << "word: " << removed << endl;
		queueCount--;
	}
	else { //what do you think?
		cout << "Queue is empty." << endl;
	}
}
//--------------------------------------------------------------------------
void Queue::printQueue() { //print that ish
	int index = queueHead;

	if (queueIsEmpty()) { //you really tryna print an empty list? come on...
		cout << "Empty" << endl;
	}
	else { //these two loops do the same thing but I did some code voodoo so that it works regardless
			//of whether or not the head and tail start out the same when going in
		if (queueHead != queueTail) {
			while (index != queueTail){
				cout << index << ": " << arrayQueue[index] << endl;
				index++;
				if (index == queueSize) { // move index to beginning if it reaches the end
					index = 0;
				}
			}
		}
		else if (queueHead == queueTail) {
			do{
				cout << index << ": " << arrayQueue[index] << endl;
				index++;
				if (index == queueSize) { // move index to beginning if it reaches the end
					index = 0;
				}
			}while(index != queueTail);
		}
	}
}
//--------------------------------------------------------------------------
bool Queue::queueIsFull() { //check if queue is full
	if (queueHead==0 && queueTail==queueSize) { // if head is at beginning and tail is at end
		return true;
	}
	if (queueHead!=0 && queueTail==queueHead) { //if head is no longer 0 but tail and head are same
		return true;
	}
	if (queueCount == queueSize) { //pretty sure I only need this one, but oh well checks if there's queueSize amount of words in queue
		return true;
	}
	else { //not full
		return false;
	}
} //send when full
//--------------------------------------------------------------------------
bool Queue::queueIsEmpty() {
	if (queueCount == 0) { //no words
		return true;
	}
	else { //not empty
		return false;
	}
} //send when empty
//--------------------------------------------------------------------------