//Liam Kolber
//Midterm 1 Review
//CSCI 2270
//Instructor: Jacobson

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

//MIDTERM
struct Product{

    int price;

    string name;

};

Product *appendArrays(Product a1[], Product a2[], int aLength1, int aLength2, int *value) {
	Product* combinedArray = new Product [aLength1+aLength2];
	int index = 0;
	for (int i = 0; i < aLength1; i++) {
		if (a1[i].price > *value) {
			combinedArray[index] = a1[i];
			index++; 
		}
	}
	for (int j = 0; j < (aLength2); j++) {
		if (a2[j].price > *value) {
			combinedArray[index] = a2[j];
			index++;
		}
	}
	return combinedArray;
}



int *removeEvens(int *a, int length, int *oddsFound) {
	int odds = 0;
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (a[i]%2 != 0) {
			odds++;
		}
	}
	delete[] oddsFound;
	int* newArray = new int [odds];
		for (int k = 0; k < length; k++) {
			if (a[k]%2 != 0) {
				newArray[index] = a[k];
				index++;
			}
		}
	if (odds == 0) {
		cout << "No odds found." <<endl;
	}
	return newArray;
}












int *removeEvens(int *a, int length, int *oddsFound) {
	int odds = 0;
	for (int i = 0; i < length; i++) {
		if (a[i]%2 != 0) {
			for (int  j = i; j < length; j++) {
				a[j] = a[j+1];
			}
			odds++;
		}
	}
	if (odds == 0) {
		cout << "No odds found." <<endl;
	}
	//*oddsFound = odds;
	return *a;
}






struct Product {
	string pname;
	int price;
};

int ShiftArray(Product arr[],int size,int target) {
	for (int i=0; i<size; i++) {
		if (arr[i].price == target) {
			for (int j = i; j < size; j++) {
				arr[j] = arr[j+1];
			}
			size--;
		}
	}
	return size;
}

string commonRepeatingElement(Product arr[],int length) {
	for (int rose=0; rose<length; rose++) {
		arr[rose].price = 0;
		for (int jennie=0; jennie<length; jennie++) {
			if (arr[jennie].pname == arr[rose].pname) {
				arr[rose].price++;
			}
		}
	}
	Product lisa = arr[0];
	for (int jisoo=0; jisoo<length; jisoo++) {
		if (lisa.price < arr[jisoo].price) {
            lisa = arr[jisoo];
		}
	}
	return lisa.pname;
}

int *CopyArray(int array[], int length, int value) {
	int* APINK= new int [length];
	for (int bomi = 0; bomi<length; bomi++) {
		if (array[bomi] != value) {
			APINK[bomi] = array[bomi];
		}
		if (array[bomi] == value) {
			for (int naeun=0; naeun<length; naeun++) {
				array[naeun] = array[naeun+1];
			}
			bomi--;
		}
	}
	return APINK;
}

int secondLargest(int arr[],int size) {
	for (int nayeon = 0; nayeon < size; nayeon++) {
		if (arr[nayeon] < arr[nayeon+1]) {
			int momo = arr[nayeon];
			for (int mina = nayeon; mina < size; mina++) {
				arr[mina] = arr[mina+1];
			}
			arr[size-1] = momo;
		}
	}
	return arr[1];
}

int main() {
	/*
	Product products[5];
	for (int i = 0; i < 5; i++) {
		products[i].pname = "Product";
		products[i].price = (i+1)*10;
	}
	int size = 5;
	int target = 30;
	cout << ShiftArray(products,size,target);
	*/
	//--------------------------
	/*
	int A[4] = {100,200,300,400};
	// length = 4;
	// value = 200;
	int *r = CopyArray(A,4,200);
	for(int i=0;i<3;i++)
	{
	cout<<r[i]<<" ";
	}
	*/

	return 0;
}