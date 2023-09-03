/*
 Your Name

 User will enter a value (size) which represents the number of values to process

 The values entered will be stored in an array of type short that has 1000 elements

 User will enter size numbers

 The user will enter a search value

 The program will search the data for a specific value

 program will display a message in which element the value was found or display a message the value was not found

 */

#include <iostream>  // required header file for input/output
#include <string>

using namespace std;


// function prototypes
void input_data(short data[], short size);
void sequential_search(short data[], short size, short search_value, short &offset);

int main()
{   // declare local variables

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

    do  // posttest loop (will execute at least one time)
    {

        // input a search value
    	cout << "Enter a search value:\n";
    	cin >> sSearchValue;

        // call sequential_search function
    	sequential_search(saData, saSize, sSearchValue, sOffset);

        // display a message to output the element # where search value was found or message value not found

    	if (sOffset == -1) {
    		cout << "Sorry the value " << sSearchValue << " was not found.\n";
    	} else {
    		cout << "The search value " << sSearchValue << " was found at element #" << sOffset << "\n";
        }

        cout<<"To search for another number enter the digit 1 otherwise enter the digit \n";

        cin>>search_again;

    } while(search_again != 0);



    return 0;

}

// function definitions are placed after main
// Do not output anything from these functions
// Function to input(store) data into the array
void input_data(short data[], short size)
{   /*code in function*/
	 for (int i=0; i<size; i++) {
		 cout << "Input numeric value "<< i+1 << ":\n";
		 cin >> data[i];
	 }
}


// Function to search the array using a sequential search
// Assign the subscript/element # to offset where found or assign offset -1 if not found.
void sequential_search(short data[], short size, short search_value, short &offset)
{   /*code in function*/
	offset = -1;
	for (int i = 0; i < size; i++) {
		if (data[i] == search_value) {
			offset = i;
			return;
		}
	}
}
