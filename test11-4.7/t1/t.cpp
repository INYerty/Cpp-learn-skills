#include <iostream>
#include <string.h>
using namespace std;

class Student
{
public:
    Student()
    {
        score = 0;
        name = new char[strlen("") + 1];
        strcpy(name, "");
        num++;
    }
    Student(char *sname)
    {
        score = 0;
        name = new char[strlen(sname) + 1];
        strcpy(name, sname);
        num++;
    }
    Student(int score1)
    {
        score = score1;
        name = new char[strlen("") + 1];
        strcpy(name, "");
        num++;
    }
    Student(char *sname, int score1)
    {
        name = new char[strlen(sname) + 1];
        strcpy(name, sname);
        score = score1;
        num++;
    }

    Student(Student &s2)
    {
        name = new char[strlen(s2.name) + 1];
        strcpy(name, s2.name);
        score = s2.score;
        num++;
    }

    ~Student()
    {
        delete[] name;
        num--;
    }

    static int getNum()
    {
        return num;
    }
    void Out()
    {
        cout << "name:" << name << "," << "score:" << score << endl;
    }

private:
    char *name;
    int score;
    static int num;
};

int Student::num = 0;
void f()

{

    Student s1, s2;
    cout << s2.getNum() << endl;
}

int main()

{

    cout << Student::getNum() << endl;

    Student s1;
    char name[10];
    int s;
    cin >> name >> s; // 输入s2的姓名和分数
    Student s2(name, s);
    cin >> name; // 输入s3的姓名
    Student s3(name);
    cout << Student::getNum() << endl;
    s1.Out();
    s2.Out();
    s3.Out();
    // 填写代码显示此时学生的人数，并显示三个人的数据
    Student s4 = s2;
    cout << s4.getNum() << endl;
    // 填写代码显示此时学生的人数 （用另一种方法）
    f();
    cout << Student::getNum() << endl;
    // 填写代码显示此时学生的人数
    return 0;
}