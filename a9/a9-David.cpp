//courseID:CIS 265
//name: David Ribeiro
//Prof. Wang
//Assignment#9
//Due by 11/15/2015

/*
 steps
 - establish array with names and phone numbers
 - initialize pointer that specifies array elements with matching string elements
 - process by going throgh each array element and checking for matching string
 -output the array elements with matching strings. 
 */


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    
    bool isFound = false;         // Flag to indicate whether contact is found
    const int SIZE = 16;          // Size of contacts array
    const int MAX = 50;           // Maximum characters per row
    char contacts[SIZE][MAX] = {
            "Alejandra Cruz, 555-9126",
            "Bob Dylan, 555-7362",
            "Nicaragua Norte, 555-7251",
            "Bobby Norte, 555-6452",
            "Geroge Zimmerman, 861-4168",
            "Nicki Norte, 777-7825",
            "Jenevive Quantom, 666-2846",
            "Natalie Ribeiro, 743-7583",
            "Jimminy Cricket, 857-6352",
            "Willy Wonka, 463-8499",
            "Willy Billy, 463-6738",
            "Icky Vicky, 362-4863",
            "Chip Skylark, 902-6732",
            "Wanda Turner, 564-6832",
            "Cosmo Turner, 564-8629",
            "David Ribeiro, 861-2581"
            };
    
    char *ptr = NULL;             // Pointer to search string within contacts
    char input[MAX];              // User search input string
    
    
    // Get the user input
    cout << "Please enter a contact to lookup in the address book: ";
    cin.getline(input,MAX);
    
    // Lookup contact(s)
    for (int i=0; i<SIZE; i++)
    {
        ptr = strstr(contacts[i], input);
        if (ptr != NULL)
        {
            cout << contacts[i] << endl;
            isFound = true;
        }
    }
    
    
    return 0;
}
