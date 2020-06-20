#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Sixteen.h"
using namespace std;
/*16_1
bool is_Palindrome(string & str);

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << ((is_Palindrome(str) == true) ? "Yes" : "No") << endl;
    return 0;
}

bool is_Palindrome(string & str) {
    int length = str.size();
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[length - 1 - i])
            return false;
    }
    return true;
}
*/
/*16_2
#include <cctype>
bool is_Palindrome(string & str);

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << ((is_Palindrome(str) == true) ? "Yes" : "No") << endl;
    return 0;
}

bool is_Palindrome(string & str) {
    string str_copy;
    for (int i = 0; i < str.size(); ++i) {
        if (isalpha(str[i]) || isdigit(str[i]))
            str_copy += tolower(str[i]);
    }
    int length = str_copy.size();
    for (int i = 0; i < str_copy.size() / 2; ++i) {
        if (str_copy[i] != str_copy[length - 1 - i])
            return false;
    }
    return true;
}
*/
/*16_3*/
