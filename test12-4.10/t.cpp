#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
    Person(char *name,int age){
        pname = new char[strlen(name)+1];
        strcpy(pname,name);
        page=age;
    }
    ~Person(){
        delete[] pname;
    }
    protected:
    char *pname;
    int page;
};

class Date{
    public:
    Date(int y,int m,int d){
        year = y;
        month = m;
        day = d;
    }
    Date(){

    }
    int gety(){
        return year;
    }
    int getm(){
        return month;
    }
    int getd(){
        return day;
    }
    ~Date(){

    }
    protected:
    int year;
    int month;
    int day;
};

class Student:public Person{
    public:
    Student(char* sname,int sage,int year,int month,int day,int sgrade):Person(sname,sage),date(year,month,day){
        grade=sgrade;
    }
    ~Student(){

    }

    void change(int newscore){
        grade = newscore;
        cout<<"name:"<<pname<<" "<<"age:"<<page<<endl;
        cout<<"birthday:"<<date.gety()<<"/"<<date.getm()<<"/"<<date.getd()<<endl;
        cout<<"score:"<<grade<<endl;
    }

    void Disp(){
        cout<<"name:"<<pname<<" "<<"age:"<<page<<endl;
        cout<<"birthday:"<<date.gety()<<"/"<<date.getm()<<"/"<<date.getd()<<endl;
        cout<<"score:"<<grade<<endl;
    }
    protected:
    Date date;
    int grade;
};

class Teacher:public Person{
    public:
    Teacher(char *tname,int tage,char* title,int tyear,int tmonth,int tday):Person(tname,tage),date(tyear,tmonth,tday){
        workname = new char[strlen(title)+1];
        strcpy(workname,title);
    }
    ~Teacher(){
        delete [] workname;
    }

    void setnew(Student &s,int newg){
        s.change(newg);
    }

    void Disp(){
        cout<<"name:"<<pname<<" "<<"age:"<<page<<endl;
        cout<<"title:"<<workname<<endl;
        
        
    }
    protected:
    Date date;
    char *workname;
};

int main(){
    char sn[100];
    char tn[100];
    char title[100];
    int sa,ta,year,month,day,grade,newgrade;
    cin>>sn>>sa>>year>>month>>day>>grade;
    cin>>tn>>ta>>title>>newgrade;
    Student s(sn,sa,year,month,day,grade);
    Teacher t(tn,ta,title,year,month,day);
    s.Disp();
    t.Disp();
    t.setnew(s,newgrade);
    return 0;
}