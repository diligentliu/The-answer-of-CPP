#include <iostream>
#include "Thirteen.h"
using namespace std;
/*13_1
void Bravo(const Cd & disk);
int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                        "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = & c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to object:\n";
    pcd->Report();
    pcd = & c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const Cd & disk){
    disk.Report();
}
*/
/*13_2
void Bravo(const Exercise2::Cd & disk);
int main() {
    Exercise2::Cd c1("Beatles", "Capitol", 14, 35.5);
    Exercise2::Classic c2 = Exercise2::Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Exercise2::Cd * pcd = & c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to object:\n";
    pcd->Report();
    pcd = & c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Exercise2::Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const Exercise2::Cd & disk){
    disk.Report();
}
*/
/*13_3
int main() {
    DMA * dma[3];
    char tempchar[20];
    char tempchar2[10];
    int tempint;
    int type;
    for (int i = 0; i < 3; ++i) {
        cout << "Enter the label: ";
        cin.getline(tempchar, 20);
        cout << "Enter the rating: ";
        cin >> tempint;
        cin.get();
        cout << "Enter your type(1 is baseDMA,2 is lacksDMA,3 is hasDMA): ";
        cin >> type;
        cin.get();
        if (type == 1) {
            dma[i] = new baseDMA(tempchar, tempint);
        } else if (type == 2) {
            cout << "Enter your color: ";
            cin.getline(tempchar2, 10);
            dma[i] = new lacksDMA(tempchar2, tempchar, tempint);
        } else if (type == 3) {
            cout << "Enter your style: ";
            cin.getline(tempchar2, 10);
            dma[i] = new hasDMA(tempchar2, tempchar, tempint);
        } else
            cout << "ERROR" << endl;
    }
    for (int i = 0; i < 3; ++i) {
        dma[i]->View();
        cout << endl;
    }
    for (int i = 0; i < 3; ++i) {
        delete dma[i];
    }
    return 0;
}
*/
/*13_4
int main() {
    Port * p1 = new Port("A", "vintage", 5);
    VintagePort * p2 = new VintagePort("B", 5, "C", 6);
    Port * p3 = p2;
    p1->Show();
    cout << endl;
    p2->Show();
    cout << endl;
    p3->Show();
    cout << endl;
    cout << * p1 << endl;
    cout << * p2 << endl;
    cout << * p3 << endl;
    return 0;
}
*/