#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getDays();                      //function has no parameters. when it is called, it returns the
//number of days to main
double timeofD();                   //function has no parameters. When it is called, it returns the time
//of departure to main.
double timeofA();                   //function has no parameters. When it is called, it returns the time
//of departure to main.
double airfare();                   //function has no parameters. When it is called, it returns the
//airfare fee to main.
double carRental();                 //function has no parameters. When it is called, it returns the
//car rental fee to main.
double milesDriven();               //function has no parameters. When it is called, it returns the
//private car miles driven fee to main.
double parking(int);                //function has 1 parameter. The first time it is called, it
//returns the total expense of parking fees to main. The second time it is
//called it returns the allowed expense of parking fees to main.
double taxi(int);                   //function has 1 parameter. The first time it is called,
//it returns the total expense of taxi fees to main. The second time it is
// called, it returns the allowed expense of taxi fees to main.
double reg();                       //function has no parameters. When it is called, it returns
//the conference/seminar fee to main.
double hotel(int);                  //function has no parameters. The first time it is called,
//it returns the total expense of hotel fees to main. The second time it is
//called, it returns the allowed expense of hotel fees to main.
double food(int, double, double);   //function has 3 parameters. The first time it is called, it returns
//the total expense of food costs to main. The second time it is called,
//it returns the allowed expense of food costs to main.
void report(double[], double[]);    //function has 2 parameters. When it is called, it returns nothing.

/*Main calls each function and receives data. It accumulates the expenses in two parallel arrays and passes them to the report function.*/

int main()
{
    int days,
    i=0;
    double actualbill[8],
    allowedbill[8],
    timeofDe,
    timeofAr,
    actualExpense,
    allowedExpense;
    
    cout << "|| Welcome to Business Trip Financial Calculator 2015 ||" << endl;
    
    days = getDays();
    timeofDe = timeofD();
    timeofAr = timeofA();
    
    actualbill[i]=airfare();
    allowedbill[i]=actualbill[i];
    i++;
    
    actualbill[i]=carRental();
    allowedbill[i]=actualbill[i];
    i++;
    
    actualbill[i]=milesDriven();
    allowedbill[i]=actualbill[i];
    i++;
    
    actualbill[i]=parking(days);
    allowedbill[i]=parking(days);
    i++;
    
    actualbill[i]=taxi(days);
    allowedbill[i]=taxi(days);
    i++;
    
    actualbill[i]=reg();
    allowedbill[i]=actualbill[i];
    i++;
    
    actualbill[i]=hotel(days);
    allowedbill[i]=hotel(days);
    i++;
    
    actualbill[i]=food(days, timeofDe, timeofAr);
    allowedbill[i]=food(days, timeofDe, timeofAr);
    
    
    report(actualbill, allowedbill);
    
    
    system("pause");
    return 0;
}

//This function will ask for the amount of days they were on the trip and return them
int getDays()
{
    int days;
    cout << "How many days were spent on the trip?" << endl;
    cin >> days;
    while (days < 1)
    {
        cout << "Enter a number of days greater than 0." << endl;
        cin >> days;
    }
    return days;
}

// This function will ask for the time of departure and return it
double timeofD()
{
    double timeofDH,
    timeofDM,
    timeofDe;
    
    cout << "At what hour did you depart for the trip? (Use military time, 0 - 23)" << endl;
    cin >> timeofDH;
    while (timeofDH < 0 || timeofDH > 23)
    {
        cout << "Enter a valid hour between 0 and 23. " << endl;
        cin >> timeofDH;
    }
    cout << "At what minute did you depart for the trip?" << endl;
    cin >> timeofDM;
    while  (timeofDM < 0 || timeofDM > 59)
    {
        cout  << "Enter a valid minute between 0 and 59. " << endl;
        cin >> timeofDM;
    }
    timeofDM = static_cast<int> (timeofDM);
    cout << "So you departed at " << timeofDH << ":" <<  setfill('0') << setw(2) <<timeofDM << "? Great!" << endl;
    
    timeofDM = timeofDM / 100;
    timeofDe = timeofDH + timeofDM;
    return timeofDe;
}


