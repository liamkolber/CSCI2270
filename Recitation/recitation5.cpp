#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

struct node {
	int key;
	node* next;
}

node* DeleteNode(node* head, int value) {
	node* temp = head;

	if (value == head->value) {
		head = head->next;
		head->prev = NULL;
		delete temp;
		temp = head;
	}
	while (temp != NULL) {
		if (temp->value == value) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		else {
			temp = temp->next;
		}
	}
	return head;
}
















