class Tyear
{
public:
    
    Tyear(int year);
    Tyear();
    Tyear(Tyear &y);
    ~Tyear();
    void Out();
private:

    int *pyear;

};

class Student
{
public:
    
    Student(char *,int);
    Student(int);
    Student(char *);
    Student();
    Student(Student &);
    ~Student();
    void Out();
    static int getNum();
    /*********************************/

    //此处声明成员函数，只声明，不定义

    /*********************************/

private:

    char name[20];

    Tyear year;

    static int num;
    /*********************************/

    //若需要其他数据成员，在此添加

    /*********************************/
};
/******************************************/

#include <bits/stdc++.h>
using namespace std;
int Student::getNum(){
    return num;
}
Tyear::Tyear(int year)
{
    pyear = new int(year);
}
Tyear::Tyear()
{
    pyear = new int(2000);
}
Tyear::Tyear(Tyear &y)
{
    pyear = new int(*y.pyear);
}
Tyear::~Tyear()
{
    delete pyear;
}
void Tyear::Out()
{
    cout<<*pyear;
}
int Student::num=0;

Student::Student(char *na,int yea):year(yea)
{
    strcpy(name,na);
    num++;
}
Student::Student(int yea):year(yea)
{
    strcpy(name,"noname");
    num++;
}
Student::Student(char *na):year(2004)
{
    strcpy(name,na);
    num++;
}
Student::Student():year(2004)
{
    strcpy(name,"noname");
    num++;
}
Student::Student(Student &s):year(s.year)
{
    strcpy(name,s.name);
    num++;
}
Student::~Student()
{
    num--;
}
void Student::Out()
{
    cout<<name<<",";
    year.Out();
    cout<<endl;
}
/******************************************/
void DispStuNum()
{
    cout<<Student::getNum()<<endl;      //横线处缺代码
}

void Sub(Student s)
{
    s.Out();
    DispStuNum();
}

int main()
{

    int year;
    char name[20];
    DispStuNum();
    Student s1;
    s1.Out();
    cin>>name>>year;
    Student s2(name,year);
    s2.Out();
    cin>>name;
    Student s3(name),s4(s1);
    s3.Out();
    s4.Out();
    DispStuNum();
    Sub(s2);
    DispStuNum();
    return 0;

}
