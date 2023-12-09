#include <iostream>
#include <fstream>

using namespace std;

const int TABLESIZE = 17;

class Node {
    public:
    string variableName;
    int data;
    int scope;

    Node* next = 0;

    Node(string vn = " ", int d = 0, int s = 0) {
        variableName = vn;
        data = d;
        scope = s;
    }
};


class HashTable {
    Node** hashTable;

    public:
    HashTable() {
        hashTable = new Node*[TABLESIZE]();
    }

    int hash(string variableName){
      int hashValue = 0;
      for (int i = 0; i < variableName.length(); i++){
        hashValue += static_cast<int>(variableName[i]) * (i + 1);
      }
      return hashValue % TABLESIZE;
    }


    void add(string variableName, int data = 0, int scope = 0) {
        int hashed = hash(variableName);

        if (hashTable[hashed] == nullptr) {
            hashTable[hashed] = new Node(variableName, data, scope);
        } 
        else {
            Node* temp = hashTable[hashed];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(variableName, data, scope);
        }
    }


    void print(string variableName, int scope) {
        int hashed = hash(variableName);
        Node* temp = hashTable[hashed];
        
        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << variableName << " is UNDEFINED" << endl;
        } 
        else if (temp->variableName == variableName && temp->scope <= scope) {
            cout << temp->variableName << " is " << temp->data << endl;
        } 
        else {
            cout << variableName << " is UNDEFINED" << endl;
        }
    }


    void calculate(string variableName, int scope, string operation, int num = 0) {
        int hashed = hash(variableName);
        Node* temp = hashTable[hashed];

        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }

        if (temp->variableName == variableName && temp->scope <= scope) {
            if (operation == "=") 
                temp->data = num;
            else if (operation == "++") 
                temp->data++;
            else if (operation == "--") 
                temp->data--;
            else if (operation == "+") 
                cout << temp->variableName << " " << operation << " " << num << " is " << temp->data + num << endl;
            else if (operation == "-") 
                cout << temp->variableName << " " << operation << " " << num << " is " << temp->data - num << endl;
            else if (operation == "*") 
                cout << temp->variableName << " " << operation << " " << num << " is " << temp->data * num << endl;
            else if (operation == "/") 
                cout << temp->variableName << " " << operation << " " << num << " is " << temp->data / num << endl;
            else if (operation == "%") 
                cout << temp->variableName << " " << operation << " " << num << " is " << temp->data % num << endl;
            else if (operation == "^") 
                cout << temp->variableName << " " << operation << " " << num << " is " << pow(temp->data, num) << endl;
        }
    }
};


int main() {
    HashTable hashTable;
    int scope = 0;
    string token;
    string variableName;
    string operation;
    string temp;
    int num;

    ifstream file("HelloWorld.txt");

    while (!file.eof()) {

        if (!temp.empty())
            temp = "";
        else
            file >> token;

        if (token == "COM") {
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore entire line
        } 
        else if (token == "START") {
            scope++;
        }
        else if (token == "FINISH") {
            scope--;
        } 
        else if (token == "VAR") {
            file >> token;
            variableName = token;
            file >> token;
            file >> token;
            num = stoi(token);
            hashTable.add(variableName, num, scope);
        } 
        else if (token == "PRINT") {
            file >> token;
            variableName = token;
            file >> token;
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "^") {
                operation = token;
                file >> token;
                num = stoi(token);
                hashTable.calculate(variableName, scope, operation, num);
            } 
            else {
                hashTable.print(variableName, scope);
                temp = token;
            }
        } 
        else { // token == a variable name
            variableName = token;
            file >> token;
            if (token == "++" || token == "--") {
                hashTable.calculate(variableName, scope, token);
            } 
            else if (token == "=") {
                operation = token;
                file >> token;
                num = stoi(token);
                hashTable.calculate(variableName, scope, operation, num);
            }
        }
    }

    file.close();
    return 0;
}

/*
OUTPUT:

CYBERBEAST is 99990
F150 is UNDEFINED
HORSEPOWER is 845
TORQUE is 10296
RANGE is 320
RANGE + 150 is 470
POTENTIALSAVINGS is 7500
HORSEPOWER is UNDEFINED
*/
