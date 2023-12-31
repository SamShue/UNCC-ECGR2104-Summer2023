#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> name;
    vector<int> id;
    vector<double> gpa;
    
    int i = 0;
    while(true){
        string temp;
        cout << "Enter the student's name (or enter 'q' to quit): " << endl;
        getline(cin, temp);
        
        if(temp == "q"){
            break;
        }
        
        name.push_back(temp);
        
        double total = 0.0;
        double userInput = 0.0;
        double numGrades = 0.0;
        while(userInput >= 0.0){
            cout << "Enter the student's grade (enter -1 to quit): " << endl;
            
            getline(cin, temp);
            userInput = stod(temp);
            if(userInput >= 0.0){
                total += userInput;
                numGrades++;
            }
        }
        gpa.push_back(total / numGrades);
        id.push_back(i);
        i++;
    }
    
    for(int i = 0; i < name.size(); i++){
        cout << "Student Name: " << name.at(i) << endl;
        cout << "Student ID: " << id[i] << endl;
        cout << "GPA: " << gpa[i] << endl;
    }
    
    return 0;
}