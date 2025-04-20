#include <iostream>
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
    int getyear()
    {
        return year;
    }
    int getmonth()
    {
        return month;
    }
    int getday()
    {
        return day;
    }

protected:
    int year;
    int month;
    int day;
};

class Student
{
public:
    Student(int n1, int y, int m, int d1) : date(y, m, d1)
    {
        cout << "construct Student" << endl;
        n = n1;
    }
    ~Student()
    {
        cout << "destruct Student" << endl;
    }
    void Disp()
    {
        cout << n << "," << date.getyear() << "/" 
             << date.getmonth() << "/" << date.getday() << endl;
    }

protected:
    int n;
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