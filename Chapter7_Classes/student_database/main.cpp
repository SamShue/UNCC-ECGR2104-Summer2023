#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Student{
    public:
    Student(const string& n, const int& i){
        name = n;
        gpa = DEFAULT_GPA;
        setId(i);
    }
    
    Student(const string& n, const int& i, const double& g){
        name = n;
        setGpa(g);
        setId(i);
    }
    
    static double computeGpa(double grades[], const unsigned int& numGrades) {
        double total = 0.0;
        for(int i = 0; i < numGrades; i++){
            if(grades[i] < 0.0 || grades[i] > 4.0)
                continue;
            total += grades[i];
        }
        return total/(double)numGrades;
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
    
    void setGpa(double grades[], unsigned int size){
        gpa = computeGpa(grades, size);
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
    
    static double DEFAULT_GPA;
    
    private:
    string name;
    int id;
    double gpa;
};

double Student::DEFAULT_GPA = 4.0;

int main(){
    double grades[] = {3.0, 2.0, 3.0, 4.0};
    //Student s("Not an acutal student", 0);
    double gpa = Student::computeGpa(grades, 4);
    double gpa2 = Student::DEFAULT_GPA;
    
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