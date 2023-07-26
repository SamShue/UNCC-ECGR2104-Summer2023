#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    /*
    // Month 5, 1900
    string month, comma;
    int day, year;
    cin >> month;
    cin >> day;
    cin >> comma;
    cin >> year;
    
    cout << month << " " << day << " " << year << endl;
    */
    
    double n = 77.0/3.0;
    cout << n << " " << setprecision(1) << scientific << n << endl;
    
    return 0;
}