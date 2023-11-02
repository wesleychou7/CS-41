#include <iostream>

using namespace std;

class HashTable{
   private:
   int nums[27] = {0};

   public:
   int Hash(int num){
      return num % 27;
   }

   void Add(int num){
      int index = Hash(num);

      while(nums[index])
         index++;

      nums[index] = num;
   }

   int Lookup(int num){
      for (int i = 0; i < 27; i++){
         if (nums[i] == num)
            return i;
      }
      return -1;
   }
};

int main(){
   int nums[27];
   HashTable ht;

   cout << "Enter 1 to add number, 2 to lookup a number, or 3 to exit: ";
   int choice;
   cin >> choice;
   while (choice != 3){
      if (choice == 1){
         int num;
         cout << "Number to add: ";
         cin >> num;
         ht.Add(num);
         cout << "Added " << num << endl;
      } 
      else if (choice == 2){
         int num;
         cout << "Number to lookup: ";
         cin >> num;
         int index = ht.Lookup(num);
         if (index != -1)
            cout << num << " is at index " << ht.Lookup(num) << endl;
         else
            cout << "Number not found" << endl;
      } 
      cout << "\nEnter 1 to add number, 2 to lookup a number, or 3 to exit: ";
      cin >> choice;
   }
}