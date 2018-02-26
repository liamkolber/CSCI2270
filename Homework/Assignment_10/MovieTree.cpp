#include "MovieTree.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------------------
//------------------------Start of public functions-------------------------
//--------------------------------------------------------------------------
MovieTree::MovieTree() {
    nil = new MovieNode(0,"",0,0);
    nil->leftChild = nil;
    nil->rightChild = nil;
    nil->parent = nil;
    nil->isRed = false;
    root = nil;
    root->parent = nil;
}
//--------------------------------------------------------------------------
MovieTree::~MovieTree() {} //DeleteAll(root); }
//--------------------------------------------------------------------------
void MovieTree::printMovieInventory() {
    if(root != nil){
        printInventory(root);
    }
}
//--------------------------------------------------------------------------
int MovieTree::countMovieNodes() {
    int nodecounter = 0;
    if(root != nil){
        countNodes(root,nodecounter);
    }
    return nodecounter;
}
//--------------------------------------------------------------------------
void MovieTree::deleteMovieNode(string title) { //delete node
	MovieNode *currentnode = root;
    if(currentnode == nil){
        cout<<"Movie not found."<<endl;
        return;
    }
    else{
        while(currentnode != nil){
           if(currentnode->title.compare(title) == 0){
                rbDelete(currentnode);
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
    if(currentnode == nil){
        cout << "Movie not found." << endl;
    }
}
//--------------------------------------------------------------------------
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {
    MovieNode *addnode = new MovieNode(ranking,title,releaseYear,quantity);
    addnode->parent = nil;
    addnode->leftChild = nil;
    addnode->rightChild = nil;
    MovieNode *currentnode = root;

    if(root == nil){
        root = addnode;
        //cout << root->title << endl << endl;
    }
    else{
        //insert movies by title - alphabetically
        while(currentnode != nil) {
            if (currentnode->title == addnode->title){
                //left
                if(currentnode->leftChild == nil){
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
                if(currentnode->rightChild == nil){
                    currentnode->rightChild = addnode;
                    addnode->parent = currentnode;
                    break;
                }
                else{
                    currentnode = currentnode->rightChild;
                }
            }
        }
        if (currentnode == nil){
            cout<<"failed node insert"<<endl;
        }
        rbAddFixup(addnode);
    }
}
//--------------------------------------------------------------------------
void MovieTree::findMovie(string title) {
    MovieNode *currentnode = root;
    if(currentnode == nil){
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
        }while(currentnode != nil);
    }
    if(currentnode == nil){
        cout<<"Movie not found."<<endl;
    }
}
//--------------------------------------------------------------------------
void MovieTree::rentMovie(string title) {
    MovieNode *currentnode = root;
    if(currentnode == nil){
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
        }while(currentnode != nil);
    }
    if(currentnode == nil){
        cout<<"Movie not found."<<endl;
    }
}
//--------------------------------------------------------------------------
bool MovieTree::isValid() {
    if(!rbValid(root)) {
        return false;
    }
    return true;
}
//--------------------------------------------------------------------------
int MovieTree::countLongestPath() {
    if (root != nil) {
        return countPath(root);
    } 
    return 0;
}
//--------------------------------------------------------------------------
void MovieTree::DeleteAll() {
    DeleteAll(root);
}
//--------------------------------------------------------------------------
//------------------------Start of private functions------------------------
//--------------------------------------------------------------------------
void MovieTree::DeleteAll(MovieNode * currentnode) {
    MovieNode *nodetodelete = nil;
    while(currentnode != nil){
        //cout<<currentnode->title<<endl;
        //traverse
        if(currentnode->leftChild != nil){
            currentnode = currentnode->leftChild;
        }
        else if(currentnode->rightChild != nil){
            currentnode = currentnode->rightChild;
        }
        else{
            //if both nil
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
                currentnode->leftChild = nil;
            }
            else{
                currentnode->rightChild = nil;
            }
            delete nodetodelete;

        }
    }
}
//--------------------------------------------------------------------------
void MovieTree::printInventory(MovieNode * node) {
    if(node == nil){return;}
    printInventory(node->leftChild);
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    printInventory(node->rightChild);
}
//--------------------------------------------------------------------------
int MovieTree::countNodes(MovieNode *node, int nodecounter) {
    if(node == nil){return nodecounter;}
    countNodes(node->leftChild,nodecounter);
    nodecounter ++;
    countNodes(node->rightChild,nodecounter);
}
//--------------------------------------------------------------------------
void MovieTree::insertnode(MovieNode *addnode){
    MovieNode *currentnode = root;
    if(currentnode == nil){
        root = addnode;
        return;
    }
    else{
            //insert movies by title - alphabetically
        while(currentnode != nil){
            if (currentnode->title.compare(addnode->title) >= 0){
                //left
                if(currentnode->leftChild == nil){
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
                if(currentnode->rightChild == nil){
                    currentnode->rightChild = addnode;
                    addnode->parent = currentnode;
                    break;
                }
                else{
                    currentnode = currentnode->rightChild;
                }
            }
        }
        if (currentnode == nil){
            cout<<"failed node insert"<<endl;
        }
    }
    rbAddFixup(addnode);
}
//--------------------------------------------------------------------------
void MovieTree::rbAddFixup(MovieNode * node) { // called after insert to fix tree
    while((node != root) && (!node->parent->isRed)) {
        if(node->parent == node->parent->parent->leftChild) {
            MovieNode *uncle = node->parent->parent->rightChild;
            if(uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            }
            else {
                if(node == node->parent->rightChild) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rightRotate(node->parent->parent);
            }
        }
        else {
            MovieNode *uncle = node->parent->parent->leftChild;
            if(uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            }
            else {
                if(node == node->parent->leftChild) {
                    node = node->parent;
                    leftRotate(node);

                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rightRotate(node->parent->parent);
            }
        }
    }
    root->isRed = false;
}
//--------------------------------------------------------------------------
void MovieTree::leftRotate(MovieNode * x) { //rotate the tree left with x as the root of the rotation
    MovieNode *y;
    y = x->rightChild;
    x->rightChild = y->rightChild;

    if (y->leftChild != nil) {
        y->leftChild->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    }
    else if (x == x->parent->leftChild) {
        x->parent->leftChild = y;
    }
    else {
        x->parent->rightChild = y;
    }
    y->leftChild = x;
    x->parent = y;
}
//--------------------------------------------------------------------------
void MovieTree::rbDelete(MovieNode * node) { //delete a node. Call this from deleteMovieNode, the actual delete functionality happens here.
    MovieNode *x = nil;
    if(node == node->parent->leftChild) {
        if(node != root) {
            if(node->leftChild == nil && node->rightChild == nil) {
                node->parent->leftChild = nil;
                x = node->parent->leftChild;
            }
            else if(node->leftChild != nil && node->rightChild != nil) {
                MovieNode *min = node->rightChild;
                while (min->leftChild != nil) {
                    min = min->leftChild;
                }
                x = min->rightChild;
                if (min == node->rightChild) {
                    node->parent->leftChild = min;
                    min->parent = node->parent;
                    min->leftChild = node->leftChild;
                    min->leftChild->parent = min;
                }
                else {
                    min->parent->leftChild = min->rightChild;
                    min->rightChild->parent = min->parent;
                    min->parent = node->parent;
                    node->parent->leftChild = min;
                    min->leftChild = node->leftChild;
                    min->rightChild = node->rightChild;
                    node->rightChild->parent = min;
                    node->leftChild->parent = min;
                }
                min->isRed = node->isRed;
            }
            else {
                x = node->leftChild;
                node->parent->leftChild = x;
                x->parent = node->parent;
            }
        }
    }
    else {
        if(node != root) {
            if(node->rightChild == nil && node->leftChild == nil) {
                node->parent->rightChild = nil;
                x = node->parent->rightChild;
            }
            else if(node->rightChild != nil && node->leftChild != nil) {
                MovieNode *min = node->rightChild;
                while (min->leftChild != nil) {
                    min = min->leftChild;
                }
                x = min->rightChild;
                if (min == node->rightChild) {
                    node->parent->leftChild = min;
                    min->parent = node->parent;
                    min->leftChild = node->leftChild;
                    min->leftChild->parent = min;
                }
                else {
                    min->parent->leftChild = min->rightChild;
                    min->rightChild->parent = min->parent;
                    min->parent = node->parent;
                    node->parent->leftChild = min;
                    min->leftChild = node->leftChild;
                    min->rightChild = node->rightChild;
                    node->rightChild->parent = min;
                    node->leftChild->parent = min;
                }
                min->isRed = node->isRed;
            }
            else {
                x = node->rightChild;
                node->parent->rightChild = x;
                x->parent = node->parent;
            }
        }
    }
    if (!node->isRed) {
        rbDeleteFixup(node);
    }
    delete node;
}
//--------------------------------------------------------------------------
void MovieTree::rightRotate(MovieNode * x) { //rotate the tree right with x as the root of the rotation
    MovieNode *y;
    y = x->leftChild;
    x->leftChild = y->leftChild;

    if (y->rightChild != nil) {
        y->rightChild->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    }
    else if (x == x->parent->rightChild) {
        x->parent->rightChild = y;
    }
    else {
        x->parent->leftChild = y;
    }
    y->rightChild = x;
    x->parent = y;
}
//--------------------------------------------------------------------------
void MovieTree::rbDeleteFixup(MovieNode * node) { //called after delete to fix the tree
    MovieNode *s = nil;
    while(node != root && !node->isRed) {
        if (node == node->parent->leftChild) {
            s = node->parent->rightChild;
            if (s->isRed) {
                s->isRed = false;
                node->parent->isRed = true;
                leftRotate(node->parent);
                s = node->parent->rightChild;
            }
            if (!s->leftChild->isRed && !s->rightChild->isRed) {
                s->isRed = true;
                node = node->parent;
            }
            else if (s->leftChild->isRed && !s->rightChild->isRed) {
                s->leftChild->isRed = false;
                s->isRed = true;
                rightRotate(s);
                s = node->parent->rightChild;
            }
            else {
                s->isRed = node->parent->isRed;
                node->parent->isRed = false;
                s->rightChild->isRed = false;
                leftRotate(node->parent);
                node = root;
            }
        }
        else {
            s = node->parent->leftChild;
            if (s->isRed) {
                s->isRed = false;
                node->parent->isRed = true;
                rightRotate(node->parent);
                s = node->parent->rightChild;
            }
            if (!s->rightChild->isRed && !s->leftChild->isRed) {
                s->isRed = true;
                node = node->parent;
            }
            else if (s->rightChild->isRed && !s->leftChild->isRed) {
                s->leftChild->isRed = false;
                s->isRed = true;
                leftRotate(s);
                s = node->parent->leftChild;
            }
            else {
                s->isRed = node->parent->isRed;
                node->parent->isRed = false;
                s->leftChild->isRed = false;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
}
//--------------------------------------------------------------------------
void MovieTree::rbTransplant(MovieNode * u, MovieNode * v) { //replace node u in tree with node v.
}
//--------------------------------------------------------------------------
int MovieTree::rbValid(MovieNode * node) { // Returns 0 if the tree is invalid, otherwise returns the black node height. 
    int lh = 0;
    int rh = 0;

    // If we are at a nil node just return 1
    if(node == nil) {
        return 1; 
    }
    else {
        // First check for consecutive red links. 
        if (node->isRed) {
            if(node->leftChild->isRed || node->rightChild->isRed) {
                cout << "This tree contains a red violation" << endl;
                return 0;
            }
        }

        // Check for valid binary search tree. 
        if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) || (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0)) {
            cout << "This tree contains a binary tree violation" << endl;
            return 0;
        }

        // Deteremine the height of let and right children. 
        lh = rbValid(node->leftChild);
        rh = rbValid(node->rightChild);

        // black height mismatch 
        if (lh != 0 && rh != 0 && lh != rh) {
            cout << "This tree contains a black height violation" << endl;
            return 0;
        }

        // If neither height is zero, incrament if it if black. 
        if (lh != 0 && rh != 0) {
                if (node->isRed)
                    return lh;
                else
                    return lh+1;
        }
        else {
            return 0;
        }
    }
}
//--------------------------------------------------------------------------
int MovieTree::countPath(MovieNode *node) {

return 0;

}
//--------------------------------------------------------------------------
MovieNode* MovieTree::searchMovieTree(MovieNode *node, string title) {

return node;

}
//--------------------------------------------------------------------------