#include <iostream>
#include "Twelve.h"
using namespace std;
/*12_1
int main(){
    Cow co1,co2,co3;
    co1=Cow("MuZhiyu","Coding",130.0);
    co1.ShowCow();
    co2 = Cow(co1);
    co2.ShowCow();
    co3=co1;
    co3.ShowCow();
    return 0;
}
*/
/*12_2
int main() {
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << endl;
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
         << "'A' characters in it.\n";
    s1 = "red";
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans) {
        ans.stringlow();
        for (int i = 0; i < 3; ++i) {
            if (ans == rgb[i]) {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye";
    return 0;
}
*/
/*12_3
const int STKS = 4;
int main(){
    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
            Stock("Fleep Enterprises", 60, 6.5)
    };
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout <<"Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; ++st)
        cout << stocks[st];
    Stock top = stocks[0];
    for (st = 1; st < STKS; ++st) {
        top = top.topval(stocks[st]);
    }
    cout <<"\nMost valuable holding:\n";
    cout << top;
    return 0;
}
*/
/*12_4
int main() {
    using STACK::Stack;
    Stack S;
    STACK::Item temp;
    cout << boolalpha << S.isempty() << endl;
    cout << boolalpha << S.isfull() << endl;
    for (int i = 0; i < 10; ++i) {
        S.pop(temp);
        cout << boolalpha << S.isempty() << endl;
        cout << boolalpha << S.isfull() << endl;
        cout << temp << endl;
    }
    Stack S2;
    cout << boolalpha << S2.isempty() << endl;
    cout << boolalpha << S2.isfull() << endl;
    S2 = S;
    cout << boolalpha << S2.isempty() << endl;
    cout << boolalpha << S2.isfull() << endl;
    return 0;
}
*/
/*12_5
#include <cstdlib>
#include <ctime>
const int MIN_PER_HR = 60;
bool newcustomer(double x);
int main() {
    std::srand(std::time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    cout << "The simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    double perhour;
    double min_per_cust;
    perhour = 1;
    Item temp;
    long turnaways;
    long customers;
    long served;
    long sum_line;
    int wait_time;
    long line_wait;
    double avetime = 0;
    while (perhour++ && avetime <= 1) {
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;
        avetime = 0;
        while (!line.isempty()) {
            line.dequeue(temp);
        }
        min_per_cust = MIN_PER_HR / perhour;
        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust)) {
                if (line.isfull())
                    turnaways++;
                else {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isempty()) {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }
        if (customers > 0) {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double) sum_line / cyclelimit << endl;
            cout << " average wait time: " << (double) line_wait / served << " minutes\n";
        } else
            cout << "No customers!\n";
        avetime = (double) line_wait / served;
    }
    cout << "When there comes " << perhour - 1
         << " people per hour, the average wait time will be about 1 minute.\n";
    cout << "Done!\n";
    return 0;
}
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
*/
/*12_6*/
int main(){
    
}