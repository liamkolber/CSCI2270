//Liam Kolber
//Recitation 3
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;



//array doubling funciton
int *ArrayDynamicAllocation(int array[], int size, int number) {
	for(int k=0;k<number;k++){
		int* array2 = new int[size*2];
		for(int i=0;i<size;i++) {
			array2[i] = array[i];
			array2[i+size] = 2*array[i];
		}
		size = size*2;
		delete[] array;
		array = array2;
	}
	return array;
}


int main() {
	return 0;
}