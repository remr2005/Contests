#include <cmath>

class Shape {
public:
    std :: vector<double> a;
    Shape() {
    }
    Shape(int b) {
        this->a.push_back(b);
    }
    double getPerimeter() {
        double sum = 0;
        for (auto i : a) {
            sum += i;
        }
        return sum;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int a, int b) {
        this->a.push_back(a);
        this->a.push_back(b);
        this->a.push_back(a);
        this->a.push_back(b);
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a, int b, int c) {
        this->a.push_back(a);
        this->a.push_back(b);
        this->a.push_back(c);
        if (!((this->a[0] + this->a[1] > this->a[2]) and (this->a[0] + this->a[2] > this->a[1]) and (this->a[2] + this->a[1] > this->a[0]))) {
            this->a.pop_back();
            this->a.pop_back();
            this->a.pop_back();
            this->a.push_back(0);
        }
    }
};

class Circle : public Shape
{
public:
    Circle(int a) {
        double buf = a;
        this->a.push_back(buf*2* M_PI);
    }
};
