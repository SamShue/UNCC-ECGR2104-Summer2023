#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string month = "Feburary";
    int day = 1;
    int year = 1924;
    
    stringstream ss;
    
    ss << month << " " << day << ", " << year;
    
    cout << ss.str() << endl;
    
    return 0;
}