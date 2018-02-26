//Liam Kolber
//Recitation 4
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

struct node {
	int key;
	node *next;
};




node* AddNode(node* head,int key) {
	node* x = new node;

	x->key = key;
	x->next = NULL;

	if (head == NULL) {
		head = x;
		return head;
	}

	node* tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = x;

	return head;
}


int main() {
	return 0;
}