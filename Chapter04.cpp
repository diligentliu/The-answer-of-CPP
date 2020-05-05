#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*4_1
int main() {
    string first_name,last_name;
    char grade;
    int age;
    cout<<"What is your first name? ";
    getline(cin,first_name);
    cout<<"What is your last name? ";
    getline(cin,last_name);
    cout<<"What letter grade do you deserve? ";
    cin>>grade;
    grade++;
    cout<<"What is your age? ";
    cin>>age;
    cout<<"Name: "<<last_name<<", "<<first_name<<endl;
    cout<<"Grade: "<<grade<<endl<<"Age: "<<age<<endl;
    return 0;
}
*/
/*4_2
int main(){
    string name,dessert;
    cout<<"Enter your name: \n";
    getline(cin,name);
    cout<<"Enter your favorite dessert: \n";
    getline(cin,dessert);
    cout<<"I have some delicious "<<dessert<<" for you, "<<name<<".\n";
    return 0;
}
*/
/*4_3
int main(){
    char *first_name=new char[10];
    char *last_name=new char[10];
    char *name=new char[20];
    cout<<"Enter your first name:";
    cin.getline(first_name,10);
    cout<<"Enter your last name:";
    cin.getline(last_name,10);
    name=last_name;
    strcat(name,", ");
    strcat(name,first_name);
    cout<<"Here's the information in a single string: "<<name;
    delete [] first_name;
    delete [] last_name;
    delete [] name;
    return 0;
}
*/
/*4_4
int main(){
    string first_name,last_name,name;
    cout<<"Enter your first name:";
    getline(cin,first_name);
    cout<<"Enter your last name:";
    getline(cin,last_name);
    name=last_name+", "+first_name;
    cout<<"Here's the information in a single string: "<<name;
    return 0;
}
*/
/*4_5
struct CandyBar{
    string brand;
    float height;
    int calories;
};
int main(){
    CandyBar snack={"Mocha Munch",2.3f,350};
    cout<<"Brand: "<<snack.brand<<endl;
    cout<<"Height: "<<snack.height<<endl;
    cout<<"Calories: "<<snack.calories<<endl;
}
*/
/*4_6
struct CandyBar{
    string brand;
    float height;
    int calories;
};
int main(){
    CandyBar *snack=new CandyBar[3];
    *snack={"Mocha Munch",2.3,350};
    *(snack+1)={"Mocha munch",2.4,360};
    *(snack+2)={"mocha munch",2.5,370};
    cout<<"NO.1"<<endl;
    cout<<"Brand: "<<(*snack).brand<<endl;
    cout<<"Height: "<<(*snack).height<<endl;
    cout<<"Calories: "<<(*snack).calories<<endl;
    cout<<"NO.2"<<endl;
    cout<<"Brand: "<<(*(snack+1)).brand<<endl;
    cout<<"Height: "<<(*(snack+1)).height<<endl;
    cout<<"Calories: "<<(*(snack+1)).calories<<endl;
    cout<<"NO.3"<<endl;
    cout<<"Brand: "<<(*(snack+2)).brand<<endl;
    cout<<"Height: "<<(*(snack+2)).height<<endl;
    cout<<"Calories: "<<(*(snack+2)).calories<<endl;
}
*/
/*4_7
struct pizza{
    string company_name;
    float diameter;
    float height;
};
int main(){
    pizza pa;
    cout<<"Please input the name of the pizza company:";
    getline(cin,pa.company_name);
    cout<<"Please input the diameter of the pizza:";
    cin>>pa.diameter;
    cout<<"Please input the height of the pizza:";
    cin>>pa.height;
    cout<<endl;
    cout<<"Pizza company: "<<pa.company_name<<endl;
    cout<<"Pizza diameter: "<<pa.diameter<<endl;
    cout<<"Pizza height: "<<pa.height<<endl;
}
*/
/*4_8
struct pizza{
    string company_name;
    float diameter;
    float height;
};
int main(){
    pizza pa;
    cout<<"Please input the diameter of the pizza:";
    cin>>pa.diameter;
    cout<<"Please input the name of the pizza company:";
    getline(cin,pa.company_name);
    cout<<"Please input the height of the pizza:";
    cin>>pa.height;
    cout<<endl;
    cout<<"Pizza company: "<<pa.company_name<<endl;
    cout<<"Pizza diameter: "<<pa.diameter<<endl;
    cout<<"Pizza height: "<<pa.height<<endl;
}
*/
/*4_9
struct CandyBar{
    string brand;
    float height;
    int calories;
};
int main(){
    CandyBar *snack=new CandyBar[3];
    *snack={"Mocha Munch",2.3,350};
    *(snack+1)={"Mocha munch",2.4,360};
    *(snack+2)={"mocha munch",2.5,370};
    cout<<"NO.1"<<endl;
    cout<<"Brand: "<<(*snack).brand<<endl;
    cout<<"Height: "<<(*snack).height<<endl;
    cout<<"Calories: "<<(*snack).calories<<endl;
    cout<<"NO.2"<<endl;
    cout<<"Brand: "<<(*(snack+1)).brand<<endl;
    cout<<"Height: "<<(*(snack+1)).height<<endl;
    cout<<"Calories: "<<(*(snack+1)).calories<<endl;
    cout<<"NO.3"<<endl;
    cout<<"Brand: "<<(*(snack+2)).brand<<endl;
    cout<<"Height: "<<(*(snack+2)).height<<endl;
    cout<<"Calories: "<<(*(snack+2)).calories<<endl;
}
*/