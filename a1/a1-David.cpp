
//"a1.cpp"

/***** Initial contributor = David Ribeiro *****/
/*****         On November 23, 2015        *****/

/* Problem #9 Page 295 "Hotel Occupancy"
 
 - Write a program that calculates the occupancy rate for a hotel. The program should start by asking the user how many floors the hotel has. A loop should then iterate once for each floor. In each iteration, the loop should ask the user for the number of
 rooms on the floor and how many of them are occupied. After all the iterations, the program should display how many rooms the hotel has, how many of them are occupied, how many are unoccupied, and the percentage of rooms that are occupied. The percentage may
 be calculated by dividing the number of rooms occupied by the number of rooms.
 
 - N O T E : It is traditional that most hotels do not have a thirteenth floor. The loop in this program should skip the entire thirteenth iteration.
 
 - Input Validation: Do not accept a value less than 1 for the number of floors. Do not
 accept a number less than 10 for the number of rooms on a floor.
 
 
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //                                                                                                          **Define a list of variables & inputs**
    
    int floorCount, // Counter variable for current floor number
        totalFloor, // The amount of floors in the Hotel
        addRoom,    // The aggregator of rooms per floor
        addOcc,     // The aggregator of occupied rooms per floor
        occNum = 0; // the total of occupied rooms
    
    double occPercent, // Perentage of rooms occupie
           roomNum = 0;    // total number of rooms
    
    cout << "This Program will help you calculate the occupancy rate for your hotel! \n\n"
    << "Please input the number of floors in the hotel. \n";
    
    cin >> totalFloor;
    
    while (totalFloor < 1 || totalFloor > 100) // validate the input for a number less than 1
    {
        cout << "That is not possible, please use a valid number of floors. \n";
        
        cin >> totalFloor;
    }
    
    //                                                                                                              **Main Proccessing For Loop**
    
    for (floorCount = 1; floorCount <= totalFloor ; floorCount++) //iterate through the floors
    {
        if (floorCount == 13)//13th floor is ommited
        {
            continue;
        }
        
        cout << "How many rooms are on floor " << floorCount << " ?\n";
        
        cin >> addRoom; //input for rooms on a specified floor
        
        while (addRoom < 10) //validation for having less than 10 rooms on any given floor
        {
            cout << "That is too low number of rooms, please use a number that is at least 10 .\n";
            
            cin >> addRoom;
        }
        
        roomNum += addRoom; //add to the total number of rooms
        
        cout << "How many of the rooms on floor " << floorCount << " are occupied?\n";
        
        cin >> addOcc;//input for occupied rooms on the selected floor.
        
        while (addOcc < 0 || addOcc > addRoom) //validation for having less than 0 rooms occupied any given floor and for having more rooms occupied than there are available on that floor
        {
            cout << "The number is either lower than 0 or larger than the number of rooms on this floor. Please enter a valid number.\n";
            
            cin >> addOcc;
        }

        
        occNum += addOcc; //add to total of occupied rooms.
        
        
    }
    
    // Calculating the Percentage
    occPercent = (occNum / roomNum) * 100;
    
    //Output
    cout << "The total number of floors is " << totalFloor << ".\n"
    
    << "The total number of rooms is " << roomNum << ".\n"
    
    << "The total number of occupied room is " << occNum << ".\n"
    
    << "The percentage of rooms occupied is " << setprecision(3) << occPercent << "%. \n";
    
    
    //Providing information based on the occupancy rates
    if (occPercent < 50)
    {
        cout << "Your occupancy rate is low, consider offering some more competitve rates!";
    }
    else if (occPercent < 90)
    {
        cout << "Your occupancy rate is good, continue to provide good customer service!";
    }
    else if (occPercent >= 90 )
    {
        cout << "Your occupancy rate is very high, your business is commendable!";
    }
    
    return 0;
    
}