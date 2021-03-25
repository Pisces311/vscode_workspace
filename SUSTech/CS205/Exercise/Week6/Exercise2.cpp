#include <iostream>
using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void display(box b) {
    cout << "Maker: " << b.maker << endl;
    cout << "Height: " << b.height << endl;
    cout << "Width: " << b.width << endl;
    cout << "Length: " << b.length << endl;
    cout << "Volume: " << b.volume << endl;
}

void set_volume(box *p) {
    p->volume = p->height * p->width * p->length;
}

int main() {
    box b;
    strcpy(b.maker, "Jack Smith");
    b.height = 3.4;
    b.width = 4.5;
    b.length = 5.6;
    cout << "Before setting volume:" << endl;
    display(b);
    cout << "After setting volume:" << endl;
    set_volume(&b);
    display(b);
    return 0;
}