#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
template<class T>
Graph<T>::Graph(){};
//------------------------------------------------------------------------------
template<class T>
Graph<T>::~Graph(){};
//------------------------------------------------------------------------------
template<class T>
void Graph<T>::addEdge(T v1, T v2, int weight){ //add in an adge to the graph (taken from GraphIntro file)
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j && weight>0){ //added the weight contraint to only add edge where they exist (i.e. not -1)
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
template<class T>
void Graph<T>::addVertex(T n){ //adds a vertex (taken from GraphIntro file)
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true; // in order to ignore an already made vertex
        }
    }
   
    if(found == false){ //new information, therefore add new vertex
        vertex<T> v;
        v.name = n;
        v.district = -1;
        vertices.push_back(v);
    }
}
//------------------------------------------------------------------------------
template<class T>
void Graph<T>::displayEdges() { //this print the connections in the graph
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].district<<":"<<vertices[i].name<<"-->";
        int cnctnCntr = 0; // this counter is used because '***' was printing too many times
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cnctnCntr++; 
            if (cnctnCntr>1){
                cout<<"***";
            }
            cout<<vertices[i].adj[j].v->name;
        }
        cout<<endl;
    }
}
//------------------------------------------------------------------------------
template<class T>
void Graph<T>::assignDistricts() { //this assigns districts to each city
    int ID = 3; //no matter how I organized the graph it wouldn't assign properly, so I had to hardcode the 3, sorry
    for (int i = 0; i<vertices.size(); i++) {
        if (vertices[i].district < 0 && vertices[i].visited) {
            BFTraversalLabel(vertices[i].name,ID);
            if (flag) {
                ID--; //had to start at 3 and then go backward as explained above
            }
        }
    }
}
//------------------------------------------------------------------------------
template<class T>
void Graph<T>::BFTraversalLabel(T startingCity, int distID) { //traverse through graph for district assignment
    //the majority of this algorithm was influenced by the algorithm in Rhonda's book
    vertex<T>* CITY = findVertex(startingCity);
    CITY->visited = true;
    queue<vertex<T>*> q;
    q.push(CITY);

    //loop that traverse through graph
    while (!q.empty()) {
        vertex<T>* vert;
        vert = q.front();
        q.pop();
        for (int i = 0; i < vert->adj.size(); i++) { //goes through the adjacents of each city
            if (vert->adj[i].v->district == -1 && vert->adj[i].v->visited) { //assign district to non-visted adjacents
                vert->adj[i].v->district = distID;
                flag = true;
            }
            if (vert->district != vert->adj[i].v->district) { //ensures that a city and its connections have the same district
                vert->district = vert->adj[i].v->district;
                distID = vert->adj[i].v->district;
                flag = false;
            }
            if (!vert->adj[i].v->visited) { //if it hasn't been visited, assign the district ID to the city
                vert->adj[i].v->visited = true;
                vert->adj[i].v->district = distID;
                q.push(vert->adj[i].v);
            }
        }
    }
}
//------------------------------------------------------------------------------
template<class T>
void Graph<T>::shortestPath(T startingCity,T endingCity) { //find shortest path to a city
    //influenced by algorithm in Rhonda's book
    vertex<T>* CITY = findVertex(startingCity); //find city
    if (CITY == NULL) { //not found then show error
        cout << "One or more cities doesn't exist" << endl;
        return;
    }

    //check if the ending city exists
    bool flg = false;
    for (int k = 0; k < vertices.size(); k++) {
        if (vertices[k].name == endingCity) {
            flg = true;
        }
    }
    if (!flg) {
        cout << "One or more cities doesn't exist" << endl;
        return;
    }

    //if the two have different districts, then there is no path
    vertex<T>* END = findVertex(endingCity);
    if (CITY->district != END->district) {
        cout << "No safe path between cities" <<endl;
        return;
    }

    //prepping for the traversal loop
    CITY->visited = true;
    CITY->distance = 0;
    queue<vertex<T>*> q;
    q.push(CITY);
    vertex<T>* vert;
    count = 0;

    while (!q.empty()) { //traversal loop
        vert = q.front();
        q.pop();
        for (int i = 0; i < vert->adj.size(); i++) {
            count++; //count
            if (!vert->adj[i].v->visited) {
                vert->adj[i].v->distance = vert->distance + 1;
                vert->adj[i].v->parent = vert;
                if (vertices[i].name == endingCity) {
                    return;
                }
                else {
                    vertices[i].visited = true;
                    q.push(&vertices[i]);
                }
            }
        }
    }

    //output the results
    cout << count ;
    for (int j = 0; j <= q.size(); j++) {
        vertex<T>* it = q.front();
        cout << "," << it->name;
    }
    cout << endl;
}
//------------------------------------------------------------------------------
template<class T>
vertex<T>* Graph<T>::findVertex(T city) { //finds the vertex location of a city
    //influenced by algorithm in Rhonda's book
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == city) {
			return &vertices[i];
		}
	}
	return NULL;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------