//Liam Kolber
//Assignment 4
//CSCI 2270
//Instructor: Jacobson
//--------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "CommunicationNetwork.h"
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
struct Connection {
//stuct of a city as a struct w/a name, pointer connecting it to next city in network, place to store message being sent
    string city;
    string message;
    Connection *next;
};

int menu() {
    //creating the variable used for the user input
    int userinput;
    //creating the proper menu output for the user to interact with
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>userinput;
    //cout << userinput<<endl;
    return userinput;
}


int main() {
	//I don't like COG....
    string newCity;
    string previousCity;
    CommunicationNetwork *city = new CommunicationNetwork;

    int userinput;
    //creating a loop that runs the specific desired function based on each menu option and what the user selects to do
    while(userinput != 5) {
        userinput = menu();
        if(userinput == 1){
            city->buildNetwork();
        }
        else if(userinput == 2){
            city->printNetwork();
        }
        else if(userinput == 3){
            city->transmitMsg("messageIn.txt");
        }
        else if(userinput == 4){
            cout<<"Enter a city name: "<<endl;
            cin.ignore(); //this funky fresh syntax is to ignore the space in userinput
            getline(cin, newCity);
            cout<<"Enter a previous city name: "<<endl;
            getline(cin,previousCity);
            cin.sync();
            city->addCity(previousCity,newCity);
        }
        else if(userinput > 5 || userinput <= 0){
            cout<<"invalid input. Please enter a number between 1 & 5"<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}





