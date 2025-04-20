#include <iostream>
using namespace std;
#include <cstring>

class Student
{
public:
    Student(const char *name, int age1); // 构造函数声明
    ~Student();                    // 析构函数声明

protected:
    char *pname; // 名字用堆存储，pname只存储名字首址
    int age;
};

Student::Student(const char *name, int age1)
{
    pname = new char[strlen(name) + 1];
    strcpy(pname, name);
    age = age1;
}

Student::~Student()
{
    delete[] pname;
}

int main()
{
    Student s("lisi", 18);
    return 0;
}
