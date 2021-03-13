#include <iostream>

void Smile() { std::cout << "Smile!"; }

int main() {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 3; j >= i; --j) Smile();
        std::cout << std::endl;
    }
    return 0;
}