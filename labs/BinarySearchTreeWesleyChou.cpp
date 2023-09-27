#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
        }
};

class BinarySearchTree{
    public:
    Node* root = nullptr;

    Node* add(Node* current, int data){
        // check if root node is empty
        if (!root){
            current = new Node(data);
            root = current;
        }
        else if (!current)
            return new Node(data);

        else if (data < current->data) // left side of tree
            current->left = add(current->left, data);
            
        else if (data > current->data) // right side of tree
            current->right = add(current->right, data);

        return current;
    }

    void inorder(Node* current){
        if (!current){
            return;
        }
        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }
};


int main(){
    BinarySearchTree bst;

    bst.add(bst.root, 1);
    bst.inorder(bst.root);
    cout << endl;
    bst.add(bst.root, 3);
    bst.inorder(bst.root);
    cout << endl;
    bst.add(bst.root, 2);
    bst.inorder(bst.root);
    cout << endl;
    bst.add(bst.root, 4);
    bst.inorder(bst.root);
    cout << endl;
    bst.add(bst.root, 6);
    bst.inorder(bst.root);
    cout << endl;
    bst.add(bst.root, 7);
    bst.inorder(bst.root);
    cout << endl;
    bst.add(bst.root, 5);
    bst.inorder(bst.root);
    cout << endl;
}