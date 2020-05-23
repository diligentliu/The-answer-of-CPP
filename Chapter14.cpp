#include <iostream>
#include "Fourteen.h"
using namespace std;
/*14_1
int main() {
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
         << ": " << more.sum() << endl;
    cout << "Bye";
    return 0;
}
*/
/*14_2
int main() {
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    Exercise2::Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Exercise2::Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
         << ": " << more.sum() << endl;
    cout << "Bye";
    return 0;
}
*/
/*14_3
int main() {
    QueueTp<Worker> q(3);
    if(q.isempty())
        cout << "Queue is empty" << endl;
    Worker w1("A", 1);
    q.enqueue(w1);
    q.Show();
    cout << endl;
    Worker w2("B", 2);
    q.enqueue(w2);
    q.Show();
    cout << endl;
    Worker w3("C", 3);
    q.enqueue(w3);
    q.Show();
    cout << endl;
    if(q.isfull())
        cout << "queue is full" << endl;
    Worker w;
    q.dequeue(w);
    w.Show();
    cout << endl;
    q.Show();
    return 0;
}
*/
/*14_4
int main() {
    BadDude bd("Jack", "Anderson", 0.5, 100, 13);
    bd.Show();
    cout << bd.Gdraw() << endl;
    cout << bd.Cdraw() << endl;
    bd.Show();
    return 0;
}
*/
/*14_5
int main() {
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; ++i)
        tri[i]->ShowAll();
    return 0;
}
*/