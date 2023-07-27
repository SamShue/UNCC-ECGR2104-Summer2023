#include <iostream>
#include <sstream>

using namespace std;

class Person {
    public:
    Person(string name, int id){
        this->name = name;
        setId(id);
    }
    
    void setName(string name){
        this->name = name;
    }
    
    void setId(int id){
        if(id >= 800000000)
            this->id = id;
        else
            this->id = -1;
    }
    
    string getName() const {
        return name;
    }
    
    int getId() const {
        return id;
    }
    
    string toString(){
        stringstream ss;
        ss << "Name: " << name << "\nID: " << id << endl;
        return ss.str();
    }
    
    protected:
    string name;
    int id;
};

class Student : public Person {
    public:
    Student(string name, int id, double gpa) : Person(name, id) {
        setGpa(gpa);
    }
    
    void setGpa(double gpa){
        if(gpa > 0.0 && gpa <= 4.0){
            this->gpa = gpa;
        } else {
            this->gpa = 4.0;
        }
    }
    
    double getGpa() const {
        return gpa;
    }
    
    string toString(){
        stringstream ss;
        ss << "Name: " << name << "\nID: " << id << "\nGPA: " << gpa << endl;
        return ss.str();
    }
    
    private:
    double gpa;
};

class Faculty : public Person {
    public:
    Faculty(string name, int id, double salary) : Person(name, id) {
        setSalary(salary);
    }
    
    void setSalary(double gpa){
        if(salary > 0.0){
            this->salary = salary;
        } else {
            this->salary = 0.0;
        }
    }
    
    double getSalary() const {
        return salary;
    }
    
    private:
    double salary;
};

int main(){
    Student s("Sam", 800387310, 2.7);
    Faculty f("Jim", 800234123, 120000);
    
    cout << s.toString() << endl;
    cout << f.toString() << endl;
    
    return 0;
}