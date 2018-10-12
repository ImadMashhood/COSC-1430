#include <iostream>
#include <string>
using namespace std;

//------------------------------
// - GROUP 2_8 -   ASSIGNMENT 1
//------------------------------
// - Christian Anacan - 1495051
// - Imad Mashhood - 
// - Mauricio Lozcano - 
//------------------------------

int main()
{

	int *ArraySize; // Size of the array
	ArraySize = new int(2);
	int *CurrentSize;
	CurrentSize = new int(0);
	char choice = 'a'; // by default the selection is 'a' -- For screen selection purposes
	int element; // For option 'a'
	int *Array;
	Array = new int[*ArraySize]; // Starting size of the array is 2
	int elementToDelete; // For option 'd'

	while (choice != 'e')
	{
		cout << "\n";
		cout << "(p) Print Elements \n";
		cout << "(a) Add Element \n";
		cout << "(d) Delete Element \n";
		cout << "(r) Return Size \n";
		cout << "(e) Exit" << endl;
		cout << "\n";
		cout << "Enter Option: ";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 'p':
		{
			//prints elements
			cout << "Elements: ";
			for (int p = 0; p < *CurrentSize; p++)
			{
				cout << Array[p];
				if (p < (*CurrentSize - 1))
				{
					cout << ", ";
				}
			}
			cout << "\n";
			break;
		}
		case 'a':
		{
			//adds elements to the arrays
			cout << "Element to add: ";
			cin >> element;
			if (*CurrentSize == *ArraySize) // checks to see if the array needs to be doubled in size
			{
				*ArraySize = *CurrentSize * 2;
				int* tempArray = new int[*ArraySize];
				for (int y = 0; y < *CurrentSize; y++)
				{
					tempArray[y] = Array[y]; // placeholder
				}
				tempArray[*CurrentSize] = element;
				*CurrentSize = *CurrentSize + 1;
				Array = tempArray;
				cout << "\n" << "Array size expanded to " << *ArraySize << endl; // specified the size of the array. 
			}
			else
			{
				Array[*CurrentSize] = element;
				*CurrentSize = *CurrentSize + 1;
			}
			break;
		}
		case 'd':
		{
			bool found = false;
			cout << "Element to Delete: ";
			cin >> elementToDelete;

			for (int i = 0; i < *CurrentSize; i++) // goes through the entire array to search for element to delete
			{
				if (Array[i] == elementToDelete)
				{
					found = true;
					cout << "Element Deleted." << endl;
					//Array[i] = Array[i + 1];
					for (i = 0; i < *CurrentSize - 1; i++)
					{
						Array[i] = Array[i + i];
					}
					Array[*CurrentSize - 1] = 0;
					*CurrentSize = *CurrentSize - 1;
				}
			}

			if (found == false)
			{
				cout << "Not there" << endl;
			}

			if (*CurrentSize < ((*ArraySize) / 2))
			{
				*ArraySize = *ArraySize / 2; ; // Cuts Array size in half
				cout << "Array Shrinked" << endl;
			}
			//cout << "Array size is now: "; // is this ok? 
			//cout << *ArraySize << endl;
			break;
		}

		case 'r':
		{
			//outputs the current size of the array
			cout << "S: #" << *ArraySize << endl;
			cout << "E: #" << *CurrentSize << endl;
			break;
		}
		default:
			break;
			//exits the while-loop and program
		}
	}
	return 0;
}
