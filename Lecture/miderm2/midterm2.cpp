#include <iostream>
#include "LinkedList.cpp"
using namespace std;

void printList(Node *head) {
	Node *tr=head;
    if (head != NULL) {
        cout<<"Traverse Forward\n==============\n";
        while(tr->next!=NULL) {
            cout<<tr->key << " ";
            tr=tr->next;
        }
        cout<<tr->key;
        cout<<"\n";
        //Traverse Backwards
        cout<<"Traverse Backward\n==============\n";
        while(tr->previous!=NULL) {
            cout<<tr->key <<" ";
            tr=tr->previous;
        }
        cout<<tr->key;
        cout<<"\n\n";
    }
}

int main() {
	LinkedList ll;
	Node *head;
	ll.addNode(1,5);  // 5->
	ll.addNode(5,10); // 5->10
	ll.addNode(5,6); //5->6->10

	cout<<"\nTest Case 1\n==========\n"; //Expected Output is 5 6 10 and 10 6 5
	head=ll.getHead();
	printList(head); //Expected Output is 5 6 10 and 10 6 5
	
	cout<<"\nTest Case 2 \n==========\n"; //Expected Output 12 5 6 7 10 11
	ll.addNode(6,7); //5->6->7->10
	ll.addNode(10,11); //5->6->7->10->11
	ll.addNode(100,12); //12->5->6->7->10->11 (As there is no 100 insert 100 in the head position)
	head=ll.getHead();
    printList(head); //Expected Output 12 5 6 7 10 11 and 11 10 7 6 5 12 
 }