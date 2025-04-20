#include <iostream>
#include <string.h>

using namespace std;

class Student
{
public:
    Student()
    {
        pname = new char[strlen("None") + 1];
        score = 0;
        strcpy(pname, "None");
        cout << "construct " << pname << endl;
    }
    Student(char *name1, int score1)
    {
        pname = new char[strlen(name1) + 1];
        strcpy(pname, name1);
        score = score1;
        cout << "construct " << pname << endl;
    }
    Student(Student &s2)
    {
        pname = new char[strlen(s2.pname) + 1];
        strcpy(pname, s2.pname);
        score = s2.score;
        cout << "copy " << pname << endl;
    }
    ~Student()
    {
        cout << "destruct " << pname << endl;
        delete[] pname;
    }

    void Disp()
    {
        cout << pname << " " << score << endl;
    }

private:
    char *pname;
    int score;
};

int main()
{
    char name[20];
    int score;
    cin >> name >> score;
    Student s1, s2(name, score), s3(s2);
    s1.Disp();
    s2.Disp();
    s3.Disp();
    Student s4 = s3;
    s4.Disp();
    return 0;
}
