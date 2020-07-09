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
#include <algorithm>
#include <iterator>
#include <vector>

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
/*17_6
#include "Fourteen.h"

void startmenu();

int main() {
    const int MAX = 5;
    abstr_emp *pc[MAX], *pc2[2 * MAX];
    int ct1 = 0, ct2 = 0;
    ofstream fout("17_6.txt", ios::out | ios::app);
    startmenu();
    enum classkind { Employee, Manager, Fink, Highfink };
    char classchioce;
    for (int i = 0; i < MAX; ++i) {
        cin >> classchioce;
        if (classchioce == 'q')
            break;
        else if (classchioce == 'e') {
            pc[i] = new employee;
            ct1++;
            pc[i]->SetAll();
        } else if (classchioce == 'm') {
            pc[i] = new manager;
            ct1++;
            pc[i]->SetAll();
        } else if (classchioce == 'f') {
            pc[i] = new fink;
            ct1++;
            pc[i]->SetAll();
        } else if (classchioce == 'h') {
            pc[i] = new highfink;
            ct1++;
            pc[i]->SetAll();
        } else {
            cout << "error" << endl;
            break;
        }
    }
    for (int i = 0; i < MAX; ++i) {
        pc[i]->WriteAll(fout);
    }
    ifstream fin("17_6.txt");
    int classtype;
    for (int i = 0; i < 2 * MAX; ++i) {
        fin >> classtype;
        if (!fin) break;
        fin.get();
        switch (classtype) {
            case Employee:
                pc2[i] = new employee;
                ct2++;
                pc2[i]->GetAll(fin);
                break;
            case Manager:
                pc2[i] = new manager;
                ct2++;
                pc2[i]->GetAll(fin);
                break;
            case Fink:
                pc2[i] = new fink;
                ct2++;
                pc2[i]->GetAll(fin);
                break;
            case Highfink:
                pc2[i] = new highfink;
                ct2++;
                pc2[i]->GetAll(fin);
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < ct2; ++i) {
        pc2[i]->ShowAll();
    }
    for (int i = 0; i < ct1; ++i) {
        delete pc[i];
    }
    for (int i = 0; i < ct2; ++i) {
        delete pc2[i];
    }
    return 0;
}

void startmenu() {
    cout << "Please enter an number, the number "
         << "represents the class you are about to create." << endl;
    cout << "********************************" << endl;
    cout << "*          e. Employee         *" << endl;
    cout << "*          m. Manager          *" << endl;
    cout << "*          f. Fink             *" << endl;
    cout << "*          h. Highfink         *" << endl;
    cout << "*          q. QUIT             *" << endl;
    cout << "********************************" << endl;
}
*/
/*17_7
#include <algorithm>
#include <vector>

// functor Store
class Store {
private:
    std::ostream &os;

public:
    Store(std::ostream &o) : os(o) {}
    // overloaded funtions
    void operator()(const std::string &s);
};

void Store::operator()(const std::string &s) {
    std::size_t len = s.length();

    // store string length
    os.write((char *)&len, sizeof(std::size_t));

    // store string data
    os.write(s.data(), len);
}

void ShowStr(const string &str);
void GetStrs(std::ifstream &fin, std::vector<std::string> &vistr);

int main() {
    using namespace std;
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0') vostr.push_back(temp);
    cout << "Here is your input" << endl;
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("17_7", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    vector<string> vistr;
    ifstream fin("17_7", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not open file for input." << endl;
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const std::string &s) { std::cout << s << std::endl; }

void GetStrs(std::ifstream &fin, std::vector<std::string> &vistr) {
    std::size_t len;  // string length
    while (fin.read((char *)&len, sizeof(std::size_t))) {
        std::string str;
        char ch;
        for (int i = 0; i < len; ++i) {
            fin.read(&ch, sizeof(char));
            str.push_back(ch);
        }

        // put string to vector
        vistr.push_back(str);
    }
}
*/