#include <iostream>
#include "Nine_4.h"
using namespace std;
namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        s.max = s.min = ar[0];
        s.average = 0;
        for (int i = 0; i < n; ++i) {
            if (ar[i] >= 0)
                s.sales[i] = ar[i];
            else
                s.sales[i] = 0;
            if (s.sales[i] < s.min)
                s.min = s.sales[i];
            if (s.sales[i] > s.max)
                s.max = s.sales[i];
            s.average += s.sales[i];
        }
        s.average /= n;
    }
    void setSales(Sales & s){
        cout << "Enter sales" << endl;
        //cout << "sales[0]: ";
        cin >> s.sales[0];
        s.max = s.min = s.average = s.sales[0];
        for (int i = 1; i < QUARTERS; ++i) {
            //cout << "sales[" << i << "]: ";
            cin >> s.sales[i];
            if (s.sales[i] < s.min)
                s.min = s.sales[i];
            if (s.sales[i] > s.max)
                s.max = s.sales[i];
            s.average += s.sales[i];
        }
        s.average /= QUARTERS;
    }
    void showSales(const Sales & s, int n){
        cout << "Sales: " << endl;
        for (int i = 0; i < n; ++i)
            cout << s.sales[i] << " ";
        cout << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
        cout << "Average: " << s.average << endl;
    }
}