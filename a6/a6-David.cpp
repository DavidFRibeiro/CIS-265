//courseID:CIS265-001
//name: David Ribeiro
//Prof. Wang
//Assignment#6
//Due by 10/25/2015

/*
steps

- intilize array size variable and pointer to array

- Ask for the array size

- Create an array of the specified size using a function

- pass the newly created array pointer back to main. 

*/


#include <iostream>
using namespace std;

//prototype function
int *allocate(int);

int main()
{

int size = 0; // inout for array size

int *numbers = nullptr; // initialize the pointer variable for the function-created array.

  cout << "Enter a number to create an array with that number of elements." << endl;
  cin >> size;

  numbers = allocate(size); // Call function to create and return array to *numbers.

  cout << "The memory address of the array that was created is " << numbers << ". " << endl; 

delete [] numbers; // delete the dynamically created places in memory. 
numbers = 0;
 return 0;   

}


int *allocate(int num) //Function to create and return the array location.
{

  int *arr = nullptr; //The array location being initialized.

  arr = new int[num]; // Create array of the size of the passed integer.

  return arr; 

}

