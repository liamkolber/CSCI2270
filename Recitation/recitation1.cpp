#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

void InsertionSort(int array[], int len) {
    int index;
    for (int i=1; i<len; i++){
    	cout << i << endl;
    	index = array[i];
    	int j = i;
    	while (j>0 && array[j-1]>index){
    		array[j] = array[j-1];
    		j--;
    	}
    	array[j] = index;
    	for (int k=0; k<len; k++){
    	    cout << array[k] << " ";
    	}
    	cout << endl;
    }
}

int main() {
	int A[8] = {5,1,3,6,4,8,7,2};
	InsertionSort(A,8);
}