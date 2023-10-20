#include <iostream>

using namespace std;

class Node{
    public:
        string name;
        int weight;
        Node* left;
        Node* right;

        Node(string n, int w){
            name = n;
            weight = w;
        }
};

class BinarySearchTree{
    public:
    Node* root = nullptr;
    int leastWeight;

    Node* add(Node* current, string name, int weight){
        // update least weight 
        if (weight < leastWeight) leastWeight = weight;

        // check if root node is empty
        if (!root){
            current = new Node(name, weight);
            root = current;
            leastWeight = weight; // set least weight
        }
        else if (!current)
            return new Node(name, weight);

        else if (name < current->name) // left side of tree
            current->left = add(current->left, name, weight);
            
        else if (name > current->name) // right side of tree
            current->right = add(current->right, name, weight);

        return current;
    }


    void inorder(Node* current){
        if (!current){
            return;
        }
        inorder(current->left);
        cout << current->name << ", ";
        inorder(current->right);
    }


    void preorder(Node* current){
        if (!current){
            return;
        }
        cout << current->name << ", ";
        preorder(current->left);
        preorder(current->right);
    }


    void postorder(Node* current){
        if (!current){
            return;
        }
        postorder(current->left);
        postorder(current->right);
        cout << current->name << ", ";
    }


    int getHeight(Node* current){
        if (!current){
            return -1; // height of empty tree is -1
        }
        else{
            int leftHeight = getHeight(current->left);
            int rightHeight = getHeight(current->right);

            // compare heights of left and right subtrees
            if (leftHeight > rightHeight)
                return leftHeight + 1;
            else
                return rightHeight + 1;
        }
    }


    int getNumLeaves(Node* current){
        if (!current){
            return 0;
        }
        else if (!current->left && !current->right){ // leaf found
            return 1;
        }
        else{
            return getNumLeaves(current->left) + getNumLeaves(current->right);
        }
    }


    int search(Node* current, string name){
        if (!current){
            return 0;
        }
        else if (name == current->name){ // name found
            return current->weight;
        }
        else if (name < current->name){ // search left side
            return search(current->left, name);
        }
        else { // search right side
            return search(current->right, name);
        }
    }


    int getLeastWeight(){
        return leastWeight;
    }


    string getFirstName() {
        if (!root){
            return "";
        }
        Node* current = root;
        string firstName = root->name;

        while (current) {
            if (current->name < firstName)
                firstName = current->name;

            current = current->left; // only need to go left because BST
        }
        return firstName;
    }
};


int main() {
    BinarySearchTree bst;

    // 1. get user inputs and build tree
    for (int i = 0; i < 15; i++){
        string name;
        int weight;
        cout << "Person " << i+1 << " name: ";
        cin >> name;
        cout << "Person " << i+1 << " weight: ";
        cin >> weight;

        bst.add(bst.root, name, weight);
    }
    cout << endl;

    // 2. execute a preorder traversal
    cout << "Preorder: ";
    bst.preorder(bst.root);
    cout << endl;

    // 3. execute an inorder traversal
    cout << "Inorder: ";
    bst.inorder(bst.root);
    cout << endl;

    // 4. execute a postorder traversal
    cout << "Postorder: ";
    bst.postorder(bst.root);
    cout << endl;

    // 5. Find and print the height of the tree
    cout << "Height: ";
    cout << bst.getHeight(bst.root) << endl;

    // 6. Find and print the number of leaves in the tree
    cout << "Number of leaves: ";
    cout << bst.getNumLeaves(bst.root) << endl;

    // 7. Search for a person by name and print their weight
    string name;
    cout << "Search for a person's weight: ";
    cin >> name;

    int weight = bst.search(bst.root, name);
    if (weight)
        cout << "Weight: " << weight << endl;
    else
        cout << "No match exists." << endl;

    // 8. Find and print the least weight in the tree
    cout << "Least weight: " << bst.getLeastWeight() << endl;

    // 9. Find and print the first name in alphabetical order
    cout << "First name in alphabetical order: " << bst.getFirstName() << endl;

}

/* Output
Person 1 name: Mike 
Person 1 weight: 220
Person 2 name: Brianna
Person 2 weight: 120
Person 3 name: Stephanie
Person 3 weight: 130
Person 4 name: Karl
Person 4 weight: 109
Person 5 name: Roger
Person 5 weight: 199
Person 6 name: Zelda
Person 6 weight: 145
Person 7 name: Chuck
Person 7 weight: 145
Person 8 name: Adam
Person 8 weight: 200
Person 9 name: Ken
Person 9 weight: 170
Person 10 name: Jane
Person 10 weight: 100
Person 11 name: Ian
Person 11 weight: 167
Person 12 name: Dan
Person 12 weight: 90
Person 13 name: Ellen
Person 13 weight: 125
Person 14 name: Hebe
Person 14 weight: 150
Person 15 name: Gabe
Person 15 weight: 300

Preorder: Mike, Brianna, Adam, Karl, Chuck, Jane, Ian, Dan, Ellen, Hebe, Gabe, Ken, Stephanie, Roger, Zelda, 
Inorder: Adam, Brianna, Chuck, Dan, Ellen, Gabe, Hebe, Ian, Jane, Karl, Ken, Mike, Roger, Stephanie, Zelda, 
Postorder: Adam, Gabe, Hebe, Ellen, Dan, Ian, Jane, Chuck, Ken, Karl, Brianna, Roger, Zelda, Stephanie, Mike, 
Height: 9
Number of leaves: 5
Search for a person's weight: Gabe
Weight: 300
Least weight: 90
First name in alphabetical order: Adam

*/