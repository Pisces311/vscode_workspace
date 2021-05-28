// use_tv.cpp -- using the Tv and Remote classes
#include <iostream>

#include "tv.h"

int main() {
    using std::cout;
    Tv s42;
    Remote grey;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();

    grey.display_state();
    s42.toggle(grey);

    s42.onoff();
    s42.chanup();

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();

    cout << "After toggling the Remote state:\n";
    s42.toggle(grey);
    grey.display_state();

    return 0;
}