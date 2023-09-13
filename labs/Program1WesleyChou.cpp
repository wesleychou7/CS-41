#include <iostream>
#include <sstream>

using namespace std;

class Node{
    public:
        float data;
        Node* next;
        Node(float d, Node* n = 0){
            data = d;
            next = n;
        }
};

class LinkBasedStack{
    private:
        Node* top;
        int count = 0;
    public:
        void push(float num){

            Node* temp = new Node(num);

            if (isEmpty()){
                top = temp;
            }else{
                temp->next = top;
                top = temp;
            }
            count++;
        }

        float pop(){
            if (isEmpty()){
                cout << "Stack is empty, cannot pop." << endl;
                return -999.99;
            }else{
                float return_number = top->data;
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

        int getCount(){
            return count;
        }
};

float calculate(float a, float b, string oper){
    if (oper == "+") return a + b;
    if (oper == "-") return a - b;
    if (oper == "*") return a * b;
    if (oper == "/") return a / b;
    return 999.999;
}

int main(){
    string expression;
    string i;

    do{ 
        // get user input
        cout << "Enter Polish expression: " << endl;
        getline(cin, expression);

        stringstream stream;
        stream.str(expression);

        LinkBasedStack stack;

        // traverse the expression
        while(stream >> i){
            // if i is a number
            try {
                stack.push(stof(i));
            }
            // if i is an operator 
            catch (exception e){
                if (i == "="){
                    float result = stack.pop();

                    // check for too many operands
                    if (!stack.isEmpty()){ 
                        cout << "Error: Too many operands";
                        break;
                    }
                    else cout << result;
                }
                else{
                    // check for too many operators
                    if(stack.getCount() < 2){
                        cout << "Error: Too many operators";
                        break;
                    }

                    float b = stack.pop(), a = stack.pop();

                    // check for zero division
                    if (i == "/" && b == 0){
                        cout << "Error: Division by zero";
                        break;
                    }
                    stack.push(calculate(a, b, i));
                }
            }
        }
        cout << "\n\n";
    }while(expression != "0");
}


/* OUTPUT
Enter Polish expression: 
10 15 + =
25

Enter Polish expression: 
10 15 - =
-5

Enter Polish expression: 
2.5 3.5 + =
6

Enter Polish expression: 
10 0 / =
Error: Division by zero

Enter Polish expression: 
10 20 * / =
Error: Too many operators

Enter Polish expression: 
12 20 30 / =
Error: Too many operands

Enter Polish expression: 
-10 -30 - =
20

Enter Polish expression: 
100 10 50 25 / * - -2 / =
-40

Enter Polish expression: 
0


*/