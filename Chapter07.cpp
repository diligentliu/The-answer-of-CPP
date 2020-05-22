#include <iostream>
using namespace std;
/*7_1
double harmonic_mean(double , double );
int main(){
    double x,y;
    cin >> x >> y;
    while (x != 0 && y != 0){
        double har = harmonic_mean(x,y);
        cout << "The harmonic mean of " << x << " and " << y << " is " << har << endl;
        cin >> x >> y;
    }
}
double harmonic_mean(double x, double y){
    return (2.0*x*y/(x+y));
}
*/
/*7_2
void input(float * ,int );
void output(float * ,int );
float average(float * ,int );
int main(){
    float score[10];
    int SIZE;
    cout << "Please Enter the numbers of your score:";
    cin >> SIZE;
    input(score,SIZE);
    output(score,SIZE);
    cout << "The average of your score is " << average(score,SIZE);
}
void input(float *p ,int SIZE){
    for (int i = 0; i < SIZE; ++i) {
        cin >> *(p+i);
    }
}
void output(float *p ,int SIZE){
    for (int i = 0; i < SIZE; ++i) {
        cout << *(p+i) << " ";
    }
    cout << endl;
}
float average(float *p,int SIZE){
    float aver=0;
    for (int i = 0; i < SIZE; ++i) {
        aver = aver + *(p+i);
    }
    return (aver/(float)SIZE);
}
*/
/*7_3
struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void show_box(box );
void product(box *);
int main(){
    box B={"Asdfghjkl",1.0,2.0,3.0,0};
    show_box(B);
    product(&B);
    show_box(B);
}
void show_box(box B){
    cout << B.maker << endl
         << B.height << endl
         << B.width << endl
         << B.length << endl
         << B.volume << endl;
}
void product(box *p){
    p->volume = p->length * p->width *p->height;
}
*/
/*7_4
long double probability(unsigned numbers, unsigned picks);
int main(){
    cout << "The probability is " << probability(47,5)*probability(27,1);
    return 0;
}
long double probability(unsigned numbers, unsigned picks){
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
*/
/*7_5
long long int factorial(int );
int main(){
    int num;
    cin >> num;
    cout << factorial(num);
}
long long int factorial(int n){
    if (n == 0){
        return 1;
    } else
        return (factorial(n-1) * n);
}
*/
/*7_6
int Fill_array(double array[], int size);
void Show_array(double array[], int size);
void Reverse_array(double array[], int size);
int main(){
    int size = 20;
    double array[size];
    int m_size = Fill_array(array,size);
    Show_array(array,m_size);
    Reverse_array(array,m_size);
    Show_array(array,m_size);
    Reverse_array(array, m_size);
    Reverse_array(array+1, m_size-2);
    Show_array(array, m_size);
}
int Fill_array(double array[], int size){
    int i = 0;
    while (cin >> array[i] && i < size)
        ++i;
    return i;
}
void Show_array(double array[], int size){
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
void Reverse_array(double array[], int size){
    int t;
    for (int i = 0; i < size / 2; ++i) {
        t = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = t;
    }
}
*/
/*7_7
const int Max = 5;
double* fill_array(double ar[],int limit);
void show_array(const double ar[],double *end);
void revalue(double r, double ar[],double *end);
int main(){
    double properties[Max];
    double* end = fill_array(properties,Max);
    show_array(properties,end);
    cout <<"Enter revaluation factor: ";
    double factor;
    cin >> factor;
    revalue(factor,properties,end);
    show_array(properties, end);
    cout << "Done.\n";
    return 0;
}
double* fill_array(double ar[], int limit){
    double temp;
    int i;
    for (i = 0; i < limit; ++i){
        cout << "Enter value #" << (i+1) << ": ";
        cin >> temp;
        if (!cin){
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input: input process terminated.\n";
            break;
        } else if (temp < 0)
            break;
        ar[i] = temp;
    }
    return (ar+i-1);
}
void show_array(const double ar[], double * end){
    for (int i = 0; ar+i <= end; ++i) {
        cout << "Property #" << (i+1) << ": $";
        cout << ar[i] << endl;
    }
}
void revalue (double r, double ar[], double *end){
    for (int i = 0; ar+i <= end; ++i)
        ar[i] *= r;
}
*/
/*7_8
const int Slen = 30;
struct student {
    char fullname[Slen];
    char hobby[Slen];
    int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);
int main(){
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for(int i = 0; i < entered; ++i){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done" << endl;
    return 0;
}
int getinfo(student pa[], int n){
    for (int i = 0; i < n; ++i) {
        cout << "Enter the information of student #" << i+1 << ":" << endl;
        cout << "Fullname:" ; cin >> pa[i].fullname;
        if (pa[i].fullname == " " || pa[i].fullname == "  ")//暂时写到两个空格吧
            return i;
        cout << "Hobby:" ; cin >> pa[i].hobby;
        cout << "Ooplevel:" ; cin >> pa[i].ooplevel;
    }
    return n;
}
void display1(student st){
    cout << "Fullname:" << st.fullname << endl
         << "Hobby:" << st.hobby << endl
         << "Ooplevel:" << st.ooplevel <<endl;
}
void display2(const student * ps){
    cout << "Fullname:" << ps->fullname << endl
         << "Hobby:" << ps->hobby << endl
         << "Ooplevel:" << ps->ooplevel <<endl;
}
void display3(const student pa[], int n){
    for(int i = 0; i < n; ++i){
        cout << "Fullname:" << pa[i].fullname << endl
             << "Hobby:" << pa[i].hobby << endl
             << "Ooplevel:" << pa[i].ooplevel <<endl;
    }
}
*/
/*7_9
typedef double (*pf)(double , double );
double add(double x, double y);
double minusx(double x, double y);
double calculate(double x,double y,pf);
int main(){
    double x , y ;
    pf p_arr[2]={ add , minusx };
    cout << "Please enter two float numbers:";
    while (cin >> x >> y) {
        double result;
        for (int i = 0; i < 2; ++i) {
            result = calculate( x, y, p_arr[i]);
            cout << "Result #" << i + 1 << ": " << result << endl;
        }cout << "Enter 2 float numbers again: " << endl;
    }
}
double add(double x, double y){
    return x + y;
}
double minusx(double x, double y){
    return x - y;
}
double calculate(double x, double y, pf p){
    return (*p)(x,y);
}
*/