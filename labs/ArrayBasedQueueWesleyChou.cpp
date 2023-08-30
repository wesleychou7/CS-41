#include <iostream>

using namespace std;

class ArrayBasedQueue{
    private:
        const int MAX_SIZE = 10;
        int arr[10] = {};
        int count = 0;
        int front = 0;
        int back = 0;
    public:
        void enqueue(int item){
            if (count == MAX_SIZE){
                cout << "Queue is full, cannot enqueue." << endl;
            }else {
                arr[back] = item;
                count++;
                back++;
                if (back == MAX_SIZE){
                    back = 0;
                }
            }
        }

        int dequeue(){
            if (count == 0){
                cout << "Queue is empty, cannot dequeue" << endl;
                return 0;
            }else{
                int temp = arr[front];

                arr[front] = 0;
                count--;
                front++;
                if (front == MAX_SIZE){
                    front = 0;
                }
                return temp;
            }
        }

        bool isEmpty(){
            return count == 0;
        }

        // for testing purposes
        void printArray(){
            for (int item : arr){
                cout << item << " ";
            }
            cout << endl;
        }
};

int main(){
    ArrayBasedQueue my_arr;
    my_arr.printArray();

    my_arr.enqueue(9);
    my_arr.enqueue(5);
    my_arr.enqueue(4);
    my_arr.printArray();

    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.printArray();

    my_arr.dequeue();
    my_arr.dequeue();

    my_arr.enqueue(9);
    my_arr.enqueue(5);
    my_arr.enqueue(4);
    my_arr.enqueue(8);
    my_arr.enqueue(7);
    my_arr.enqueue(1);
    my_arr.printArray();

    my_arr.enqueue(3);
    my_arr.enqueue(4);
    my_arr.enqueue(2);
    my_arr.printArray();

    my_arr.enqueue(5);
    my_arr.printArray();
    my_arr.enqueue(6);

    my_arr.dequeue();
    my_arr.printArray();

    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.dequeue();
    my_arr.printArray();
}