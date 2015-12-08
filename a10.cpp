#include <iostream>
using namespace std;

struct movieData {
    
    string Title;
    string Director;
    int yearReleased;
    int runningTime;
    
    //processing for input
    
    movieData moviePass(){
        static int movieNum = 1;
        movieData Movie;
        cout << "Movie " << movieNum << endl;
        cout << "Enter movie title: ";
        getline(cin,Movie.Title);
        cout << "Enter movie director: ";
        getline(cin,Movie.Director);
        cout << "Enter year released: ";
        cin >> Movie.yearReleased;
        cout << "Enter run time(minutes): ";
        cin >> Movie.runningTime;
        cout << endl;
        cin.ignore();
        movieNum++;
        return Movie;
    }
    
    //processing for output
    
    void movieDisplay(movieData &display){
        cout << "Movie Title: " << display.Title << endl;
        cout << "Movie Director: " << display.Director << endl;
        cout << "Year Released: " << display.yearReleased << endl;
        cout << "Running Time: " << display.runningTime << " minutes" << endl << endl;
    }
    
} movie[2];
//Above: object type of movieData

int main() {

    //function calls
    
    movie[0] = movie[0].moviePass();
    movie[1] = movie[1].moviePass();
    
    movie[0].movieDisplay(movie[0]);
    movie[1].movieDisplay(movie[1]);
    
    system("pause");
    return 0;
}
