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

#endif //STUDY_TWELVE_H
