//Liam Kolber
//Midterm 2 Review
//CSCI 2270
//Instructor: Jacobson
//--------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
struct node {
    int value;
    node *next;
    node *prev;
};

node* DeleteNode(node* head, int value) {
    node* temp = head;
    node* temp2 = head;

    while (temp != NULL) {
        if (value == head->value) {
            head = head->next;
            head->prev = NULL;
            delete temp;
            temp = head;
        }
        else if (temp->value == value) {
            temp2 = temp->next;
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            temp = temp2;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}

node* dequeue() {
    node* temp = head;
    if (tail->next == head) {
        head  = head->next;
        tail->next = NULL;
        delete temp;
    }
    else {
        head = head->next;
        delete temp;
    }
    return *head;
}

//Question 1
void findMax(){
    Node *cur = head;
    Node *max = head;  //set first element as max element
    while (cur != NULL){
        //If current element key is greater that max element key, then set that as max.
        //At the end of this loop you will have maximum element stored in max
        if (cur->key > max->key){
            max = cur;
        }
        
        cur = cur->next;
    }
    
    //For testcases to match
    cout << max->key;
}


//Question 2
void Queue::enqueue(node *newNode){
    //if head is NULL, that means newNode is going to be the first element to be inserted into the queue;
    //So attach the newNode to tail. Make head and tail both point to that newly appended node.
    if (head == NULL){
        tail = newNode;
        head = tail;
        head->next = NULL;
        tail->next = NULL;
    }
    
    //Else append newNode to tail->next and shift the tail so that it points to newNode
    else {
        tail->next = newNode;
        tail = newNode;
    }
}





