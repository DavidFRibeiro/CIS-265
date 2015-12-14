#include <iostream>
using namespace std;

enum budgetCategory{HOUSING, UTIL, HOUSEEXPENSE,
                    TRANSPORTATION, FOOD, MEDICAL,
                    INSURANCE, ENTERTAINMENT, CLOTHING, MISC};

struct monthlyBudget{

    double Expense[10];
    
    //processing for input
    
    monthlyBudget budgetMaker(string NAMES[], monthlyBudget exp){
        cout << "Enter expenses for the month" << endl;
        cout << "----------------------------" << endl;
        for(int i = HOUSING; i<=MISC;i++){
            cout << NAMES[i] << ": ";
            cin >> exp.Expense[i];
        }
        cout << endl;
        return exp;
    }

    //processing for calculations and display
    
    void budgetCompare(string NAMES[], double stored[], monthlyBudget entered){
        cout << "Report for the month (over or under budget)" <<
        endl << "-------------------------------------------" << endl;
        double totalBudget = 0, totalSpent = 0;
        for(int i = HOUSING; i<=MISC; i++){
            cout << NAMES[i] << ": ";
            if(entered.Expense[i] - stored[i]> 0){
                cout << "+";
            }
            cout << entered.Expense[i] - stored[i]  << endl;
            totalBudget+=stored[i], totalSpent+=entered.Expense[i];
        }
        cout << endl << "Totals" << endl << "------------" << endl;
        cout << "Total Budget: " << totalBudget << endl;
        cout << "Total Spent: " << totalSpent << endl;
    }
};


int main() {
    double budgetArray[] = {500.00, 150.00, 65.00,
                            50.00, 250.00, 30.00,
                            100.00, 150.00, 75.00, 50.00};
    string names[] = {"Housing", "Utilities", "Household Expenses" ,
                      "Transportation", "Food", "Medical", "Insurance",
                      "Entertainment", "Clothing", "Miscellaneous"};
    //function calls and initialization of enteredBudget
    monthlyBudget enteredBudget = enteredBudget.budgetMaker(names, enteredBudget);
    enteredBudget.budgetCompare(names, budgetArray, enteredBudget);
    
    system("pause");
    return 0;
}
