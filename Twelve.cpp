#include <iostream>
#include <cstring>
#include "Twelve.h"
using namespace std;
//12_1
Cow::Cow() {
    strcpy(name, "");
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}
Cow::Cow(const char *nm, const char *ho, double wt) {
    strcpy(name, nm);
    int len = strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::Cow(const Cow &c) {
    strcpy(name, c.name);
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow() {
    delete[] hobby;
}
Cow & Cow::operator = (const Cow &c) {
    if (this == &c)
        return *this;
    strcpy(name, c.name);
    delete[] hobby;
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}
void Cow::ShowCow() const {
    cout << "Name: " << name << std::endl;
    cout << "Hobby: " << hobby << std::endl;
    cout << "Weight: " << weight << std::endl;
}
//12_2
int String::num_strings = 0;
int String::HowMany() {
    return num_strings;
}
void String::stringlow() {
    for (int i = 0; i < len; ++i) {
        str[i] = tolower(str[i]);
    }
}
void String::stringup() {
    for (int i = 0; i < len; ++i) {
        str[i] = toupper(str[i]);
    }
}
int String::has(char c) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == c)
            ++count;
    }
    return count;
}
String::String(const char *s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    ++num_strings;
}
String::String() {
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
String::String(const String & st) {
    ++num_strings;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}
String::~String() {
    --num_strings;
    delete [] str;
}
String & String::operator = (const String & st) {
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}
String & String::operator = (const char * s) {
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}
String String::operator + (const String & st) {
    int length = len + st.length() - 1;
    char str2[length];
    for (int i = 0; i < len - 1; ++i) {
        str2[i] = str[i];
    }
    for (int i = len - 1; i < length; ++i) {
        str2[i] = st.str[i];
    }
    return String(str2);
}
char & String::operator[](int i) {
    return str[i];
}
const char & String::operator[](int i)const {
    return str[i];
}
String operator + (const char * s, String & st){
    int length = strlen(s) + st.length() - 1;
    char str2[length];
    for (int i = 0; i < strlen(s) - 1; ++i) {
        str2[i] = s[i];
    }
    for (int i = 0; i < length; ++i) {
        str2[i] = st.str[i];
    }
    return String(str2);
}
bool operator < (const String & st1, const String & st2) {
    return (strcmp(st1.str, st2.str) < 0);
}
bool operator > (const String & st1, const String & st2) {
    return st2.str < st1.str;
}
bool operator == (const String & st1, const String & st2) {
    return (strcmp(st1.str, st2.str) == 0);
}
ostream & operator << (ostream & os, const String & st) {
    os << st.str;
    return os;
}
istream & operator >> (istream & is, String & st) {
    char temp[String::CINLIN];
    is.get(temp, String::CINLIN);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
//12_3
Stock::Stock() {
    int len = strlen("no name");
    company = new char[len + 1];
    strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const char *co, int n, double pr) {
    int len = strlen(co);
    company = new char[len + 1];
    if (len > 30) {
        strncpy(company, co, 29);
        company[29] = '\0';
    }
    strcpy(company, co);
    if (n < 0) {
        cerr << "Number of shares can't be negative. "
             << company << " shares set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}
Stock::~Stock() {
    delete [] company;
}
void Stock::buy(int num, double price) {
    if (num < 0) {
        cerr << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(int num, double price) {
    if (num < 0) {
        cerr << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    } else if (num > shares) {
        cerr << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price) {
    share_val = price;
    set_tot();
}
void Stock::show() const {
    cout << "Company: " << company
         << " Shares: " << shares << endl
         << " Share Price: $" << share_val
         << " Total Worth: $" << total_val << endl;
}
ostream & operator << (ostream & os, Stock & s){
    os << "Company: " << s.company
       << " Shares: " << s.shares << endl
       << " Share Price: $" << s.share_val
       << " Total Worth: $" << s.total_val << endl;
}
const Stock & Stock::topval(const Stock &s) const {
    if (s.total_val > total_val)
        return s;
    return *this;
}
//12_4
namespace STACK{
    Stack::Stack(int n) {
        size = n;
        pitems = new Item[n];
        for (int i = 0; i < n; ++i) {
            pitems[i] = i;
        }
        top = n;
    }
    Stack::Stack(const Stack & st){
        size = st.size;
        pitems = new Item[size];
        for (int i = 0; i < size; ++i) {
            pitems[i] = st.pitems[i];
        }
        top = st.top;
    }
    Stack::~Stack() {
        delete [] pitems;
    }
    bool Stack::isempty() const {
        return top == 0;
    }
    bool Stack::isfull() const {
        return top == MAX;
    }
    bool Stack::push(const Item &item) {
        if (top < MAX){
            pitems[top++] = item;
            return true;
        }
        return false;
    }
    bool Stack::pop(Item &item) {
        if (top > 0){
            item = pitems[--top];
            return true;
        }
        return false;
    }
    Stack & Stack::operator = (const Stack & st) {
        if (this == &st)
            return *this;
        delete [] pitems;
        size = st.size;
        for (int i = 0; i < size; ++i) {
            pitems[i] = st.pitems[i];
        }
        top = st.top;
    }
}
