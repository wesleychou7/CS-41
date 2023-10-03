#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    string name;
    int weight;
    Node* name_nextptr;  // next ptr for name
    Node* weight_nextptr;  // next ptr for weight
    Node(string n, int w){
        name = n;
        weight = w;
    }
};

class DoublyLinkedList{
    private:
    Node* name_head = nullptr;  // head node for name
    Node* weight_head = nullptr;  // head node for weight

    public:
    void add(string name, int weight){
        
        Node* new_node = new Node(name, weight);

        // check if head nodes are empty
        if(!weight_head && !name_head){
            weight_head = name_head = new_node;
        } 
        else{
            // adjust name pointers 
            if ((name_head->name) > (new_node->name)){
                new_node->name_nextptr = name_head;
                name_head = new_node;
            }else{
                Node* i = name_head;
                while((i->name_nextptr) != 0 && 
                    (new_node->name) > (i->name_nextptr->name)){
                    i = i->name_nextptr;
                }
                new_node->name_nextptr = i->name_nextptr;
                i->name_nextptr = new_node;
            }

            // adjust weight pointers (same exact code as above, with "name" swapped with "weight")
            if ((weight_head->weight) > (new_node->weight)){
                new_node->weight_nextptr = weight_head;
                weight_head = new_node;
            }else{
                Node* i = weight_head;
                while((i->weight_nextptr) != 0 && 
                    (new_node->weight) > (i->weight_nextptr->weight)){
                    i = i->weight_nextptr;
                }
                new_node->weight_nextptr = i->weight_nextptr;
                i->weight_nextptr = new_node;
            }
            
        }
    }

    void print(){
        // print in names order
        Node* current = name_head;
        cout << "By name: ";
        while(current != 0){
            cout << current->name << " - " << current->weight << ", ";
            current = current->name_nextptr;
        }
        cout << endl;

        // print in weights order
        current = weight_head;
        cout << "By weight: ";
        while(current != 0){
            cout << current->name << " - " << current->weight << ", ";
            current = current->weight_nextptr;
        }
        cout << endl;
    }
};


int main(){
    DoublyLinkedList dll;

    for (int i = 0; i < 15; i++){
        string name;
        int weight;
        cout << "Name: "; 
        cin >> name;
        cout << "Weight: ";
        cin >> weight;
        dll.add(name, weight);
    }
    dll.print();
}

/*
OUTPUT:
By name: Aaron - 195, Alex - 175, Amy - 140, Brandon - 78, Brian - 220, Brian - 250, Eric - 175, Jason - 210, Kim - 135, Laura - 115, Liz - 125, Mark - 150, Steve - 220, Tina - 115, Zach - 55, 
By weight: Zach - 55, Brandon - 78, Laura - 115, Tina - 115, Liz - 125, Kim - 135, Amy - 140, Mark - 150, Eric - 175, Alex - 175, Aaron - 195, Jason - 210, Brian - 220, Steve - 220, Brian - 250,
*/