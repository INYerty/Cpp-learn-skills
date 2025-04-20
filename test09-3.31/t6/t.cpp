#include<iostream>
#include <string.h>
using namespace std;


class Name{
    public:
    Name(char* name){
        pname = new char[strlen(name)+1];
        strcpy(pname,name);

    }
    ~Name(){
        delete[] pname;
    }

    char* getname(){
        return pname;
    }

    protected:
    char* pname;
};

class Student{
    public:

    Student(int n1, char* name2):n(n1),name(name2){
        
    }
    ~Student(){

    }
    Student(Student &s):n(s.n),name(s.name){

    }
    void Disp(){
        cout<<"Num:"<<n<<endl;
        cout<<"Name:"<<name.getname()<<endl;
    }


    
    protected:
    int n;
    Name name;

};



void fn(Student x)
{
    x.Disp();
}
int main()
{
    int n;//xuehao
    char name[10];
    cin >> n >> name;
    Student s(n, name);
    fn(s);
    return 0;
}