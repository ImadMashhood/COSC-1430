#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DynamicArray{

  int *arr;
  int arraySize;
  int numOfElements;

public:

   DynamicArray(int arraySize){
      if (arraySize<1)
        arraySize = 1;
      arr = new int[arraySize];
      numOfElements = 0;
   }

   DynamicArray( const DynamicArray &a ){

     arraySize = a.arraySize;
     arr = new int[arraySize];
     for (int i = 0; i < arraySize; i++) {
       arr [i] = a.arr[i];
     }
     numOfElements = a.numOfElements;
   }

   int getArraySize(){
     return arraySize;
   }

   int getNumOfElements(){
     return numOfElements;
   }

   string print(){

     string printTxt = "No element"

     if(numOfElements > 0){

       printTxt = " "

       for (int i = 0; i < arraySize; i++) {
         stringstream ss;
         ss << arr[i];
         string converter = ss.str();
         printTxt = printTxt+converter;
         if (i < numOfElements-1) {
           printTxt = printTxt+ ", ";
         }
       }
     }
     return printTxt;
   }

   























}
