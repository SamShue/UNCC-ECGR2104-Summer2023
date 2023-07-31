#include <iostream>
#include <sstream>
#include <vector>

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
    
    virtual string toString() = 0;
    
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
    
    void setSalary(double salary){
        if(salary > 0.0){
            this->salary = salary;
        } else {
            this->salary = 0.0;
        }
    }
    
    double getSalary() const {
        return salary;
    }
    
    string toString(){
        stringstream ss;
        ss << "Name: " << name << "\nID: " << id << "\nSalary: " << salary << endl;
        return ss.str();
    }
    
    private:
    double salary;
};

int main(){
    vector<Person*> database;
    database.push_back(new Student("Sam", 800387310, 2.7));
    database.push_back(new Faculty("Jim", 800234123, 120000));
    //database.push_back(new Person("Jeremy", 800210321));
    
    for(int i = 0; i < database.size(); i++){
        cout << database.at(i)->toString() << endl;
    }
    
    return 0;
}