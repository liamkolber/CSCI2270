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
		Node *search(int value){
			Node *x = head;
			while(x != NULL){
				if(x->key == value){
					break;
				}
				else{
					x = x->next;
				}
			}
			return x;
		}

	public:
		LinkedList(){head = NULL;};
		void addNode(int value, int newVal){
			Node *node = new Node(newVal,NULL,NULL); //the new node
			Node *temp = head;
			Node *loc = search(value); //location of the desired value

			if (head == NULL) { //empty list
				head = node;
				return;
			}
			else if (loc == head) { //if the head has the value
				*node = Node(newVal,head->next,head);
				if (head->next != NULL) { //if it's going between nodes
					head->next->previous = node;
				}
				head->next = node;
			}
			else if (loc == NULL) { //if the value is not found in the list
				head->previous = node;
				node->next = head;
				head = node;
			}

		    while (temp->next != NULL) { //traverse through list (temp will hold the previous value)
		        if (temp->next == loc) {
		        	if (loc->next != NULL) { //if the vaule is not the end of the list
		        		loc->next->previous = node;
		        	}
		        	*node = Node(newVal,loc->next,loc); //give node a spot
		        	*loc = Node(value,node,temp); //reassign loc's pointers
		        	break;
		        }
		        else {
		        	temp = temp->next;
		        }		        
		    }
        }

		void printList(Node *h){
			Node *x = h;
			while(x != NULL){
				cout<<x->key<<endl;
				x = x->next;
			}
		}

	    Node *getHead(){
	        return head;
	    }
};