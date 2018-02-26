//Liam Kolber
//Assignment 6
//CSCI 2270
//Instructor: Jacobson
//--------------------------------------------------------------------------
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int menu() { //the menu obvi
    int userinput;
    //creating the proper menu output for the user to interact with
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Enqueue word"<<endl;
    cout<<"2. Dequeue word"<<endl;
    cout<<"3. Print queue"<<endl;
    cout<<"4. Enqueue sentence"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>userinput;
    return userinput;
}
//--------------------------------------------------------------------------
int main() {
    int userinput;
    bool flag = true; //to know when to exit upcoming loop
    Queue queue(10);
    string word;
    string line;
    stringstream sentence;

    while(flag) { //collect user input
        userinput = menu();

        if (userinput == 1) {
        	cin >> word;
        	cout << "word: ";
        	queue.enqueue(word);
        }
        else if (userinput == 2) {
        	queue.dequeue();
        }
        else if (userinput == 3) {
        	queue.printQueue();
        }
        else if (userinput == 4) {
        	cin.clear(); // for multi-word input
        	cin.ignore();
        	getline(cin, line);
        	cout << "sentence: ";//<< line <<endl;
        	sentence.str(line);
        	while (sentence >> word) {
        		queue.enqueue(word);
            }
        }
        else if (userinput == 5) {
        	flag = false;
        }
    }
    cout << "Goodbye!"  <<endl;
    return 0;
}
//--------------------------------------------------------------------------