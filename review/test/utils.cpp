#include "utils.h"

double circleArea(const double& radius){
    const double PI = 3.14;
    double area = square(radius)*PI;
    return area;
}

double square(const double& val){
    return val * val;
}