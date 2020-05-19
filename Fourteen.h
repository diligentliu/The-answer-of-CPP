#include <climits>
#ifndef STUDY_FOURTEEN_H
#define STUDY_FOURTEEN_H
#include <iostream>
#include <valarray>
#include <string>
//14_1
template <class T1, class T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair() {}
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
};
template <class T1, class T2>
T1 & Pair<T1, T2>::first() {
    return a;
}
template <class T1, class T2>
T2 & Pair<T1, T2>::second() {
    return b;
}
class Wine {
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    std::string label;
    PairArray yearandbottles;
    int years;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    Wine() {}
    ~Wine() {}
    void GetBottles();
    std::string & Label();
    int sum();
    void Show();
};
//14_2
namespace Exercise2 {
    class Wine
            : private Pair<std::valarray<int>, std::valarray<int>>,
              private std::string{
    private:
        typedef std::valarray<int> ArrayInt;
        typedef Pair<ArrayInt, ArrayInt> PairArray;
        int years;
    public:
        Wine(const char * l, int y, const int yr[], const int bot[]);
        Wine(const char * l, int y);
        Wine() {}
        ~Wine() {}
        void GetBottles();
        std::string & Label();
        int sum();
        void Show();
    };
}
//14_3
template <typename T>
class QueueTp {
private:
    static const int QSIZE = 10;
    struct QNODE {
        T data;
        QNODE * next;
    };
    QNODE * front;
    QNODE * rear;
    int items;
    const int qsize;
public:
    QueueTp(int qs = QSIZE);
    ~QueueTp();
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    int queuecount() const { return items; }
    bool enqueue(const T & item);
    bool dequeue(T & item);
    void Show();
};
template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs) {
    front = rear = NULL;
    items = 0;
}
template <typename T>
QueueTp<T>::~QueueTp() {
    QNODE * temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
template <typename T>
bool QueueTp<T>::enqueue(const T & item) {
    if(isfull())
        return false;
    QNODE * add = new QNODE;
    if (front == NULL) {
        add->data = item;
        add->next = NULL;
        front = rear = add;
    } else {
        add->data = item;
        add->next = NULL;
        rear->next = add;
        rear = add;
    }
    items++;
    return true;
}
template <typename T>
bool QueueTp<T>::dequeue(T & item) {
    if(isempty())
        return false;
    item = front->data;
    QNODE * temp;
    temp = front;
    front = front->next;
    delete temp;
    items--;
    return true;
}
template <typename T>
void QueueTp<T>::Show() {
    if (isempty())
        std::cout << "Queue is empty." << std::endl;
    QNODE * p = front;
    while (p != rear) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
    std::cout << rear->data <<std::endl;
}
class Worker {
private:
    std::string fullname;
    long id;
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string & s, long n)
            : fullname(s), id(n) {}
    ~Worker() {}
    void Set();
    void Show() const;
    friend std::ostream & operator << (std::ostream & os,const Worker & wk);
};
//14_4
class Person {
private:
    char * firstname;
    char * lastname;
protected:
    virtual void Data() const;
public:
    Person();
    Person(char * fn, char * ln);
    Person(const Person & person);
    virtual ~Person();
    virtual void Show() const;
    virtual Person & operator = (const Person & person);
};
class Gunslinger : public virtual Person {
private:
    double pulltime;
    int score;
protected:
    virtual void Data() const;
public:
    Gunslinger();
    Gunslinger(char *fn, char *ln, double pt, int sc);
    Gunslinger(const Gunslinger & gs);
    virtual ~Gunslinger();
    virtual void Show() const;
    double Draw() const;
    virtual Gunslinger & operator=(const Gunslinger &gs);
};
class PokerPlayer : public virtual Person {
private:
    int card;
protected:
    virtual void Data() const;
public:
    PokerPlayer();
    PokerPlayer(char *fn, char *ln, int c = 0);
    PokerPlayer(const PokerPlayer & pp);
    virtual ~PokerPlayer() {}
    virtual void Show() const;
    int Draw();
    int GetCard(int n = 0);
    virtual PokerPlayer & operator=(const PokerPlayer &pp);
};
class BadDude : public Gunslinger, public PokerPlayer {
protected:
    void Data() const;
public:
    BadDude();
    BadDude(char *fn, char *ln, double pt, int sc, int c = 0);
    BadDude(const BadDude &bd);
    virtual void Show() const;
    double Gdraw() const;
    int Cdraw();
    virtual BadDude & operator=(const BadDude &bd);
};
//14_5
class abstr_emp {
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln,
            const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream & operator<<(std::ostream &os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};
class employee : public abstr_emp {
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
            const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual ~employee() {}
};
class manager : virtual public abstr_emp {
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual ~manager() {}
};
class fink : virtual public abstr_emp {
private:
    std::string reportsto;
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    ~fink() {}
};
class highfink : public manager, public fink {
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual ~highfink() {}
};
#endif //STUDY_FOURTEEN_H