//courseID:CIS265
//name: David Ribeiro
//Prof. Wang
//Assignment#11
//Due by November 22, 2015

//Set up the nested structures
//send the structure to a function to input the values
//send the data in the structure to be formatted for output. 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



struct nameVal{ // The structure to hold the name and value
    string name;
    double value;
};

struct monthlyBudget{ // the structure to hold the array that allows me to make a nested structure 
    nameVal category[10];
};

void getvalues(monthlyBudget); //Prototypes of the two functions for input

void displayvalues(monthlyBudget);// and display

int main ()
{
    monthlyBudget expenses; // Create the structure that will hold the data
    
    
    expenses.category[0].name = "Housing";  // Make a very rudimentary and bad set of values
    expenses.category[1].name = "Utilities";
    expenses.category[2].name = "Household Expenses";
    expenses.category[3].name = "Transportation";
    expenses.category[4].name = "Food";
    expenses.category[5].name = "Medical";
    expenses.category[6].name = "Insurance";
    expenses.category[7].name = "Entertainment";
    expenses.category[8].name = "Clothing";
    expenses.category[9].name = "Miscellaneous";
    
  
    getvalues(expenses); // Call to the value gathering function

}


void getvalues(monthlyBudget expenses)
{
    
    for(int i = 0; i<10; i++) //Get input for the nested structure array values.
    {
        
        
        cout << "Enter " << expenses.category[i].name << " value: ";
        
        cin >> expenses.category[i].value;
        
        cin.ignore();
        
    }
    

    displayvalues(expenses); //Call the display function
    

}

void displayvalues(monthlyBudget expenses) // Display the contents of the struct
{
    
    
    cout << endl;
    
    for(int i = 0; i<10; i++)
    {
        cout << expenses.category[i].name << "=$" << setprecision(2) << fixed << expenses.category[i].value << endl;
    }
   
}


