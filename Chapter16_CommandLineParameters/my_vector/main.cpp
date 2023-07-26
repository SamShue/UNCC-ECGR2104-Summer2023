#include <iostream>
#include <cstring>

using namespace std;

bool debugMode = false;

class MyVector{
    public:
    MyVector(){
        allocatedSize = 3;
        a = new int[allocatedSize];
        nextIndex = 0;
        
        if(debugMode) cout << a << endl;
    }
    
    MyVector(const MyVector& rhs){
        if(debugMode) cout << "Copy Constructor called!" << endl;
        allocatedSize = rhs.allocatedSize;
        nextIndex = rhs.nextIndex;
        a = new int[allocatedSize];
        for(int i = 0; i < nextIndex; i++){
            a[i] = rhs.a[i];
        }
    }
    
    ~MyVector(){
        if(debugMode) cout << "Destructor called!" << endl;
        delete[] a;
    }
    
    void operator=(const MyVector& rhs){
        if(debugMode) cout << "Copy assignment operator called!" << endl;
        delete[] a;
        
        allocatedSize = rhs.allocatedSize;
        nextIndex = rhs.nextIndex;
        a = new int[allocatedSize];
        for(int i = 0; i < nextIndex; i++){
            a[i] = rhs.a[i];
        }
    }
    
    void push_back(const int& x){
        if(nextIndex == allocatedSize){
            if(debugMode) cout << "Out of space! Allocating more..." << endl;
            int* temp = new int[allocatedSize + 3];
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
    
    int& at(int index) const{
        return a[index];
    }
    
    int size() const{
        return nextIndex;
    }
    
    private:
    int* a;
    int nextIndex;
    int allocatedSize;
};

void makesABigProblem(){
    MyVector v;
    v.push_back(5);
    v.push_back(13);
    v.push_back(7);
    
    MyVector v2 = v;
    
    v2.at(1) = 23;
    
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    MyVector v3;
    v3.push_back(13);
    v3.push_back(8);
    
    v3 = v2;
}

int main(int argc, char* argv[]){
    
    // look for -d or --debug
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i],"-d") == 0 || strcmp(argv[i],"--debug") == 0){
            debugMode = true;
        }
        
        if(strcmp(argv[i], "--help") == 0){
            cout << "-d / --debug\tEnable verbose debug mode" << endl;
            cout << "--help\t\tDisplay this information" << endl;
            return 0;
        }
    }
    
    makesABigProblem();
    makesABigProblem();
    makesABigProblem();
    
    return 0;
}