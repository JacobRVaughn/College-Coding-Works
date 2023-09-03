/*
 Your Name

 User will enter a value (size) which represents the number of values to process

 The values entered will be stored in an array of type short that has 1000 elements

 User will enter size numbers

 The array will be sorted using the insertion sort

 The user will enter a search value

 The program will search the data for a specific value

 program will display a message in which element the value was found or display a message the value was not found

 */

#include <iostream>
using namespace std;

// function prototypes
void input_data(short data[], short size);
void insertionSort(short list[], short listLength);
int binarySearch(const short data[], short size, short search_value);

int main(int argc, char **argv) {
	// declare local variables

	int search_again;
    short saSize = 0;
    short saData[1000];
    short sSearchValue;
    short sOffset;

    // input the number of values to store in the array
    cout << "Enter the number of values to store for processing:\n";
    cin >> saSize;

    // call the function to input the data into the array
    input_data(saData, saSize);

	// call the function to sort the data in ascending order
    insertionSort(saData, saSize);

	do  // posttest loop (will execute at least one time)
	{

	  // input a search value
      cout << "Enter a search value:\n";
      cin >> sSearchValue;

	  // call binarySearch function
	  sOffset = binarySearch(saData, saSize, sSearchValue);

	  // display a message to output the element # where search value was found or message value not found
      if (sOffset == -1) {
  		cout << "Sorry the value " << sSearchValue << " was not found.\n";
  	  } else {
  		cout << "The search value " << sSearchValue << " was found at element #" << sOffset << "\n";
      }

	  cout << "To search for another number enter the digit 1 otherwise enter the digit 0 ";

	  cin >> search_again;

	} while(search_again != 0);

	return 0;
}

// function definitions are placed after main
// Do not output anything from these functions
// Function to input(store) data into the array
void input_data(short data[], short size)
{
  for (int i=0; i<size; i++) {
    cout << "Input numeric value "<< i+1 << ":\n";
	cin >> data[i];
  }
};


void insertionSort(short list[], short listLength)
{
	int firstOutOfOrder, location;
	int temp;

	for (firstOutOfOrder = 1; firstOutOfOrder < listLength; firstOutOfOrder++) {
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			temp = list[firstOutOfOrder];
			location = firstOutOfOrder;

			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location -1] > temp);

			list[location] = temp;
		}
	}
}

// Function to search the array using the binary search
int binarySearch(const short data[], short size, short search_value)
{
  int low = 0;
  int high = size;
  while (low <= high) {
	int mid = low + (high - low) / 2;

	if (search_value == data[mid]){
	  return mid;
	}

	if (search_value > data[mid]){
	  low = mid + 1;
	} else if (search_value < data[mid]){
	  high = mid - 1;
	}
  }

  return -1;
};

