#include <iostream>
using namespace std;

int main()
{
   int input;
   int *p1;


   p1 = new int;

   cin >> input;

   *p1 = input;


   //Create new dynamic variable and store its address in p1


   //Get an integer value from keyboard and store it in the dynamic variable p1


   cout << "Value stored in p1" << *p1;

   //Delete p1
   delete p1;
}
