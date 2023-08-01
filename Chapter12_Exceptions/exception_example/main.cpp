#include <iostream>
#include <stdexcept>

using namespace std;

int getUserAge(){
    int userAge;
    cin >> userAge;
        
    if(userAge < 0){
        throw runtime_error("Invalid Age.");
    }
    
    return userAge;
}

int main(){
    int avgMaxHeartRate;
    
    try{
        avgMaxHeartRate = 220 - getUserAge();
        
        cout << "Avg: " << avgMaxHeartRate << endl;
    }
    catch(const runtime_error& e){
        cout << "runtime error caught!" << endl;
        cout << e.what() << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    };
    
    return 0;
}