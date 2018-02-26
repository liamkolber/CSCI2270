//Liam Kolber
//Assignment 10
//CSCI 2270
//Instructor: Jacobson
#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.h"
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int menu(){ //creating the proper menu output for the user to interact with
    int userinput;
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Find a movie"<<endl;
    cout<<"2. Rent a movie"<<endl;
    cout<<"3. Print the inventory"<<endl;
    cout<<"4. Delete a movie"<<endl;
    cout<<"5. Count the movies"<<endl;
    cout<<"6. Count the longest path"<<endl;
    cout<<"7. Quit"<<endl;
    cin>>userinput;
    return userinput;
}
//--------------------------------------------------------------------------
MovieTree filefunction(char* filename, MovieTree movieinventory){ //reads file, sorts data, and adds node
    string data;
    string line;
    int ranking;
    string title;
    int year;
    int quantity;
    ifstream inFile;
    inFile.open(filename);
    if(inFile.good()){
        while(getline(inFile,line)){
            stringstream ss(line);
            getline(ss,data,',');
            stringstream convert1(data);
            convert1>>ranking;
            getline(ss,title,',');
            getline(ss,data,',');
            stringstream convert2(data);
            convert2>>year;
            getline(ss,data,',');
            stringstream convert3(data);
            convert3>>quantity;
            movieinventory.addMovieNode(ranking,title,year,quantity);
        }
    }
    inFile.close();
    //return the movieinventory so it can follow through through the function
    return movieinventory;
}
//--------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    MovieTree movieinventory;
    movieinventory = filefunction(argv[1], movieinventory);

    int userinput;
    string movietitle;
    while(userinput != 7) {
        userinput = menu();
        if(userinput == 1) { //user chose find movie
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin, movietitle);
            movieinventory.findMovie(movietitle);
        }
        else if(userinput == 2) { //user chose rent movie
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin, movietitle);
            movieinventory.rentMovie(movietitle);
        }
        else if(userinput == 3) { //user chose print inventory
            movieinventory.printMovieInventory();
        }
        else if(userinput == 4) { //user chose delete movie
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin, movietitle);
            movieinventory.deleteMovieNode(movietitle);
        }
        else if(userinput == 5) { //user chose count movies
            cout<<"Tree contains: "<<movieinventory.countMovieNodes()<<" movies."<< endl;
        }
        else if(userinput == 6) { // user chose count path
            cout<<"Longest Path: "<<movieinventory.countLongestPath()<<endl;
        }
        else if(userinput > 7 || userinput <= 0){
            cout<<"Invalid input. Please enter a number between 1 & 7"<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
    movieinventory.DeleteAll();
    return 0;
}
//--------------------------------------------------------------------------