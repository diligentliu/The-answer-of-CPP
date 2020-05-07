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
    friend ostream & operator << (ostream & os, Stock & s);
};
//12_4
namespace STACK {
    typedef unsigned long Item;
    class Stack {
    private:
        enum {MAX = 10};
        Item * pitems;
        int size;
        int top;
    public:
        Stack(int n = MAX);
        Stack(const Stack & st);
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);
        bool pop(Item & item);
        Stack & operator = (const Stack & st);
    };
}
//12_5
class Customer {
private:
    long arrive;
    int processtime;
public:
    Customer(){ arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;
class Queue {
private:
    struct Node { Item item; struct Node * next; };
    enum {Q_SIZE = 10};
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q) : qsize(0) { }
    Queue & operator = (const Queue & q) { return *this; }
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};
#endif //STUDY_TWELVE_H
