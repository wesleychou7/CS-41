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

class LinkBasedStack{
    private:
        Node* top;
        int count = 0;
    public:
        void push(int num){

            Node* temp = new Node(num);

            if (isEmpty()){
                top = temp;
            }else{
                temp->next = top;
                top = temp;
            }
            count++;
        }

        int pop(){
            if (isEmpty()){
                cout << "Stack is empty, cannot pop." << endl;
                return -999;
            }else{
                int return_number = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
                count--;
                return return_number;
            }
        }

        bool isEmpty(){
            return count == 0;
        }

        // for testing purposes
        void printStack(){
            Node* temp = top;
            while(temp != 0){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    LinkBasedStack stack;
    stack.push(5);
    stack.push(7);
    stack.push(2);
    stack.printStack();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.printStack();
    stack.pop();
    stack.push(8);
    stack.push(3);
    stack.pop();
    stack.push(1);
    stack.printStack();
}