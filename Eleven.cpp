#include "Eleven.h"
// 11_1 & 11_3
#include <cmath>

using std::atan2;
using std::cos;
using std::cout;
using std::sin;
namespace VECTOR {
    const double Rad_to_deg = 57.29557795130823;

    void Vector::set_mag() { mag = sqrt(x * x + y * y); }

    void Vector::set_ang() {
        if (x == 0.0 && y == 0.0) ang = 0.0;
        ang = atan2(y, x);
    }

    void Vector::set_x() { x = mag * cos(ang); }

    void Vector::set_y() { y = mag * sin(ang); }

    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = 'r';
    }

    Vector::Vector(double n1, double n2, char form) {
        mode = form;
        if (form == 'r') {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else {
            cout << "Incorrect 3rd argument to Vector()-- ";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }

    void Vector::set(double n1, double n2, char form) {
        mode = form;
        if (form == 'r') {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == 'p') {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector()--";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }

    void Vector::polar_mode() { mode = 'p'; }

    void Vector::rect_mode() { mode = 'r'; }

    Vector Vector::operator+(const Vector &b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const {
        return Vector(x - b.x, y + b.y);
    }

    Vector Vector::operator-() const { return Vector(-x, -y); }

    Vector Vector::operator*(double n) const { return Vector(n * x, n * y); }

    Vector operator*(double n, const Vector &a) { return a * n; }

    std::ostream &operator<<(std::ostream &os, const Vector &v) {
        if (v.mode == 'r')
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == 'p') {
            os << "(x, y) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        } else
            os << "Vector object mode is invalid.";
        return os;
    }
}  // namespace VECTOR
// 11_2
namespace VECTOR2 {
    const double Rad_to_deg = 57.29557795130823;

    void Vector::set_x() { x = magval() * cos(angval()); }

    void Vector::set_y() { y = magval() * sin(angval()); }

    Vector::Vector() {
        x = y = 0.0;
        mode = 'r';
    }

    Vector::Vector(double n1, double n2, char form) {
        mode = form;
        if (form == 'r') {
            x = n1;
            y = n2;
        } else {
            cout << "Incorrect 3rd argument to Vector()-- ";
            cout << "Vector set to 0\n";
            x = y = 0.0;
            mode = 'r';
        }
    }

    void Vector::set(double n1, double n2, char form) {
        mode = form;
        if (form == 'r') {
            x = n1;
            y = n2;
        } else if (form == 'p') {
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector()--";
            cout << "Vector set to 0\n";
            x = y = 0.0;
            mode = 'r';
        }
    }

    double Vector::magval() const { return sqrt(x * x + y * y); }

    double Vector::angval() const { return atan2(y, x); }

    void Vector::polar_mode() { mode = 'p'; }

    void Vector::rect_mode() { mode = 'r'; }

    Vector Vector::operator+(const Vector &b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const {
        return Vector(x - b.x, y + b.y);
    }

    Vector Vector::operator-() const { return Vector(-x, -y); }

    Vector Vector::operator*(double n) const { return Vector(n * x, n * y); }

    Vector operator*(double n, const Vector &a) { return a * n; }

    std::ostream &operator<<(std::ostream &os, const Vector &v) {
        if (v.mode == 'r')
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == 'p') {
            os << "(x, y) = (" << v.magval() << ", " << v.angval() * Rad_to_deg
               << ")";
        } else
            os << "Vector object mode is invalid.";
        return os;
    }
}  // namespace VECTOR2
// 11_4
Time::Time() { hours = minutes = 0; }

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) { hours += h; }

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time operator+(const Time &t, const Time &t2) {
    Time sum;
    sum.minutes = t.minutes + t2.minutes;
    sum.hours = t.minutes + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time &t, const Time &t2) {
    Time diff;
    int tot1, tot2;
    tot1 = t2.minutes + 60 * t2.hours;
    tot2 = t.minutes + 60 * t.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time operator*(const Time &t, double mult) {
    Time result;
    long totalminute = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminute / 60;
    result.minutes = totalminute % 60;
    return result;
}

void Time::Show() const {
    std::cout << hours << " hours, " << minutes << " minutes";
}

// 11_5
Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = 'p';
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = 's';
}

Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
    mode = 'p';
}

Stonewt Stonewt::operator+(Stonewt St) {
    double lbs = pounds + St.pounds;
    return Stonewt(lbs);
}

Stonewt Stonewt::operator-(Stonewt St) {
    double lbs = pounds - St.pounds;
    return Stonewt(lbs);
}

Stonewt operator*(double n, Stonewt St) {
    double lbs = n * St.pounds;
    return Stonewt(lbs);
}

std::ostream &operator<<(std::ostream &os, Stonewt &St) {
    if (St.mode == 's')
        os << St.stone << "stone, " << St.pds_left << "pounds";
    else
        os << St.pounds << "pounds";
    return os;
}
// 11_6
namespace STONEWT {
    Stonewt::Stonewt(double lbs) {
        stone = int(lbs) / Lbs_per_stn;
        pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
        pounds = lbs;
        mode = 'p';
    }

    Stonewt::Stonewt(int stn, double lbs) {
        stone = stn;
        pds_left = lbs;
        pounds = stn * Lbs_per_stn + lbs;
        mode = 's';
    }

    Stonewt::Stonewt() {
        stone = pounds = pds_left = 0;
        mode = 'p';
    }

    Stonewt Stonewt::operator+(Stonewt St) {
        double lbs = pounds + St.pounds;
        return Stonewt(lbs);
    }

    Stonewt Stonewt::operator-(Stonewt St) {
        double lbs = pounds - St.pounds;
        return Stonewt(lbs);
    }

    Stonewt operator*(double n, Stonewt St) {
        double lbs = n * St.pounds;
        return Stonewt(lbs);
    }

    std::ostream &operator<<(std::ostream &os, Stonewt &St) {
        if (St.mode == 's')
            os << St.stone << "stone, " << St.pds_left << "pounds";
        else
            os << St.pounds << "pounds";
        return os;
    }
}  // namespace STONEWT
// 11_7
Complex::Complex(double Re, double Im) {
    Re_num = Re;
    Im_num = Im;
}

Complex Complex::operator+(Complex &co) const {
    return Complex(Re_num + co.Re_num, Im_num + co.Im_num);
}

Complex Complex::operator-(Complex &co) const {
    return Complex(Re_num - co.Re_num, Im_num - co.Im_num);
}

Complex Complex::operator*(Complex &co) const {
    return Complex(Re_num * co.Re_num - Im_num * co.Im_num,
                   Re_num * co.Im_num + Im_num * co.Re_num);
}

Complex Complex::operator*(double n) const {
    return Complex(n * Re_num, n * Im_num);
}

Complex Complex::operator~() const { return Complex(Re_num, -Im_num); }

Complex operator*(double n, Complex &co) {
    return Complex(n * co.Re_num, n * co.Im_num);
}

std::ostream &operator<<(std::ostream &os, const Complex &co) {
    os << "(" << co.Re_num << ", " << co.Im_num << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Complex &co) {
    is >> co.Re_num;
    is >> co.Im_num;
    return is;
}
