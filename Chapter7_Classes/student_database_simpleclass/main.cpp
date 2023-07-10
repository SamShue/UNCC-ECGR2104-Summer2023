#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student{
    public:
    void computeGpa(double grades[], const unsigned int& numGrades){
        double total = 0.0;
        for(int i = 0; i < numGrades; i++){
            total += grades[i];
        }
        gpa = total/(double)numGrades;
    }
    
    // mutator / setter
    void setName(const string& n){
        name = n;
    }
    
    void setId(const int& i){
        if(i < 800000000){
            id = -1;
            return;
        }
            
        id = i;
    }
    
    // accessor / getter
    double getGpa() const {
        return gpa;
    }
    
    string getName() const {
        return name;
    }
    
    int getId() const {
        return id;
    }
    
    private:
    string name;
    int id;
    double gpa;
};

int main(){
    vector<Student> studentVector;
    
    double grades[] = {2.0, 2.0, 3.0};
    Student s;
    s.setName("Sam");
    s.setId(800387310);
    s.computeGpa(grades, 3);
    
    studentVector.push_back(s);

    double moreGrades[] = {4.0, 2.0, 1.0, 2.0};
    s.setName("Joe");
    s.setId(3);
    s.computeGpa(moreGrades, 4);
    
    studentVector.push_back(s);
    
    for(int i = 0; i < studentVector.size(); i++){
        cout << "Student Name: " << studentVector.at(i).getName() << endl;
        if(studentVector.at(i).getId() < 0){
            cout << "Student ID invalid!" << endl;
        } else {
            cout << "Student ID: " << studentVector.at(i).getId() << endl;
        }
        cout << "GPA: " << studentVector.at(i).getGpa() << endl;
    }
    
    return 0;
}