// This function will ask for the time of arrival/return and return it
double timeofA()
{
    double timeofAH;
    double timeofAM;
    double timeofAr;
    cout << "At what hour did you return? (Use military time, 0 - 23)" << endl;
    cin >> timeofAH;
    while (timeofAH < 0 || timeofAH > 23)
    {
        cout << "Enter a valid hour between 0 and 23. " << endl;
        cin >> timeofAH;
    }
    cout << "At what minute did you return? " << endl;
    cin >> timeofAM;
    while (timeofAM < 0 || timeofAM > 59)
    {
        cout << "Please enter  a valid minute between 0 and 59" << endl;
        cin >> timeofAM;
    }
    timeofAM = static_cast<int> (timeofAM);
    cout << "So you returned at " << timeofAH << ":" <<  setfill('0') << setw(2) << timeofAM << "? Great!" << endl;
    timeofAM = timeofAM/100;
    timeofAr = timeofAH + timeofAM;
    return timeofAr;
}

// This function will ask for the amount of airfare and return it.
double airfare()
{
    double airfarefee;
    cout << "How much did the round-trip airfare cost?" << endl;
    cin >> airfarefee;
    while (airfarefee <= 0)
    {
        cout << "Enter a number greater than 0" << endl;
        cin >> airfarefee;
    }
    
    return airfarefee;
}

//This function will ask for the amount of car rentals and return it
double carRental()
{
    double carfare;
    char rental;
    cout << "Did you rent a car during your trip? (Y/N)" << endl;
    cin >> rental;
    while (rental != 'Y' && rental != 'y' && rental != 'N' && rental != 'n')
    {
        cout << "That is not a possible Yes or No choice. Please use the letter Y for yes or the letter N for no. " << endl;
        cin >> rental;
    }
    
    if (rental == 'Y' || rental == 'y')
    {
        cout << "How much did the rental cost?" << endl;
        cin >> carfare;
        while (carfare <= 0)
        {
            cout << "Enter a number greater than 0. " << endl;
            cin >> carfare;
        }
    }
    
    return carfare;
}


//This function will ask if a private car was used. It will calculate the fee and return it.
double milesDriven()
{
    double milesdriven,
    milescost = 0;
    char rental;
    cout << "Did you employ a private car during your trip? (Y/N)" << endl;
    cin >> rental;
    while (rental != 'Y' && rental != 'y' && rental != 'N' && rental != 'n')
    {
        cout << "That is not a possible Yes or No choice. Please use the letter Y for yes or the letter N for no. " << endl;
        cin >> rental;
    }
    
    if (rental == 'Y' || rental == 'y')
	   {
           cout << "How many miles were driven in the private car?" << endl;
           cin >> milesdriven;
           while (milesdriven <= 0)
           {
               cout << "Enter a number greater than 0. " << endl;
               cin >> milesdriven;
           }
           milescost = milesdriven * .27;
       }
    
    return milescost;
}

//This function will calculate thee parking fees and return it.
double parking(int days)
{
    static int    j = 0;
   	static double expenses = 0, // actual expenses
    allowed;           //used to accrue values added by for loop
    if(j==0){
        double addition;      // value added in each iteration of for loop
        for (int i = 1; i <= days; i++)
        {
            cout << "How many parking fees did you incur on day " << i << " of your trip?" << endl;
            cin >> addition;
            
            while (addition < 0.00) //input validation on fees of the day
            {
          	 	 		cout << "That was not a valid number for parking fees incurred on day " << i << ". "
          	 	 		<< "Please use a value equal to or above $0.00." << endl;
          	 	 		cin >> addition;
            }
            
            expenses += addition; // Expenses total
        }
    		  allowed = days * 6; // Allowed Calculated.
        
        //Passing values to the respective functions
        j++;
        return expenses;
    }
    return allowed;
}

