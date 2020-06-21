#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
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
/*16_3
int reduce(long ar[], int n);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    long arr[n];
    cout << "Enter the " << n << " numbers(long): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = reduce(arr, n);
    cout << num;
    return 0;
}

int reduce(long ar[], int n) {
    sort(ar, ar + n);
    return unique(ar, ar + n) - ar;
}
*/
/*16_5
template <class T>
int reduce(T ar[], int n);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    long arr[n];
    cout << "Enter the " << n << " numbers(long): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = reduce(arr, n);
    cout << num << endl;
    int m;
    cout << "Enter m: ";
    cin >> m;
    string arrstr[m];
    cout << "Enter the " << m << " strings: " << endl;
    for (int i = 0; i < m; i++) {
        cin.get();
        getline(cin, arrstr[i]);
    }
    num = reduce(arrstr, m);
    cout << num;
    return 0;
}
template <class T>
int reduce(T ar[], int n) {
    sort(ar, ar + n);
    return unique(ar, ar + n) - ar;
}
*/
/*16_6*/
int main() {
    
    return 0;
}