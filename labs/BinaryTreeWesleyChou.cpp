#include <iostream>

using namespace std;

class BinaryTree{
    private:
        int arr[10] = {};
        int count = 0;
    public:
        void add(int data){
            if (count < 10){
                arr[count] = data;
                count++;
            }

            preorder();
            cout << endl;
        }

        void preorder(int i = 0){
            if (i < count){
                cout << arr[i] << " ";
                preorder(2 * i + 1);
                preorder(2 * i + 2);
            }
        }
};

int main(){
    BinaryTree binarytree;

    binarytree.add(1);
    binarytree.add(2);
    binarytree.add(3);
    binarytree.add(4);
    binarytree.add(5);
    binarytree.add(6);
    binarytree.add(7);
    binarytree.add(8);
    binarytree.add(9);
    binarytree.add(10);

}