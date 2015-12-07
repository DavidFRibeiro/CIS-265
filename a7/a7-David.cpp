//courseID:CIS265-001
//name: David Ribeiro
//Prof. Wang
//Assignment#7
//Due by 10/25/2015

/*
 steps

 - initialize the original array using input for size.

 - Call function that creates new array and assign its return value to a nullptr whihc will become the new array's address.

 - Create a new array with twice as many elements as the original array.

 - Copy the elements of the old array into the new, the uncopied are automatically initialized as 0. 

 returnt he pointer to the new array. 

 */


#include <iostream>
using namespace std;

//prototype new array function. 
int *expander(int*, int);

int main()
{
    
    int size = 0; // input for original array size. 
    
    int *numbers = nullptr; //define the pointer variable to hold the newly created array. 
    
    cout << "Enter a number for the size of the original array." << endl;
    cin >> size;

    int array1[size];
    
    numbers = expander(array1 , size); // Call function to create and return array to *numbers.
    
    cout << "The memory address of the array that was created is " << numbers << ". " << endl;
    
   // delete [] numbers; // delete the dynamically created places in memory.
    numbers = 0;
    return 0;
    
}


int *expander(int* arr,int size) //Function to create a new double-sized array.
{
    int newArraySize = 2*size; // get variable for the size of new array.
    
    int *newArray = nullptr; //The new array location being initialized.
    
    newArray = new int[newArraySize]; // Create array double the size of the passed array.
    
    //Copy the contents of the old array into the new one.
    for (int i = 0; i < size; ++i)
    {
    	newArray[i] = arr[i];
    }

    return newArray; //send back the new array's location in memory. 
    
}

