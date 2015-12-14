//courseID:CIS265
//name: David Ribeiro
//Prof. Wang
//Assignment#10
//Due by November 22, 2015

#include <iostream>
#include <string>
using namespace std;



struct MovieData                        //Movie Structure including parameters
{
    string title;
    string director;
    int year;
    double mins;
    
};

void displayData(MovieData, MovieData); // Function prototype


int main() {
    


  
    MovieData gump;                      //Movie #1
    gump.title ="Forest Gump";
    gump.director = "Robert Zemekis";
    gump.year = 1994;
    gump.mins = 142;
    
    MovieData summer;                       //Movie #2
    summer.title = "(500) Days of Summer";
    summer.director = "Marc Webb";
    summer.year = 2009;
    summer.mins = 95;
  
    
    displayData(summer, gump); // Function call sending the two structures
}



    void displayData(MovieData summer, MovieData gump) //function defintion
    {
     
        cout << " Title    ~ " << summer.title << endl;  // Output for film #1
        cout << " Director ~ " << summer.director << endl;
        cout << " Released ~ " << summer.year << endl;
        cout << " Length   ~ " << summer.mins << " minutes " <<  endl;
    
        cout << "\n Title    ~ " << gump.title << endl; //Output for film #2
        cout << " Director ~ " << gump.director << endl;
        cout << " Released ~ " << gump.year << endl;
        cout << " Length   ~ " << gump.mins << " minutes \n" <<  endl;
    
    }
    
    
    
    

