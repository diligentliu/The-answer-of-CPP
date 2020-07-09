#include "Fourteen.h"

// 14_1
Wine::Wine(const char *l, int y, const int *yr, const int *bot)
        : yearandbottles(ArrayInt(yr, y), ArrayInt(bot, y)) {
    label = l;
    years = y;
}

Wine::Wine(const char *l, int y) : yearandbottles(ArrayInt(y), ArrayInt(y)) {
    label = l;
    years = y;
}

void Wine::GetBottles() {
    std::cout << "Enter " << label << " data for " << years
              << " year(s): " << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "Enter year: ";
        std::cin >> yearandbottles.first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> yearandbottles.second()[i];
    }
}

std::string &Wine::Label() { return label; }

int Wine::sum() { return yearandbottles.second().sum(); }

void Wine::Show() {
    std::cout << "Wine: " << label << std::endl;
    std::cout << "\tYear"
              << "\t"
              << "Bottles" << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "\t" << yearandbottles.first()[i] << "\t"
                  << yearandbottles.second()[i] << std::endl;
    }
}
// 14_2
namespace Exercise2 {
    Wine::Wine(const char *l, int y, const int *yr, const int *bot)
            : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {
        years = y;
    }

    Wine::Wine(const char *l, int y)
            : std::string(l), PairArray(ArrayInt(y), ArrayInt(y)) {
        years = y;
    }

    void Wine::GetBottles() {
        std::cout << "Enter " << Label() << " data for " << years
                  << " year(s): " << std::endl;
        for (int i = 0; i < years; ++i) {
            std::cout << "Enter year: ";
            std::cin >> PairArray::first()[i];
            std::cout << "Enter bottles for that year: ";
            std::cin >> PairArray::second()[i];
        }
    }

    std::string &Wine::Label() { return (std::string &) (*this); }

    int Wine::sum() { return PairArray::second().sum(); }

    void Wine::Show() {
        std::cout << "Wine: " << Label() << std::endl;
        std::cout << "\tYear"
                  << "\t"
                  << "Bottles" << std::endl;
        for (int i = 0; i < years; ++i) {
            std::cout << "\t" << PairArray::first()[i] << "\t"
                      << PairArray::second()[i] << std::endl;
        }
    }
}  // namespace Exercise2
// 14_3
void Worker::Set() {
    std::cout << "Enter worker's name: ";
    getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n') continue;
}

void Worker::Show() const {
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Worker &wk) {
    os << "Name: " << wk.fullname << std::endl;
    os << "Employee ID: " << wk.id;
    return os;
}
// 14_4
#include <cstring>

Person::Person() { firstname = lastname = NULL; }

Person::Person(char *fn, char *ln) {
    firstname = new char[strlen(fn) + 1];
    strcpy(firstname, fn);
    lastname = new char[strlen(ln) + 1];
    strcpy(lastname, ln);
}

Person::Person(const Person &person) {
    firstname = new char[strlen(person.firstname) + 1];
    strcpy(firstname, person.firstname);
    lastname = new char[strlen(person.lastname) + 1];
    strcpy(lastname, person.lastname);
}

Person::~Person() {
    delete[] lastname;
    delete[] firstname;
}

void Person::Data() const {
    std::cout << "Firstname: " << firstname << std::endl;
    std::cout << "Lastname: " << lastname << std::endl;
}

void Person::Show() const { Data(); }

Person &Person::operator=(const Person &person) {
    if (this == &person) return *this;
    delete[] firstname;
    firstname = new char[strlen(person.firstname) + 1];
    strcpy(firstname, person.firstname);
    delete[] lastname;
    lastname = new char[strlen(person.lastname) + 1];
    strcpy(lastname, person.lastname);
    return *this;
}

Gunslinger::Gunslinger() : Person() {
    pulltime = 0.0;
    score = 0;
}

Gunslinger::Gunslinger(char *fn, char *ln, double pt, int sc) : Person(fn, ln) {
    pulltime = pt;
    score = sc;
}

Gunslinger::Gunslinger(const Gunslinger &gs) : Person(gs) {
    pulltime = gs.pulltime;
    score = gs.score;
}

Gunslinger::~Gunslinger() {}

