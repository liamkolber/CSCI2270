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
//the constructor and destructor of the class
CommunicationNetwork::CommunicationNetwork() {
    //ctor
}

CommunicationNetwork::~CommunicationNetwork() {
    //dtor
}

//creating a class that adds a city somewhere in the linked list depending on user inputs of where they want it
void CommunicationNetwork::addCity(string previousCity, string newCity){
//initially setting the current city equal to the first city in the list
    City *currentCity = head;
//creating the 'node' for the created city and setting the "parameters of it"
    City *createdCity = new City;
    createdCity->cityName = newCity;
    createdCity->next = NULL;
//setting an if statement to account if the new city is suppose to go as the head
    if(previousCity == "First"){
        //linking the new city the what was originally the head city and then inserting the new city as the head
        head = createdCity;
    }
    else{
        while(currentCity != tail) {
            //loop to make sure that the previous city insert is found in the current linked list and then insert the city into the proper place of the l.list once that place is found
            if(currentCity->cityName == previousCity){

                createdCity->next = currentCity->next;
                currentCity->next = createdCity;
                break;
            }
                currentCity = currentCity->next;
        }
    }
}
//function to build the network of given original cities in their proper order:
//L.A -> phoenix -> denver -> dallas -> St. Louis -> Chicago-> Atlanta -> D.C. -> New York -> Boston -> NULL
//have to create the node for each city and set its output name and what node it connects to
void CommunicationNetwork::buildNetwork(){

    City *LosAngeles = new City;
    LosAngeles->cityName = "Los Angeles";

    City *Phoenix = new City;
    Phoenix->cityName = "Phoenix";
    LosAngeles->next = Phoenix;

    City *Denver = new City;
    Denver->cityName = "Denver";
    Phoenix->next = Denver;

    City *Dallas = new City;
    Dallas->cityName = "Dallas";
    Denver->next = Dallas;

    City *StLouis = new City;
    StLouis->cityName = "St. Louis";
    Dallas->next = StLouis;

    City *Chicago = new City;
    Chicago->cityName = "Chicago";
    StLouis->next = Chicago;

    City *Atlanta = new City;
    Atlanta->cityName = "Atlanta";
    Chicago->next = Atlanta;

    City *Washington = new City;
    Washington->cityName = "Washington, D.C.";
    Atlanta->next = Washington;

    City *NewYork = new City;
    NewYork->cityName = "New York";
    Washington->next = NewYork;

    City *Boston = new City;
    Boston->cityName = "Boston";
    NewYork->next = Boston;

    Boston->next = NULL;
//set the head and the tail of the linked list
    head = LosAngeles;
    tail = NULL;
    printNetwork();
}

//function created to be able to transmit a message from a text file through the linked list 1 word at a time and delete that word after it leaves the city
void CommunicationNetwork::transmitMsg(char *fileName){
    City *current = head;
    City *prior = new City;
    if(head == NULL){
        cout<<"Empty List"<<endl;
    }
//reading in the file and capturing each word to run through the list
    else{
        string word;
        ifstream inFile;
        inFile.open(fileName); //read in file
        if (inFile.good()) {
            while(inFile >> word){
                current = head;
//outprint that the city has received the message and the word it receives then moving the city of reference & passing the word to that city then deleting the word from the old city
                while(current->next != NULL) {
                    current->message = word;
                    cout<<current->cityName<<" received "<<current->message<<endl;
                    prior = current;
                    current = current->next;
                    prior->message = "";
                }
                if (current->next == NULL) {
                    current->message = word;
                    cout<<current->cityName<<" received "<<current->message<<endl;
                    prior = current;
                    current = head;
                    prior->message = "";
                }
            }
        }
    }
}
//creating a function to print out the network created in an above function
void CommunicationNetwork::printNetwork(){

    City *print = head;
    cout<<"===CURRENT PATH==="<<endl;
    while(print->next != NULL) {
        cout<<print->cityName<<" -> ";
        print = print->next;
    }
    if (print->next == NULL) {
    	cout << print->cityName << " -> ";
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;

}