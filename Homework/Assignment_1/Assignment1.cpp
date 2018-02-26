//Liam Kolber
//Assignment 1
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

//--------------------------------------------------------------------------
//this is the struct that I use through my program to hold sale item info
struct item { 
	string object; //type of item
	int ask; //wanted or for sale
	int price; //price (obvi)
};
//--------------------------------------------------------------------------
//this is the function that shifts the array after a match has been made
void arrayRemoval(item listedItem[], int ind, int &shiftCounter, int &length, int &index) {
	for (int j=ind; j < length; j++) {
		if (listedItem[j].object == "") { //this checks to ensure the end of the filled array has been reached
			break; //ABORT!!! I REPEAT: ABORT!!!
		}
		shiftCounter++;
	    listedItem[j] = listedItem[j+1]; //this does the shifting
	}
	shiftCounter--;
	length--;
	index--;
}
//--------------------------------------------------------------------------
//this is the function that finds the index at which a match has been made
int matchFinder(item product, item array[], int &searchCounter, int &length) {
	for (int i=0; i < length; i++) {
		searchCounter++;
		if ((array[i].object == product.object) && (array[i].ask != product.ask)) { //these conditions check for proper match
			if ((array[i].ask) && (array[i].price >= product.price)) {
				return i; //yay match!
			}
			else if ((!array[i].ask) && (array[i].price <= product.price)) {
				return i; //yay match!
			}
		}
	}
	return -1; //no match :( le cry
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main() {
	//ALRIGHT BOYS LET'S DO THIS
	//LEEROYYYYYY JEEEENKINNNNNS
	string filename;
	cin >> filename; //get input from the user

	ifstream readIn;
	readIn.open(filename);
	item product;
	item listedItem[100]; //known max number of items is 100 so this can be initialized

	//boring junk that's only kinda sorta extremely necessary to count anything properly
	int searchCounter = 0; //counts number of times the array is searched
	int fileCounter = 0; //counts number of items in the file
	int shiftCounter = 0; //counts number of times a shift is made
	int index = 0;
	int length = 0;

	while (readIn.good()) { //where the magic happens *wink wink*
		string data;
		istringstream iss(data); //stringstream variable for easier manipulation

		if (!getline(readIn,data,',')) {break;}
		product.object = data; //this holds the type of item
		if (!getline(readIn,data,',')) {break;}
		product.ask = (data == " wanted") ? 1 : 0; //this holds whether it is for sale or wanted
		if (!getline(readIn,data)) {break;}
		istringstream convert(data);
		convert >> product.price; //this converts the string into an int and saves as price

		int match = matchFinder(product,listedItem,searchCounter,length); //call to function
		if (match >= 0) { //basically if there is a match do the thing
            if (product.ask == 0) {
            	cout << product.object << " " << product.price << endl;
            }
            else {
            	cout << listedItem[match].object << " " << listedItem[match].price << endl;
            }
            arrayRemoval(listedItem,match,shiftCounter,length,index); //call to index removal after print of match has been made
		}
		else { //no match was made :( so sad
			listedItem[index] = product; //add the unmatched item to the array
			length++;
			index++;
		}
		fileCounter++;
	}
	//the rest of these lines are the final print statements 
	readIn.close();
	cout << "#" << endl;
    for(int y = 0; y < fileCounter; y++){
    	if(listedItem[y].object != ""){
            cout<<listedItem[y].object<<", "<<((listedItem[y].ask == 1) ? "wanted" : "for sale")<<", "<<listedItem[y].price<<endl;
    	}
    }
    cout << "#" <<endl;
    cout << "file read:" << fileCounter << endl;
    cout << "search array:" << searchCounter << endl;
    cout << "shift array:" << shiftCounter << endl;
	return 0;
}
//yay it compiles
//it's really the little things in life