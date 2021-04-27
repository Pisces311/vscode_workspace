#include <iostream>
using namespace std;

class Rectangle {
    double width, height;
    int getArea() { return width * height; }
    int getPerimeter() { return 2 * (width + height); }

   public:
    Rectangle() : width(1), height(1) {}
    Rectangle(double w, double h) : width(w), height(h) {}

    void display() {
        cout << "Width:\t" << width << endl;
        cout << "Height:\t" << height << endl;
        cout << "Area:\t" << getArea() << endl;
        cout << "Perimeter:\t" << getPerimeter() << endl;
    }
};

int main() {
    Rectangle r1(4, 40), r2(3.5, 35.9);
    cout << "Rectangle 1" << endl;
    cout << "--------------" << endl;
    r1.display();
    cout << "Rectangle 2" << endl;
    cout << "--------------" << endl;
    r2.display();
    return 0;
}