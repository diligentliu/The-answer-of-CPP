#include <iostream>
using namespace std;
/*8_1
const int SIZE = 20;
int print(char *str, int n = 0);
int main(){
    char str[SIZE];
    cin.get(str,SIZE);
    print(str);
    print(str,5);
    print(str,6);
}
int print(char *str, int n) {
    static int digits = 0;
    ++digits;
    if (n == 0)
        cout << str << endl;
    else {
        for (int i = 0; i < digits; ++i) {
            cout << str << endl;
        }
    }
    cout << endl;
    return 0;
}
*/
/*8_2
#include <cstring>
const int SIZE = 30;
struct CandyBar{
    char brand[SIZE];
    double weight;
    int calories;
};
void set(CandyBar & candybar,const char arr[]="Millennium Munch",
                    const double weight = 2.85,
                    const int calories = 350) {
    strcpy(candybar.brand, arr);
    candybar.weight = weight;
    candybar.calories = calories;
}
void show(const CandyBar & candybar) {
    cout << candybar.brand << endl;
    cout << candybar.weight << endl;
    cout << candybar.calories << endl;
}
int main() {
    CandyBar candybar = {"Munch",2.60,250};
    show(candybar);
    set(candybar);
    show(candybar);
    set(candybar,"Millennium",3.00,360);
    show(candybar);
    return 0;
}
*/
/*8_3
#include <cctype>
void ToUp(string & str){
    for (int i = 0; i < str.length(); ++i) {
        str[i] = toupper(str[i]);
    }
    cout << str << endl;
}
int main() {
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin, str);
    while (str != "q") {
        ToUp(str);
        cout << "Next string (q to quit): ";
        getline(cin,str);
    }
    cout << "Bye";
    return 0;
}
*/
/*8_4
#include <cstring>
struct stringy {
    char *str;
    int ct;
};
void set(stringy & beany,const char testing[]);
void show(const stringy & beany,int n = 1);
void show(const char testing[],int n = 1);
int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be. ";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done! ");
    return 0;
}
void set(stringy & beany,const char testing[]){
    int len = strlen(testing);
    beany.str = new char [len];
    strcpy(beany.str,testing);
    beany.ct = len;
}
void show(const stringy & beany,int n) {
    for (int i = 0; i < n; ++i) {
        cout << "str: " << beany.str << endl;
        cout << "ct: " << beany.ct << endl;
    }
}
void show(const char testing[],int n) {
    for (int i = 0; i < n; ++i) {
        cout << testing << endl;
    }
}
*/
/*8_5
template<class T>
T max5(const T *arr);
int main() {
    int arr1[5];
    double arr2[5];
    cout << "Enter 5 int numbers: " << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> arr1[i];
    }
    cout << "Max of the 5 numbers is: " << max5(arr1) << endl;
    cout << "Enter 5 double numbers: " << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> arr2[i];
    }
    cout << "Max of the 5 numbers is: " << max5(arr2) << endl;
    return 0;
}
template<typename T>
T max5(const T *arr){
    int j = 0;
    for (int i = 1; i < 5; ++i) {
        if (*(arr + i) > *(arr + j))
            j = i;
    }
    return *(arr + j);
}
*/
/*8_6
#include <cstring>
template<typename T>
T maxn(T *arr,int n);
template<> char * maxn<char *>(char **arr, int n);
int main() {
    const int arr1[6] = {4, 7, 5, 9, 6, 2};
    const double arr2[4] = {1.0, 8.0, 4.0, 0.0};
    char * arr3[5] = {"you", "are", "son", "of", "bitch"};
    cout << "The max number of 'arr1' is: " << maxn(arr1, 6) << endl;
    cout << "The max number of 'arr2' is: " << maxn(arr2, 4) << endl;
    cout << static_cast<void*>(arr3[4]) << endl;
    cout << maxn(arr3, 5) << endl;
    cout << "The address of the longest string is: " << (void *)(maxn(arr3, 5)) << endl;
}
template<typename T>
T maxn(T * arr,int n) {
    int j = 0;
    for (int i = 1; i < n; ++i) {
        if (*(arr + i) > *(arr + j))
            j = i;
    }
    return *(arr + j);
}
template<> char * maxn<char *>(char **arr, int n) {
    int j = 0;
    for (int i = 1; i < n; ++i) {
        if (strlen(*(arr + i))>strlen(*(arr + j)))
            j = i;
    }
    return (arr[j]);
}
*/
/*8_7
template <typename T>
int ShowArray (T arr[], int n);
template <typename T> // template B
double ShowArray (T * arr[], int n);
struct debts {
    char name[50];
    double amount;
};
int main () {
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
            {"Ima Wolfe", 2400.0},
            {"Ura Foxe",  1300.0},
            {"Iby Stout", 1800.0}
    };
    double *pd[3];
    for (int i = 0; i < 3; ++i)
        pd[i] = &mr_E[i].amount;
    cout << "Listing Mr. E's counts of things: " << ShowArray(things,6) << endl;
    cout << "Listing Mr. E's debts: " << ShowArray(pd,3) << endl;
    return 0;
}
template <typename T>
int ShowArray (T arr[] , int n) {
    cout << "template A\n";
    int add = 0;
    for (int i = 0; i < n; ++i)
        add += arr[i];
    return add;
}
template <typename T>
double ShowArray (T * arr[] , int n) {
    cout << "template B\n";
    double add;
    for (int i = 0; i < n; ++i)
        add += *arr[i];
    return add;
}
*/