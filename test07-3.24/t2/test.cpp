#include <iostream>
#include "cstring"
using namespace std;

class Tdate
{
public:
    Tdate(int y, int m, int d) : year(y), month(m), day(d)
    {
        cout << "construct Tdate" << endl;
    }
    ~Tdate()
    {
        cout << "distruct Tdate" << endl;
    }
    void DSPDate()
    {
        cout << year << "/" << month << "/" << day;
    }

protected:
    int year;
    int month;
    int day;
};

class Student
{
public:
    Student(int n, int y, int m, int d) : n(n), date(y, m, d) 
    {
        cout << "construct Student" << endl;
    }
    ~Student()
    {
        cout << "destruct Student" << endl;
    }
    void Disp()
    {
        cout << n << ","; 
        date.DSPDate();
        cout << endl;
    }

protected:
    int n;  // 修正了这里
    Tdate date;
};

int main()
{
    int n, y, m, d;
    cin >> n >> y >> m >> d;
    Student s(n, y, m, d);
    s.Disp();
    return 0;
}

/*#include <iostream>
using namespace std;

class Tdate {
private:
    int year;
    int month;
    int day;
public:
    Tdate(int y, int m, int d) : year(y), month(m), day(d) {
        cout << "construct Tdate" << endl;
    }
    ~Tdate() {
        cout << "distruct Tdate" << endl;
    }
    void printDate() {
        cout << year << "/" << month << "/" << day;
    }
};

class Student {
private:
    int n1;
    Tdate date;
public:
    Student(int n, int y, int m, int d) : n1(n), date(y, m, d) {
        cout << "construct Student" << endl;
    }
    ~Student() {
        cout << "distruct Student" << endl;
    }
    void Disp() {
        cout << n1 << ",";
        date.printDate();
        cout << endl;
    }
};*/