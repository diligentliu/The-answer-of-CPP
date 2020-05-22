#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;
/*5_1
int main(){
    int min,max,count=0;
    cin>>min>>max;
    for (int i = min; i <= max; ++i) {
        count=count+i;
    }
    cout<<count;
    return 0;
}
*/
/*5_2
int main(){
    int a,count=0;
    cin>>a;
    while (a){
        count=count+a;
        cout<<count<<endl;
        cin>>a;
    }
}
*/
/*5_3
int main(){
    float valueD=100.0f,valueC=100.0f;
    int i;
    for (i = 1; valueC <= valueD; ++i) {
        valueD=100.0+10.0*i;
        valueC=valueC*1.05;
    }
    cout<<"Years: "<<i-1<<endl;
    cout<<"Daphne: "<<valueD<<endl;
    cout<<"Cleo: "<<valueC<<endl;
    return 0;
}
*/
/*5_4
int main(){
    int i;
    int *sales=new int [13];
    sales[0]=0;
    const char *months[12]={"January","February","March","April","May","June",
           "July","August","September","October","November","December"};
    //or
    //const string months[12]={"January","February","March","April","May","June",
    //                            "July","August","September","October","November","December"};
    for (int i = 0; i < 12; ++i) {
        cout<<"The sales of "<<months[i]<<" is $:";
        cin>>sales[i+1];
    }
    for (int j = 1; j < 13; ++j) {
        sales[0]=sales[0]+sales[j];
    }cout<<"The total of sales is $"<<sales[0]<<endl;
    delete [] sales;
    return 0;
}
*/
/*5_5
int main(){
    int sales[3][13]={0};
    int total_sales;
    const char *months[12]={"January","February","March","April","May","June",
                            "July","August","September","October","November","December"};
    //or
    //const string months[12]={"January","February","March","April","May","June",
    //                            "July","August","September","October","November","December"};
    for (int t = 0; t < 3; ++t) {
        for (int i = 1; i < 13; ++i) {
            cout<<"The year NO."<<t+1<<". The sales of "<<months[i-1]<<" is $";
            cin>>sales[t][i];
        }
    }
    for (int j = 0; j < 3; ++j) {
        for (int k = 1; k < 13; ++k) {
            sales[j][0]=sales[j][0]+sales[j][k];
        }
    }
    for (int j = 0; j < 3; ++j) {
        total_sales=total_sales+sales[j][0];
    }
    for (int i = 0; i < 3; ++i) {
        cout<<"The sales of the NO."<<i+1<<" is $"<<sales[i][0]<<endl;
    }
    cout<<"The total of sales is $"<<total_sales<<endl;
    return 0;
}
*/
/*5_6
struct car{
    string manufacturer;
    int production_Year;
};
int main(){
    int count;
    cout<<"How many cars do you wish to catalog?";
    (cin>>count).get();
    car *cars=new car[count];
    for (int i = 1; i <= count; ++i) {
        cout<<"Car #"<<i<<":"<<endl;
        cout<<"Please enter the make:";
        getline(cin,cars[i-1].manufacturer);
        cout<<"Please enter the year made:";
        (cin>>cars[i-1].production_Year).get();
    }cout<<"Here is your collection:"<<endl;
    for (int j = 0; j < count; ++j) {
        cout<<cars[j].production_Year<<"  "<<cars[j].manufacturer<<endl;
    }
    delete [] cars;
    return 0;
}
*/
/*5_7
int main(){
    const int MAXSIZE=20;
    char word[MAXSIZE];
    int i=0;
    cout<<"Enter words (to stop, type the word done):";
    cin>>word;
    while (strcmp(word,"done")){
        ++i;
        cin>>word;
    }
    cout<<"You entered a total of "<<i<<" words.";
}
*/
/*5_8
int main(){
    string word;
    int sum=0;
    cout<<"Enter words (to stop, type the word done):";
    cin>>word;
    while (word!="done"){
        sum++;
        cin>>word;
    }
    cout<<"You entered a total of "<<sum<<" words.";
}
*/
/*5_9
int main(){
    int N;
    cout<<"Enter number of rows:";
    cin>>N;
    for (int j=1; j <= N; ++j) {
        for (int i = 0; i < N-j; ++i) {
            cout << ".";
        }
        for (int i = 1; i <= j; ++i) {
            cout << "*";
        }
        cout<<endl;
    }
}
*/