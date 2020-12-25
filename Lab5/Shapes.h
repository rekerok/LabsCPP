#pragma once
class Shape {
private:
    int x, y, size;
public:
    Shape();
    Shape(int x, int y, int size);
    int GetX();
    int GetY();
    int GetSize();
    void SetX(int x);
    void SetY(int y);
    void SetSize(int size);
    void SetXandY(int x, int y);
    void SetUp(int up);
    void SetRight(int right);
    void SetDown(int down);
    void SetLeft(int left);
    virtual void GetInfo() = 0;
    virtual float GetPerimetr() = 0;
    virtual float GetArea() = 0;
};

class Square : private Shape {
private:
public:
    Square();
    Square(int x, int y, int lenght);
    void GetInfo() override;
    float GetPerimetr() override;
    float GetArea() override;
};


class Ellipse : public Shape {
private:
    int width, height;
public:
    Ellipse();
    Ellipse(int x, int y, int width, int height);   

    int GetWidth();
    int GetHeight();
    void SetWidth(int width);
    void SetHeight(int height);
    void GetInfo() override;
    float GetPerimetr() override;
    float GetArea() override;

};

class Circle : public Shape {
private:
public:
    Circle();
    Circle(int x, int y, int radius);
    void GetInfo() override;
    float GetPerimetr() override;
    float GetArea() override;
};