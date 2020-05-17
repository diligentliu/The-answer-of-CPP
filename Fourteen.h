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
template <class T>
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
};
#endif //STUDY_FOURTEEN_H