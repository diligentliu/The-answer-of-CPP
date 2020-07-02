#include <fstream>
#include <iostream>

using namespace std;
/*17_1
int main() {
    cout << "Enter a sentence with a '$' in it: " << endl;
    int ct = 0;
    char ch;
    while ((ch = cin.get()) != '$')
        ct++;
    // put $ back to stream
    cin.putback(ch);

    while (cin.get() != '\n')
        continue;

    cout << "There are " << ct << " characters before $" << endl;

    return 0;
}
*/
/*17_2
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "need file name" << endl;
        exit(0);
    }
    string fileName = argv[1];
    ofstream fo(fileName.c_str());

    char ch;
    while (cin && cin.get(ch)) {
        fo << ch;
    }
    return 0;
}
// >g++ Chapter17.cpp -o C17E2.exe
// PowerShell: >.\C17E2.exe 17_2.txt
*/
/*17_3
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Please enter 2 filename." << endl;
        exit(0);
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fin.is_open()) {
        cout << "can not find file: " << argv[1] << endl;
        exit(0);
    }
    if (!fout.is_open()) {
        cout << "can not find file: " << argv[2] << endl;
        exit(0);
    }
    char ch;
    while (fin && fin.get(ch)) {
        fout << ch;
    }
    fout.close();
    fin.close();
    return 0;
}
// >g++ .\Chapter17.cpp -o C17E3.exe
// PowerShell: >.\C17E3.exe 17_2.txt 17_3.txt
*/
/*17_4
int main() {
    ifstream fin1("17_2.txt");
    ifstream fin2("17_3.txt");
    ofstream fout("17_4.txt");
    if (!fin1.is_open() || !fin2.is_open() || !fout.is_open()) {
        cout << "File failed to open." << endl;
        exit(0);
    }
    string str1, str2;
    while (true) {
        if (fin1) {
            getline(fin1, str1);
        }
        if (fin2) {
            getline(fin2, str2);
        }
        if (!fin1 && !fin2) {
            break;
        } else if (fin1 && fin2) {
            fout << str1 << " " << str2 << endl;
        } else if (!fin1 && fin2) {
            fout << str2 << endl;
        } else if (fin1 && !fin2) {
            fout << str1 << endl;
        }
    }
    fout.close();
    fin2.close();
    fin1.close();
    return 0;
}
*/
/*17_5
#include <iterator>
#include <vector>
#include <algorithm>

void EnterFriends(ifstream & fin, vector<string>& vec_str);

int main() {
    ifstream fin1("mat.dat");
    ifstream fin2("pat.dat");
    ofstream fout("matnpat.dat");
    vector<string> FriendsMat, FriendsPot, TotalFriends;
    EnterFriends(fin1, FriendsMat);
    EnterFriends(fin2, FriendsPot);
    TotalFriends.insert(TotalFriends.end(), FriendsMat.begin(),
                        FriendsMat.end());
    TotalFriends.insert(TotalFriends.end(), FriendsPot.begin(),
                        FriendsPot.end());
    ostream_iterator<string, char> out_iter(fout, "\n");
    sort(TotalFriends.begin(), TotalFriends.end());
    TotalFriends.erase(unique(TotalFriends.begin(), TotalFriends.end()),
                       TotalFriends.end());
    copy(TotalFriends.begin(), TotalFriends.end(), out_iter);
    cout << endl;
    return 0;
}

void EnterFriends(ifstream & fin, vector<string>& vec_str) {
    string temp;
    while (fin && getline(fin, temp)) {
        vec_str.push_back(temp);
    }
}
*/
/*17_6*/
#include "Fourteen.h"

int main() {
    
    return 0;
}