#include <iostream>
#ifndef STUDY_TWELVE_H
#define STUDY_TWELVE_H
//12_1
class Cow {
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator = (const Cow & c);
    void ShowCow() const;
};
//12_2
using std::ostream;
using std::istream;
class String {
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIN = 80;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length()const {return len; }
    void stringlow();
    void stringup();
    int has(char c);
    String & operator = (const String &);
    String & operator = (const char *);
    String operator + (const String &);
    char & operator [] (int i);
    const char & operator [] (int i) const;
    friend String operator + (const char * s, String & st);
    friend bool operator < (const String & st, const String & st2);
    friend bool operator > (const String & st, const String & st2);
    friend bool operator == (const String & st, const String & st2);
    friend ostream & operator << (ostream & os, const String & st);
    friend istream & operator >> (istream & is, String & st);
    static int HowMany();
};
//12_3
class Stock {
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();
    Stock(const char * co, int n = 0, double pr = 0.0);
    ~Stock();
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double  price);
    void show()const;
    const Stock & topval(const Stock & s)const;
};
//12_4

#endif //STUDY_TWELVE_H
