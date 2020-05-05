#include <iostream>
#include <cstring>
#include "Twelve.h"
//12_1
Cow::Cow() {
    strcpy(name, "");
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}
Cow::Cow(const char *nm, const char *ho, double wt) {
    strcpy(name, nm);
    int len = strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::Cow(const Cow &c) {
    strcpy(name, c.name);
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow() {
    delete[] hobby;
}
Cow & Cow::operator = (const Cow &c) {
    if (this == &c)
        return *this;
    strcpy(name, c.name);
    delete[] hobby;
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}
void Cow::ShowCow() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hobby: " << hobby << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}
//12_2
