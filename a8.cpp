#include <iostream>
using namespace std;
int cLength(char*);
int main(int argc, const char * argv[]) {
    //initialize/define variables
    const int size = 20;
    char charo[size];
    char * charpoint = charo;
    //input output
    cout << "Enter a word no longer than " << size-1 << " chars in length." << endl;
    cin.getline(charpoint,size);
    
    int catcher = cLength(charpoint);
    cout << catcher << endl;
    system ("pause");
    return 0;
}
int cLength(char* charpointer){
    //processing
    int lenggth = 0;
    while(charpointer[lenggth] != '\0')
        lenggth++;

    return lenggth;
}
