#include <iostream>
using namespace std;
/*6_1
#include <cctype>
int main(){
    char ch;
    cin.get(ch);
    while(ch!='@'&&!(isdigit(ch))){
        if (islower(ch))
            ch = toupper(ch);
        else if (isupper(ch))
            ch = tolower(ch);
        cout << ch;
        cin.get(ch);
    }
}
*/
/*6_2
int main(){
    double *donation = new double[10];
    double t=0.0,average;
    int i=0,upcount=0;
    cin>>donation[i];
    t=t+donation[i];
    ++i;
    while (i < 10 && cin >> donation[i]) {
        t = t + donation[i];
        ++i;
    }
    average = t / (float) i;
    for (int j = 0; j < i+1; ++j){
        if (donation[j] > average)
            ++upcount;
    }
    cout <<"average= "<<average << endl;
    cout <<"There are "<<upcount
         <<" number greater than average."<<endl;
    delete [] donation;
}
*/
/*6_4
#include <cstdlib>
const int strsize = 21;
struct bop{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int perference;
};
enum perferences {fullname,title,bopname};
int main(){
    char ch;
    bop display[5]={{"Wimp Macho","Best Programmer","hhhnmsl",0},
                    {"Raki Rhodes","More Best Programmer","hhhnmysl",1},
                    {"Celia Laiter","Most Best programmer","nimeima",2},
                    {"Hoppy Hipman","I am best","niquanjiadousi",0},
                    {"Pat Hand","HSB","nimeiquanjia",1}};
    cout <<"Benevolent Order of Programmers Report"<<endl
         <<"a. display by name"<<endl
         <<"b. display by title"<<endl
         <<"c. display by bopname"<<endl
         <<"q. quit"<<endl;
    while (0==0){
        cout <<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 'a':
                for (int i = 0; i < 5; ++i)
                    cout << display[i].fullname << endl;
                break;
            case 'b':
                for (int i = 0; i < 5; ++i)
                    cout << display[i].title << endl;
                break;
            case 'c':
                for (int i = 0; i < 5; ++i)
                    cout << display[i].bopname << endl;
                break;
            case 'd':
                for (int i = 0; i < 5; ++i){
                    switch (display[i].perference){
                        case fullname:
                            cout << display[i].fullname << endl;
                            break;
                        case title:
                            cout << display[i].title << endl;
                            break;
                        case bopname:
                            cout << display[i].bopname << endl;
                            break;
                        default :
                            cout << "data error";
                            exit(EXIT_FAILURE);
                    }
                }
                break;
            case 'q':
                cout <<"Bye!"<<endl;
                exit(EXIT_FAILURE);
                break;
            default :
                cout << "input error,please input again";
                exit(EXIT_FAILURE);
        }
    }
}
*/
/*6_5
int main(){
    float income;
    while (cin >> income && income >= 0){
        if (income <= 5000)
            cout << "Tax collection is zero tvarps."<<endl;
        else if (income <= 15000)
            cout << "Tax collection is " << (income - 5000.0) * 0.1 <<
            " tvarps."<< endl;
        else if (income <= 35000)
            cout << "Tax collection is " << (10000.0 * 0.1
                                            + (income - 15000.0) * 0.15)
                                         <<" tvarps."<<endl;
        else
            cout << "Tax collection is " << (10000.0 * 0.1 + 20000 * 0.15
                                            + (income - 35000.0) * 0.2)
                                         <<" tvarps."<<endl;
    }
}
*/
/*6_7
#include <cstring>
int main(){
    int beg_oth=0,beg_vow=0,beg_con=0;
    char words[10];
    cout<<"Enter words (q to quit):";
    cin>>words;
    while (strcmp(words,"q")){
        if (!isalpha(words[0]))
            ++beg_oth;
        else{
            switch (words[0]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    ++beg_vow;
                    break;
                default :
                    ++beg_con;
                    break;
            }
        }
        cin>>words;
    }
    cout << beg_vow << " words beginning with vowels" << endl;
    cout << beg_con << " words beginning with consonants" << endl;
    cout << beg_oth << " others" << endl;
}
*/
/*6_8
#include <fstream>
#include <string>
int main(){
    char ch;
    string longstring;
    getline(cin,longstring);
    int count = 0;
    ofstream outFile;
    outFile.open("6_8.txt");
    outFile << longstring;
    outFile.close();
    ifstream inFile;
    inFile.open("6_8.txt");
    inFile >> noskipws;//操作符noskipws会令输入运算符读取空白符，而不是跳过它们。
                       // 为了恢复默认行为，可以使用skipws操作符。
    while (inFile >> ch){
        count++;
    }
    cout << count << endl;
    inFile.close();
    return 0;
}
*/
/*6_9
#include <fstream>
struct donation{
    string name;
    double value;
};
int main(){
    int N,j = 0;
    donation *message = new donation [N];
    donation *message2 = new donation [N];
    ifstream inFile;
    inFile.open("patron.txt");
    inFile >> N;
    cout << "Grand Patrons" << endl;
    inFile.get();
    for (int i = 0; i < N; ++i) {
        getline(inFile,message[i].name);
        inFile >> message[i].value;
        inFile.get();
        if (message[i].value > 10000)
            cout << message[i].name << '\t' << message[i].value << endl;
        else{
            message2[j].name = message[i].name;
            message2[j].value = message[i].value;
            ++j;
        }
    }
    inFile.close();
    if (j == N)
        cout << "none" << endl;
    cout << "Patrons" << endl;
    for (int i = 0; i < j; ++ i){
        cout << message2[i].name << '\t' << message2[i].value << endl;
    }
    delete[] message;
    delete[] message2;
}
*/