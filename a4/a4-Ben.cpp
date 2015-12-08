#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string monthNamer(int);

int main()
{
    //define/initialize inputs & outputs
    int big, small, total = 0, j = 0, k = 0;
    int rainbig[12];
    int rainsmall[12];
    double rain[12];
    //receive input
    cout << "What was the rainfall for each month?" << endl;
    for(int i=0;i<12;i++)
    {
        do{
            cout << monthNamer(i+1) << ": ";
            cin >> rain[i];
            if(rain[i]<0)
            {
                cout << "Re-enter that number please" << endl;
                i--;
            }
        }while(rain[i]<0);
    }
    //processing
    big = rain[0];
    small = rain[0];
    for(int i=0;i<12;i++)
    {
        if (rain[i]>big)
        {
            big = rain[i];
            j=0;
        }
        if(rain[i]==big)
        {
            rainbig[j]=i;
            j++;
        }
        if (rain[i]<small)
        {
            small = rain[i];
            k=0;
        }
        if(rain[i]==small)
        {
            rainsmall[k]=i;
            k++;
        }
    }
    for(int i=0;i<12;i++)
    {
        total+=rain[i];
    }
    //Output
    cout << "The total rainfall for the year is " << total << " inches." << endl;
    cout << "The average monthly rainfall is " << setprecision(1) << fixed << total/12.0 << " inches." << endl;
    cout << "The month(s) with the highest rainfall, " << big << " inch(es) of rain:" << endl;
    for(int i=0;i<j;i++)
        cout << monthNamer(rainbig[i]+1) << " ";
    cout << endl;
    cout << "The month(s) with the lowest rainfall, " << small << " inch(es) of rain:" << endl;
    for (int i=0;i<k;i++)
        cout << monthNamer(rainsmall[i]+1) << " ";
    cout << endl;
    
    system ("pause");
    return 0;
}
//This function takes the month number and returns the abbreviated
//  name (for the purpose of pretty output)
string monthNamer(int num){
    string name;
    if(num == 1){
        name = "Jan";
    }
    if(num == 2){
        name = "Feb";
    }
    if(num == 3){
        name = "Mar";
    }
    if(num == 4){
        name = "Apr";
    }
    if(num == 5){
        name = "May";
    }
    if(num == 6){
        name = "Jun";
    }
    if(num == 7){
        name = "Jul";
    }
    if(num == 8){
        name = "Aug";
    }
    if(num == 9){
        name = "Sep";
    }
    if(num == 10){
        name = "Oct";
    }
    if(num == 11){
        name = "Nov";
    }
    if(num == 12){
        name = "Dec";
    }
    
    return name;
}






