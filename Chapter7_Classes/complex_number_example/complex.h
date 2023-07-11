#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

struct Complex {
    Complex();
    Complex(const double& real);
    Complex(const double& real, const double& imag);
    
    Complex add(const Complex& rhs);
    Complex add(const double& rhs);
    Complex operator+(const Complex& rhs);
    Complex operator+(const double& rhs);
    Complex operator-(const Complex& rhs);
    Complex operator-(const double& rhs);
    
    void print();
    
    double real;
    double imag;
};

#endif