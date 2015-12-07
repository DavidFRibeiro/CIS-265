//courseID:CIS265
//name: David F Ribeiro
//Prof. Wang
//Assignment#12
//Due by 12/6/2015

/*
 Steps
 - Main Menu with option to branch off into any of the main functions
 *Add branch that adds records.
 *Display branch that displays all records.
 *Change branch that allows the user to edit the records.
 
 
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void MainMenu();
void addRecord();
void displayRecord();
void changeRecord();

struct Item
{
    string Description;
    int hand;
    int wholeCost;
    int retailCost;
    string dateAdded;
    
};



int main(int argc, const char * argv[])
{

cout << "**Welcome to Inventory Managers 2015!**\n";
    
   fstream dataFile("Test.txt", ios::in | ios::out| ios::binary);
    
   
        MainMenu();
    
cout << "Thank you for using Inventory Manager 2015!";

    return 0;
}


void MainMenu ()
{
    char Choice;

cout << "What would you like to do?\n" << endl
     << "A. Add a set of new records to the file." << endl
     << "B. Display the records in the file." << endl
     << "C. Change records in the file.\n" << endl
     << "Or Q to Quit." << endl;

    while (Choice != 'A' || Choice != 'B' || Choice != 'C' || Choice != 'Q')
    {
        
        cin >> Choice;
    
        switch(Choice)
        {
            case 'A':
            
                addRecord();
                break;
            
            case 'B':
            
                displayRecord();
                break;
            
            case 'C':
            
                changeRecord();
                break;
            
            case 'Q':
                return;
                break;
            default:
            cout << "Please use a valid Menu Key!";
                break;
        }
    }

}

void addRecord ()
{
    cout << "\nYou haved entered Addition Mode!\n" << endl;
    char ender;
    int numRecords;
    cout << "How many empty records would you like to create?" << endl;
    cin >> numRecords;
    
    // Create an empty Item Structure
    Item record = { "Empty", 0, 0, 0, "Empty"};
    
    //Open the file for binary output
    fstream data("Test.txt", ios::out | ios::binary);
    
    //write the blank records
    for (int count = 1; count <= numRecords; count++)
    {
        cout << "Now writing record #" << count << endl;
        data.write(reinterpret_cast<char *>(&record), sizeof(record));
    
    
    }
    
    //Close the file
    data.close();
    
    
    // What to do next
    cout << "\nR to return to the Menu \nQ to quit the program." << endl;
    cin >> ender;
    if (ender == 'R')
    {
        cout << "A. Add a set of new records to the file." << endl
        << "B. Display the records in the file." << endl
        << "C. Change records in the file.\n" << endl
        << "Or Q to Quit." << endl;
    }
    else
        exit(0);

}

void displayRecord()
{
    char ender,
         again;
    cout << "\nYou have entered Display Mode! \n" << endl;
    cout << "Press enter to cycle through the records!" << endl;
    cin.get(again);
    
    
    Item record;  // To hold inventory record
    
    //Open the file for binary output
    fstream data("Test.txt" , ios::in | ios::binary);
    
    // Now read and display the records
    data.read(reinterpret_cast<char *>(&record), sizeof(record));
    int counter = 1;
    while (!data.eof())
    {
        cout << "\nRecord #" << counter;
        cout << "\nDescription: " << endl;
        cout << record.Description << endl;
        cout << "Quantity on Hand: "<< endl;
        cout << record.hand << endl;
        cout << "Wholesale Cost: " << endl;
        cout << record.wholeCost << endl;
        cout << "Retail Cost: " << endl;
        cout << record.retailCost << endl;
        cout << "Date added to Intentory: " << endl;
        cout << record.dateAdded << endl;
        counter++;
       
        
        //Read the next record from the file
        data.read(reinterpret_cast<char *>(&record), sizeof(record));
        
        //Wait for user to press enter key
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cin.get(again);
        
        
    }
    
    //close the file
    data.close();
    
    
    
    // What to do next
    cout << "\nR to return to the Menu \nQ to quit the program.\n"<< endl;
    cin >> ender;
    if (ender == 'R')
    {
        cout << "A. Add a set of new records to the file." << endl
        << "B. Display the records in the file." << endl
        << "C. Change records in the file.\n" << endl
        << "Or Q to Quit.\n" << endl;
        
    }
    else
        exit(0);
    
    
    
    
}

void changeRecord()
{
   
    Item record;
    int originalNum,
        recNum;
    char ender;
    
    // Open the file in binary mode for input and output.
    fstream data("Test.txt", ios::in | ios::out | ios::binary);

    
    //Get the record number of the desired record.
    cout << "Which Record do you want to edit?" << endl;
    cin >> originalNum;
    recNum = originalNum - 1; 
    
    //Move to the record and read it
    data.seekg(recNum * sizeof(record), ios::beg);
    data.read(reinterpret_cast<char *>(&record), sizeof(record));
    
    // Display the Record contents.
    cout << "\nDescription: " << endl;
    cout << record.Description << endl;
    cout << "Quantity on Hand: "<< endl;
    cout << record.hand << endl;
    cout << "Wholesale Cost: " << endl;
    cout << record.wholeCost << endl;
    cout << "Retail Cost: " << endl;
    cout << record.retailCost << endl;
    cout << "Date added to Intentory: " << endl;
    cout << record.dateAdded << endl;
    
    // Get the new Record Data
    cout << "\nEnter the new Data for the record.\n" << endl;p
    cout << "Description: ";
    cin.ignore();
    getline(cin, record.Description);
    cout << "Quantity on Hand: ";
    cin >> record.hand;
    cout << "Wholesale Cost: ";
    cin >> record.wholeCost;
    cout << "Retail Cost: ";
    cin >> record.retailCost;
    cout << "Date added to the Inventory: ";
    cin.ignore();
    getline(cin, record.dateAdded);
    
    // Move back to the beggining of this record's position.
    data.seekp(recNum * sizeof(record), ios::beg);
    
    //Write the new Record over the current record.
    data.write(reinterpret_cast<char *>(&record), sizeof(record));
    
    // close the file
    data.close();
    
    
    
    // What to do next
    cout << "\nR to return to the Menu \nQ to quit the program.\n"<< endl;
    cin >> ender;
    if (ender == 'R')
    {
        cout << "A. Add a set of new records to the file." << endl
        << "B. Display the records in the file." << endl
        << "C. Change records in the file.\n" << endl
        << "Or Q to Quit.\n" << endl;
        
    }
    else
        exit(0);
    
}