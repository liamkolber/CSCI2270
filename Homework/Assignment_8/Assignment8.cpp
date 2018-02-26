//Liam Kolber
//Assignment 8
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
int menu(){
    //creating the variable used for the user input
    int userinput;
    //creating the proper menu output for the user to interact with
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Find a movie"<<endl;
    cout<<"2. Rent a movie"<<endl;
    cout<<"3. Print the inventory"<<endl;
    cout<<"4. Delete a movie"<<endl;
    cout<<"5. Count the movies"<<endl;
    cout<<"6. Quit"<<endl;
    cin>>userinput;
    return userinput;
}
//--------------------------------------------------------------------------
//function that reads in a text file and sorts it into its topic with topic specific information
//this function also calls the addmovienode function to create/add the node while it reads the data in
MovieTree filefunction(char* filename, MovieTree movieinventory){
    string data2;
    string data;
    int ranking;
    string title;
    int year;
    int quantity;
    ifstream inFile;
    inFile.open(filename);
    if(inFile.good()){
        while(getline(inFile,data)){
            stringstream ss(data);
            getline(ss,data2,',');
            stringstream convert1(data2);
            convert1>>ranking;
            getline(ss,title,',');
            getline(ss,data2,',');
            stringstream convert2(data2);
            convert2>>year;
            getline(ss,data2,',');
            stringstream convert3(data2);
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
    while(userinput != 6){
        userinput = menu();
        if(userinput == 1){
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin, movietitle);
            movieinventory.findMovie(movietitle);
        }
        else if(userinput == 2){
            cout<<"option 2"<<endl;
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin, movietitle);
            movieinventory.rentMovie(movietitle);
        }
        else if(userinput == 3){
            movieinventory.printMovieInventory();
        }
        else if(userinput == 4){
            cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin, movietitle);
            movieinventory.deleteMovieNode(movietitle);
        }
        else if(userinput == 5){
            cout<<"Tree contains: "<<movieinventory.countMovieNodes()<<" movies."<< endl;
        }
        else if(userinput > 6 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 6"<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
    movieinventory.DeleteAll();
}
//--------------------------------------------------------------------------