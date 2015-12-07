//courseID:CIS165-001
//name: David Ribeiro
//Prof. Wang
//Assignment#1
//Due by 9/22/2015

/*
 steps
 1.Input:
 a. sales numbers for each of the divisions
 
 
 2.Processing:
 a. Rewrites the sales figures for each division to the input number.
 
 
 3.Output:
 a. Computes the highest number and the corresponding Sales division name 
 */
 
#include <iostream>
#include <string>
using namespace std;


double getSales(string, double);
void findHighest();

                                            /*Global Variables*/


     // Establishing Integer values for Sales figures in Each Sales Division as a Global Variable
double salesNe,
salesNw,
salesSe,
salesSw;


                                                    /*Main*/

int main()
{
    
                                                    // Establish the String Values for Each Sales Division
    string northE = " NorthEast sales division",
    northW = " NorthWest sales division",
    southE = " SouthEast sales division",
    southW = " SouthWest sales division";
    
    
                                                    // Input the Sales for each division
                                                    // Call getSale function for each Division and pass name of Division
    salesNe = getSales(northE, salesNe);
    salesNw = getSales(northW, salesNw);
    salesSe = getSales(southE, salesSe);
    salesSw = getSales(southW, salesSw);
                                                    // Call the findHighest function
    findHighest();
    
    
    return 0;
    
}

                                                                    // Proccessing
                                                                    /*getSales*/

double getSales(string name, double sales){

    
    cout << "What are the quarterly earnings for the " << name << "?" << endl;
    
    cin >> sales;
    
    while (sales < 0)
    {
        cout << "That was an invalid sales number, please enter a number over 0." << endl;
        
        cin >> sales;
    }

    return sales;
}




                                                                    /*findHighest*/
void findHighest(){
    
        double array[5] = {salesNe, salesNw, salesSe, salesSw};
        int temp = 0;
        
        for(int i=0;i<4;i++)
        {
            if(array[i]>temp)
                temp=array[i];
        }
    
                                                                    // Output
    if (temp == salesNe)
    {
    cout << "The highest grossing division is the Northeast sales division and it's sales figure was $"
        << salesNe << "." << endl;
    }
    else if (temp == salesNw)
    {
        cout << "The highest grossing division is the NorthWest sales division and it's sales figure was $"
        << salesNw << "." << endl;
    
    }
    else if (temp == salesSe)
    {
        cout << "The highest grossing division is the Southeast sales division and it's sales figure was $"
        << salesSe << "." << endl;

    }
    else if (temp == salesSw)
    {
        cout << "The highest grossing division is the Southwest sales division and it's sales figure was $"
        << salesSw << "." << endl;

    }
        
        
        }













