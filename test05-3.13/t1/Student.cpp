#include <iostream>
#include <cstring>
using namespace std;
class Student{
    public:
        void Set(char*, int);  //用来设置学号和分数
        void Edit(int);    //用来修改成绩，参数为新成绩
        void Out();         //用来输出学号和分数
    protected:
        char  num[10];
        int  score;
    };

int main()
{
    void Set(char *, int); // 用来设置学号和分数
    void Edit(int);        // 用来修改成绩，参数为新成绩
    void Out();
    void fn(Student & s, int newscore);

    Student s;
    char n[10];
    int score, newscore;
    cin >> n >> score;
    s.Set(n, score);
    s.Out();
    cin >> newscore;
    s.Edit(newscore);
    fn(s, newscore);
    s.Out();
    return 0;
}

void Student::Set(char *n,int s)
{
    score = s;
    strcpy(num,n);
}
void Student::Edit(int newscore)
{
    score = newscore;
}

void Student::Out()
{
    cout<<num<<" "<<score<<endl;
}
void fn(Student &s,int newscore)//引用
{
    s.Edit(newscore);
}


/*
请编写fn函数和类的各成员函数，并在主函数每个下划线上填上一个语句
要求：所有成员函数都在类外定义，fn函数用合适的参数传递方式以便节省内存
Input
输入学号、分数，然后再输入一个新分数
Output
输出学号和分数，在fn中修改数据后，再输出一次


Sample Input
09010101 80
90
Sample Output
09010101 80
09010101 90
Code 1 here:*/