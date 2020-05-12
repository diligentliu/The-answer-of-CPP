#include <iostream>
#include <cstring>
#include "Thirteen.h"
//13_1
Cd::Cd(char *s1, char *s2, int n, double x) {
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd() {
    strcpy(performers, "null");
    strcpy(label, "null");
    selections = 0;
    playtime = 0.0;
}
Cd::~Cd() { }
void Cd::Report() const {
    std::cout << "Performers: " << performers << std::endl
              << "Label: " << label << std::endl
              << "Selections: " << selections << std::endl
              << "Play Time: " << playtime << std::endl;
}
Classic::Classic(char *s1, char *s2, char *s3, char n, double x) :Cd(s1, s2, n, x) {
    strcpy(mainworks, s3);
}
Classic::Classic() :Cd() {
    strcpy(mainworks, "null");
}
Classic::~Classic() { }
void Classic::Report() const {
    Cd::Report();
    std::cout << "Main Works: " << mainworks << std::endl;
}
//13_2











