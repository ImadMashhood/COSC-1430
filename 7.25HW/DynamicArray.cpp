#include <iostream>
#include <string>
#include <sstream>

using namespace std;

  class DynamicArray
  {
    int *arr; //pointer to dynamic array
    int arraySize; //size of array
    int numOfElements; //no of elements actually in the array
    public:
  DynamicArray(int a=1) //constructor
  {
    if(a<1) //set a to 1 if it is less than 1
    a=1;
    arraySize=a; //set the size of the array
    arr=new int[arraySize]; //create the array
    numOfElements=0;
  }

  DynamicArray(const DynamicArray &a) //copy constructor
  {
    arraySize=a.arraySize;
    arr=new int[arraySize];
    for(int i=0;i<a.numOfElements;i++)
    arr[i]=a.arr[i];
    numOfElements=a.numOfElements;
  }

  int getArraySize() //return size of the array
  {
    return arraySize;
  }
  int getNumOfElements() //return no of elements in the array
  {
    return numOfElements;
  }
  string print() //return the array as a formatted string
  {
    string strArr="No Element"; //initialize the string to be returned

    if(numOfElements>0) //if there is data in the array
    {
      strArr=""; //make the return string blank
      for(int i=0;i<numOfElements;i++)
      {
        stringstream ss; //stringstream object to covert int to string
        ss<<arr[i]; //insert the array element into the string stream
        string temp=ss.str(); //convert the element into string
        strArr=strArr+temp; //add this element string into the return string
        if(i<numOfElements-1) //if the current element is not the last element in the array
        strArr=strArr+","; //add a comma to the return string
      } //end for
    } //end if
    return strArr;
  } //end print()

  void addElement(int num) //add num to the array
  {
    if(numOfElements==arraySize) //if array is full
    {
      int *arr1=new int[arraySize*2]; //create a new array, twice the size of the current array
      int i;
      for(i=0;i<arraySize;i++) //copy elements from current array into new array
      arr1[i]=arr[i];
      arraySize*=2; //double the arraySize
      delete arr; //delete the old array
      arr=arr1; //make the new array the current array
  } //end if
    arr[numOfElements++]=num; //add the new element into the array and increment the num of elements counter
  } //end addElement()

  void deleteElement(int num) //delete 1st occurrence of num from the array
  {
    for(int i=0;i<numOfElements;i++) //look for num in the array
    if(arr[i]==num) //if num is found in the array
    {
      for(;i<numOfElements;i++) //remove num by overwriting it by the next element
      arr[i]=arr[i+1]; //overwrite the current element with the next element to fill in the gap(remove num)
      numOfElements--; //decrement the numOfElements counter as one element has been removed from the array
      break; //break out of the for loop as only the 1st occurrence of num needs to be removed
    } //end if
    if(numOfElements<=(arraySize/2)) //if no of elements in the array is <= half its size
    {
      int *arr1=new int[arraySize/2]; //create a new array, half the size of the current array
      int i;
      for(i=0;i<numOfElements;i++) //copy elements from current array into new array
      arr1[i]=arr[i];
      arraySize/=2; //halve the arraySize
      delete arr; //delete the old array
      arr=arr1; //make the new array the current array
    } //end if
  } //end deleteElement()

  ~DynamicArray() //destructor
  {
    delete[] arr;
  }

  void setArraySize(int array_size) //set size of the array
  {
    if(array_size>=numOfElements) //if the new size is >= current no of elements in the array
    {
      int *arr1=new int[array_size]; //create a new array of new size
      for(int i=0;i<numOfElements;i++) //copy elements from current array into new array
      arr1[i]=arr[i];
      arraySize=array_size; //update the arraySize
      delete arr; //delete the old array
      arr=arr1; //make the new array the current array
    } //end if - do nothing if array_size<numOfElements
  } //end setArraySize()

};

int main()
{
  return 0;
}
