#include <iostream>
#include <cstring>
using namespace std;

class Tyear {
private:
    int* year;
public:
    Tyear(int y = 2000) {
        year = new int(y);
    }

    Tyear(const Tyear& other) {
        year = new int(*(other.year));
    }

    Tyear& operator=(const Tyear& other) {
        if (this != &other) {
            delete year;
            year = new int(*(other.year));
        }
        return *this;
    }

    ~Tyear() {
        delete year;
    }

    void Out() const {
        cout << *year;
    }
};

class Student {
private:
    char name[20];
    Tyear birth;
    static int count;
public:
    Student(const char* n = "noname", int y = 2004) : birth(y) {
        strncpy(name, n, 19);
        name[19] = '\0'; // 防止越界
        count++;
    }

    Student(const Student& other) : birth(other.birth) {
        strncpy(name, other.name, 19);
        name[19] = '\0';
        count++;
    }

    ~Student() {
        count--;
    }

    void Out() const {
        cout << name << ",";
        birth.Out();
        cout << endl;
    }

    static int GetCount() {
        return count;
    }
};

int Student::count = 0;

void DispStuNum() {
    cout << Student::GetCount() << endl;
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
    cin >> name >> year;
    Student s2(name, year);
    s2.Out();
    cin >> name;
    Student s3(name), s4(s1);
    s3.Out();
    s4.Out();
    DispStuNum();
    Sub(s2);
    DispStuNum();
    return 0;
}
