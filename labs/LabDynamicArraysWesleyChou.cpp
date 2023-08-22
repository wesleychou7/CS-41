#include <iostream>

using namespace std;

int main() {
  cout << "Array size? ";
  
  int size;
  cin >> size;

  int* numbers = new int[size];

  // get inputs for array
  for (int i = 0; i < size; i++){
    cout << "Enter number: ";
    cin >> numbers[i];
    if (numbers[i] == -1){
      break;
    }
  }

  // print array
  for (int i = 0; i < size; i++){
    cout << numbers[i] << endl;
  }
  
  return 0;
}