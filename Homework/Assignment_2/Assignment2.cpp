//Liam Kolber
//Assignment 2
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;
//--------------------------------------------------------------------------
//this struct is used to store data about each word and the number of times it appears in the text
struct item {
	int wordcount;
	string word;
};
//--------------------------------------------------------------------------
//this function compares each analyzed word and ensures that it isn't one of the 50 most common
//words in the english language
bool wordCompare(string commonWord[], string text) {
	for (int i = 0; i < 50; i++) {
		if (commonWord[i] == text) {
			return true; //it's a common word! Blasphemy!
		}
	}
	return false; //aight we good
}
//--------------------------------------------------------------------------
//as the name suggests this function checks if the current word being analyzed already exists
//within the array of words already analyzed. If it already does, it return the index
//at which the specific word resides
int doesWordAlreadyExist(item funcgeneralWords[], int length, string text) {
	for(int i=0; i<length; i++) {
		if (funcgeneralWords[i].word == text) {
			return i; //it exists y'all!
		}
	}
	return -1; //boooooooo
}
//--------------------------------------------------------------------------
//after all is said and done this function sorts the final array so that the top n words
//can be displayed easily for the user
void sorting(item funcgeneralWords[], int arrayLength) {
	int flag = 0; //this flag will be used for the while loop
	item temp; //temp variable for reezuns (loljk it's so I can do a reassignment in the for loop)
	while (flag <= arrayLength) {
		for(int j = 0; j < (arrayLength -1); j++) {
			//now we go through the actual sorting process
			if (funcgeneralWords[j+1].wordcount > funcgeneralWords[j].wordcount) {
				temp = funcgeneralWords[j];
				funcgeneralWords[j] = funcgeneralWords[j+1];
				funcgeneralWords[j+1] = temp;
			}
		}
		flag++;
	}
	//phew! now we're all organized -- much better!
}
//--------------------------------------------------------------------------
//because c++ is lazy we have to manually increase the memory allocation for our arrays (i miss python *cries*)
//but yeah this function doubles the size of the array when space is needed
item *arraydoubler(item *funcgeneralwords, int arrayLength){
	int newSize = 2*arrayLength;
	item* functionArray = new item [newSize];
	for(int i = 0; i < arrayLength; i++){ //can't forget to move all the stuff from the old array to the new one!
		functionArray[i] = funcgeneralwords[i];
	}
	delete[] funcgeneralwords; //lord help the poor student who forgets to free the extra memory
	return functionArray; //back to business!
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	//ALRIGHT BOYS LET'S DO THIS
	//LEEROYYYYYY JEEEENKINNNNNS
	
	//first we read in the data (obvi)
	ifstream readIn;
	string text;
	readIn.open(argv[1]);

	//various variables
	string commonWords[] = {"the", "you", "one", "be", "do", "all", "to", "at", 
	"would", "of", "this", "there", "and", "but", "their", "a", "his", "what", 
	"in", "by", "so", "that", "from", "up", "have", "they", "out", "i", "we", 
	"if", "it", "say", "about", "for", "her", "who", "not", "she", "get", "on", 
	"or", "which", "with", "an", "go", "he", "will", "me", "as", "my"}; //bless the student on piazza who made this array for us
	int totalWordCount = 0;
	int arrayLength = 0;
	int indexInArray = 0;
	int timesDoubled = 0;
	int numWordsInArray = 100;
	int wordsToOutput;
	item *generalWords = new item[numWordsInArray];
	stringstream convert(argv[2]);
	convert >> wordsToOutput; //convert that number to an int

	//this is where basically everything happens
	if (readIn.good()) {
		while (readIn>>text) {
			if (!wordCompare(commonWords,text)) { //check if the word is a common word
				indexInArray = doesWordAlreadyExist(generalWords,arrayLength,text); //find where the word is if I've already seen it
				totalWordCount++;
				if (indexInArray >= 0) { //increment the wordcount of the found word
					generalWords[indexInArray].wordcount++;
				}
				else { //guess we haven't seen this word before
					if (arrayLength == numWordsInArray){ //no room?? that's not a problem for my handy dandy array doubler!
						generalWords = arraydoubler(generalWords,numWordsInArray);
						numWordsInArray = 2*numWordsInArray; 
						timesDoubled ++; //gotta know how many times this was necessay
					}
					//put the new word at the end of the array
					generalWords[arrayLength].word = text;
					generalWords[arrayLength].wordcount = 1;
					arrayLength++;
				}
			}
		}
	}
	//sort that ish
	sorting(generalWords,arrayLength);

	readIn.close();

	//print everything in an extremely specific manner because COG is way too picky
	for(int i = 0; i < wordsToOutput; i++){
		cout<<generalWords[i].wordcount<<" - "<<generalWords[i].word<<endl;
	}
	cout<<"#"<<endl;
	cout<<"Array doubled: "<<timesDoubled<<endl;
	cout<<"#"<<endl;
	cout<<"Unique non-common words: "<<arrayLength<<endl;
	cout<<"#"<<endl;
	cout<<"Total non-common words: "<<totalWordCount<<endl;
	
	return 0;
}
//wut
//it worked
//well alrighty then
//PRAISE!!!