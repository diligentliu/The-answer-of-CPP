#ifndef STUDY_THIRTEEN_H
#define STUDY_THIRTEEN_H
//13——1
class Cd {
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
};
class Classic : public Cd {
private:
    char mainworks[50];
public:
    Classic(char * s1, char * s2, char * s3, char n, double x);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
};
//13_2
namespace Exercise2 {
    class Cd {
    private:
        char * performers;
        char * label;
        int selections;
        double playtime;
    public:
        Cd(char * s1, char * s2, int n, double x);
        Cd(const Cd & d);
        Cd();
        virtual ~Cd();
        virtual void Report() const;
        virtual Cd & operator = (const Cd & d);
    };
    class Classic : public Cd {
    private:
        char * mainworks;
    public:
        Classic(char * s1, char * s2, char * s3, char n, double x);
        Classic(const Classic & c);
        Classic();
        virtual ~Classic();
        virtual void Report() const;
        virtual Classic & operator = (const Classic & c);
    };
}











#endif //STUDY_THIRTEEN_H
