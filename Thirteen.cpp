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
namespace Exercise2 {
    Cd::Cd(char *s1, char *s2, int n, double x) {
        performers = new char[strlen(s1) + 1];
        strcpy(performers, s1);
        label = new char[strlen(s2) + 1];
        strcpy(label, s2);
        selections = n;
        playtime = x;
    }
    Cd::Cd(const Cd &d) {
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
    }
    Cd::Cd() {
        performers = new char[1];
        performers[0] = '\0';
        label = new char[1];
        label[0] = '\0';
        selections = 0;
        playtime = 0.0;
    }
    Cd::~Cd() {
        delete [] label;
        delete [] performers;
    }
    void Cd::Report() const {
        std::cout << "Performers: " << performers << std::endl
                  << "Label: " << label << std::endl
                  << "Selections: " << selections << std::endl
                  << "Play Time: " << playtime << std::endl;
    }
    Cd & Cd::operator = (const Cd & d) {
        if (this == &d)
            return * this;
        delete [] performers;
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
        return * this;
    }
    Classic::Classic(char *s1, char *s2, char *s3, char n, double x)
     :Cd(s1, s2, n, x){
        mainworks = new char[strlen(s3) + 1];
        strcpy(mainworks, s3);
    }
    Classic::Classic(const Classic &c) :Cd(c){
        mainworks = new char[strlen(c.mainworks) + 1];
        strcpy(mainworks, c.mainworks);
    }
    Classic::Classic() :Cd(){
        mainworks = new char[1];
        mainworks[0] = '\0';
    }
    Classic::~Classic() {
        delete [] mainworks;
    }
    void Classic::Report() const {
        Cd::Report();
        std::cout << mainworks << std::endl;
    }
    Classic & Classic::operator = (const Classic & c) {
        if (this == & c)
            return * this;
        Cd::operator = (c);
        delete [] mainworks;
        mainworks = new char[strlen(c.mainworks) + 1];
        strcpy(mainworks, c.mainworks);
        return * this;
    }
}










