#ifndef STUDY_FIFTEEN_H
#define STUDY_FIFTEEN_H
//15_1
class Tv;

class Remote {
public:
    friend class Tv;
    enum State { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };
    enum { Normal, Interactice };
private:
    int mode;
    int Rmode;
public:
    Remote(int m = TV) : mode(m) { }
    bool volup(Tv & t);
    bool voldown(Tv & t);
    void onoff(Tv & t);
    void chanup(Tv & t);
    void chandown(Tv & t);
    void set_mode(Tv & t);
    void set_input(Tv & t);
    void set_chan(Tv & t, int c);
    void show_Rmode();
    int & get_Rmode();
};
class Tv {
public:
    /*friend void Remote::set_chan(Tv &t, int c);
    enum State { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };
    */
    friend class Remote;
    Tv(int s = Remote::Off, int mc = 125)
    : state(s), volume(5), maxchannel(mc), channel(2), mode(Remote::Cable), input(Remote::TV)
    { }
    void onoff() { state = (state == Remote::On) ? Remote::Off : Remote::On; }
    bool ison() const { return state == Remote::On; }
    bool volup();
    bool voldown();
    bool set_Rmode(Remote & R);
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Remote::Antenna) ? Remote::Cable : Remote::Antenna; }
    void set_input() { input = (input == Remote::TV) ? Remote::DVD : Remote::TV; }
    void settings() const;
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};
//Remote methods as inline functions
inline bool Remote::volup(Tv &t) { return t.volup(); }
inline bool Remote::voldown(Tv &t) { return t.voldown(); }
inline void Remote::onoff(Tv &t) { t.onoff(); }
inline void Remote::chanup(Tv &t) { t.chanup(); }
inline void Remote::chandown(Tv &t) { t.chandown(); }
inline void Remote::set_mode(Tv &t) { t.set_mode(); }
inline void Remote::set_input(Tv &t) { t.set_input(); }
inline void Remote::set_chan(Tv &t, int c) { t.channel = c; }
//15_2
#include <iostream>

class bad_hmean {
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) { }
    void mesg();
};
inline void bad_hmean::mesg() {
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid argument: a = -b\n";
}

class bad_gmean {
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) { }
    const char * mesg();
};
inline const char * bad_gmean::mesg() {
    return "gmean() arguments should be >= 0\n";
}

#endif //STUDY_FIFTEEN_H
