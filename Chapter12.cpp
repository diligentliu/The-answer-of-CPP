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
/*12_4*/
int main() {
    using namespace STACK;
    Stack S;
    Item temp;
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