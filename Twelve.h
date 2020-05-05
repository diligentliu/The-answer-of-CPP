#ifndef STUDY_TWELVE_H
#define STUDY_TWELVE_H
//12_1
class Cow {
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator = (const Cow & c);
    void ShowCow() const;
};
//12_2

#endif //STUDY_TWELVE_H
