#include <iostream>
#include <cstring>
#include "Ten.h"
//10_1
Bank::Bank(const string & name, const string & account, const double & deposit) {
    m_name = name;
    m_account = account;
    m_deposit = deposit;
}
void Bank::show() const {
    cout.precision(2);
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    std::cout << "name: " << m_name << endl
              << "account: " << m_account << endl
              << "deposit: " << m_deposit << endl;
}
void Bank::add(double m_add) {
    m_deposit += m_add;
}
void Bank::minus(double m_minus) {
    m_deposit -= m_minus;
}
//10_2
namespace EXERCISE2 {
    Person::Person(const string &ln, const char *fn) {
        lname = ln;
        strncpy(fname, fn, LIMIT - 1);
        fname[LIMIT - 1] = '\0';
    }
    void Person::Show() const {
        cout << "name: " << fname << " " << lname << endl;
    }
    void Person::FormalShow() const {
        cout << "lastname: " << lname << endl
             << "firstname: " << fname << endl;
    }
}
//10_3
golf::golf(const char *name, int hc) {
    strncpy(m_fullname, name, Len - 1);
    m_fullname[Len - 1] = '\0';
    m_handicap = hc;
}
golf::golf() {
    cout << "Enter your fullname: ";
    cin.getline(this->m_fullname, Len);
    cout << "Enter the handicap: ";
    cin >> this->m_handicap;
}
void golf::handicap(int hc) {
    m_handicap = hc;
}
void golf::showgolf() const {
    cout << "Fullname: " << m_fullname << endl
         << "Handicap: " << m_handicap << endl;
}
//10_4
SALES::Sales::Sales(const double *ar, int n) {
    m_max = m_min = ar[0];
    m_average = 0;
    for (int i = 0; i < n; ++i) {
        if (ar[i] >= 0)
            m_sales[i] = ar[i];
        else
            m_sales[i] = 0;
        if (m_sales[i] < m_min)
            m_min = m_sales[i];
        if (m_sales[i] > m_max)
            m_max = m_sales[i];
        m_average += m_sales[i];
    }
    m_average /= n;
}
SALES::Sales::Sales() {
    cout << "Enter sales" << endl;
    //cout << "sales[0]: ";
    cin >> m_sales[0];
    m_max = m_min = m_average = m_sales[0];
    for (int i = 1; i < QUARTERS; ++i) {
        //cout << "sales[" << i << "]: ";
        cin >> m_sales[i];
        if (m_sales[i] < m_min)
            m_min = m_sales[i];
        if (m_sales[i] > m_max)
            m_max = m_sales[i];
        m_average += m_sales[i];
    }
    m_average /= QUARTERS;
}
void SALES::Sales::showSales(int n)const{
    cout << "Sales: " << endl;
    for (int i = 0; i < n; ++i)
        cout << m_sales[i] << " ";
    cout << endl;
    cout << "Max: " << m_max << endl;
    cout << "Min: " << m_min << endl;
    cout << "Average: " << m_average << endl;
}
//10_5
Stack::Stack() {
    top = 0;
}
bool Stack::isempty() const {
    return top == 0;
}
bool Stack::isfull() const {
    return top == MAX;
}
bool Stack::push(const Item &item) {
    if (top < MAX){
        items[top++] = item;
        return true;
    }
    return false;
}
bool Stack::pop(Item &item) {
    if (top > 0){
        item = items[--top];
        return true;
    }
    return false;
}
//10_6
Move::Move(double a, double b) {
    x = a;
    y = b;
}
void Move::showmove() const {
    cout << "x = " << x << endl
         << "y = " << y << endl;
}
Move Move::add(const Move &m) const {
    double a = m.x + this->x;
    double b = m.y + this->y;
    Move newmove(a, b);
    return newmove;
}
void Move::reset(double a, double b) {
    x = a;
    y = b;
}
//10_7
Plorga::Plorga(const char *name, const int CI) {
    strncpy(m_name,name,19);
    m_name[19] = '\0';
    m_CI = CI;
}
void Plorga::CImodify(const int CI) {
    m_CI = CI;
}
void Plorga::showplorga() const {
    cout << "name: " << m_name << endl
         << "CI: " << m_CI << endl;
}
//10_8
List::List()
{
    count = 0;
}
bool List::isempty() const
{
    return count == 0;
}
bool List::isfull() const
{
    return count == MAX;
}
int List::itemcount() const
{
    return count;
}
void List::additem(const ITem & item)
{
    if(isfull())
        std::cout << "full already" << std::endl;
    else
        items[++count] = item;
}
void List::visit(void (*pf)(ITem &))
{
    for(int i = 0; i < count; ++i)
        (*pf)(items[i]);
}
