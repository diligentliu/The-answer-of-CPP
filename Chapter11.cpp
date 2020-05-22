#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Eleven.h"
using namespace std;

/*11_1
int main() {
    using VECTOR::Vector;
    ofstream fout;
    fout.open("Eleven_1.txt");
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int i = 0;
    cout << "Enter target distance (q ti quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        fout << "Target Distance: " << target << ", ";
        if (!(cin >> dstep))
            break;
        fout << "Step Size: " << dstep << endl;
        while (result.magval() < target) {
            fout << i << ": " << result << endl;
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            ++steps;
            ++i;
        }
        fout << "After " << steps << "steps, the subject has the following location: \n";
        fout << result << endl;
        result.polar_mode();
        fout << "or\n" << result << endl;
        fout << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
        fout.close();
    }
    cout << "Bye!";
    return 0;
}
*/
/*11_2//Same as the main program of the previous question.
      //The interface representing the class has not changed.
int main(){
    using VECTOR::Vector;
    ofstream fout;
    fout.open("Eleven_1.txt");
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int i = 0;
    cout << "Enter target distance (q ti quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        fout << "Target Distance: " << target << ", ";
        if (!(cin >> dstep))
            break;
        fout << "Step Size: " << dstep << endl;
        while (result.magval() < target) {
            fout << i << ": " << result << endl;
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            ++steps;
            ++i;
        }
        fout << "After " << steps << "steps, the subject has the following location: \n";
        fout << result << endl;
        result.polar_mode();
        fout << "or\n" << result << endl;
        fout << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
        fout.close();
    }
    cout << "Bye!";
    return 0;
}
*/
/*11_3
int main() {
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0, M_step = 0, m_step = 0, aver_step = 0;
    int n = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q ti quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target) {
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            ++steps;
        }
        if (steps > M_step)
            M_step = steps;
        if (n == 0)
            m_step = steps;
        if (steps < m_step)
            m_step = steps;
        aver_step += steps;
        ++n;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    aver_step /= n;
    cout << "Maximum steps: " << M_step << endl;
    cout << "Minimum steps: " << m_step << endl;
    cout << "Average steps: " << aver_step;
    return 0;
}
*/
/*11_4
int main() {
    Time wedding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;
    cout << "weeding time = ";
    wedding.Show();
    cout << endl;
    cout << "waxing time = ";
    waxing.Show();
    cout << endl;
    cout << "total work time = ";
    total = wedding + waxing;
    total.Show();
    cout << endl;
    diff = wedding - waxing;
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;
    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;
    return 0;
}
*/
/*11_5
int main(){
    Stonewt St1(100.0);
    cout << St1 << endl;
    St1.set_st_p();
    cout << St1 << endl;
    Stonewt St2(20,7.0);
    cout << St2 << endl;
    St2.set_po();
    cout << St2 << endl;
    Stonewt St = St1 + St2;
    St.set_po();
    cout << St << endl;
    St = St1 - St2;
    cout << St << endl;
    St.set_st_p();
    cout << St << endl;
    St.set_po();
    St = 2 * St1;
    cout << St << endl;
    St = Stonewt();
    St1 = Stonewt();
    St2 = Stonewt();
    return 0;
}
*/
/*11_6
int main() {
    using STONEWT::Stonewt;
    Stonewt St[6];
    int count[6] = {6, 6, 6, 6, 6, 6}, j = 0;
    for (int i = 0; i < 3; ++i) {
        int stn;
        double lbs;
        cin >> stn >> lbs;
        St[i] = Stonewt(stn, lbs);
    }
    Stonewt max_St = St[0];
    Stonewt min_St = St[0];
    Stonewt eleven_St = Stonewt(11, 0.0);
    for (int i = 0; i < 3; ++i) {
        if (St[i] > max_St)
            max_St = St[i];
        if (St[i] < min_St)
            min_St = St[i];
        if (St[i] >= eleven_St) {
            count[j] = i;
            ++j;
        }
    }
    cout << "The Largest Element is: " << max_St << endl;
    cout << "The Smallest Element is: " << min_St << endl;
    cout << "Element greater than or equal to 11 pounds are: " << endl;
    j = 0;
    while (count[j] != 6) {
        cout << St[count[j]] << endl;
        ++j;
    }
}
*/
/*11_7
int main() {
    Complex a(3.0,4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c){
        cout << "c is " << c << endl;
        cout << "Complex conjugate is " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a + c is " << a + c << endl;
        cout << "a - c is " << a - c << endl;
        cout << "a * c is " << a * c << endl;
        cout << "2 * c is " << 2 * c << endl;
        cout << "Enter a complex number (q to quit):" << endl;
    }
    cout << "Done!";
    return 0;
}
*/