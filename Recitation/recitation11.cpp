#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------------------
class customVector {
  public:
    vector <int>intVec;
    vector <int>::iterator it;
    void printVector();
    void reverseVector();
    void removeAll();
    void removeElement(int n);
    customVector(){};
};
// ----------------------------------------------------------------------
void customVector::printVector() {
  if (intVec.empty()) {
    cout << "Empty vector" << endl;
  }
  else{
    cout << "Elements of Integer Vector: ";
    for (it = intVec.begin(); it != intVec.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }
}

void customVector::reverseVector() {
  reverse(intVec.begin(),intVec.end());
}

void customVector::removeAll() {
  intVec.clear();
}

void customVector::removeElement(int n) {
  intVec.erase(intVec.begin()+n);
}

// ----------------------------------------------------------------------
int main() {
  customVector vec1;
  auto numbers = {1,2,3,4,5,6,7,8};
  for (auto num : numbers){
    vec1.intVec.push_back(num);
  }

  vec1.printVector();

  vec1.reverseVector();
  vec1.printVector();

  vec1.removeElement(4);
  vec1.printVector();

  vec1.removeAll();
  vec1.printVector();

  return 0;
}