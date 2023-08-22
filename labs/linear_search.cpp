#include <iostream>

using namespace std;

int linear_search(int arr[], int size, int target_value){
    for (int i = 0; i < size; i++){
        if (arr[i] == target_value){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[5] = {6, 8, 3, 9, 1};
    int size = 5;

    int target_value;
    cout << "target value: ";
    cin >> target_value;

    cout << linear_search(arr, size, target_value);
}