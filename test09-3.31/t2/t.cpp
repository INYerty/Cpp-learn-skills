#include<iostream>
using namespace std; 

#include <cstring>
class Student{
public:
    Student(char*,int);
    ~Student();
protected:
    char *pname;   //名字用堆存储，pname只存储名字首址
    int age;
};

Student::Student(char* name,int sage){
    pname = new char[strlen(name)+1];
    strcpy(pname,name);
    age=sage;
}

Student::~Student(){
    delete[] pname;
}



int main()

{

    Student s("lisi",18);    

    return 0;

}