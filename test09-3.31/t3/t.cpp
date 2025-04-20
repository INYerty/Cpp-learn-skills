#include <iostream>
using namespace std;


class Student{
    public:

    Student(int n,int s):id(n),score(s){
        cout<<"Construct a student"<<endl;
    }

    ~Student(){
        cout<<"Destructing student..."<<endl;
    }

    void Disp(){
        cout<<id<<" "<<score<<endl;
    }

    protected:
    int id;
    int score;

};

class Teacher{
    public:
    Teacher(char* name,int age):tname(name),tage(age){
        cout<<"Construct a teacher"<<endl;
    }

    ~Teacher(){
        cout<<"Destructing teacher..."<<endl;
    }
    void Disp(){
        cout<<tname<<" "<<tage<<" ";
    }


    protected:
    char* tname;
    int tage;
};

class Pair{
    public:
    Pair(char* pname,int page,int pn,int ps):t(pname,page),s(pn,ps){
        cout<<"Construct a pair"<<endl;
    }
    ~Pair(){
        cout<<"Destructing pair..."<<endl;
    }
    void Disp(){
        t.Disp();
        s.Disp();
    }

    protected:
    Teacher t;
    Student s;
};


int main()
{
    int n, s, age;
    char name[10];
    cin>>name>>age>>n>>s;
    Pair p(name, age, n ,s);
    p.Disp();   //显示派对的信息
    return 0;
}