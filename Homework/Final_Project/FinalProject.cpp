//Liam Kolber and Cameron Heppe
//Final Project
//CSCI 2270
//Instructor: Jacobson
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <typeinfo>
using namespace std;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int menu(){ //creating the proper menu output for the user to interact with
    int userinput;
    cout << "======Main Menu======" << endl;
    cout << "1. Query hash table" << endl;
    cout << "2. Quit program" << endl;
    cin>>userinput;
    return userinput;
}
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    HashTable bball;
    int tempNum = atoi(argv[1]);
    bball.tableSize = tempNum;
    int count = 0;

    //prep file reading variables
    string line;
    string yearID,teamID,leagueID,playerID,salary,firstName,lastName,birthYear,birthCountry,weight,height,bats,throws;
    ifstream inFile;
    inFile.open("playerData.txt");
    getline(inFile,line);

    //read in the file
	while (getline(inFile,line)) {
    stringstream ss(line); 
		string dataKey;
		int i = 0;
		while(getline(ss, dataKey, ',')) {
			i++;
			stringstream tempStream(dataKey);
			switch(i) {
				case 1: bball.playerData[i-1] = tempStream.str(); break;
				case 2: bball.playerData[i-1] = tempStream.str(); break;
				case 3: bball.playerData[i-1] = tempStream.str(); break;
				case 4: bball.playerData[i-1] = tempStream.str(); break;
				case 5: bball.playerData[i-1] = tempStream.str(); break;
				case 6: bball.playerData[i-1] = tempStream.str(); break;
				case 7: bball.playerData[i-1] = tempStream.str(); break;
				case 8: bball.playerData[i-1] = tempStream.str(); break;
				case 9: bball.playerData[i-1] = tempStream.str(); break;
				case 10: bball.playerData[i-1] = tempStream.str(); break;
				case 11: bball.playerData[i-1] = tempStream.str(); break;
				case 12: bball.playerData[i-1] = tempStream.str(); break;
				case 13: bball.playerData[i-1] = tempStream.str(); break;
			}
		}
		string playerName = bball.playerData[5]+bball.playerData[6];
		bball.insertRecordChain(playerName,bball.tableSize);
		bball.insertRecordOpen(playerName,bball.tableSize);
	}

	cout << "Oh my God it worked! Praise! *praising hands emoji*" << endl << endl;
	cout << "Hash table size: " << bball.tableSize << endl;
	cout << "Collisions using open addressing: " << bball.openCol << endl;
	cout << "Collisions using chaining: " << bball.chainCol << endl;
	cout << "Search operations using open addressing: " << bball.openSea << endl;
	cout << "Search operations using chaining: " << bball.chainSea << endl;

    //display menu for user
    int userinput;
    while(userinput != 2) {
        userinput = menu();
        if(userinput == 1) {
            string first;
            string last;
            cout << "First name: " << endl;
            cin >> first;
            cout << "Last name: " << endl;
            cin >> last;
            cout << endl;
            string con = first+last;
            bball.chainSea = 0;
            bball.openSea = 0;
            Data* foundChain = bball.searchChain(con);
            Data* foundOpen = bball.searchOpen(con);
            bball.printRecords(foundChain,true);
            bball.printRecords(foundOpen,false);
        }
        else if(userinput > 2 || userinput <= 0){
            cout<<"Invalid input. Please enter a 1 or 2"<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
    inFile.close();
    return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
