#include <iostream>
#include <string.h>
using namespace std;

class Tyear{

    public: 
        Tyear();
        Tyear(int);
        int getYear();
        ~Tyear();
    
    private:
    
        int *pyear;         
    
    };
    
class Student{
    
    public:
    
        Student();
        Student(char* sname);
        Student(char* sname,int year);
        Student(Student& s);
        ~Student();
        void Out();
        static int getCount();
    private:
    
        char name[20];
    
        Tyear year;
    
        static int count;
    
    };

    int Student::count = 0;

    Tyear::Tyear(int year){
        pyear = new int (year);
    }
    Tyear::Tyear(){
        pyear = new int(2000);
    }
    Tyear::~Tyear(){
        delete pyear;//DELETE(pyear);
    }
    int Tyear::getYear(){
        return *pyear;
    }

    Student::Student():year(2004){
        strcpy(name,"noname");
        count++;
    }

    Student::Student(char* sname,int year):year(year){
        strcpy(name,sname);
        count++;
    }

    Student::Student(char* sname):year(2004){
        strcpy(name,sname);
        count++;
        
    }
    Student::Student(Student&s):year(s.year.getYear()){
        strcpy(name,s.name);
        count++;

    }
    Student::~Student(){
        count--;
    }

    void Student::Out(){
        cout<<name<<","<<year.getYear()<<endl;
    }
    int Student::getCount(){
        return count;
    }
    void DispStuNum()
    {
        cout<<Student::getCount()<<endl;      //横线处缺代码
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