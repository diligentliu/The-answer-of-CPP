#include <iostream>
#include "Ten.h"
/*10_1
int main() {
    Bank bank = Bank("Mac","000001",1000000.0);
    bank.show();
    bank.add(10000000.0);
    bank.show();
    bank.minus(10000000.0);
    bank.show();
    return 0;
}
*/
/*10_2
int main(){
    EXERCISE2::Person one;
    EXERCISE2::Person two("Smythecraft");
    EXERCISE2::Person three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();
    return 0;
}
*/
/*10_3
int main() {
    golf g("Mac", 520);
    g.showgolf();
    g.handicap(250);
    g.showgolf();
    g = golf();
    g.showgolf();
    return 0;
}
*/
/*10_4
int main() {
    using namespace SALES;
    double arr[3] = {3.2, 2.5, 6.4};
    Sales SA1(arr, 3);
    SA1.showSales(3);
    Sales SA2;
    SA2.showSales();
    return 0;
}
*/
/*10_5
int main() {
    Stack S;
    double total = 0.0;
    customer temp;
    customer c[3] = {{"Mac",   3500.0},
                     {"Jenny", 2500.0},
                     {"Oops",  5000.0}};
    for (int i = 0; i < 3; ++i) {
        if (!S.isfull())
            S.push(c[i]);
    }
    S.pop(temp);
    total += temp.payment;
    cout << "total = " << total << endl;
    S.pop(temp);
    total += temp.payment;
    cout << "total = " << total << endl;
    return 0;
}
*/
/*10_6
int main(){
    Move move(3.0,4.0);
    cout << "Move #1: " << endl;
    move.showmove();
    Move move2(6.0,8.0);
    cout << "Move #2: " << endl;
    move2.showmove();
    Move move3;
    move3 = move.add(move2);
    cout << "Move #3: " << endl;
    move3.showmove();
    return 0;
}
*/
/*10_7
int main(){
    Plorga plorga("Mac",50);
    plorga.showplorga();
    plorga.CImodify(90);
    plorga.showplorga();
    return 0;
}
*/
/*10_8
void addage(ITem & item);
int main()
{
    List l;
    ITem i = {"shaozhengjiang", 24};
    l.additem(i);
    int n;
    n = l.itemcount();
    std::cout << n << " items in list" << std::endl;
    l.visit(addage);

    return 0;
}
void addage(ITem & item)
{
    item.age += 1;
}
*/