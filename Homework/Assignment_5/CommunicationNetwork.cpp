#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
CommunicationNetwork::CommunicationNetwork() {
    //ctor
}
//--------------------------------------------------------------------------
CommunicationNetwork::~CommunicationNetwork() {
    deleteNetwork();
}
//--------------------------------------------------------------------------
//creating a class that adds a city somewhere in the linked list depending on user inputs of where they want it
void CommunicationNetwork::addCity(string previousCity, string newCity){
    //initially setting the current city equal to the first city in the list
    City *currentcity = head;
    //creating the 'node' for the created city and setting the "parameters of it"
    City *createdCity = new City;
    createdCity->cityName = newCity;
    createdCity->next = NULL;
    createdCity->previous = NULL;
    //setting an if statement to account if the new city is suppose to go as the head
    if(previousCity == "First"){
        //linking the new city the what was originally the head city and then inserting the new city as the head
        createdCity->next = head;
        createdCity->next->previous = createdCity;
        head = createdCity;
    }
    else{
        while(currentcity != NULL) {
            //loop to make sure that the previous city insert is found in the current linked list and then insert the city into the proper place of the l.list once that place is found
            if(currentcity->cityName == previousCity){
                createdCity->next = currentcity->next;
                createdCity->previous = currentcity;
                currentcity->next = createdCity;
                if(createdCity->next != NULL){
                    createdCity->next->previous = createdCity;
                }
                break;
            }
                currentcity = currentcity->next;
        }
        //output to tell the user that their input was not found, to cover if this happens
        if(currentcity == NULL){
            cout<<"Your previous city has not been found. Please try again."<<endl;
        }
    }
}
//--------------------------------------------------------------------------
//function to build the network of given original cities in their proper order
void CommunicationNetwork::buildNetwork() {
    City *LosAngeles = new City;
    LosAngeles->cityName = "Los Angeles";
    LosAngeles->previous = NULL;

    City *Phoenix = new City;
    Phoenix->cityName = "Phoenix";
    LosAngeles->next = Phoenix;
    Phoenix->previous = LosAngeles;

    City *Denver = new City;
    Denver->cityName = "Denver";
    Phoenix->next = Denver;
    Denver->previous = Phoenix;

    City *Dallas = new City;
    Dallas->cityName = "Dallas";
    Denver->next = Dallas;
    Dallas->previous = Denver;

    City *StLouis = new City;
    StLouis->cityName = "St. Louis";
    Dallas->next = StLouis;
    StLouis->previous = Dallas;

    City *Chicago = new City;
    Chicago->cityName = "Chicago";
    StLouis->next = Chicago;
    Chicago->previous = StLouis;

    City *Atlanta = new City;
    Atlanta->cityName = "Atlanta";
    Chicago->next = Atlanta;
    Atlanta->previous = Chicago;

    City *Washington = new City;
    Washington->cityName = "Washington, D.C.";
    Atlanta->next = Washington;
    Washington->previous = Atlanta;

    City *NewYork = new City;
    NewYork->cityName = "New York";
    Washington->next = NewYork;
    NewYork->previous = Washington;

    City *Boston = new City;
    Boston->cityName = "Boston";
    NewYork->next = Boston;
    Boston->previous = NewYork;

    Boston->next = NULL;

    //set the head and the tail of the linked list
    head = LosAngeles;
    tail = Boston;
    printNetwork();
}
//--------------------------------------------------------------------------
//function created to be able to transmit a message from a text file through the linked list 1 word at a time and delete that word after it leaves the city
void CommunicationNetwork::transmitMsg(char *fileName){
    City *currentcity = head;
    City *priorcity;
    if(head == NULL) { //just some error checking
        cout << "Empty List" << endl;
    }
    //reading in the file and capturing each word to run through the list
    else {
        string data;
        ifstream inFile;
        inFile.open(fileName);
        if (inFile.good()) {
            while(getline(inFile,data)) { //read through the datafile
                stringstream ss(data);
                string textword;
                while(ss >> textword) {
                    currentcity = head;
                    //outprint that the city has received the message and the word it receives
                    while(currentcity != tail) { //send message out
                        currentcity->message = textword;
                        cout << currentcity->cityName << " received " << currentcity->message << endl;
                        priorcity = currentcity;
                        currentcity = currentcity->next;
                        priorcity->message = "";
                    }
                    while(currentcity != NULL) { //send message back
                        currentcity->message = textword;
                        cout << currentcity->cityName << " received " << currentcity->message << endl;
                        priorcity = currentcity;
                        currentcity = currentcity->previous;
                        priorcity->message = "";
                    }
                }
            }
        }
    }
}
//--------------------------------------------------------------------------
//creating a function to print out the network created in an above function
void CommunicationNetwork::printNetwork(){
    if (head == NULL) { //in case a call is made with an empty network
        cout<<"===CURRENT PATH==="<<endl;
        cout << "NULL" << endl;
        cout<<"=================="<<endl;
    }
    else {
        City *currentcity = head;
        cout<<"===CURRENT PATH==="<<endl;
        cout<<"NULL <- ";
        while(currentcity != NULL) {
            cout<<currentcity->cityName;
            if(currentcity->next != NULL){
                cout<<" <-> ";
            }
            currentcity = currentcity->next;
        }
        cout<<" -> NULL"<<endl;
        cout<<"=================="<<endl;
    }
}
//--------------------------------------------------------------------------
//this is a function created to be able to delete a single node from the linked list & also give the user feedback if the city was not found
void CommunicationNetwork::deleteCity(string cityToDelete) {
    City *currentcity = head;
    while(currentcity != NULL) { //let's delete a city
        if(currentcity->cityName == cityToDelete) {
            if(currentcity->previous == NULL) { //the deleting city is first in the list
                head = currentcity->next;
                currentcity->next->previous = NULL;
            }
            else {
                currentcity->previous->next = currentcity->next;
                if(currentcity->next == NULL) { //the deleteing city is last in the list
                    tail = currentcity->previous;
                    currentcity->previous->next = NULL;
                }
                else {
                    currentcity->next->previous = currentcity->previous;
                }
            }
            delete currentcity;
            break;
        }
        currentcity = currentcity->next;
    }
}
//--------------------------------------------------------------------------
//this is a function created to be able to delete the entire network of nodes created in the linked list
void CommunicationNetwork::deleteNetwork() {
    City *currentcity = head;
    tail = NULL;
    while(currentcity != NULL) {
        cout << "deleting " << currentcity->cityName << endl;
        head = currentcity->next;
        delete currentcity;
        currentcity = head;
    }
    head = NULL;
}
//--------------------------------------------------------------------------