//Liam Kolber
//Assignment 3
//CSCI 2270
//Instructor: Jacobson
//--------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "WordAnalysis.h"
using namespace std;
//--------------------------------------------------------------------------
//doubles the size of the array when it fills up
void WordAnalysis::doubleArrayAndAdd(string thing) { 
	int newSize = 2*index;
	word* temp = new word [newSize]; //creates new array of double size

	for(int i = 0; i < index; i++){ //can't forget to move all the stuff from the old array to the new one!
		temp[i] = words[i];
	}
	delete[] words; //lord help the poor student who forgets to free the extra memory
	words = temp;

	//add the new words to the end of the array
	words[index+1].w = thing;
	words[index+1].count = 1;
	timesDoubled++; // gotta count those doubles
}
//--------------------------------------------------------------------------
//checks if the current word in the text is a common word or not
bool WordAnalysis::checkIfCommonWord(string text) { 
	string commonWords[] = {"the", "you", "one", "be", "do", "all", "to", "at", 
	"would", "of", "this", "there", "and", "but", "their", "a", "his", "what", 
	"in", "by", "so", "that", "from", "up", "have", "they", "out", "i", "we", 
	"if", "it", "say", "about", "for", "her", "who", "not", "she", "get", "on", 
	"or", "which", "with", "an", "go", "he", "will", "me", "as", "my"};
	
	for (int i = 0; i < 50; i++) { //compares to each of the common words in the list
		if (commonWords[i] == text) {
			return true; //it's a common word! Blasphemy!
		}
	}

	return false; //yay!
}
//--------------------------------------------------------------------------
void WordAnalysis::sortData() { //as the name literally states, it sorts the array
	int flag = 0; //this flag will be used for the while loop
	word temp; //temp variable for reezuns (loljk it's so I can do a reassignment in the for loop)
	while (flag <= index) {
		for(int j = 0; j < index; j++) {
			//now we go through the actual sorting process
			if (words[j+1].count > words[j].count) {
				temp = words[j];
				words[j] = words[j+1];
				words[j+1] = temp;
			}
		}
		flag++;
	}
}
//--------------------------------------------------------------------------
bool WordAnalysis::readDataFile(char* file) {
	index = 0;
	timesDoubled = 0;
	int j = 100;

	//read in that data cuz what would the world be without the knowledge of 
	//the word count in The Hunger Games? I mean it's truly a treasure of man.
	ifstream readIn;
	string text;
	readIn.open(file);

	//oh god here we go with the word analysis. pray this works.
	if (readIn.good()) {
		while (readIn>>text) {
			if (!checkIfCommonWord(text)) { //check if the word is a common word
				wordCount++; //up that wordCount y'all!
				
				bool flag = false; //this will be used to skip the doubling and word assignment if we've already seen the word before
				for(int i=0; i < index; i++) { //find where the word is if I've already seen it
					if (words[i].w == text) {
						words[i].count++;
						flag = true;
						break; //it exists y'all!
					}
				}
				if (flag) { //the word was already accounted for so continue loop
					continue;
				}
				//guess we haven't seen this word before
				if (index == j){ //no room?? that's not a problem for my handy dandy array doubler!
					doubleArrayAndAdd(text);
					j = 2*index;
				}
				//put the new word at the end of the array
				words[index].w = text;
				words[index].count = 1;
				index++; //let's increment this poorly named variable so we know how many unique words are in the array (and so we know where the end is)
			}
		}
	}
	else { //you done messed up if you get this result
		cout << "File not read properly" << endl;
		return false;
	}

	sortData(); //let's get all that junk sorted properly to make our lives easier when printing
	
	return true;
}
//--------------------------------------------------------------------------
int WordAnalysis::getWordCount() { //this returns the total number of non-common words
	return wordCount;
}
//--------------------------------------------------------------------------
int WordAnalysis::getUniqueWordCount() { //returns number of unique non-common words
	return index;
}
//--------------------------------------------------------------------------
int WordAnalysis::getArrayDoubling() { //returns the number of times the array size is doubled
	return timesDoubled;
}
//--------------------------------------------------------------------------
void WordAnalysis::printCommonWords(int num) { //does the printing of results (obvi)
	for (int i=0; i<num; i++) {
		cout << words[i].count << " - " << words[i].w << endl;
	}
}
//--------------------------------------------------------------------------
WordAnalysis::WordAnalysis(int a) { //intitalizes the first state of the array to be used throughout
	words = new word[a];
	wordCount = a;
}
//--------------------------------------------------------------------------
WordAnalysis::~WordAnalysis() {}