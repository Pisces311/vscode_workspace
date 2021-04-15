#include <iostream>

#include "sales.h"
using namespace std;

int main() {
    cout << "Non-interactive version of setSales() to provide values:" << endl;
    double ar[] = {345.2, 621.8, 1073.5};
    SALES::Sales a, b;
    SALES::setSales(a, ar, 3);
    SALES::showSales(a);
    cout << "Interactive version of setSales() to provide values:" << endl;
    SALES::setSales(b);
    SALES::showSales(b);
    return 0;
}