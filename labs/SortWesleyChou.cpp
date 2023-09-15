#include <iostream>

using namespace std;

void insertionSort(int arr[], int size){
    int current, j;

    for (int i = 1; i < size; i++) {
        current = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}


int main(){
    int my_arr[8] = {4, 2, 9, 1, -6, -2, 1, 7};
    int size = 8;

    insertionSort(my_arr, size);

    for(int a : my_arr) cout << a << " ";
} 

