#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
    Person(char* name1){
        name = new char[strlen(name1)+1];
        strcpy(name,name1);
    }
    Person(){
        
    }
    ~Person(){
        delete[] name;
    }
    void Disp(){
        cout<<name<<endl;
    }

    protected:
    char* name;

};

class Student:virtual public Person{
    public:
    Student(){

    }
    char* getName(){
        return name;
    }
    Student(char* sname,int age):Person(sname){
        sage = age;
    }
    ~Student(){

    }
    void Study(){
        cout<<"I'm studying"<<endl;
    }
    void Disp(){
        cout<<Person::name<<endl;
        cout<<sage<<endl;
    }

    protected:
    int sage;
};

class Teacher:virtual public Person{
    public:
    Teacher(){

    }
    Teacher(char* tname,char* title):Person(tname){
        
        tjob = new char[strlen(title)+1];
        strcpy(tjob,title);
    }
    ~Teacher(){
        delete[] tjob;
    }
    void Teach(){
        cout<<"I'm teaching"<<endl;
    }
    void Disp(){
        cout<<Person::name<<endl;
        cout<<tjob<<endl;
    }

    protected:
    char* tjob;
};

class Stu_teacher:public Student,public Teacher{
    public:
    Stu_teacher(char* stname1,int stage1):Student(stname1,stage1),Teacher(stname1,(char*)"jxzj"){
        
    }
    ~Stu_teacher(){
        
    }
    void Disp(){
        cout<<Person::name<<endl;
        cout<<Student::sage<<endl;
        cout<<tjob<<endl;
    }
};



int main()
{
    char name[15], title[20];
    int age;
    cin >> name >> age >> title;
    Person p(name);
    p.Disp();
    Student s(name, age);
    s.Disp();
    s.Study();
    Teacher t(name, title);
    t.Disp();
    t.Teach();
    Stu_teacher st(name, age);
    st.Disp();
    st.Study();
    st.Teach();
    return 0;
}