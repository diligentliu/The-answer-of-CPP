#include <string>

#ifndef TEN_H
#define TEN_H

using namespace std;

//10_1
class Bank {
    string m_name;
    string m_account;
    double m_deposit;
public:
    Bank(const string &name = "", const string &account = "", const double &deposit = 0.0);

    ~Bank() {}

    void show() const;

    void add(double m_add);

    void minus(double m_minus);
};
//10_2
namespace EXERCISE2 {
    class Person {
    private:
        static const int LIMIT = 25;
        string lname;
        char fname[LIMIT];
    public:
        Person() {
            lname = "";
            fname[0] = '\0';
        }

        Person(const string &ln, const char *fn = "Heyyou");

        ~Person() {}

        void Show() const;

        void FormalShow() const;
    };
}
//10_3
class golf {
private:
    static const int Len = 40;
    char m_fullname[Len];
    int m_handicap;
public:
    golf(const char *name, int hc);

    golf();

    ~golf() {}

    void handicap(int hc);

    void showgolf() const;
};
//10_4
namespace SALES {
    class Sales {
    private:
        static const int QUARTERS = 4;
        double m_sales[QUARTERS];
        double m_average;
        double m_max;
        double m_min;
    public:
        Sales(const double ar[], int n);

        Sales();

        ~Sales() {}

        void showSales(int n = QUARTERS) const;
    };
}
//10_5
struct customer {
    char fullname[35];
    double payment;
};
typedef customer Item;

class Stack {
private:
    enum {
        MAX = 10
    };
    Item items[MAX];
    int top;
public:
    Stack();

    bool isempty() const;

    bool isfull() const;

    bool push(const Item &item);

    bool pop(Item &item);
};

//10_6
class Move {
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);

    ~Move() {};

    void showmove() const;

    Move add(const Move &m) const;

    void reset(double a = 0, double b = 0);
};

class Plorga {
private:
    char m_name[20];
    int m_CI;
public:
    Plorga(const char *name = "", const int CI = 50);

    ~Plorga() {};

    void CImodify(const int CI);

    void showplorga() const;
};

//10_8
const int MAX = 10;

struct people {
    std::string name;
    int age;
};
typedef struct people ITem;

class List {
private:
    ITem items[MAX];
    int count;
public:
    List();

    bool isempty() const;

    bool isfull() const;

    int itemcount() const;

    void additem(const ITem &item);

    void visit(void (*pf)(ITem &));
};

#endif //STUDY_TEN_H
