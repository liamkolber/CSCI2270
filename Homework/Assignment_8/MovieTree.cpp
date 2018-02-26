#include "MovieTree.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------------------
MovieTree::MovieTree() {
    root = NULL;
}
//--------------------------------------------------------------------------
MovieTree::~MovieTree() {
    DeleteAll(root);
}
//--------------------------------------------------------------------------
void MovieTree::printMovieInventory() {
    if(root != NULL){
        printInventory(root);
    }
}
//--------------------------------------------------------------------------
int MovieTree::countMovieNodes() {
    nodecounter = 0;
    if(root != NULL){
        countNodes(root);
    }
    return nodecounter;
}
//--------------------------------------------------------------------------
void MovieTree::deleteMovieNode(string title) { //delete node
	MovieNode *currentnode = root;
    if(currentnode == NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    else{
        while(currentnode != NULL){
           if(currentnode->title.compare(title) == 0){
                //figure out if left or right child or parent
                if(currentnode == currentnode->parent->leftChild){
                    currentnode->parent->leftChild = NULL;
                }
                else{
                    currentnode->parent->rightChild = NULL;
                }

                //reattaching children of node to delete to tree
                if(currentnode->leftChild != NULL){ //rearrange the nodes to fill tree
                    insertnode(currentnode->leftChild);
                }
                if(currentnode->rightChild != NULL){
                    //insert
                    insertnode(currentnode->rightChild);
                }
                //delete
                delete currentnode;
                return;
            }
            else if (currentnode->title.compare(title) >= 0){
                currentnode = currentnode->leftChild;
            }
            else{
                currentnode = currentnode->rightChild;
            }
        }
    }
    if(currentnode == NULL){
        cout << "Movie not found." << endl;
    }
}
//--------------------------------------------------------------------------
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {
    MovieNode *addnode = new MovieNode(ranking,title,releaseYear,quantity);
    addnode->parent = NULL;
    addnode->leftChild = NULL;
    addnode->rightChild = NULL;
    MovieNode *currentnode = root;

    if(root == NULL){
        root = addnode;
    }
    else{
        //insert movies by title - alphabetically
        while(currentnode != NULL) {
            if (currentnode->title == addnode->title){
                //left
                if(currentnode->leftChild == NULL){
                    currentnode->leftChild = addnode;
                    addnode->parent = currentnode;

                    break;
                }
                else{
                    currentnode = currentnode->leftChild;
                }
            }
            else{
                //right
                if(currentnode->rightChild == NULL){
                    currentnode->rightChild = addnode;
                    addnode->parent = currentnode;
                    break;
                }
                else{
                    currentnode = currentnode->rightChild;
                }
            }
        }
        if (currentnode == NULL){
            cout<<"failed node insert"<<endl;
        }
    }
}
//--------------------------------------------------------------------------
void MovieTree::findMovie(string title) {
    MovieNode *currentnode = root;
    if(currentnode == NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    else{
        do{
           if(currentnode->title.compare(title) == 0){
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                cout<<"Ranking:"<<currentnode->ranking<<endl;
                cout<<"Title:"<<currentnode->title<<endl;
                cout<<"Year:"<<currentnode->year<<endl;
                cout<<"Quantity:"<<currentnode->quantity<<endl;
                return;
            }
            else if (currentnode->title.compare(title) >= 0){
                currentnode = currentnode->leftChild;
            }
            else{
                currentnode = currentnode->rightChild;
            }
        }while(currentnode != NULL);
    }
    if(currentnode == NULL){
        cout<<"Movie not found."<<endl;
    }
}
//--------------------------------------------------------------------------
void MovieTree::rentMovie(string title) {
    MovieNode *currentnode = root;
    if(currentnode == NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    else{
        do{
           if(currentnode->title.compare(title) == 0){
                if(currentnode->quantity == 0){
                    cout<<"Movie out of stock"<<endl;
                    deleteMovieNode(currentnode->title);
                    return;
                }
                currentnode->quantity --;
                cout<<"Movie has been rented."<<endl;
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                cout<<"Ranking:"<<currentnode->ranking<<endl;
                cout<<"Title:"<<currentnode->title<<endl;
                cout<<"Year:"<<currentnode->year<<endl;
                cout<<"Quantity:"<<currentnode->quantity<<endl;
                if(currentnode->quantity == 0){
                    deleteMovieNode(currentnode->title);
                }
                return;
            }
            else if (currentnode->title.compare(title) >= 0){
                currentnode = currentnode->leftChild;
            }
            else{
                currentnode = currentnode->rightChild;
            }
        }while(currentnode != NULL);
    }
    if(currentnode == NULL){
        cout<<"Movie not found."<<endl;
    }
}
//--------------------------------------------------------------------------
void MovieTree::DeleteAll(MovieNode * currentnode) {
    MovieNode *nodetodelete = NULL;
    while(currentnode != NULL){
        cout<<currentnode->title<<endl;
        //traverse
        if(currentnode->leftChild != NULL){
            currentnode = currentnode->leftChild;
        }
        else if(currentnode->rightChild != NULL){
            currentnode = currentnode->rightChild;
        }
        else{
            //if both null
            nodetodelete = currentnode;
            if(currentnode == root){
                cout<<"Deleting: "<<nodetodelete->title<<endl;
                delete currentnode;
                break;
            }
            else{
                currentnode = currentnode->parent;
            }
            cout<<"Deleting: "<<nodetodelete->title<<endl;
            if(nodetodelete == currentnode->leftChild){
                currentnode->leftChild = NULL;
            }
            else{
                currentnode->rightChild = NULL;
            }
            delete nodetodelete;

        }
    }
}
//--------------------------------------------------------------------------
void MovieTree::printInventory(MovieNode * node) {
    if(node == NULL){return;}
    printInventory(node->leftChild);
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    printInventory(node->rightChild);
}
//--------------------------------------------------------------------------
void MovieTree::countNodes(MovieNode *node) {
    if(node == NULL){return;}
    countNodes(node->leftChild);
    nodecounter ++;
    countNodes(node->rightChild);
}
//--------------------------------------------------------------------------
void MovieTree::insertnode(MovieNode *addnode){
    MovieNode *currentnode = root;
    if(currentnode == NULL){
        root = addnode;
        return;
    }
    else{
            //insert movies by title - alphabetically
        while(currentnode != NULL){
            if (currentnode->title.compare(addnode->title) >= 0){
                //left
                if(currentnode->leftChild == NULL){
                    currentnode->leftChild = addnode;
                    addnode->parent = currentnode;
                    break;
                }
                else{
                    currentnode = currentnode->leftChild;
                }
            }
            else{
                //right
                if(currentnode->rightChild == NULL){
                    currentnode->rightChild = addnode;
                    addnode->parent = currentnode;
                    break;
                }
                else{
                    currentnode = currentnode->rightChild;
                }
            }
        }
        if (currentnode == NULL){
            cout<<"failed node insert"<<endl;
        }
    }
}
//--------------------------------------------------------------------------
MovieNode* MovieTree::search(string title) {

}
//--------------------------------------------------------------------------
MovieNode* MovieTree::searchRecursive(MovieNode *node, string value) {

}
//--------------------------------------------------------------------------
MovieNode* MovieTree::treeMinimum(MovieNode *node) {

}
//--------------------------------------------------------------------------
