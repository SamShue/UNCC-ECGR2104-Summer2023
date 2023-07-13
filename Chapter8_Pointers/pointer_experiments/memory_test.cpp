#include <iostream>

using namespace std;

int main(){
    int x = 0x00FF0000;
    
    char* p = (char*)(((long int)&x) + 2);
    
    cout << (int)*p << endl;
    
    return 0;
}