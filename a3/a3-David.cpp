//courseID:CIS265-001
//name: David Ribeiro
//Prof. Wang
//Assignment#3
//Due by 9/28/2015

/*
 steps
 
 1.Input:
 a. Daily charges
 b. Fees
 
 
 2.Processing:
 a. Add fees together
 
 
 3.Output:
 a. The toal amounts of fees incurred by hospital stay
 
 
 */


#include <iostream>
#include <string>
using namespace std;


int totalCharge(int);
double totalCharge(double);

                                            // Main
                                            // *Input*
int main()
{
    string patient;
    cout << "Hello, Patient, were you an in-patient? (y/n)" << endl;
    cin >> patient;
                                    //If User was In-Patient
    if (patient == "y" ) {
        int intotal;
        int days = 0;
        
        cout << "How many days did you spend in the Hospital?" << endl;
        cin >> days;
                                                // Output 1
        intotal = totalCharge(days);
        cout << "The total amount of charges you incurred from your stay at the hospital is " <<
       intotal << endl;
    }
    
                                // If user was Out-Patient
    else{

        double serves, totalChargeOp;
        
        cout << "What was the cost for Hospital services? " << endl;
        cin >> serves;
        while (serves < 0) {
            cout << "That was an invalid number, please re-enter a value above 0" << endl;
            cin >> serves;
        }
        
        totalChargeOp = totalCharge(serves);
                                                    //Output 2
        
        cout << "The total amount of charges you incurred from your stay at the hospital is " <<
        totalChargeOp << endl;

        
    }
    
}

    
                                        //Processing

                                        // In-Patient Charges
int totalCharge(int number) {
    double daily,
        meds,
        tests,
        total,
    daytotal;
    
                                        //In-P Daily Rate
    cout << "What was the daily rate of the hopsital stay?" << endl;
    cin >> daily;
    while (daily < 0) {
        cout << "That was an invalid number, please re-enter a value above 0" << endl;
        cin >> daily;
    }

                                        // In-P Medications
    cout << "What were your Hospital medication charges? " << endl;
    cin >>meds;
    while (meds < 0) {
        cout << "That was an invalid number, please re-enter a value above 0" << endl;
        cin >> meds;
    }

                                            // In-P Services
    cout << "What was the cost for Hospital services? " << endl;
    cin >> tests;
    while (tests < 0) {
        cout << "That was an invalid number, please re-enter a value above 0" << endl;
        cin >> tests;
    }
    
    daytotal = number * daily;
    total = daytotal + tests + meds;
    
    return total;
}



                                        //Out-Patient Charges
double totalCharge(double number){

    double meds,
            totals;
    
    
   
    
                                        //Out-P Medication
    cout << "What were your Hospital medication charges " << endl;
    cin >> meds;
    while (meds < 0) {
    cout << "That was an invalid number, please re-enter a value above 0" << endl;
    cin >> meds;
    }
    
    totals = meds + number;
    
    
    
    
    return totals;

}




