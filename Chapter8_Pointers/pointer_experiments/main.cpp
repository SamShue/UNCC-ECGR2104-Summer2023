#include <iostream>

using namespace std;

// get number 1 - 10 from user
bool getNumberFromUser(int* userNum){
    cin >> *userNum;
    if(*userNum > 0 && *userNum < 11)
        return true;
    else
        return false;
}

int main(){
    int secretNum = 7;
    int guess;
    int* guessPointer = &guess;
    
    while(!getNumberFromUser(guessPointer));
    
    if(guess == secretNum){
        cout << "You win! Congrats big boy!" << endl;
    } else {
        cout << "I'm really disappointed in you." << endl;
    }
    
    return 0;
}