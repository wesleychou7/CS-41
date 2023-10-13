#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    int points;
    map<char, int> label_map = {}; // e.g. {{'A', 0}, {'B', 1}}

    // get user input
    cout << "How many vertices? ";
    cin >> points;

    char label;
    char label_arr[points]; // e.g. {'A', 'B', 'C', ...}

    for (int i = 1; i <= points; i++){
        cout << "What is the label for vertex " << i << "? ";
        cin >> label;
        label_map.insert({label, i-1});
        label_arr[i-1] = label;
    }
    cout << endl;

    // initialize matrix
    bool matrix[points][points];
    // set all entries in matrix to false
    for (int i = 0; i < points; i++){
        for (int j = 0; j < points; j++){
            matrix[i][j] = false;
        }
    }

    // define edges
    cout << "Define an edge by listing a pair of vertices, or -1 to stop." << endl;
    
    char first_char, second_char;
    cin >> first_char >> second_char;
    while (first_char != '-' && second_char != '1'){
        matrix[label_map[first_char]][label_map[second_char]] = true;
        cout << "Added Edge " << first_char << "->" << second_char << endl;
        cin >> first_char >> second_char;
    }
    cout << endl;

    // print edges
    cout << "Your edges are: ";
    for (int i = 0; i < points; i++){
        for (int j = 0; j < points; j++){
            if (matrix[i][j])
                cout << label_arr[i] << label_arr[j] << ", ";
        }
    }

}