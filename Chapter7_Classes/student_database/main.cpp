#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Student{
    public:
    Student(const string& n, const int& i){
        name = n;
        gpa = 4.0;
        setId(i);
    }
    
    Student(const string& n, const int& i, const double& g){
        name = n;
        setGpa(g);
        setId(i);
    }
    
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
    
    void setGpa(const double& g){
        if(g > 4.0 || g < 0.0){
            gpa = 0.0;
            return;
        }
        gpa = g;
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

    studentVector.push_back(Student("Sam", 800387310, 2.8));
    studentVector.push_back(Student("Joe", 3));
    studentVector.push_back(Student("Mark", 800123456, 5.0));
    
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