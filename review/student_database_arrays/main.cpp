#include <iostream>
#include <string>

using namespace std;

int main(){
    const unsigned int NUM_STUDENTS = 5;
    
    string name[NUM_STUDENTS];
    int id[NUM_STUDENTS];
    double gpa[NUM_STUDENTS];
    
    //int i = 0;
    //while(i < num_students){
    for(int i = 0; i < NUM_STUDENTS; i++){
        cout << "Enter the student's name: " << endl;
        getline(cin, name[i]);
        
        double total = 0.0;
        double userInput = 0.0;
        double numGrades = 0.0;
        while(userInput >= 0.0){
            cout << "Enter the student's grade (enter -1 to quit): " << endl;
            string temp;
            getline(cin, temp);
            userInput = stod(temp);
            if(userInput >= 0.0){
                //total = total + userInput;
                total += userInput;
                //numGrades = numGrades + 1.0;
                numGrades++;
            }
        }
        gpa[i] = total / numGrades;
        id[i] = i;
        //i++;
    }
    
    //i = 0;
    //while(i < NUM_STUDENTS){
    for(int i = 0; i < NUM_STUDENTS; i++){
        cout << "Student Name: " << name[i] << endl;
        cout << "Student ID: " << id[i] << endl;
        cout << "GPA: " << gpa[i] << endl;
    }
    
    return 0;
}