#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;
void setgolf(golf & g, const char * name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
    return;
}
int setgolf(golf & g) {
    cout << "Enter fullname: ";
    cin.getline(g.fullname, Len);
    if (!g.fullname[0])
        return 0;
    cout << "Enter handicap: ";
    cin >> g.handicap;
    cin.get();
    return 1;
}
void handicap(golf & g, int hc) {
    g.handicap = hc;
}
void showgolf(const golf & g){
    cout << "Fullname : " << g.fullname << endl;
    cout << "Handicap : " << g.handicap << endl;
}