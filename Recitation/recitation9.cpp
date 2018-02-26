#include <iostream>
//include correct libraries
using namespace std;
//I placed counts in each function where each iteration thorugh the function would take place.
//This is the value that is printed. Select Sort seems to be the most efficient

int quickCnt = 0;
int selectCnt = 0;
int insertCnt = 0;
int bubbleCnt = 0;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
        quickCnt++;
    };
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void selectSort(int arr[], int n) {
  int index_min_value;
  int temp;

  for (int i=0; i<n-1; i++) {
  // outer loop tracks the sorted portion of the list
    index_min_value = i; //set index_min_value to the current index of array
    for (int j=i+1; j < n; j++){ // inner loop finds the next smallest value
      if (arr[j] < arr[index_min_value])
        index_min_value = j;
    }
    if (index_min_value != i) {
      temp = arr[i];
      arr[i] = arr[index_min_value];
      arr[index_min_value] = temp;
    }
    selectCnt++;
  }
}

void insertionSort (int arr[], int length) {
  int j, temp;

  for (int i = 0; i < length; i++)  {
      j = i;
      while (j > 0 && arr[j] < arr[j-1])
      { // move elements over until find the position for next element
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
        insertCnt++;

      }
  }
}

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void bubbleSort(int arr[], int n) {
  int i, j;

  for (i = 0; i < n-1; i++) {// Last i elements are already in place
    for (j = 0; j < n-i-1; j++){
      if (arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
      }
      bubbleCnt++;
    }
  }
}


void printList(int arr[], int length){
  for (int i = 0; i<length; i++){
    cout<<arr[i]<<" ";
  }
  cout << endl;
}

int main(){
  //HINT: You should place a counter into each algorithm to see how many time each of them run. Then you can compare them easier. 
  //You should use the given print statements for better organization. 

  int myArray1[] = {12, 13, 5, 4, 7, 18, 9 };
  int myArray2[] = {12, 13, 5, 4, 7, 18, 9 };
  int myArray3[] = {12, 13, 5, 4, 7, 18, 9 };
  int myArray4[] = {12, 13, 5, 4, 7, 18, 9 };

  cout << endl;
  cout << " ======== Small array ======= " << endl;
  cout << endl;

  cout<<"My original small array is: "<<endl;
  printList(myArray1,7);

  //selectSort
  selectSort(myArray1,7);
  cout<<"When ordered with selectSort, after "<<selectCnt<<" operations the result is: "<<endl;
  printList(myArray1,7);

  //insertionSort
  insertionSort(myArray2,7);
  cout<<"When ordered with insertionSort, after "<<insertCnt<<" operations the result is: "<<endl;
  printList(myArray2,7);

  //bubbleSort
  bubbleSort(myArray3,7);
  cout<<"When ordered with bubbleSort, after "<<bubbleCnt<<" operations the result is: "<<endl;
  printList(myArray3,7);

  //quickSort
  quickSort(myArray4,0,6);
  cout<<"When ordered with quickSort, after "<<quickCnt<<" operations the result is: "<<endl;
  printList(myArray4,7);

  int myArray5[1000];
  int myArray6[1000];
  int myArray7[1000];
  int myArray8[1000];
  for (int i = 0; i < 1000; i++) {
    myArray5[i] = rand() % 100;
    myArray6[i] = rand() % 100;
    myArray7[i] = rand() % 100;
    myArray8[i] = rand() % 100;
  }

  cout << endl;
  cout << " ======== Large array ======= " << endl;
  cout << endl;

  //selectSort
  selectSort(myArray5,1000);
  cout<<"When ordered with selectSort, after "<<selectCnt<<" operations the result is: "<<endl;

  //insertionSort
  insertionSort(myArray6,1000);
  cout<<"When ordered with insertionSort, after "<<insertCnt<<" operations the result is: "<<endl;

  //bubbleSort
  bubbleSort(myArray7,1000);
  cout<<"When ordered with bubbleSort, after "<<bubbleCnt<<" operations the result is: "<<endl;

  //quickSort
  quickSort(myArray8,0,999);
  cout<<"When ordered with quickSort, after "<<quickCnt<<" operations the result is: "<<endl;

  return 0;
}