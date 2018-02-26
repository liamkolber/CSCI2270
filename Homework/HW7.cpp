//Liam Kolber
//Homework 7
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

TreeNode *search(TreeNode *n, char curr) {
    if (n == NULL) {
        return n;
    }
    else {
        if (n->key == curr) {
            return  n;
        }
        else if (n->key > curr) {
            return search(n->left,curr);
        }
        else {
            return search(n->right,curr);
        }
    }
}



void RangeSearch(TreeNode *node, char m, char n) {
    TreeNode *temp = new TreeNode;
    Node *temphead = new Node;
    Node *tempnode = new Node;
    bool flag = true;
    
    while (node != NULL) {
        temp = search(node, m);
        if (temp != NULL) {
            if (flag) {
                temphead->key = m;
                head = temphead;
                flag = false;
            }
            else {
                tempnode = temphead;
                cout << tempnode->key <<endl;
                while (tempnode != NULL) {
                    tempnode = tempnode->next;
                }
                tempnode->key = m;
            }
        }
        m++;
        if (m>n) {
            break;
        }
    }
}