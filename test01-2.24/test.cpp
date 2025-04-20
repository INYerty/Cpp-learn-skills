#include <iostream>
#include <string>
using namespace std;

struct student {
    string id;
    int age;
    int year;
    int month;
    int day;
    int score;
} stu[3];

int main() {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        cin >> stu[i].id
        >> stu[i].age
        >> stu[i].year
        >> stu[i].month
        >> stu[i].day
        >> stu[i].score;
        sum += stu[i].score;
    }
    int aver = sum / 3;
    for (int i = 0; i < 3; i++) {
        cout << "Num:"
        << stu[i].id
         << ",Age:"
         << stu[i].age
         << ",Birthday:"
         << stu[i].year
         << "/"
         << stu[i].month
         << "/"
         << stu[i].day
         << ",Score:"
         << stu[i].score
         << endl;
    }
    cout << "Aver:" << aver << endl;
    return 0;
}