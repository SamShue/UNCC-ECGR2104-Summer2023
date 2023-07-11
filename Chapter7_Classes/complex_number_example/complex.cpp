#include "complex.h"

Complex::Complex(){
    this->real = 0.0;
    this->imag = 0.0;
}

Complex::Complex(const double& real){
    this->real = real;
    this->imag = 0.0;
}

Complex::Complex(const double& real, const double& imag){
    this->real = real;
    this->imag = imag;
}

Complex Complex::add(const Complex& rhs){
    return Complex(real + rhs.real, imag + rhs.imag);
}

Complex Complex::add(const double& rhs){
    return Complex(real + rhs, imag);
}

Complex Complex::operator+(const Complex& rhs){
    return Complex(real + rhs.real, imag + rhs.imag);
}

Complex Complex::operator+(const double& rhs){
    return Complex(real + rhs, imag);
}

Complex Complex::operator-(const Complex& rhs){
    return Complex(real - rhs.real, imag - rhs.imag);
}

Complex Complex::operator-(const double& rhs){
    return Complex(real - rhs, imag);
}

void Complex::print(){
    std::cout << real << " + " << imag << "i" << std::endl;
}