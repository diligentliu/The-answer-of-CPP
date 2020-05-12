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
//13_3
class DMA {
private:
    char * label;
    int rating;
public:
    DMA(const char * l = "null", int r = 0);
    DMA(const DMA & dma);
    virtual ~DMA() = 0;
    virtual void View();
    DMA & operator = (const DMA & dma);
    friend std::ostream & operator << (std::ostream & os, const DMA & dma);
};
class baseDMA : public DMA {
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const DMA & dma);
    virtual ~baseDMA();
    virtual void View();
    baseDMA & operator = (const baseDMA &baseDma);
    friend std::ostream & operator << (std::ostream & os, const baseDMA &baseDma);
};
class lacksDMA : public DMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const DMA & dma);
    virtual ~lacksDMA();
    virtual void View();
    friend std::ostream & operator << (std::ostream & os, const lacksDMA & lacksDma);
};
class hasDMA : public DMA {
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const DMA & dma);
    hasDMA(const hasDMA & hasDma);
    virtual ~hasDMA();
    virtual void View();
    hasDMA & operator = (const hasDMA & hasDma);
    friend std::ostream & operator << (std::ostream & os, const hasDMA & hasDma);
};
//13_4

#endif //STUDY_THIRTEEN_H