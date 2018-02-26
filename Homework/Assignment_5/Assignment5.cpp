//Liam Kolber
//Assignment 5
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
struct Connection{ 
//stuct of a city as a struct w/a name, pointer connecting it to next city in network, place to store message being sent
    string city;
    string message;
    Connection *next;
};
//--------------------------------------------------------------------------
int menu() {
    int userinput;
    //creating the proper menu output for the user to interact with
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Delete City"<<endl;
    cout<<"6. Clear Network"<<endl;
    cout<<"7. Quit"<<endl;
    cin>>userinput;
    return userinput;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main() {
    string newCity;
    string previousCity;
    string citytodelete;
    CommunicationNetwork Network;

    int userinput;
    bool flag = true;
    
    //creating a loop that runs the specific desired function based on each menu option and what the user selects to do
    while(flag) {
        userinput = menu();

        if (userinput == 1) {
            Network.buildNetwork();
        }
        else if (userinput == 2) {
            Network.printNetwork();
        }
        else if (userinput == 3) {
            Network.transmitMsg("messageIn.txt");
        }
        else if (userinput == 4) {
            cout<<"Enter a city name: "<<endl;
            cin.ignore(); //the extra cin stuff is to ignore avoid considering spaces in city names as separate cities
            getline(cin, newCity);
            cout<<"Enter a previous city name: "<<endl;
            getline(cin,previousCity);
            cin.sync();
            Network.addCity(previousCity,newCity);
        }
        else if (userinput == 5) {
            cout<<"Enter a city name: "<<endl;
            cin.ignore();
            getline(cin,citytodelete);
            Network.deleteCity(citytodelete);
        }
        else if (userinput == 6) { 
            Network.deleteNetwork();
        }
        else if (userinput == 7) {
        	flag = false;
        }
        else if(userinput > 7 || userinput <= 0) {
            cout<<"invalid input. Please enter a number between 1 & 5"<<endl;
        }
    }

    cout<<"Goodbye!"<<endl;
}
//--------------------------------------------------------------------------