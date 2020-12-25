#define _USE_MATH_DEFINES
#include "Shapes.h"
#include <iostream>
#include <cmath>
using namespace std;

Shape::Shape() {
    this->x = this->y = 0;
}
Shape::Shape(int x, int y, int size) {
    this->x = x;
    this->y = y;
    this->size - size;
}
int Shape::GetX() { return this->x; }
int Shape::GetY() { return this->y; }
int Shape::GetSize() { return this->size; }
void Shape::SetX(int x) { this->x = x; }
void Shape::SetY(int y) { this->y = y; }
void Shape::SetSize(int size) { this->size = size; }
void Shape::SetXandY(int x, int y) { this->x = x, this->y = y; }
void Shape::SetUp(int up) { this->y += up; }
void Shape::SetRight(int right) { this->x += right; }
void Shape::SetDown(int down) { this->y -= down; }
void Shape::SetLeft(int left) { this->x -= left; }


Square::Square() : Shape() {};
Square::Square(int x, int y, int lenght) : Shape(x, y, lenght) {};
void Square::GetInfo() {
    cout << "x1 = " << Shape::GetX() << "\ty1 = " << Shape::GetY() << endl;
    cout << "x2 = " << Shape::GetX() + Shape::GetSize() << "\ty2 = " << Shape::GetY() << endl;
    cout << "x3 = " << Shape::GetX() + Shape::GetSize() << "\ty3 = " << Shape::GetY() - Shape::GetSize() << endl;
    cout << "x4 = " << Shape::GetX() << "\ty4 = " << Shape::GetY() - Shape::GetSize() << endl;
    
    cout << endl;
}
float Square::GetPerimetr() { return Shape::GetSize() * 4; }
float Square::GetArea() { return pow(Shape::GetSize(), 2); }


Ellipse::Ellipse() : Shape() {};
Ellipse::Ellipse(int x, int y, int width, int height) : Shape(x, y, 0) {
    this->width = width;
    this->height = height;
};
int Ellipse::GetWidth() { return this->width;}
int Ellipse::GetHeight() { return this->height; }
void Ellipse::SetWidth(int width) { this->width = width; }
void Ellipse::SetHeight(int Height) { this->height = height; }
void Ellipse::GetInfo() {
    cout << "x1 = " << Shape::GetX() << "\ty1 = " << Shape::GetY() << endl;
    cout << "x2 = " << Shape::GetX() + Ellipse::GetWidth() << "\ty2 = " << Shape::GetY() << endl;
    cout << "x3 = " << Shape::GetX() + Ellipse::GetWidth() << "\ty3 = " << Shape::GetY() - Ellipse::GetWidth() << endl;
    cout << "x4 = " << Shape::GetX() - Ellipse::GetHeight() << "\ty4 = " << Shape::GetY() << endl;
    cout << endl;
}
float Ellipse::GetPerimetr() { return  2 * M_PI * sqrt((pow(Ellipse::GetHeight(), 2) + pow(Ellipse::GetWidth(), 2)) / 2); }
float Ellipse::GetArea() { return M_PI * Ellipse::GetHeight() * Ellipse::GetWidth(); }


Circle::Circle() :Shape() {};
Circle::Circle(int x, int y, int radius) :Shape(x, y, radius) {};
void Circle::GetInfo() {
    cout << "x = " << Shape::GetX() << "\ty = " << Shape::GetY() << endl;
    cout << endl;
}
float Circle::GetPerimetr() { return 2 * M_PI * Shape::GetSize(); }
float Circle::GetArea() { return M_PI * pow(Shape::GetSize(), 2); }