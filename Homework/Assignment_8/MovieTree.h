#ifndef MOVIETREE_H
#define MOVIETREE_H

#include <string>
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
struct MovieNode{
    int ranking;
    string title;
    int year;
    int quantity;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, string in_title, int in_year, int in_quantity) {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
};
//--------------------------------------------------------------------------
class MovieTree {
    public:
        MovieTree();
        ~MovieTree();
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(string title);
        void addMovieNode(int ranking, string title, int releaseYear, int quantity);
        void findMovie(string title);
        void rentMovie(string title);
        void insertnode(MovieNode *addnode); //added to help my own logic

    protected:

    private:
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printInventory(MovieNode * node);
        void countNodes(MovieNode *node);
        MovieNode* search(string title);
        MovieNode* searchRecursive(MovieNode *node, string value);
        MovieNode* treeMinimum(MovieNode *node);
        MovieNode *root;
        int nodecounter;
};
//--------------------------------------------------------------------------
#endif // MOVIETREE_H