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

class SortedLinkedList{
    private:
        Node* front;
        int count = 0;
    public:
        void addNumber(int num){
            Node* temp = new Node(num);
            if (count == 0){
                front = temp;
            }else{
                // first check if front node less than temp node
                if ((front->data) > (temp->data)){
                    temp->next = front;
                    front = temp;
                }
                else{
                    Node* i = front;
                    while((i->next) != 0 && (temp->data) > (i->next->data)){
                        i = i->next;
                    }
                    temp->next = i->next;
                    i->next = temp;
                }
            }
            count++;
        }

        void print(){
            Node* temp = front;
            while(temp != 0){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    SortedLinkedList list;
    int number;
    
    do{
        cout << "Enter a number: ";
        cin >> number;
        if (number != -1){
            list.addNumber(number);
        }
        list.print();
    }while(number != -1);
}