void Gunslinger::Data() const {
    std::cout << "Gun pull time: " << pulltime << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void Gunslinger::Show() const {
    Person::Show();
    Data();
}

double Gunslinger::Draw() const { return pulltime; }

Gunslinger &Gunslinger::operator=(const Gunslinger &gs) {
    if (this == &gs) return *this;
    Person::operator=(gs);
    pulltime = gs.pulltime;
    score = gs.score;
    return *this;
}

#include <cstdlib>
#include <ctime>

PokerPlayer::PokerPlayer() : Person(), card(0) {}

PokerPlayer::PokerPlayer(char *fn, char *ln, int c) : Person(fn, ln), card(c) {}

PokerPlayer::PokerPlayer(const PokerPlayer &pp) : Person(pp), card(pp.card) {}

void PokerPlayer::Data() const { std::cout << "Card: " << card << std::endl; }

void PokerPlayer::Show() const {
    Person::Show();
    Data();
}

int PokerPlayer::Draw() {
    srand(time(0));
    card = rand() % 52 + 1;
    return card;
}

int PokerPlayer::GetCard(int n) {
    if (n == 0) return card;
    card = n;
    return card;
}

PokerPlayer &PokerPlayer::operator=(const PokerPlayer &pp) {
    if (this == &pp) return *this;
    Person::operator=(pp);
    card = pp.card;
    return *this;
}

BadDude::BadDude() : Person(), Gunslinger(), PokerPlayer() {}

BadDude::BadDude(char *fn, char *ln, double pt, int sc, int c)
        : Person(fn, ln), Gunslinger(fn, ln, pt, sc), PokerPlayer(fn, ln, c) {}

BadDude::BadDude(const BadDude &bd)
        : Person(bd), Gunslinger(bd), PokerPlayer(bd) {}

void BadDude::Data() const {
    Gunslinger::Data();
    PokerPlayer::Data();
}

void BadDude::Show() const {
    Person::Data();
    Data();
}

double BadDude::Gdraw() const { return Gunslinger::Draw(); }

int BadDude::Cdraw() { return PokerPlayer::Draw(); }

BadDude &BadDude::operator=(const BadDude &bd) {
    if (this == &bd) return *this;
    Person::operator=(bd);
    Gunslinger::operator=(bd);
    PokerPlayer::operator=(bd);
    return *this;
}

// 14_5
abstr_emp::abstr_emp() {
    fname = "";
    lname = "";
    job = "";
}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln,
                     const std::string &j) {
    fname = fn;
    lname = ln;
    job = j;
}

void abstr_emp::ShowAll() const {
    std::cout << "FirstName: " << fname << std::endl;
    std::cout << "LastName: " << lname << std::endl;
    std::cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll() {
    std::cout << "Enter FirstName: ";
    std::cin >> fname;
    std::cout << "Enter LastName: ";
    std::cin >> lname;
    std::cout << "Enter job: ";
    std::cin >> job;
}

void abstr_emp::WriteAll(std::ostream &os) {
    os << fname << std::endl << lname << std::endl << job;
}

void abstr_emp::GetAll(std::istream &is) {
    std::getline(is, fname);
    std::getline(is, lname);
    std::getline(is, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
    os << "FirstName: " << e.fname << std::endl
       << "LastName: " << e.lname << std::endl
       << "Job: " << e.job;
    return os;
}

abstr_emp::~abstr_emp() {}

employee::employee() : abstr_emp() {}

employee::employee(const std::string &fn, const std::string &ln,
                   const std::string &j)
        : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }

void employee::WriteAll(std::ostream &os) {
    os << (int)0 << std::endl;
    abstr_emp::WriteAll(os);
    os << std::endl;
}

void employee::GetAll(std::istream &is) {
    abstr_emp::GetAll(is);
}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager &m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "InChargeOf: " << inchargeof << std::endl;
}

void manager::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter InChargeOf: ";
    std::cin >> inchargeof;
}

void manager::WriteAll(std::ostream &os) {
    os << (int)1 << std::endl;
    abstr_emp::WriteAll(os);
    os << std::endl << inchargeof;
    os << std::endl;
}

void manager::GetAll(std::istream &is) {
    abstr_emp::GetAll(is);
    is >> inchargeof;
    is.get();
}

fink::fink() : abstr_emp(), reportsto("") {}

fink::fink(const std::string &fn, const std::string &ln, const std::string &j,
           const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo)
        : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "ReportsTo: " << reportsto << std::endl;
}

void fink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter ReportsTo: ";
    std::cin >> reportsto;
}

void fink::WriteAll(std::ostream &os) {
    os << (int)2 << std::endl;
    abstr_emp::WriteAll(os);
    os << std::endl << reportsto;
    os << std::endl;
}

void fink::GetAll(std::istream &is) {
    abstr_emp::GetAll(is);
    std::getline(is, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink() {}

highfink::highfink(const std::string &fn, const std::string &ln,
                   const std::string &j, const std::string &rpo, int ico)
        : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), fink(f) {
    manager::InChargeOf() = ico;
}

highfink::highfink(const manager &m, const std::string &rpo)
        : abstr_emp(m), manager(m) {
    fink::ReportsTo() = rpo;
}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "InChargeOf: " << InChargeOf() << std::endl;
    std::cout << "ReportsTo: " << ReportsTo() << std::endl;
}

void highfink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter InChargeOf: ";
    std::cin >> InChargeOf();
    std::cout << "Enter ReportsTo: ";
    std::cin >> ReportsTo();
}

void highfink::WriteAll(std::ostream &os) {
    os << (int)3 << std::endl;
    abstr_emp::WriteAll(os);
    os << std::endl << InChargeOf() << std::endl << ReportsTo();
    os << std::endl;
}

void highfink::GetAll(std::istream &is) {
    abstr_emp::GetAll(is);
    is >> InChargeOf();
    is.get();
    std::getline(is, ReportsTo());
}