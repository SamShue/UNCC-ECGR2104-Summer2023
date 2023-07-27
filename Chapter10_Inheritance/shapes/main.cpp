#include <iostream>

using namespace std;

// Right Triangle, Rectangles, Squares
class Shape {
    public:
    Shape(double height, double width){
        setHeight(height);
        setWidth(width);
    }
    
    void setHeight(double height){
        if(height >= 0.0){
            this->height = height;
        } else {
            this->height = 0.0;
        }
    }
    
    void setWidth(double width){
        if(width >= 0.0){
            this->width = width;
        } else {
            this->width = 0.0;
        }
    }
    
    protected:
    double height, width;
};

class Rectangle : public Shape {
    public:
    Rectangle(double height, double width) : Shape(height, width) {}
    
    double computeArea() const {
        return height * width;
    }
};

class Square : public Rectangle {
    public:
    Square(double height) : Rectangle(height, height) {}
};

class RightTriangle : public Shape {
    public:
    RightTriangle(double height, double width) : Shape(height, width) {}
    
    double computeArea() const {
        return 0.5 * height * width;
    }
};


int main(){
    
    RightTriangle rt(4.0, 8.0);
    Rectangle r(4.0, 8.0);
    Square s(4.0);
    
    cout << "Triangle Area: " << rt.computeArea() << endl;
    cout << "Rectangle Area: " << r.computeArea() << endl;
    cout << "Square Area: " << s.computeArea() << endl;
    
    return 0;
}