#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class MyVector{
    public:
    MyVector(){
        allocatedSize = 3;
        a = new T[allocatedSize];
        nextIndex = 0;
        
        cout << a << endl;
    }
    
    MyVector(const MyVector& rhs){
        cout << "Copy Constructor called!" << endl;
        allocatedSize = rhs.allocatedSize;
        nextIndex = rhs.nextIndex;
        a = new T[allocatedSize];
        for(int i = 0; i < nextIndex; i++){
            a[i] = rhs.a[i];
        }
    }
    
    ~MyVector(){
        cout << "Destructor called!" << endl;
        delete[] a;
    }
    
    void operator=(const MyVector& rhs){
        cout << "Copy assignment operator called!" << endl;
        delete[] a;
        
        allocatedSize = rhs.allocatedSize;
        nextIndex = rhs.nextIndex;
        a = new int[allocatedSize];
        for(int i = 0; i < nextIndex; i++){
            a[i] = rhs.a[i];
        }
    }
    
    void push_back(const T& x){
        if(nextIndex == allocatedSize){
            cout << "Out of space! Allocating more..." << endl;
            T* temp = new T[allocatedSize + 3];
            for(int i = 0; i < allocatedSize; i++){
                temp[i] = a[i];
            }
            allocatedSize = allocatedSize + 3;
            delete[] a;
            a = temp;
        }
        
        a[nextIndex] = x;
        nextIndex++;
    }
    
    void pop_back(){
        if(nextIndex == 0)
            return;
        
        nextIndex--;
    }
    
    T& at(int index) const{
        if(index >= nextIndex){
            throw out_of_range("Index out of range.");
        }
        return a[index];
    }
    
    int size() const{
        return nextIndex;
    }
    
    private:
    T* a;
    int nextIndex;
    int allocatedSize;
};

void makesABigProblem(){
    MyVector<int> v;
    v.push_back(5);
    v.push_back(13);
    v.push_back(7);
    
    MyVector<int> v2 = v;
    
    v2.at(1) = 23;
    
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    MyVector<int> v3;
    v3.push_back(13);
    v3.push_back(8);
    
    v3 = v2;
    
    MyVector<double> v4;
    v4.push_back(3.5);
    
    v4.at(200);
}

int main(){
    makesABigProblem();
    makesABigProblem();
    makesABigProblem();
    
    return 0;
}