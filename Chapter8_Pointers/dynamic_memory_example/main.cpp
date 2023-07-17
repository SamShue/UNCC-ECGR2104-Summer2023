#include <iostream>

using namespace std;

int main(){
    
    // create a single variable on the heap
    int* p = new int(10);
    
    *p = 5;
    
    cout << p <<endl;
    cout << *p << endl;
    
    delete p;
    
    // create an array on the heap
    int* a = new int[3];
    
    a[0] = 5;
    a[1] = 2;
    a[2] = 7;
    
    cout << a << endl;
    cout << a[0] << " " << *(a + 1) << " " << a[2] << endl;
    
    delete[] a;
    
    return 0;
}