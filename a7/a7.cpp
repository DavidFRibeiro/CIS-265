#include <iostream>
using namespace std;

int * newArray(int[], int);

int main(){
    //Defined/initialized pointer and array
    int *pointlessArray;
    const int size = 100;
    int theArrayPassed[size],
    size2=0;
    cout << "How many elements do you want in your initial array?(<=100)" << endl;
    while (size2<1){
        cin >> size2;
        if(size2<1){
            cout << "Please enter a number greater than 0" << endl;
        }
    }
    cout << "Fill in the array please." << endl;
    for(int i = 0; i<size2; i++){
        cout << "Enter a number:";
        cin >> theArrayPassed[i];
    }

    pointlessArray = newArray(theArrayPassed, size2);

    //output
    for(int i = 0; i<size2*2; i++){
        cout << pointlessArray[i] << endl;
    }

    delete [] pointlessArray;
    pointlessArray = 0;
    system ("pause");
    return 0;
}
//This is the assignment, the rest of the program is to demonstrate this function in action.
int * newArray(int array1[], int arraySize){
    //processing
    int * twiceSize;
    twiceSize = new int[arraySize*2];
    for(int i = 0; i<arraySize*2; i++){
        if(i<arraySize){
            twiceSize[i] = array1[i];
        }
        else{
            twiceSize[i] = 0;
        }
    }
    
    return twiceSize;
}
