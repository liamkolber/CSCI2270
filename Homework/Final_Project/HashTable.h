#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
struct Data {
  string key;
  string yearID,teamID,leagueID,playerID,salary,firstName,lastName,birthYear,birthCountry,weight,height,bats,throws;
  Data *next;
  Data *previous;
};

class HashTable {
  public:
    HashTable();
    ~HashTable();
    int tableSize;
    int duplicate = 0;
    int chainCol = 0;
    int openCol = 0;
    int chainSea = 0;
    int openSea = 0;
    void insertRecordChain(string key, int tableSize);
    void insertRecordOpen(string key, int tableSize);
    int hashSum(string key, int tableSize);
    Data* searchChain(string key);
    Data* searchOpen(string key);
    void printRecords(Data* player,bool flag);
    Data* playerRecordChain[30000];
    Data* playerRecordOpen[30000];
    string playerData[13];
    unsigned int hashfunc(const char* str, unsigned int seed);
  protected:
  private:
    HashTable **table;
};

#include "HashTable.cpp"
#endif //HASH_H
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
