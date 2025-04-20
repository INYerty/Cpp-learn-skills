#include <iostream>
#include <string.h>
using namespace std;
class Student;
class Teacher
{
public:
    Teacher(char* tname)
    {
        strcpy(name,tname);
    }
    void AssignScore(Student &s,int score2);

protected:
    char name[10];
};

class Student
{

public:

friend class Teacher;
    Student(char* sname,int score1)
    {
        strcpy(name,sname);
        score=score1;
    }
    void Disp(){
        cout<<name<<","<<score<<endl;
    }

protected:
    char name[10];
    int score;
};


void Teacher::AssignScore(Student &s,int score2){
    s.score=score2;
}

int main()

{
int n;
Teacher t("Wang");
Student s("Li",59);
s.Disp();
cin>>n;
 //添加代码，修改学生成绩为n
t.AssignScore(s,n);
s.Disp();
return 0;
}