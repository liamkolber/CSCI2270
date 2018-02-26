//Liam Kolber
//Recitation 4
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

struct TreeNode
{
   char key;
   TreeNode *left;
   TreeNode *right;
   TreeNode *parent;
};
struct Node{
   char key;
   Node *next;
};
Node *head = NULL;


bool search(TreeNode *node, char curr, char n, Node *temp) {
    if (node->left != NULL) {
    	search(node->left,curr,n,temp);
    }
    if (node->key >= curr) {
    	temp->key = curr;
    	return true;
    }
    if (node->right != NULL) {
    	search(node->right,curr,n,temp);
    }
    return false;
}

void RangeSearch(TreeNode *node, char m, char n) {
    Node *temp = new Node;
    Node *newh = new Node;
    newh->key = m;
    newh->next = NULL;
    TreeNode *org = node;

    while (node != NULL) {
        if (node->key > m && node->left != NULL) {
            node = node->left;
        }
        else if (node->key < m && node->right != NULL) {
            node = node->right;
        }
        else if (node->key >= m) {
            newh->key = node->key;
            m = node->key;
            newh->next = temp;
            break;
        }
    }
    if (node->right != NULL) {
        m = node->right->key;
    }
    else {
        m = node->parent->key;
    }
    bool flag = true;
    while(flag) {
    	flag = search(node,m,n,temp);
    }
    head = temp;
}