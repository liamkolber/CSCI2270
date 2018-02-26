//Eric Speaker
//Assignment 1
//CSCI 2270
//Recitation #: 309

//call the appropriate libraries that you would need for all code
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//creating a struct to read in and use the data. 3 points of interest what item, if it's for sale or wanted & the price
//item is a string because we need to match the word
//for sale or want is a int b/c it's easier to compare sale or want as a 1 or 0  (which the words get converted to later)
//price is an int because its a number
struct wantSellList{
    string item;
    int saleOrWant;  //treating this part of struct as boolean or integer (0 & 1 representing sale or want - 0 is)
    int price;
};

/*
This is a function that is used to match the items / see if the items do match or do not match
If first matches to see if the item matches and the sale/want ints do not match -- want item to match & want a sell to match to a wanted
    The sale/want must not match to make sure a sale doesnt get matched with a sale, etc.
Once those are done it then compares the price
    For the price the price of the WANT MUST BE GREATER THAN OR EQUAL TO THE SALE price
If any of these conditions are not met the for loop (comparison loop) is exited because the items are not a match
The function is an int not void because it's returning a #>=0 if match or a -1 if not a match -- tells the main what to do with the current comparison
*/
int itemMatch(wantSellList readLine, wantSellList itemArray[], int &counter, int &arraySize ){
    for(int index = 0; index < 100; index ++){
            //for(int index = 0; index <= arraySize; index ++){
            counter ++;
            //cout<<"itemmatchloop"<<" "<<counter<<endl;
/*
This was an attempt at optimizing the loop but when this ran my program stopped matching
        if(itemArray[index].item.empty()){
                //cout<<"end of array data"<<endl;
                break;
        }*/
                   //cout<<'\t'<<index<<" "<<itemArray[index].item<<" "<<itemArray[index].saleOrWant<<" "<<itemArray[index].price<<endl;
        if((readLine.item == itemArray[index].item) && (readLine.saleOrWant != itemArray[index].saleOrWant)){
            if((readLine.saleOrWant == 1) && (readLine.price >= itemArray[index].price)){ //readline = want, item = sale, want <= sale
            //cout<<"match"<<endl;
            return index; // index is a match >= 0
            }
            else if((readLine.saleOrWant == 0) && (readLine.price <= itemArray[index].price)){
                return index;
            }
        }
    }
   // cout<<"no match"<<endl;
    return -1; // -1 is not a match
}
/*
This is a function that is created to handle the movement of the array if a match is found and that line item is to be removed from the created array of the want/sell list
This program takes in where in the array the specific row needs to be removed from.
After printing out or moving that line--whatever is necessary --the function then works on deleting the line
It removes the item portion from that line and works everything below it upward b/c you just need a beg. marker for what the line your moving something into
The rest doesnt matter b/c as you move the lower line up it will just overwrite what was there before
Also makes note of what happens if the current line (to move up) has nothing in it
It breaks the function b/c this will save a number of iterations of the loop because we know that once the lines have nothing in them (when moving stuff up) there should be nothing below it besides more "0's"
*/
void arrayDelete (wantSellList itemArray[], int z, int &counter, int &arraySize ){
    for(z; z < 100; z++){
        counter ++;
        //cout<<"arraydelete"<<" "<<counter<<endl;
        if(itemArray[z].item == ""){ break; }
        //set all field to empty string - and can only set first item because that is all you need to test the line --> reduces what the code does
        itemArray[z].item = "";
        //copy lines up
        itemArray[z] = itemArray[z+1];
    arraySize --;
    }
}

//this starts the main function that does reading of the file, initializing some variables and calls other functions created above & prints out a few key final results
int main(int argc, char* argv[])
{
    string data;            //specifies data type for further use later
    wantSellList readLine; //creates a single element of structure (struct) for itemMatch function
    int counter;    //creates the counter (from the struct) for use in the main function
    wantSellList itemArray[100]; //this creates/initializes the array for use at 100 rows -> as specified in project instructions
    int x = 0;
    int matchIndex; //the row in comparison array(itemArray) that matches the line being read in
    int arraySize = 0;
    //read and open the file
    ifstream inFile;
    inFile.open(argv[1]);

//create a while loop for reading in and converting the specific points of each line.
        while(inFile.good()){
        counter ++;
        //cout<<"main counter"<<" "<<counter<<endl;
        //this is for dealing with reading in the line you are trying to compare
        //the trick is getting it to recognize that the commas are delimiters and not the spaces
        //this must be done through each line section because 2 of the line parts have to be converted to booleans or integers
        string s;
        if (!getline(inFile,s)) break;

        istringstream ss(s);

        if (!getline(ss,s,',')) {break;}
        //next couple lines specify what each portion of the line read in is...first item (element one) is the item, etc.
        readLine.item = s;
        if (!getline(ss,s,',')) {break;}
        //this is an inline if statement -> for specifying want/forsale as a 1 or 0 for comparison when comparing lines
        // 0 is sale, 1 is want
        readLine.saleOrWant = (s == " wanted") ? 1 : 0;
        if (!getline(ss,s,',')) {break;}
        //converting string to integer
        stringstream convert(s);
        convert>>readLine.price;
        //cout<<readLine.item<<" "<<readLine.saleOrWant<<" "<<readLine.price<<endl;
        //cout<<x<<" "<<itemArray[x].item<<" "<<itemArray[x].saleOrWant<<" "<<itemArray[x].price<<endl;

        //call the item match function and run what to do with each circumstance found within the function --> what to print or what to put where
        matchIndex = itemMatch(readLine, itemArray, counter, arraySize);
        //cout<<'\t'<<matchIndex<<" "<<readLine.item<<" "<<readLine.saleOrWant<<" "<<readLine.price<<endl;
        if(matchIndex >= 0){//function call
            //this if else is used for how the output should be printed in the window
            //considering each case if what you have is a sale or want
            if(readLine.saleOrWant == 0) { cout<<readLine.item<<" "<<readLine.price<<endl;}
            else{ cout<<itemArray[matchIndex].item<<" "<<itemArray[matchIndex].price<<endl; }
            //call the array delete function and complete the delete/moving of the array if the itemMatch came back with the specific result
            arrayDelete(itemArray, matchIndex, counter, arraySize);
        }
        else{
            //insert current line into itemArray
            itemArray[x] = readLine;
            arraySize ++;
        }
        //incriment the counter used for specifying the location in the array?
        x++;
    }
    if(!inFile.eof()){
        cout<<"file not read correctly"<<endl;
    }
        //close the file
inFile.close();

//have a few extra lines for the final output for readability
cout<<"#"<<endl;
//FINAL PRINT FOR CODE!!!!!!!!
    for(int y = 0; y < x; y++){
    if(itemArray[y].item != ""){
            cout<<itemArray[y].item<<" "<<((itemArray[y].saleOrWant == 1) ? "wanted" : "for sale")<<" "<<itemArray[y].price<<endl;
    }
    }
    cout<<"#"<<endl;
    cout<<"loop iterations:"<<counter<<endl;
}
