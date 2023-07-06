#include <iostream>
#include <string>

using namespace std;

int main(){
    const unsigned int NUM_STUDENTS = 1000;
    
    string name[NUM_STUDENTS];
    int id[NUM_STUDENTS];
    double gpa[NUM_STUDENTS];
    
    unsigned int total_students = 0;
    
    int i = 0;
    while(true){
        cout << "Enter the student's name (or enter 'q' to quit): " << endl;
        getline(cin, name[i]);
        
        if(name[i] == "q"){
            break;
        }
        
        total_students++;
        
        double total = 0.0;
        double userInput = 0.0;
        double numGrades = 0.0;
        while(userInput >= 0.0){
            cout << "Enter the student's grade (enter -1 to quit): " << endl;
            string temp;
            getline(cin, temp);
            userInput = stod(temp);
            if(userInput >= 0.0){
                total += userInput;
                numGrades++;
            }
        }
        gpa[i] = total / numGrades;
        id[i] = i;
        i++;
    }
    
    for(int i = 0; i < total_students; i++){
        cout << "Student Name: " << name[i] << endl;
        cout << "Student ID: " << id[i] << endl;
        cout << "GPA: " << gpa[i] << endl;
    }
    
    return 0;
}