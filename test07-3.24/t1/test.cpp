#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    int score;
public:
    Student(int n, int s) : id(n), score(s) {
        cout << "Construct a student" << endl;
    }
    ~Student() {
        cout << "Destructing student..." << endl;
    }
    void Disp() {
        cout << id << " " << score;
    }
};

class Teacher {
    private:
        char* Name1;
        int Age;
    public:
        Teacher(char* name, int age) : Age(age) {
            Name1 = new char[strlen(name) + 1];
            strcpy(Name1, name);
            cout << "Construct a teacher" << endl;
        }
        ~Teacher() {
            delete[] Name1;
            cout << "Destructing teacher..." << endl;
        }
        void Disp() {
            cout << Name1 << " " << Age;
        }
    };
    
class Pair {
private:
    Teacher t;
    Student s;
public:
    Pair(char* name, int age, int n, int s) : t(name, age), s(n, s) {
        cout << "Construct a pair" << endl;
    }
    
    ~Pair(){
        cout << "Destructing pair..." << endl;
    }
    void Disp() {
        t.Disp();
        cout << " ";
        s.Disp();
        cout << endl;
    }
};

int main() {
    int n, s, age;
    char name[10];
    cin >> name >> age >> n >> s;
    Pair p(name, age, n, s);
    p.Disp();
    return 0;
}
