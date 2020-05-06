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
//12_3
int main(){
    return 0;
}