//Liam Kolber
//Assignment 12
//CSCI 2270
//Instructor: Jacobson
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Graph.h"
using namespace std;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int menu(){ //creating the proper menu output for the user to interact with
    int userinput;
    cout << "======Main Menu======" << endl;
    cout << "1. Print vertices" << endl;
    cout << "2. Find districts" << endl;
    cout << "3. Find shortest path" << endl;
    cout << "4. Quit" << endl;
    cin>>userinput;
    return userinput;
}
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    Graph<string> network;
    char* filename = argv[1];

    //prep file reading variables
    string line;
    ifstream inFile;
    inFile.open(filename);
    vector<string> cities;
    string word;
    string city;

    while(getline(inFile,line)){ // read in the file
        stringstream cts(line);
        getline(cts,word,',');
        if (word == "cities") {
            while (getline(cts,city,',')) {
                cities.push_back(city);
                network.addVertex(city);
            }
            continue;
        }
        string fromCity = word;
        int index = 0;
        string weight;
        int wht;
        while (getline(cts,weight,',')) {
            stringstream convert(weight);
            convert >> wht;
            string toCity = cities[index];
            network.addEdge(fromCity,toCity,wht);
            index++;
        }
    }

    //display menu for user
    int userinput;
    string cityName;
    while(userinput != 4) {
        userinput = menu();
        if(userinput == 1) { //print vertices
            network.displayEdges();
        }
        else if(userinput == 2) { //find districts
            network.assignDistricts();
        }
        else if(userinput == 3) { //find shortest path
            string from;
            string to;
            cout << "Enter a starting city:" << endl;
            cin.ignore();
            getline(cin,from);
            cout << "Enter an ending city:" << endl;
            //cin.ignore();
            getline(cin,to);
            network.shortestPath(from,to);
        }
        else if(userinput > 4 || userinput <= 0){
            cout<<"Invalid input. Please enter a number between 1 & 7"<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
    inFile.close();
    return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------