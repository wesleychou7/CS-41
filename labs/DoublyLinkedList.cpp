#include <iostream>

using namespace std;

class Link{
    public:
    int info;
    Link* prev;
    Link* next;
};

class List{
    public:
    Link* head = nullptr;
    Link* tail = nullptr;

    void AddToTail(int data){
        Link* temp = new Link();
        temp->info = data;
        temp->next = nullptr;

        if (head == nullptr){
            head = tail = temp;
            temp->prev = nullptr;
        } 
        else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void AddToHead(int data){
        Link* temp = new Link();
        temp->info = data;
        temp->prev = nullptr;

        if (head == nullptr){
            head = tail = temp;
            temp->next = nullptr;
        } 
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void deleteFromTail(){
        if (head == 0){
            cout << "Can't delete" << endl;
        }
        else if (head == tail){
            Link* temp = head;
            head = tail = nullptr;
            delete temp;
        }
        else {
            Link* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void print(){
        Link* i = head;
        while(i != nullptr){
            cout << i->info << " ";
            i = i->next;
        }
        cout << endl;
    }
};


int main(){
    List a;
    a.AddToHead(5);
    a.print();
    a.AddToHead(10);
    a.print();
    a.AddToHead(15);
    a.print();
}