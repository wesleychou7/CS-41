#include <iostream>

using namespace std;

int main(){
   string data;
   cout << "Enter string: ";
   cin >> data;

   string encoded_data = "";

   int count;
   for (int i = 0; i < data.length(); i += count){
      char current = data[i];
      count = 0;
      int j = i;
      while (data[j] == current){
         count++;
         j++;
      }
      encoded_data = encoded_data + to_string(count) + current;
   }

   cout << "encoded string: " << encoded_data << endl;

   float compression_rate = 1.0 - (static_cast<float>(encoded_data.length()) / data.length());
   cout << "compression rate: " << compression_rate * 100 << "%";

   return 0;
}