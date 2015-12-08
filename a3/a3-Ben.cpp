#include <iostream>

using namespace std;

void datacollectin();
void datacollectout();
double days();
double rates();
double meds();
double medservs();
double total(int, double, double, double);
double total(double, double);


int main() {
    int patient;
    cout << "Were you admitted as an:" << endl << "1. in-patient" << endl << "2. out-patient" << endl;
    do{
        if (patient != 1 && patient != 2)
            cout << "Please enter 1 or 2." << endl;
        cin >> patient;
    }while(patient != 1 && patient != 2);
    switch(patient){
        case 1: datacollectin();
            break;
        case 2:datacollectout();
    }
    
    system ("pause");
    return 0;
}


//Output functions (also collect inputs)

void datacollectin(){
    
    int day;
    day = days();
    double rate;
    rate = rates();
    double med;
    med = meds();
    double medserv;
    medserv = medservs();
    double totals1;
    totals1 = total(day, rate, med, medserv);
    cout << "The total cost is $" << totals1 << endl;
}

void datacollectout(){
    double medserv;
    medserv = medservs();
    double med;
    med = meds();
    double totals2;
    totals2 = total(med, medserv);
    cout << "The total cost is $" << totals2 << endl;
}
//End output functions

//Input functions
double days(){
    int day = 0;
    do{
        if (day<=0)
            cout << "Enter the number of days that were spent in the hospital." << endl;
        cin >> day;
    }while(day<0);
    return day;
}

double rates(){
    double rate = 0;
    do{
        if (rate<=0)
            cout << "Please enter the daily rate." << endl;
        cin >> rate;
    }while(rate<0);
    return rate;
}

double meds(){
    double med = 0;
    do{
        if (med<=0)
            cout << "Please enter the total hospital medication charges." << endl;
        cin >> med;
    }while(med<0);
    return med;
}

double medservs(){
    double medserv = 0;
    do{
        if (medserv<=0)
            cout << "Please enter the total charges for hospital services." << endl;
        cin >> medserv;
    }while(medserv<0);
    return medserv;
}


//End input functions


//Processing functions
double total(int days, double rate, double med, double medserv){
    double total;
    total = days * rate + med + medserv;
    return total;
}

double total(double med, double medserv){
    double total;
    total = med + medserv;
    return total;
}
