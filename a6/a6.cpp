#include <iostream>
using namespace std;

int * getAryPtr(int);

int main(){
    //initialize/define pointer/variable
    int *hello;
    int num = 5;
    hello = getAryPtr(num);
    cout << "Enter 5 numbers" << endl;
    //Input/Output
    for(int i = 0; i<num; i++){
        cin >> hello[i];
        cout << hello[i] << endl;
    }
    //frees up memory
    delete [] hello;
    hello = 0;
    system ("pause");
    return 0;
}
//This is the assignment, the rest of the program is to demonstrate it in action.
int * getAryPtr(int innuger){
    //processing
    int * arrayPointer;
    if(innuger<=0){
        return NULL;
    }
    arrayPointer = new int[innuger];
    return arrayPointer;
}
