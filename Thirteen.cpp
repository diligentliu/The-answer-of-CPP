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
//13_3
DMA::DMA(const char * l, int r) {
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}
DMA::DMA(const DMA & dma) {
    label = new char[strlen(dma.label) + 1];
    strcpy(label, dma.label);
    rating = dma.rating;
}
DMA::~DMA() noexcept {
    delete [] label;
}
void DMA::View() {
    std::cout << "Label: " << label << std::endl
              << "Rating: " << rating << std::endl;
}
DMA & DMA::operator = (const DMA & dma) {
    if (this == & dma)
        return * this;
    delete [] label;
    label = new char[strlen(dma.label) + 1];
    strcpy(label, dma.label);
    rating = dma.rating;
    return * this;
}
std::ostream & operator << (std::ostream & os, const DMA & dma) {
    os << "Label: " << dma.label << std::endl
       << "Rating: " << dma.rating;
    return os;
}
baseDMA::baseDMA(const char * l, int r) : DMA(l, r) { }
baseDMA::baseDMA(const DMA &dma) : DMA(dma) { }
baseDMA::~baseDMA() noexcept { }
void baseDMA::View() {
    DMA::View();
}
baseDMA & baseDMA::operator = (const baseDMA &baseDma) {
    DMA::operator = (baseDma);
    return * this;
}
std::ostream & operator << (std::ostream & os, const baseDMA & baseDma) {
    os << (const DMA &)baseDma;
    return os;
}
lacksDMA::lacksDMA(const char *c, const char *l, int r) : DMA(l, r){
    strcpy(color, c);
}
lacksDMA::lacksDMA(const char *c, const DMA &dma) : DMA(dma) {
    strcpy(color, c);
}
lacksDMA::~lacksDMA() noexcept { }
void lacksDMA::View() {
    DMA::View();
    std::cout << "Color: " << color << std::endl;
}
std::ostream & operator << (std::ostream & os, const lacksDMA & lacksDma) {
    os << (const DMA &)lacksDma;
    return os;
}
hasDMA::hasDMA(const char *s, const char *l, int r) : DMA(l, r) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const DMA &dma) : DMA(dma) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &hasDma) :DMA(hasDma) {
    style = new char[strlen(hasDma.style) + 1];
    strcpy(style, hasDma.style);
}
hasDMA::~hasDMA() noexcept {
    delete [] style;
}
void hasDMA::View() {
    DMA::View();
    std::cout << "Style: " << style << std::endl;
}
hasDMA & hasDMA::operator = (const hasDMA & hasDma) {
    if (this == & hasDma)
        return * this;
    DMA::operator = (hasDma);
    delete [] style;
    style = new char[strlen(hasDma.style) + 1];
    strcpy(style, hasDma.style);
    return * this;
}
std::ostream & operator << (std::ostream & os, const hasDMA & hasDma) {
    os << (const DMA &)hasDma << std::endl << hasDma.style;
    return os;
}
//13_4
Port::Port(const char *br, const char *st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}
Port::Port(const Port &p) {
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}
Port & Port::operator = (const Port &p) {
    if (this == & p)
        return * this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return * this;
}
Port & Port::operator += (int b) {
    bottles += b;
    return * this;
}
Port & Port::operator -= (int b) {
    bottles -= b;
    return * this;
}
void Port::Show() const {
    std::cout << "Brand: " << brand << std::endl
              << "Kind: " << style << std::endl
              << "Bottles: " << bottles << std::endl;
}
std::ostream & operator << (std::ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
VintagePort::VintagePort(const char *br, int b, const char *nn, int y)
: Port(br, "vintage", b) {
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}
VintagePort::VintagePort(const VintagePort &vp)
: Port(vp) {
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
VintagePort & VintagePort::operator = (const VintagePort &vp) {
    if (this == & vp)
        return * this;
    Port::operator = (vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return * this;
}
void VintagePort::Show() const {
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl
              << "Year: " << year << std::endl;
}
std::ostream & operator << (std::ostream & os, const VintagePort & vp) {
    os << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}