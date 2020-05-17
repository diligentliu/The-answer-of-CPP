#include "Fourteen.h"
//14_1
Wine::Wine(const char *l, int y, const int * yr, const int * bot)
: yearandbottles(ArrayInt(yr, y), ArrayInt(bot, y)){
    label = l;
    years = y;
}
Wine::Wine(const char *l, int y)
: yearandbottles(ArrayInt(y), ArrayInt(y)){
    label = l;
    years = y;
}
void Wine::GetBottles() {
    std::cout << "Enter " << label << " data for " << years << " year(s): " << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "Enter year: ";
        std::cin >> yearandbottles.first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> yearandbottles.second()[i];
    }
}
std::string & Wine::Label() {
    return label;
}
int Wine::sum() {
    return yearandbottles.second().sum();
}
void Wine::Show() {
    std::cout << "Wine: " << label << std::endl;
    std::cout << "\tYear" << "\t" << "Bottles" << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "\t" << yearandbottles.first()[i] << "\t" << yearandbottles.second()[i] << std::endl;
    }
}
//14_2
namespace Exercise2 {
    Wine::Wine(const char * l, int y, const int * yr, const int * bot)
    : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {
        years = y;
    }
    Wine::Wine(const char *l, int y)
    : std::string(l), PairArray(ArrayInt(y), ArrayInt(y)) {
        years = y;
    }
    void Wine::GetBottles() {
        std::cout << "Enter " << Label() << " data for " << years << " year(s): " << std::endl;
        for (int i = 0; i < years; ++i) {
            std::cout << "Enter year: ";
            std::cin >> PairArray::first()[i];
            std::cout << "Enter bottles for that year: ";
            std::cin >> PairArray::second()[i];
        }
    }
    std::string & Wine::Label() {
        return (std::string &)(* this);
    }
    int Wine::sum() {
        return PairArray::second().sum();
    }
    void Wine::Show() {
        std::cout << "Wine: " << Label() << std::endl;
        std::cout << "\tYear" << "\t" << "Bottles" << std::endl;
        for (int i = 0; i < years; ++i) {
            std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << std::endl;
        }
    }
}
//14_3
template <class T>
QueueTp<T>::QueueTp(int qs) : qsize(qs){
    front = rear = NULL;
    qsize = 0;
}
template <class T>
QueueTp<T>::~QueueTp() {
    QNODE temp;
    while (front != rear) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
template <class T>
bool QueueTp<T>::enqueue(const T & item) {
    if (isfull())
        return false;
    QNODE * add = new QNODE;
    if (isempty()) {
        add->data = item;
        add->next = NULL;
        front = rear = add;
    } else {
        add->data = item;
        add->next = NULL;
        rear->next = add;
        rear = add;
    }
    ++items;
    return true;
}
template <class T>
bool QueueTp<T>::dequeue(T & item) {
    if (isempty())
        return false;
    QNODE *temp;
    item = front->data;
    temp = front;
    front = front->next;
    delete temp;
    --items;
    return true;
}