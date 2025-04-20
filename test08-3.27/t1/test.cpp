#include <iostream>
#include <cstring>
using namespace std;

class Student{
    private:
    char* pname;
    int score;
    public:
    void Disp()
    {
        cout<<pname<<" "<<score<<endl;
    }
    Student()
    {
        pname = new char[20];
        strcpy(pname,"None");
        score = 0;
        cout<<"construct None"<<endl;
    }

    Student(char* name, int score)
    {
        pname = new char[20];
        strcpy(pname, name);
        this->score = score;
        cout<<"construct "<<pname<<endl;
    }
    ~Student()
    {
        cout<<"destruct "<<pname<<endl;
        delete[] pname;
    }
    Student(Student& s3):score(s3.score)
    {
        pname = new char[20];
        strcpy(pname, s3.pname);
        cout<<"copy "<<pname<<endl;
    }
};




int main()
{
    char name[20];
    int  score;
    cin>>name>>score;
    Student s1, s2(name,score), s3(s2);
    s1.Disp();
    s2.Disp();
    s3.Disp();
    Student s4=s3;
    s4.Disp();
    return 0;
}