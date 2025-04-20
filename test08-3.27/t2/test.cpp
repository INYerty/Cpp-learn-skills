#include <iostream>
#include <cstring>
using namespace std;

class Name{
public:
    char* pname;
};

class Student
{
private:
    int n;
        
public:
    Student(int , char *);
    Student(Student &s);
    Name name;
    void Disp()
    {
        cout<<"Num:"<<n<<endl;
        cout<<"Name:"<<name.pname<<endl;
    }

};
Student::Student(int num, char *sname)
{  
    n=num;
    name.pname=new char[strlen(sname)+1];
    strcpy(name.pname, sname);
}
Student::Student(Student &s):n(s.n)
{
    name.pname=new char[strlen(s.name.pname)+1];
    strcpy(name.pname, s.name.pname);
}

void fn(Student x)
{
    x.Disp();
}
int main()
{
    int n;
    char name[10];
    cin>>n>>name; 
    Student s(n,name); 
    fn(s);
    return 0;
}