#include <iostream>
#include <cstring>

struct stringy {
    char * str;
    int ct;
};

void set(stringy &s, const char *str) {
    int len = strlen(str);
    char *block = new char[len + 1];
    strcpy(block, str);
    s.str = block;
    s.ct = len;
    delete[] block;
}

void show(const stringy &s, int times = 1) {
    for (int i = 0; i < times; i++) {
        printf("%s\n", s.str);
    }
}

void show(const char *str, int times = 1) {
    for (int i = 0; i < times; i++) {
        printf("%s\n", str);
    }
}

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    
    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}