#ifndef STUDY_ELEVEN_H
#define STUDY_ELEVEN_H
#include <iostream>

//11_1 & 11_3
namespace VECTOR {
    class Vector {
    private:
        double x;
        double y;
        double mag;
        double ang;
        char mode;
        void set_x();
        void set_y();
        void set_mag();
        void set_ang();
    public:
        Vector();
        Vector(double n1,double n2,char form = 'r');
        void set(double n1,double n2,char form = 'r');
        ~Vector(){}
        double xval()const {return x;}
        double yval()const {return y;}
        double magval()const {return mag;}
        double angval()const {return ang;}
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector & b)const ;
        Vector operator-(const Vector & b)const ;
        Vector operator-()const ;
        Vector operator*(double n)const ;
        friend Vector operator*(double n,const Vector & a);
        friend std::ostream  & operator<<(std::ostream & os, const Vector & v);
    };
}
//11_2
namespace VECTOR2 {
    class Vector {
    private:
        double x;
        double y;
        char mode;
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1,double n2,char form = 'r');
        void set(double n1,double n2,char form = 'r');
        ~Vector(){}
        double xval()const {return x;}
        double yval()const {return y;}
        double magval()const;
        double angval()const;
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector & b)const ;
        Vector operator-(const Vector & b)const ;
        Vector operator-()const ;
        Vector operator*(double n)const ;
        friend Vector operator*(double n,const Vector & a);
        friend std::ostream  & operator<<(std::ostream & os, const Vector & v);
    };
}
//11_4
class  Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time & t, const Time & t2);
    friend Time operator-(const Time & t, const Time & t2);
    friend Time operator*(const Time & t, double n);
    void Show() const;
};
//11_5
class Stonewt {
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    char mode;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt(){}
    void set_st_p(){mode = 's';}
    void set_po(){mode = 'p';}
    Stonewt operator + (Stonewt St);
    Stonewt operator - (Stonewt St);
    friend Stonewt operator * (double n, Stonewt St);
    friend std::ostream & operator << (std::ostream & os, Stonewt & St);
};
//11_6
namespace STONEWT {
    class Stonewt {
    private:
        enum {
            Lbs_per_stn = 14
        };
        int stone;
        double pds_left;
        double pounds;
        char mode;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt() {}
        void set_st_p() { mode = 's'; }
        void set_po() { mode = 'p'; }
        bool operator == (Stonewt St) { return pounds == St.pounds; }
        bool operator > (Stonewt St) { return pounds > St.pounds; }
        bool operator < (Stonewt St) { return pounds < St.pounds; }
        bool operator >= (Stonewt St) { return pounds >= St.pounds; }
        bool operator <= (Stonewt St) { return pounds <= St.pounds; }
        bool operator != (Stonewt St) { return pounds != St.pounds; }
        Stonewt operator + (Stonewt St);
        Stonewt operator - (Stonewt St);
        friend Stonewt operator * (double n, Stonewt St);
        friend std::ostream & operator << (std::ostream & os, Stonewt & St);
    };
}
//11_7
class Complex : public std::error_code {
private:
    double Re_num;
    double Im_num;
public:
    Complex(double Re = 0.0, double Im = 0.0);
    ~Complex() {}
    Complex operator + (Complex & co) const;
    Complex operator - (Complex & co) const;
    Complex operator * (Complex & co) const;
    Complex operator * (double n) const;
    Complex operator ~ () const;
    friend Complex operator * (double n, Complex & co);
    friend std::ostream & operator << (std::ostream & os, const Complex & co);
    friend std::istream & operator >> (std::istream & is, Complex & co);
};
#endif //STUDY_ELEVEN_H
