

//courseID:CIS265
//name: David Ribeiro
//Prof. Wang
//Assignment#8
//Due by 11/15/2015

/*
steps
 Get the string. 
 Save the string character array to a pointer. 
 Send the pointer to the function. 
 Return an int that is equal to the number of elements in that array to get the size of the stirng.
*/


#include <iostream>
#include <string>
using namespace std;

double stringCount(char *);

int main()
{
    const int SIZE= 80;
    char word[SIZE];
    char * cptr = word;
    
    cout << "Enter a string\n";
    cin.getline(cptr, SIZE); //get the string

    cout << "The length of the string is " << stringCount(cptr)<< endl; //send it to the function
}

double stringCount(char * ptr)
{

    return strlen(ptr);//return the string length. 
}