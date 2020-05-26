#include <iostream>
#include "Fifteen.h"
//15_1
void Remote::show_Rmode() {
    std::cout << "Status = " << (Rmode == Normal ? "Normal" : "Interactive") << std::endl;
}
int & Remote::get_Rmode() {
    return Rmode;
}
bool Tv::volup() {
    if (volume >= Remote::MaxVal)
        return false;
    ++volume;
    return true;
}
bool Tv::voldown() {
    if (volume <= Remote::MinVal)
        return false;
    --volume;
    return true;
}
bool Tv::set_Rmode(Remote & R) {
    if (state == Remote::Off)
        return false;
    R.get_Rmode() = (R.get_Rmode() == Remote::Interactice ? Remote::Normal : Remote::Interactice);
    return true;
}
void Tv::chanup() {
    if (channel >= maxchannel)
        channel = 1;
    else
        ++channel;
}
void Tv::chandown() {
    if (channel == 1)
        channel = maxchannel;
    else
        --channel;
}
void Tv::settings() const {
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "TV is " << (state == Remote::Off ? "Off" : "On") << endl;
    if (state == Remote::On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Remote::Antenna ? "antenna" : "cable") << endl;
        cout << "input = " << (input == Remote::TV ? "TV" : "DVD") << endl;
    }
}