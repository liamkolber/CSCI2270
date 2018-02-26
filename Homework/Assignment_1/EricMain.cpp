#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct wantSellList{
    string item;
    int saleOrWant;  //treating this part of struct as boolean or integer (0 & 1 representing sale or want - 0 is)
    int price;
};

int itemMatch(wantSellList readLine, wantSellList itemArray[], int &counter, int &arraySize ){
    for(int index = 0; index < 100; index ++){
        counter ++;
        if((readLine.item == itemArray[index].item) && (readLine.saleOrWant != itemArray[index].saleOrWant)){
            if((readLine.saleOrWant == 1) && (readLine.price >= itemArray[index].price)){ //readline = want, item = sale, want <= sale
                return index; // index is a match >= 0
            }
            else if((readLine.saleOrWant == 0) && (readLine.price <= itemArray[index].price)){
                return index;
            }
        }
    }
    return -1; // -1 is not a match
}

void arrayDelete (wantSellList itemArray[], int z, int &counter, int &arraySize ){
    for(z; z < 100; z++){
        counter ++;
        if(itemArray[z].item == ""){ 
            break;
        }
        itemArray[z].item = "";
        itemArray[z] = itemArray[z+1];
        arraySize --;
    }
}

int main(int argc, char* argv[]) {
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

    while(inFile.good()){
        counter ++;
        string s;
        if (!getline(inFile,s)) break;

        istringstream ss(s);

        if (!getline(ss,s,',')) {break;}
        readLine.item = s;
        if (!getline(ss,s,',')) {break;}
        readLine.saleOrWant = (s == " wanted") ? 1 : 0;
        if (!getline(ss,s,',')) {break;}
        //converting string to integer
        stringstream convert(s);
        convert>>readLine.price;

        matchIndex = itemMatch(readLine, itemArray, counter, arraySize);
        if(matchIndex >= 0){
            if(readLine.saleOrWant == 0) { cout<<readLine.item<<" "<<readLine.price<<endl;}
            else{ cout<<itemArray[matchIndex].item<<" "<<itemArray[matchIndex].price<<endl; }
            arrayDelete(itemArray, matchIndex, counter, arraySize);
        }
        else{
            itemArray[x] = readLine;
            arraySize ++;
        }
        x++;
    }
    if(!inFile.eof()){
        cout<<"file not read correctly"<<endl;
    }

    inFile.close();

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
