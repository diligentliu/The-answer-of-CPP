#include <iostream>
#include "Fifteen.h"
using namespace std;
/* 15_1
int main() {
    using std::cout;
    Tv s42;
    cout << "Initial setting for 42\"TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted setting for 42\"TV:\n";
    s42.settings();
    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.voldown(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    Tv s58(Remote::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();
    return 0;
}
*/