#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *next;
	Node *previous;
	Node(int k, Node *n, Node *p){
		key = k;
		next = n;
		previous = p;
	}
};

class LinkedList{
	private:
		Node *head;
		Node *search(int value) {
			Node *node = head;
			while (node != NULL) {
				if (node->key == value) {
					return node;
				}
				else {
					node = node->next;
				}
			}
			return head;
		}

	public:
		LinkedList(){head = NULL;};
		void getName() {
			cout<<"Liam Kolber";
		}

		void addNode(int value, int newVal) {
			Node *temp = new Node(newVal,NULL,NULL);
			Node *found = new Node(value,NULL,NULL);

			if (head == NULL) {
		        head->key = value;
		        head->previous = NULL;
		        head->next = NULL;
		    }
		    found = search(value);
		    if (found->next == NULL) { //end of list
		    	found->next = temp; //add to end
		    	temp->previous = found;
		    }
		    else if (found == head) {
		    	head->previous = temp; //put before head
		    	head = temp; //move head
		    	head->next = found; //head points to it's old self
		    	delete temp;
		    }
		    else {
		    	temp->next = found->next;
		    	temp->previous = found;
		    	found->next->previous = temp;
		    	found->next = temp;
		    }

		}

	  	Node *getHead() {
			return head;
	    }
		void printList(){
			Node *x = head;
			while(x != NULL){
				cout<<x->key<<endl;
				x = x->next;
			}
		}
};