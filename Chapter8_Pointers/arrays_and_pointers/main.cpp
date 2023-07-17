#include <iostream>

using namespace std;

void foo(int* x){
    
    cout << *x << endl;
    cout << x[2] << endl;
    
}

int main(){
    
    int a[] = {5, 10, 11, 15, 20};
    
    foo(a);
    
    return 0;
}