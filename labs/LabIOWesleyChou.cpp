#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  string sentence;
  string word;
  cout << "Enter sentence: ";
  getline(cin, sentence);
  stringstream stream;
  stream.str(sentence);
  while (stream >> word){
    cout << word << endl;
  }
  return 0;
}