#include <iostream>

using namespace std;

class MyVector{
    public:
    MyVector(){
        allocatedSize = 3;
        a = new int[allocatedSize];
        nextIndex = 0;
    }
    
    void push_back(const int& x){
        if(nextIndex == allocatedSize){
            cout << "Out of space! Allocating more..." << endl;
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

int main(){
    MyVector v;
    v.push_back(5);
    v.push_back(13);
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(13);
    v.push_back(7);
    v.push_back(1);
    
    v.at(1) = 23;
    
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    return 0;
}