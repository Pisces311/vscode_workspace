#include <bits/stdc++.h>
using namespace std;

class CStereoShape {
    static int numberOfObject;

   public:
    CStereoShape() { numberOfObject++; }
    virtual double GetArea() {
        cout << "CStereoShape::GetArea()" << endl;
        return 0.0;
    }
    virtual double GetVolume() {
        cout << "CStereoShape::GetVolume()" << endl;
        return 0.0;
    }
    virtual void Show() { cout << "CStereoShape::Show()" << endl; }
    int GetNumOfObject() { return numberOfObject; }
};

int CStereoShape::numberOfObject = 0;

class CCube : public CStereoShape {
    double length, width, height;

   public:
    CCube() {}
    CCube(double l, double w, double h) : length(l), width(w), height(h) {}
    CCube(const CCube &o)
        : length(o.length), width(o.width), height(o.height) {}
    double GetArea() {
        return 2 * (length * height + length * width + width * height);
    }
    double GetVolume() { return length * width * height; }
    void Show() {
        cout << "Cube length: " << length << " width: " << width
             << " height: " << height << endl;
        cout << "Cube area: " << GetArea() << " volume: " << GetVolume()
             << endl;
    }
};

class CSphere : public CStereoShape {
    double radius;
    constexpr static double pi = 3.14;

   public:
    CSphere() {}
    CSphere(double r) : radius(r) {}
    CSphere(const CSphere &o) : radius(o.radius) {}
    double GetArea() { return 4 * pi * radius * radius; }
    double GetVolume() { return 4 / 3.0 * pi * radius * radius * radius; }
    void Show() {
        cout << "Sphere radius: " << radius << " area: " << GetArea()
             << " volume: " << GetVolume() << endl;
    }
};

int main() {
    CCube a_cube(4.0, 5.0, 6.0);
    CSphere c_sphere(7.9);
    CStereoShape *p = &a_cube;
    p->Show();
    p = &c_sphere;
    p->Show();
    cout << p->GetNumOfObject() << " objects are created." << endl;
    return 0;
}