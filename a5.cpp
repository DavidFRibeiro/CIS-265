#include <iostream>
using namespace std;
//define column and row size for the array
const int COLS = 3;
const int ROWS = 3;

double getTotal(double[][COLS]);

double getAverage(double[][COLS]);

double getRowTotal(double[][COLS], int);

double getColumnTotal(double[][COLS], int);

double getHighestInRow(double[][COLS], int);

double getLowestInRow(double[][COLS], int);


int main() {
    //initialize array
    double array[ROWS][COLS] = {{1,2,3},{2,3,4},{3,4,5}};
    //output
    cout << "array to getTotal: " << getTotal(array) << endl;
    cout << "array to getAverage: " << getAverage(array) << endl;
    cout << "array to getRowTotal, 1st row: " << getRowTotal(array,0) << endl;
    cout << "array to getColumnTotal, 2nd col: " << getColumnTotal(array,1) << endl;
    cout << "array to getHighestInRow, 3rd row: " << getHighestInRow(array,2) << endl;
    cout << "array to getLowestInRow, 3rd row: " << getLowestInRow(array,2) << endl;
    
    system ("pause");
    return 0;
}
//processing
double getTotal(double array[][COLS]){
    double total = 0;
    for(int row = 0; row<ROWS; row++){
        for(int col = 0; col<COLS;col++){
            total += array[row][col];
        }
    }
    return total;
}
double getAverage(double array[][COLS]){
    
    return getTotal(array)/(ROWS*COLS);
}
double getRowTotal(double array[][COLS], int row){
    double rowTotal = 0;
    for(int col = 0; col<COLS; col++){
        rowTotal += array[row][col];
    }
    return rowTotal;
}
double getColumnTotal(double array[][COLS], int col){
    double colTotal = 0;
    for(int row = 0; row<ROWS; row++){
        colTotal += array[row][col];
    }
    return colTotal;
}
double getHighestInRow(double array[][COLS], int row){
    double highRow = array[row][0];
    for(int col = 0; col<COLS; col++){
        if(array[row][col]>highRow){
            highRow = array[row][col];
        }
    }
    return highRow;
}
double getLowestInRow(double array[][COLS], int row){
    double lowRow = array[row][0];
    for(int col = 0; col<ROWS; col++){
        if(array[row][col]<lowRow){
            lowRow = array[row][col];
        }
    }
    return lowRow;
}
