#include <iostream>
#include <cstring>
using namespace std;

class Student{
    public:
    Student(){
        pnum = new char[strlen("None") + 1];
        strcpy(pnum, "None");
        pname = new char[strlen("None") + 1];
        strcpy(pname, "None");
        score = 0;
        cout << "construct:" << pname << endl;
        
    }
    Student(char* num, char* name, int sc){
        pnum = new char[strlen(num) + 1];
        strcpy(pnum, num);
        pname = new char[strlen(name) + 1];
        strcpy(pname, name);
        score = sc;
        cout << "construct:" << pname << endl;
        
    }


    Student(char* num1, char* name1){
        pnum = new char[strlen(num1) + 1];
        strcpy(pnum, num1);
        pname = new char[strlen(name1) + 1];
        strcpy(pname, name1);
        score = 0;
        cout << "construct:" << pname << endl;
        
    }
    void Disp(){
        cout << "学号:" << pnum << "姓名:" << pname << "分数:" << score << endl;
    }


    Student(const Student& s2){
        pnum = new char[strlen(s2.pnum) + 1];
        strcpy(pnum, s2.pnum);
        pname = new char[strlen(s2.pname) + 1];
        strcpy(pname, s2.pname);
        score = s2.score;
        cout << "copy:" << pname << endl;
        
    }

    ~Student(){
        cout << "distruct:" << pname << endl;
        delete[] pnum;
        delete[] pname;
    }

    protected:
    char* pnum;
    char* pname;
    int score;
};

int  main()    

{
     int score;
     char num1[10],num2[10],name1[10],name2[10];
     cin>>num1>>name1>>score;
     cin>>num2>>name2;
     Student s1,s2(num1,name1,score),s3(num2,name2);    
      s1.Disp();
      s2.Disp();
      s3.Disp();
      Student s4=s2;    
      Student s5(s3);    
      s4.Disp();
      s5.Disp();
       return 0;
}
