#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Data {
   string key;
   string yearID,teamID,leagueID,playerID,salary,firstName,lastName,birthYear,birthCountry,weight,height,bats,throws;
    Data *next;
    Data *previous; 
};

class Hash {
    public:      
        Hash();
        ~Hash();
        void insertRecord(string key);
        Data* playerRecord[10000];
        string playerData[13];
    protected:
    private:
    	int hashSum(string key, int tableSize);
    	int tableSize;
        
};

#include "HashTable.cpp"
#endif //HASH_H
