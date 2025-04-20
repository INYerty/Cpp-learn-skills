
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

void Student::input(){
    cin>>score>>name;
}

void Student::output(){
    cout<<"Name:"<<name<<" Score:"<<score<<endl;
}
