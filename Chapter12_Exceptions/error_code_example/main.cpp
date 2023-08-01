#include <iostream>
#include <stdlib.h>

using namespace std;

typedef enum {NO_ERROR, INVALID_INPUT, DIVIDE_BY_ZERO} ErrorCode_t;

ErrorCode_t getFractionFromUser(double& n){
    double numerator, denominator;
    
    string temp;
    getline(cin, temp);
    numerator = atof(temp.c_str());
    if(numerator < 0.0000001){
        // user did not enter an integer
        return INVALID_INPUT;
    }
    
    getline(cin, temp);
    denominator = atof(temp.c_str());
    if(denominator < 0.0000001){
        // user did not enter an integer or entered 0
        return DIVIDE_BY_ZERO;
    }
    
    n = numerator / denominator;
    return NO_ERROR;
}

int main(){
    double n;
    switch(getFractionFromUser(n)){
        case INVALID_INPUT:
        cout << "No proper numerical value entered for numerator." << endl;
        break;
        case DIVIDE_BY_ZERO:
        cout << "Divide by zero error." << endl;
        break;
        default:
        cout << n << endl;
        break;
    }
    
    return 0;
}