//This function will calculate the taxi fees and return it.
double taxi(int days) {
    
    //Establish Variables
    
    char didTaxi;
    static int j;
    static double expenses,
    allowed;
    if(j==0){
        double addition = 0;
        int days2 = days;
        
        
        //did you use a Taxi?
        cout << "Did you employ taxi services at all during your trip? (Y/N)" << endl;
        cin >> didTaxi;
        //if Yes or No
        while (didTaxi != 'Y' && didTaxi != 'y' && didTaxi != 'N' && didTaxi != 'n')
        {
            cout << "That is not a possible Yes or No choice. Please use the letter Y for yes or the letter N for no." << endl;
            cin >> didTaxi;
        }
        // if YES
        if (didTaxi == 'Y' || didTaxi == 'y'){
            // Use Days to ask fee for each day
            for (int i = 1; i <= days; i++)
            {
                cout << "How many taxi fees did you incur on day "<< i
                << " of your trip?"<<endl;
                cin >> addition;
                // input validation for character input
                while(!cin){
                    cout << "Enter a number!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> addition;
                }
                while(addition < 0.00) // input validation for addition
                {
                    cout << "That is not a valid cost for taxi fees on day " << i
                    << " of your trip."
                    << "\nPlease use a value equal to or above 0.00" << endl;
                    cin >> addition;
                    while(!cin){
                        cout << "Enter a number!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> addition;
                    }
                    
                }
                if(addition == 0){
                    days2--;
                }
                expenses += addition; // Expenses total
            }
            allowed = days2 * 10; // allowed Calculate
            if(expenses==0){
                allowed = 0;
            }
            
            j++;
            return expenses;
        }
        else{
            j++;
        }
    }
    return allowed;
}


//This function will ask for the conf/sem fees and return it.
double reg()
{
    double regcost;
    cout << "What was the total of conference/seminar registration fees?" << endl;
    cin >> regcost;
    while (regcost < 0)
    {
        cout << "Enter a number above 0. " << endl;
        cin >> regcost;
    }
    return regcost;
}

//This function will calculate the hotel fees and return it.
double hotel(int days)
{
    static double expenses = 0,
    allowed = 0;
    static int j;
    if(j==0){
        double addition = 0;
        
        for (int i = 1; i <= days; i++)
        {
            cout << "How many hotel fees did you incur on day "<< i
            << " of your trip?"<<endl;
            cin >> addition;
            
            while(!cin){
                cout << "Enter a number!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> addition;
            }
            while(addition < 0.00) // input validation
            {
                cout << "That is not a valid cost for hotel fees on day " << i
                << " of your trip."
                << "\nPlease use a value equal to or greater than 0.00" << endl;
                cin >> addition;
                
                while(!cin){
                    cout << "Enter a number!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> addition;
                }
                
            }
            
            expenses += addition; // Expenses total
        }
        allowed = days * 90; // allowed Calculate
        
        j++;
        return expenses;
    }
    return allowed;
}



//This function will calculate the food fees and return it.

