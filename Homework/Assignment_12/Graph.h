#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
template<class T>
struct vertex;
//------------------------------------------------------------------------------
template<class T>
struct adjVertex {
    vertex<T> *v;
    int weight;
};
//------------------------------------------------------------------------------
template<class T>
struct vertex {
    int ID;
    T name;
    vertex<T> *parent;
    int district;
    bool visited;
    int distance;
    vector<adjVertex<T>> adj;
};
//------------------------------------------------------------------------------
template<class T>
struct queueVertex {
    int distance;
    vector<vertex <T>*> path;
};
//------------------------------------------------------------------------------
template<class T>
class Graph {
    public:
        int count = 0; // used to give each city a number/ID
        bool flag = false; //had to add this, sorry
        Graph();
        ~Graph();
        void addEdge(T v1, T v2, int weight);
        void addVertex(T name);
        void displayEdges();
        void assignDistricts();
        void BFTraversalLabel(T startingCity, int distID);
        void shortestPath(T startingCity,T endingCity);
        vertex<T>* findVertex(T name);
    protected:
    private:
        vector<vertex<T>> vertices;
};
//------------------------------------------------------------------------------
#include "Graph.cpp"
#endif // GRAPH_H
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------