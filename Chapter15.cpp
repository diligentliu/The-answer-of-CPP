#include <iostream>
#include "Fifteen.h"
using namespace std;
/*15_1
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
/*15_2
#include <cmath>
double hmean(double a, double b);
double gmean(double a, double b);
int main() {
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_hmean &bg) {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean &hg) {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!";
    return 0;
}
double hmean(double a, double b) {
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) {
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return sqrt(a * b);
}
*/