double food(int days,double timeofDe, double timeofAr){
    static double expenses,
    allowed;
    static int j;
    if(j==0){
        int i=1;
        string breakfast,lunch, dinner;
        double BreakfastCost=0, LunchCost=0, DinnerCost=0;
        do{
            if (timeofDe<7&&i==1){
                cout<<"Did you eat breakfast on day "<<i<<"? (Y/N)""\n";
                cin>>breakfast;
                while( (!isalpha(breakfast[0])) || (breakfast.size() > 1) ){
                    cout<<"Please use a character for Yes or No.""\n";
                    cin>>breakfast;
                }
                while (breakfast[0] !='y' && breakfast[0]!='Y' && breakfast[0]!='n' && breakfast[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>breakfast;
                }
                if (breakfast[0]=='Y' ||breakfast[0]=='y'){
                    cout<<"How much did breakfast cost?""\n";
                    cin>>BreakfastCost;
                    while (BreakfastCost<0){
                        cout<<"Please enter a valid number.""\n";
                        cin>>BreakfastCost;
                    }
                }
                if (breakfast[0]=='N' ||breakfast[0]=='n'){
                    BreakfastCost=0;
                }
                allowed+=9;
            }
            if (timeofAr>8&&i==days&&i!=1){
                cout<<"Did you eat breakfast on day "<<i<<"? (Y/N)""\n";
                cin>>breakfast;
                while( (!isalpha(breakfast[0])) || (breakfast.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>breakfast;
                }
                while (breakfast[0] !='y' && breakfast[0]!='Y' && breakfast[0]!='n' && breakfast[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>breakfast;
                }
                if (breakfast[0]=='Y' ||breakfast[0]=='y'){
                    cout<<"How much did breakfast cost?""\n";
                    cin>>BreakfastCost;
                    while (BreakfastCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>BreakfastCost;
                    }
                }
                if (breakfast[0]=='N' ||breakfast[0]=='n'){
                    BreakfastCost=0;
                }
                allowed+=9;
            }
            if (i>1&&i<days){
                cout<<"Did you eat breakfast on day "<<i<<"? (Y/N)""\n";
                cin>>breakfast;
                while( (!isalpha(breakfast[0])) || (breakfast.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>breakfast;
                }
                while (breakfast[0] !='y' && breakfast[0]!='Y' && breakfast[0]!='n' && breakfast[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>breakfast;
                }
                if (breakfast[0]=='Y' ||breakfast[0]=='y'){
                    cout<<"How much did breakfast cost?""\n";
                    cin>>BreakfastCost;
                    while (BreakfastCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>BreakfastCost;
                    }
                }
                if (breakfast[0]=='N' ||breakfast[0]=='n'){
                    BreakfastCost=0;
                }
                allowed+=9;
            }
            
            
            if (timeofDe<12&&i==1){
                cout<<"Did you eat lunch on day "<<i<<"? (Y/N)""\n";
                cin>>lunch;
                while( (!isalpha(lunch[0])) || (lunch.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>lunch;
                }
                while (lunch[0] !='y' && lunch[0]!='Y' && lunch[0]!='n' && lunch[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>lunch;
                }
                if (lunch[0]=='Y' ||lunch[0]=='y'){
                    cout<<"How much did lunch cost?""\n";
                    cin>>LunchCost;
                    while (LunchCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>LunchCost;
                    }
                }
                if (lunch[0]=='N' ||lunch[0]=='n'){
                    LunchCost=0;
                }
                allowed+=12;
            }
            if (timeofAr>13&&i==days&&i!=1){
                cout<<"Did you eat lunch on day "<<i<<"? (Y/N)""\n";
                cin>>lunch;
                while( (!isalpha(lunch[0])) || (lunch.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>lunch;
                }
                while (lunch[0] !='y' && lunch[0]!='Y' && lunch[0]!='n' && lunch[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>lunch;
                }
                if (lunch[0]=='Y' ||lunch[0]=='y'){
                    cout<<"How much did lunch cost?""\n";
                    cin>>LunchCost;
                    while (LunchCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>LunchCost;
                    }
                }
                if (lunch[0]=='N' ||lunch[0]=='n'){
                    LunchCost=0;
                }
                allowed+=12;
            }
            if(i>1&&i<days){
                cout<<"Did you eat lunch on day "<<i<<"? (Y/N)""\n";
                cin>>lunch;
                while( (!isalpha(lunch[0])) || (lunch.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>lunch;
                }
                while (lunch[0] !='y' && lunch[0]!='Y' && lunch[0]!='n' && lunch[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>lunch;
                }
                if (lunch[0]=='Y' ||lunch[0]=='y'){
                    cout<<"How much did lunch cost?""\n";
                    cin>>LunchCost;
                    while (LunchCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>LunchCost;
                    }
                }
                if (lunch[0]=='N' ||lunch[0]=='n'){
                    LunchCost=0;
                }
                allowed+=12;
            }
            
            
            if (timeofDe<18&&i==1){
                cout<<"Did you eat dinner on day "<<i<<"? (Y/N)""\n";
                cin>>dinner;
                while( (!isalpha(dinner[0])) || (dinner.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>dinner;
                }
                while (dinner[0] !='y' && dinner[0]!='Y' && dinner[0]!='n' && dinner[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>dinner;
                }
                if (dinner[0]=='Y' ||dinner[0]=='y'){
                    cout<<"How much did dinner cost?""\n";
                    cin>>DinnerCost;
                    while (DinnerCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>DinnerCost;
                    }
                }
                if (dinner[0]=='N' ||dinner[0]=='n'){
                    DinnerCost=0;
                }
                allowed+=16;
            }
            if (timeofAr>19&&i==days&&i!=1){
                cout<<"Did you eat dinner on day "<<i<<"? (Y/N)""\n";
                cin>>dinner;
                while( (!isalpha(dinner[0])) || (dinner.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>dinner;
                }
                while (dinner[0] !='y' && dinner[0]!='Y' && dinner[0]!='n' && dinner[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>dinner;
                }
                if (dinner[0]=='Y' ||dinner[0]=='y'){
                    cout<<"How much did dinner cost?""\n";
                    cin>>DinnerCost;
                    while (DinnerCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>DinnerCost;
                    }
                }
                if (dinner[0]=='N' ||dinner[0]=='n'){
                    DinnerCost=0;
                }
                allowed+=16;
            }
            if(i>1&&i<days){
                cout<<"Did you eat dinner on day "<<i<<"? (Y/N)""\n";
                cin>>dinner;
                while( (!isalpha(dinner[0])) || (dinner.size() > 1) ){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>dinner;
                }
                while (dinner[0] !='y' && dinner[0]!='Y' && dinner[0]!='n' && dinner[0]!='N'){
                    cout<<"Please enter (Y/N)""\n";
                    cin>>dinner;
                }
                if (dinner[0]=='Y' ||dinner[0]=='y'){
                    cout<<"How much did dinner cost?""\n";
                    cin>>DinnerCost;
                    while (DinnerCost<0){
                        cout<<"Please enter a valid number""\n";
                        cin>>DinnerCost;
                    }
                }
                if (dinner[0]=='N' ||dinner[0]=='n'){
                    DinnerCost=0;
                }
                allowed+=16;
            }
            
            i++;
            expenses+=BreakfastCost+LunchCost+DinnerCost;
        }
        
        while(i<days+1);
        
        j++;
        return expenses;
    }
    return allowed;
}


//Report - This function displays all the Bills and Expenses
void report(double actualbill[], double allowedbill[]){
    double actual = 0,
    allowed = 0;
    for(int i=0; i<8; i++)
    {
        actual  += actualbill[i];
        allowed += allowedbill[i];
    }
    double calculate[4] = {actual, allowed, 0, 0};
    string output[4] = {"Total Expenses  ", "Allowed Expenses", "Reimbursement   ", "Amount Saved    "};
    string output2[8] = {"Airfare Fees", "Car Rental Fees", "Mileage Fees", "Parking Fees", "Taxi Fees", "Conf/Sem Fees", "Hotel Fees", "Food Cost"};
    if (actual>allowed){
        calculate[2] = actual - allowed;
    }
    else{
        calculate[3] = (allowed-actual);
    }
    cout << "---------------------------------------------------" << endl;
    cout << setfill(' ') << "Expense Category" << right << setw(17)<< "Actual Bill($)" << setw(18) << "Allowed Bill($)" << endl;
    cout << "---------------------------------------------------" << endl;
    for(int i=0; i<8; i++)
    {
        
        cout << left << setw(16) << output2[i];
        cout << left << setw(6) << "|" << right << setw(8) << setprecision(2) << fixed << actualbill[i];
        cout << right << setw(7) << " " << right << setw(10) <<allowedbill[i] << endl;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Expense Report         ($)"<< endl;
    cout << "---------------------------------------------------" << endl;
    for(int i = 0;i<4;i++){
        cout << output[i] << setw(3) << "| " << right << setw(8) << setprecision(2) << fixed << calculate[i] << endl;
    }
}








