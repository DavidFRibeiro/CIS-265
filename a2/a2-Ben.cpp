#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double getSales(string);
void findHighest(double, double, double, double, string, string, string, string);
int main(int argc, const char * argv[]) {
    
    //Input/define list of variables/strings
    
    string division1, division2, division3, division4;
    string shorten = "What is the name of the next division?";
    double sales1, sales2, sales3, sales4;
    
    cout << "What is the name of the division?" << endl;
    cin >> division1;
    sales1 = getSales(division1);
    cout << shorten << endl;
    cin >> division2;
    sales2 = getSales(division2);
    cout << shorten << endl;
    cin >> division3;
    sales3 = getSales(division3);
    cout << shorten << endl;
    cin >> division4;
    sales4 = getSales(division4);
    
    findHighest(sales1,sales2,sales3,sales4,division1,division2,division3,division4);
    system ("Pause");
    return 0;
}

//Processing for input of sales-biggest sales
double getSales(string division)
{
    double sales;
    cout << "What are the quarterly sales for " << division << "?" << endl;
    do{
        cin >> sales;
        if (sales<0)
            cout << "Please enter a positive number good sir or madam!" << endl;
    }while(sales<0);
    return sales;
}
void findHighest(double sales1, double sales2, double sales3, double sales4, string division1, string division2, string division3, string division4)
{
    double bigsales;
    string bigdivision;
    if (sales1>sales2){
        bigsales = sales1;
        bigdivision = division1;
    }
    else{
        bigsales = sales2;
        bigdivision = division2;
    }
    if (sales3>bigsales){
        bigsales = sales3;
        bigdivision = division3;
    }
    if (sales4>bigsales){
        bigsales = sales4;
        bigdivision = division4;
    }
//Processing end

//Output
    
    cout << "The highest grossing division was " << bigdivision;
    cout << " and the sales total was $" << fixed << setprecision(2) << bigsales;
}
