#include <iostream>

using namespace std;

class Node {
   public:
   int key;
   string value;
   Node* next = 0;

   Node(int k, string v){
      key = k;
      value = v;
   }
};

class LinkedList {
   public:
   Node* head = 0;

   void add_node(int key, string value){
      Node* temp = new Node(key, value);
      temp->next = head;
      head = temp;
   }

   void delete_node(){
      int a = 0;
   }

   void print_ll(){
      Node* temp = head;
      while(temp){
         cout << temp->value << ", ";
         temp = temp->next;
      }
   }

};

class HashTable {
   private:
   LinkedList hash_table[3];

   int hash(int key){
      return key % 3;
   }

   public:
   void add(int key, string value){
      int hashed = hash(key);
      hash_table[hashed].add_node(key, value);
   }

   void lookup(int key){
      int hashed = hash(key);
      cout << hash_table[hashed].head->value;
   }

   void del(int key){
      int hashed = hash(key);
      hash_table[hashed].head = 0;
   }

   void print_ht(){
      for(int i = 0; i < 3; i++){
         cout << i << " - ";
         hash_table[i].print_ll();
         cout << endl;
      }
   }

};

int main(){
   HashTable ht;
   int user_input;
   int key;
   string value;

   do {
      cout << "1 - add\n2 - lookup\n3 - delete\n4 - print\n0 - quit" << endl;
      cin >> user_input;

      switch(user_input){
         case 1:
            cout << "key: ";
            cin >> key;
            cout << "value: ";
            cin >> value;
            ht.add(key, value);
            break;
         case 2:
            cout << "key: ";
            cin >> key;
            cout << "found: ";
            ht.lookup(key);
            break;
         case 3:
            cout << "key: ";
            cin >> key;
            ht.del(key);
            break;
         case 4:
            ht.print_ht();
            break;
      }
      cout << endl;
   } while (user_input != 0);
}