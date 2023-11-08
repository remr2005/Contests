#include<cmath>
class Point {
public:
    double x;
    double y;
    double r;
    double a;
    double get_x() {
        return x;
    }
    double get_y() {
        return y;
    }
    double get_r() {
        return r;
    }
    double get_a() {
        return a;
    }
    void set_x(double c) {
        x = c;
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }
    void set_y(double c) {
        y = c;
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }
    void set_r(double c) {
        r = c;
        x = r * cos(a);
        y = r * sin(a);
    }
    void set_a(double c) {
        a = c;
        x = r * cos(a);
        y = r * sin(a);
    }
    Point(double c, double b) {
        x = c;
        y = b;
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }
};