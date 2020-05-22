#include <iostream>
using namespace std;
/*9_1
#include "golf.h"
const int MAXLEN = 5;
int main() {
    golf g[MAXLEN];
    int i = 0;
    for (; i < MAXLEN; ++i) {
        int result = setgolf(g[i]);
        if (result == 0) {
            cout << "Empty! Over!" << endl;
            break;
        }
    }
    i = 0;
    while (g[i].fullname[0]) {
        showgolf(g[i]);
        ++i;
    }
    setgolf(g[0], "Microsoft Edge", 520);
    showgolf(g[0]);
    handicap(g[0], 250);
    showgolf(g[0]);
    return 0;
}
*/
/*9_2
const int ArSize = 10;
void strcount (const string str);
int main(){
    string input;
    cout << "Enter a line: \n";
    getline(cin,input);
    while (cin && input != ""){
        strcount(input);
        cout << "Enter next line (empty line to quit): \n";
        getline(cin,input);
    }
    cout << "Bye\n";
    return 0;
}
void strcount(const string str){
    static int total = 0;
    int count = str.size();
    cout << "\"" << str << "\"contains ";
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
*/
/*9_3
#include <cstring>
const int N = 2;
struct chaff{
    char dross[20];
    int slag;
};
chaff buffer[N];
int main()
{
    chaff arr[N] = {
            {"son of", 24},
            {"a bitch", 23},
    };
    chaff * cha = new (buffer) chaff [N];
    strcpy(cha[0].dross, arr[0].dross);
    cha[0].slag = arr[0].slag;
    strcpy(cha[1].dross, arr[1].dross);
    cha[1].slag = arr[1].slag;
    for(int i = 0; i < N; ++i){
        cout << "chaff[" << i << "]" << endl;
        cout << "dross: " << cha[i].dross << endl;
        cout << "slag: " << cha[i].slag << endl;
    }
    return 0;
}
*/
/*9_4
#include "Nine_4.h"
int main(){
    using namespace SALES;
    Sales SA1,SA2;
    double arr[3] = {3.2,2.5,6.4};
    setSales(SA1,arr,3);
    showSales(SA1,3);
    setSales(SA2);
    showSales(SA2);
    return 0;
}
*/