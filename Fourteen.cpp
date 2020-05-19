#include "Fourteen.h"
//14_1
Wine::Wine(const char *l, int y, const int * yr, const int * bot)
: yearandbottles(ArrayInt(yr, y), ArrayInt(bot, y)) {
    label = l;
    years = y;
}
Wine::Wine(const char *l, int y)
: yearandbottles(ArrayInt(y), ArrayInt(y)) {
    label = l;
    years = y;
}
void Wine::GetBottles() {
    std::cout << "Enter " << label << " data for " << years << " year(s): " << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "Enter year: ";
        std::cin >> yearandbottles.first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> yearandbottles.second()[i];
    }
}
std::string & Wine::Label() {
    return label;
}
int Wine::sum() {
    return yearandbottles.second().sum();
}
void Wine::Show() {
    std::cout << "Wine: " << label << std::endl;
    std::cout << "\tYear" << "\t" << "Bottles" << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "\t" << yearandbottles.first()[i] << "\t" << yearandbottles.second()[i] << std::endl;
    }
}
//14_2
namespace Exercise2 {
    Wine::Wine(const char * l, int y, const int * yr, const int * bot)
    : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {
        years = y;
    }
    Wine::Wine(const char *l, int y)
    : std::string(l), PairArray(ArrayInt(y), ArrayInt(y)) {
        years = y;
    }
    void Wine::GetBottles() {
        std::cout << "Enter " << Label() << " data for " << years << " year(s): " << std::endl;
        for (int i = 0; i < years; ++i) {
            std::cout << "Enter year: ";
            std::cin >> PairArray::first()[i];
            std::cout << "Enter bottles for that year: ";
            std::cin >> PairArray::second()[i];
        }
    }
    std::string & Wine::Label() {
        return (std::string &)(* this);
    }
    int Wine::sum() {
        return PairArray::second().sum();
    }
    void Wine::Show() {
        std::cout << "Wine: " << Label() << std::endl;
        std::cout << "\tYear" << "\t" << "Bottles" << std::endl;
        for (int i = 0; i < years; ++i) {
            std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << std::endl;
        }
    }
}
//14_3
void Worker::Set() {
    std::cout << "Enter worker's name: ";
    getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n')
        continue;
}
void Worker::Show() const {
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}
std::ostream & operator << (std::ostream & os, const Worker & wk) {
    os << "Name: " << wk.fullname << std::endl;
    os << "Employee ID: " << wk.id;
    return os;
}
//14_4
