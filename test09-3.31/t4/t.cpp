#include<iostream>
using namespace std;



class Tdate{
    public:
    Tdate(int y,int m,int d){
        year = y;
        month = m;
        day = d;
        cout<<"construct  Tdate"<<endl;
    }
    ~Tdate(){
        cout<<"distruct Tdate"<<endl;
    };
    int gety(){
        return year;
    }
    int getm(){
        return month;
    }
    int getd(){
        return day;
    }

    protected:
    int year;
    int month;
    int day;
};

class Student{
    public:
    Student(int n,int y,int m,int d):id(n),birth(y,m,d){
        cout<<"construct  Student"<<endl;
    }

    ~Student(){
        cout<<"distruct  Student"<<endl;
    }

    void Disp(){
        cout<<id<<","<<birth.gety()<<"/"<<birth.getm()<<"/"<<birth.getd()<<endl;
    }

    protected:
    int id;
    Tdate birth;

};


int main()
{
      int  n,  y,  m,  d;
      cin>>n>>y>>m>>d;
      Student  s(n, y, m ,d);
      s.Disp();
      return 0;
}