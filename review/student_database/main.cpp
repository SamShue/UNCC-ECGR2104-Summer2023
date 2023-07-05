#include <iostream>

using namespace std;

int main(){
    string name;
    int id = 0;
    double gpa = 4.0;
    
    cout << "Enter the student's name: " << endl;
    getline(cin, name);
    
    double total = 0.0;
    double userInput = 0.0;
    double numGrades = 0.0;
    while(userInput >= 0.0){
        cout << "Enter the student's grade (enter -1 to quit): " << endl;
        cin >> userInput;
        if(userInput >= 0.0){
            //total = total + userInput;
            total += userInput;
            //numGrades = numGrades + 1.0;
            numGrades++;
        }
    }
    gpa = total / numGrades;
    
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "GPA: " << gpa << endl;
    
    return 0;
}