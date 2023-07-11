#include <iostream>
#include "complex.h"

using namespace std;

int main(){
    Complex x(4.0, 2.0);
    Complex y(3.3, 2.2);
    
    double z = 5.0;
    
    //Complex t = x.add(y);
    Complex t = x + y;
    t = t + z;
    
    t = (Complex)z + t;
    
    t.print();
    
    t = t - x;
    
    t.print();
    
    /*
    double x_real = 4.0;
    double x_imag = 2.0;
    
    double y_real = 3.3;
    double y_imag = 2.2;
    
    double t_real = x_real + y_real;
    double t_imag = x_imag + y_imag;
    
    cout << "The sum of the imaginary numbers is: " << t_real << " + " << t_imag << "i." << endl;
    */
    
    return 0;
}