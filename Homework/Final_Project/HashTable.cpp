#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
HashTable::HashTable(){
    Data* playerRecord = new Data[30000];
	for (int i = 0; i<30000; i++) {
		playerRecord[i].key = "empty";
	}
}
//------------------------------------------------------------------------------
HashTable::~HashTable() {};
//------------------------------------------------------------------------------
void HashTable::insertRecordChain(string key, int tSize) { //algorithms influenced by rhonda's lectures
	//assign values
	int index = hashSum(key,tSize);
	Data* newEntry = new Data;
    newEntry->key = key;
    newEntry->yearID = playerData[0];
	newEntry->teamID = playerData[1];
	newEntry->leagueID = playerData[2];
	newEntry->playerID = playerData[3];
	newEntry->salary = playerData[4];
	newEntry->firstName = playerData[5];
	newEntry->lastName = playerData[6];
	newEntry->birthYear = playerData[7];
	newEntry->birthCountry = playerData[8];
	newEntry->weight = playerData[9];
	newEntry->height = playerData[10];
	newEntry->bats = playerData[11];
	newEntry->throws = playerData[12];
	newEntry->next = NULL;

    //There is an open spot
	if (playerRecordChain[index] == NULL) {
		chainSea++;
		newEntry->previous = NULL;
		playerRecordChain[index] = newEntry;
	}
	//The spot is taken
	else {
		Data* tmp = playerRecordChain[index];
		while (tmp != NULL) { //ignore duplicates
		    if (tmp->playerID == newEntry->playerID) {
		        duplicate++;
		        chainSea++;
		        return;
		    }
		    tmp = tmp->next;
		}
		//time to place the new entry at the end of the linked list
		tmp = playerRecordChain[index];
		while (tmp->next != NULL) {
			chainCol++;
			chainSea++;
		    tmp = tmp->next;
		}
		tmp->next = newEntry;
		newEntry->previous = tmp;
	}
}
//------------------------------------------------------------------------------
void HashTable::insertRecordOpen(string key, int tSize) { //algorithms influenced by rhonda's lectures
	//assign values
	int index = hashSum(key,tSize);
	Data* newEntry = new Data;
  newEntry->key = key;
  newEntry->yearID = playerData[0];
	newEntry->teamID = playerData[1];
	newEntry->leagueID = playerData[2];
	newEntry->playerID = playerData[3];
	newEntry->salary = playerData[4];
	newEntry->firstName = playerData[5];
	newEntry->lastName = playerData[6];
	newEntry->birthYear = playerData[7];
	newEntry->birthCountry = playerData[8];
	newEntry->weight = playerData[9];
	newEntry->height = playerData[10];
	newEntry->bats = playerData[11];
	newEntry->throws = playerData[12];
	newEntry->next = NULL;
	newEntry->previous = NULL;

	//is the spot open?
	if (playerRecordOpen[index] == NULL) {
		openSea++;
		playerRecordOpen[index] = newEntry;
	}
	//no open spot
	else {
		if (playerRecordOpen[index]->key == key ) { //duplicate
			openCol++;
		}
		else {
			//the following loop will taverse until it finds an open spot
			int i = index;
			index++;
			openSea++;
			while (playerRecordOpen[index] != NULL && i != index && playerRecordOpen[index]->key != key) {
				openSea++;
				if (index + 1 == tableSize) { //no more spots, go back to beginning
					index = 0;
				}
				else {
					index++;
				}
			}
			playerRecordOpen[index] = newEntry;
		}
	}
}
//------------------------------------------------------------------------------
int HashTable::hashSum(string key, int tSize) { //algorithms influenced by rhonda's lectures
	int sum = 0;
	for (int i = 0; i < key.length(); i++) {
		sum += key[i];
	}
	if (tSize > 6000) { //this method changes the index values to differ with larger table sizes
		sum = sum*100; //arbitrary
	}
	return sum%tableSize;
}
//------------------------------------------------------------------------------
Data* HashTable::searchChain(string key) { //algorithms influenced by rhonda's lectures
	int index = hashSum(key,tableSize);
	Data* tmp = playerRecordChain[index];
	while (tmp != NULL) { //basic linked list traversal
		chainSea++;
		if (tmp->key == key) {
			return tmp;
		}
		else {
			tmp = tmp->next;
		}
	}
	return NULL;
}
//------------------------------------------------------------------------------
Data* HashTable::searchOpen(string key) { //algorithms influenced by rhonda's lectures
	//the search used here is essentially the same method used in the insert funciton
	//to place the value in the next open spot.
	//Instead of inserting a value, stop when the value is found.
	int index = hashSum(key,tableSize);
	if (playerRecordOpen[index]->key == key) {
		openSea++;
		return playerRecordOpen[index];
	}
	else if (playerRecordOpen[index]->key != key && playerRecordOpen[index] != NULL) {
		int i = index;
		index++;
		while (playerRecordOpen[index]->key != key && i != index && playerRecordOpen[index]->key != key) {
			openSea++;
			if (index + 1 == tableSize) {
				index = 0;
			}
			else {
				index++;
			}
		}
		Data* tmp = playerRecordOpen[index];
		if (playerRecordOpen[index]->key == key) {
			cout << tmp->key << endl;
			return tmp;
		}
	}
	return NULL; //not found :(
}
//------------------------------------------------------------------------------
void HashTable::printRecords(Data* player, bool flag) { //le print
	cout << "First name: " << player->firstName << endl;
	cout << "Last name: " << player->lastName << endl;
	cout << "Year born: " << player->birthYear << endl;
	cout << "Country born: " << player->birthCountry << endl;
	cout << "Weight: " << player->weight << endl;
	cout << "Height: " << player->height << endl;
	cout << "Bats: " << player->bats << endl;
	cout << "Throws: " << player->throws << endl;
	cout << "Teams and salary: " << endl;
	cout << player->yearID << "," << player->teamID << "," << player->leagueID << "," << player->salary;
	cout << endl;
	cout << endl;
	if (!flag) {
		cout << "Search operations using open addressing: " << openSea << endl << endl;
	}
	else {
		cout << "Search operations using chaining: " << chainSea << endl << endl;
	}
}
//------------------------------------------------------------------------------
unsigned int HashTable::hashfunc(const char* str, unsigned int seed) {
    // Based on work of Paul Larson & George V Reilly from Microsoft.
    unsigned int hash = seed;
    while (*str) hash = hash * 101  +  *str++;
    return hash % tableSize;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
