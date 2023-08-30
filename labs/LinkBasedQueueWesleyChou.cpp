#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d, Node* n = 0){
            data = d;
            next = n;
        }
};

class LinkBasedQueue{
    private:
        Node *front, *back;
        int count = 0;
    public:
        void enqueue(int num){

            Node* temp = new Node(num);

            if (count == 0){
                front = back = temp;
            }else{
                back->next = temp;
                back = temp;
            }
            count++;
        }

        int dequeue(){
            if (count == 0){
                cout << "Queue is empty, cannot dequeue" << endl;
                return -999;
            }

            Node* temp = front;
            int return_number = front->data;
            front = front->next;
            delete temp;
            count--;
            return return_number;
        }

        bool isEmpty(){
            return count == 0;
        }

        void printQueue(){
            Node* node = front;
            while(node != 0){
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }
};

int main(){
    LinkBasedQueue queue;
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(2);
    queue.printQueue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.printQueue();
    queue.dequeue();
    queue.enqueue(8);
    queue.enqueue(3);
    queue.dequeue();
    queue.enqueue(1);
    queue.printQueue();
}