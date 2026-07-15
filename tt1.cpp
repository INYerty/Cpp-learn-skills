//**************************期末复习汇总*******************************


//t0      5539    26、静态成员的应用
/*
#include <iostream>
#include <string.h>
using namespace std;

class Student{    
    public:      
    Student():score(0){
        pname = new char[strlen("\0")+1];
        strcpy(pname,"\0");
        num++;
    }

    Student(char* sname):score(0){
        pname = new char[strlen(sname)+1];
        strcpy(pname,sname);
        num++;
    }

    Student(int sscore){
        pname = new char[strlen("\0")+1];
        strcpy(pname,"\0");
        score = sscore;
        num++;
    }

    Student(char* sname,int sscore){
        pname = new char[strlen(sname)+1];
        strcpy(pname,sname);
        score = sscore;
        num++;
    }

    Student(Student& s){
        pname = new char[strlen(s.pname)+1];
        strcpy(pname,s.pname);
        score = s.score;
        num++;
    }

    ~Student(){
        delete[] pname;
        num--;
    }

    static int getNum(){
        return num;
    }

    void Disp(){
        cout<<"name:"<<pname<<",score:"<<score<<endl;
    }

    protected:      
    char* pname;
    int score;
    static int num;
};

int Student::num=0;

void f()    
{
    Student s1,s2;    
    cout<<s2.getNum()<<endl;  
}     

int main()      
{
    //填写代码显示此时学生的人数         
    cout<<Student::getNum()<<endl;
    Student s1;
    char name[10];
    int s;
    cin>>name>>s;  //输入s2的姓名和分数
    Student s2(name,s);
    cin>>name;     //输入s3的姓名
    Student s3(name);           
    //填写代码显示此时学生的人数，并显示三个人的数据    
    cout<<s3.getNum()<<endl;
    s1.Disp();
    s2.Disp();
    s3.Disp();
    Student s4=s2;       
    //填写代码显示此时学生的人数 （用另一种方法）   
    cout<<s4.getNum()<<endl;;
    f();    
    //填写代码显示此时学生的人数      
    cout<<Student::getNum()<<endl;
    return 0;
}  


*/






//--------------------------------------------------------------------------------------------








// 5545-5546:31、构造、拷贝构造、析构、静态成员、多继承、虚拟继承

/*#include <iostream>
using namespace std;
#include <string.h>
class Furniture{
    public:
    Furniture():high(0),length(0),width(0){
        ptype = nullptr;
    }
    Furniture(char* type,int l,int w,int h){
        ptype = new char[strlen(type)+1];
        strcpy(ptype,type);
        length = l;
        width = w;
        high = h;
    }
    Furniture(Furniture &f){
        ptype = new char[strlen(f.ptype)+1];
        strcpy(ptype,f.ptype);
        length = f.length;
        width = f.width;
        high = f.high;
    }
    ~Furniture(){
        delete []ptype;
    }
    void Disp(){
        cout<<"type:"<<ptype<<endl<<"length:"<<length<<endl
        <<"width:"<<width<<endl<<"high:"<<high<<endl;
    }
    char* Getptype(){
        return ptype;
    }
    int Getlength(){
        return length;
    }
    int Getwidth(){
        return width;
    }
    int Gethigh(){
        return high;
    }

    private:
    char* ptype;
    int length;
    int width;
    int high;

};

class Bed:virtual public Furniture{
    public:
    Bed(){
        material = nullptr;
    }
    Bed(char* btype,int bl,int bw,int bh,char* bmaterial):Furniture(btype,bl,bw,bh){
        material = new char[strlen(bmaterial)+1];
        strcpy(material,bmaterial);
    }
    Bed(Bed &b):Furniture(b){
        material = new char[strlen(b.material)+1];
        strcpy(material,b.material);
    }
    ~Bed(){
        delete[] material;
    }
    void Disp(){
        cout<<"type:"<<Getptype()<<endl<<"length:"<<Getlength()<<endl
        <<"width:"<<Getwidth()<<endl<<"high:"<<Gethigh()<<endl
        <<"material:"<<material<<endl;
    }

    char* Getmaterial(){
        return material;
    }

    void Sleep(){
        cout<<"Sleep"<<endl;
    }

    private:
    char* material;

};

class Sofa:virtual public Furniture{
    public:
    Sofa(){

    }
    Sofa(char* stype,int sl,int sw,int sh,int speople):Furniture(stype,sl,sw,sh){
        people = speople;
    }
    Sofa(Sofa &s):Furniture(s){
        people = s.people;

    }
    void Disp(){
        cout<<"type:"<<Getptype()<<endl<<"length:"<<Getlength()<<endl
        <<"width:"<<Getwidth()<<endl<<"high:"<<Gethigh()<<endl
        <<"Num:"<<people<<endl;
    }
    int Getpeople(){
        return people;
    }

    void WatchTV(){
        cout<<"Watch TV"<<endl;
    }

    private:
    int people;

};

class SleeperSofa:public Bed,public Sofa{
    public:
    SleeperSofa(){

    }

    SleeperSofa(char* sstype,int ssl,int ssw,int ssh,char* ssmaterial,int sspeople):Furniture(sstype, ssl, ssw, ssh),Bed(sstype,ssl,ssw,ssh,ssmaterial),Sofa(sstype,ssl,ssw,ssh,sspeople){
        num++;
    }
    SleeperSofa(SleeperSofa&ss):Furniture(ss),Bed(ss),Sofa(ss){
        num++;
    }
    ~SleeperSofa(){
        num--;
    }

    void Disp(){
        cout<<"type:"<<Getptype()<<endl<<"length:"<<Getlength()<<endl
        <<"width:"<<Getwidth()<<endl<<"high:"<<Gethigh()<<endl
        <<"material:"<<Getmaterial()<<endl<<"num:"<<Getpeople()<<endl;
    }

    void FoldOut(){
        cout<<"Fold Out"<<endl;
    }

    static int GetNum(){
        return num;
    }

    private:
    static int num;

};

int SleeperSofa::num=0;

int main()
{
char type[20]; //存储床、沙发等家具的型号
int a,b,c; //存储长宽高
char material[10]; //床的材质
int num; //沙发可坐人数量
/////////////////////////////////////////////////////
cin>>type>>a>>b>>c>>material;//输入床的数据
Bed bed(type,a,b,c,material); //生成一个床
bed.Disp();//显示床的数据
bed.Sleep();//展示睡觉功能
/////////////////////////////////////////////////////
cin>>type>>a>>b>>c>>num;//输入沙发的数据
Sofa s(type,a,b,c,num);//生成一个沙发
s.Disp();//显示沙发的数据
s.WatchTV();//展示看电视功能
/////////////////////////////////////////////////////
cout<<SleeperSofa::GetNum()<<endl;//显示两用沙发产品数量
cin>>type>>a>>b>>c>>material>>num;//输入两用沙发的数据
SleeperSofa ss(type,a,b,c,material,num);//生成一个两用沙发
ss.Disp();//显示两用沙发各项数据
cout<<ss.GetNum()<<endl;//显示两用沙发产品数量
//////////////////////////////////////////////////////
SleeperSofa sss(ss); //再生成一个
sss.Disp();//显示刚生成产品信息
cout<<sss.GetNum()<<endl;//显示两用沙发产品数量
///////////////////////////////////////////////////////
SleeperSofa *p = new SleeperSofa (ss);//堆中生成一个两用沙发,与前面sss数据相同
p->Disp();//显示堆中刚生成的产品信息
cout<<p->GetNum()<<endl;//显示两用沙发产品数量
///////////////////////////////////////////////////////
delete p;//析构堆中产品
cout<<SleeperSofa::GetNum()<<endl;//显示两用沙发产品数量
/////////////////////////////////////////////////////////
ss.Sleep();//展示ss睡觉功能
ss.WatchTV();//展示ss看电视功能
ss.FoldOut();//展示ss折叠功能
/////////////////////////////////////////////////////
    return 0;
}

*/







//--------------------------------------------------------------------------------------------









// t2:   5547  33、多继承、虚拟继承和多态
/*

#include <iostream>
using namespace std;
#include <string.h>

class Person{
    public:
    Person():age(0){
        pname = nullptr;
    }

    Person(char* ppname,int page){
        pname = new char[strlen(ppname)+1];
        strcpy(pname,ppname);
        age = page;
    }

    ~Person(){
        delete[] pname;
    }
    char* GetName(){
        return pname;
    }
    int GetAge(){
        return age;
    }
    virtual void Disp(){
        cout<<"name:"<<GetName()<<" age:"<<GetAge()<<endl;
    }
    private:
    char* pname;
    int age;
};

class Date{
    public:
    Date():year(0),month(0),day(0){

    }
    Date(int y,int m,int d):year(y),month(m),day(d){

    }
    int Getyear(){
        return year;
    }
    int Getmonth(){
        return month;
    }
    int Getday(){
        return day;
    }

    private:
    int year;
    int month;
    int day;
};

class Student:virtual public Person{
    public:
    Student(){

    }
    Student(char* sname,int sage,int syear,int smonth,int sday,int sscore)
    :Person(sname,sage),birth(syear,smonth,sday),score(sscore){

    }

    int Getscore(){
        return score;
    }
    int sGetyear(){
        return birth.Getyear();
    }
    int sGetmonth(){
        return birth.Getmonth();
    }
    int sGetday(){
        return birth.Getday();
    }

    //friend class Teacher;//--------------------------------

    void Disp(){
        cout<<"name:"<<GetName()<<" age:"<<GetAge()<<endl;
        cout<<"birthday:"<<birth.Getyear()<<"/"<<birth.Getmonth()<<"/"<<birth.Getday()<<endl;
        cout<<"score:"<<score<<endl;
    }

    private:
    Date birth;
    int score;
};

class Teacher:virtual public Person{
    public:
    Teacher(){
        title = nullptr;
    }
    Teacher(char* tname,int tage,char*ttitle):Person(tname,tage){
        title = new char[strlen(ttitle)+1];
        strcpy(title,ttitle);
    }
    ~Teacher(){
        delete[] title;
    }
    void Disp(){
        cout<<"name:"<<GetName()<<" age:"<<GetAge()<<endl;
        cout<<"title:"<<title<<endl;
    }
    char* Gettitle(){
        return title;
    }
    //----------------------------------------
    //void Assign(Student& s,int newscore){
    //   s.score = newscore;
    //}
    //------------------------------------------
    private:
    char* title;

};

class Stu_teacher:public Student,public Teacher{
    public:
    Stu_teacher(){

    }
    Stu_teacher(char* stname,int stage,int styear,int stmonth,int stday,int stscore,char* sttitle):Person(stname,stage),Student(stname,stage,styear,stmonth,stday,stscore),Teacher(stname,stage,sttitle){

    }
    void Disp(){
        cout<<"name:"<<GetName()<<" age:"<<GetAge()<<endl;
        cout<<"birthday:"<<sGetyear()<<"/"<<sGetmonth()<<"/"<<sGetday()<<endl;
        cout<<"score:"<<Getscore()<<endl;
        cout<<"title:"<<Gettitle()<<endl;
    }
    private:

};
void fn(Person& p){
    p.Disp();
}


int main()

{

    char name[20],title[20];

    int age,month,day,year,score;

    cin>>name>>age>>year>>month>>day>>score;

    Student s(name,age,year,month,day,score);

    cin>>name>>age>>title;

    Teacher t(name,age,title);

    cin>>name>>age>>year>>month>>day>>score>>title;

    Stu_teacher st(name,age,year,month,day,score,title);

    s.Disp();  //显示学生的信息

    t.Disp();  //显示教师的信息

    st.Disp();  //显示实习老师的信息

    //t.Assign(s,90);//--------------

    //s.Disp();   //-----------------

    fn(s);  //调用函数fn，显示参数s的有关信息

    fn(t);  //调用函数fn，显示参数t的有关信息

    fn(st);  //调用函数fn，显示参数st的有关信息

    return 0;

}
*/










//--------------------------------------------------------------------------









// t3 5549 34、类的分解、纯虚函数、多继承、虚拟继承、多态

/*
#include <iostream>
using namespace std;
#include <string.h>

class Furniture{
    public:
    virtual void Disp()=0;
    void Setweight(int wweight){
        weight = wweight;
    }
    int Getweight(){
        return weight;
    }
    private:
    int weight;
};

class Bed:virtual public Furniture{
    public:

    void Disp(){
        cout<<"BBBBBB"<<endl;
    }


    private:

};

class Sofa:virtual public Furniture{
    public:
    void Disp(){
        cout<<"SSSSSS"<<endl;
    }

    private:

};

class SofaBed:public Bed,public Sofa{
    public:
    void Disp(){
        cout<<"SBSBSB"<<endl;
    }

    private:
};

void fn(Furniture *f){
    cout<<"weight:"<<f->Getweight()<<" ";
    f->Disp();
}


int main()

{

    int  weight1,weight2,weight3;

    Bed   *b=new Bed;

    Sofa  *s=new  Sofa;

    SofaBed  *sb=new SofaBed;

    cin>>weight1>>weight2>>weight3;

    b->Setweight(weight1);

    s->Setweight(weight2);

    sb->Setweight(weight3);

    fn(b);

    fn(s);

    fn(sb);

    delete b;

    delete s;

    delete sb;

    return 0;

}
*/









//------------------------------------------------------------------------










// t4   5552   35、重载-、--运算符（非成员函数形式）
/*
#include <iostream>
using namespace std;

class Time{
    public:
    Time();
    Time(int,int,int);
    friend Time operator - (Time &,Time &);
    friend Time operator --(Time &,int);
    friend Time &operator --(Time &);

    void disp();
    private:
    int hour;
    int minute;
    int second;

};
Time::Time(){

}

Time::Time(int hou,int min,int sec):hour(hou),minute(min),second(sec){
    if(second<0)
    {
        second+=60;
        minute-=1;
    }
    if(minute<0)
    {
        minute+=60;
        hour-=1;
    }

}

Time operator-(Time &t1,Time &t2){
    Time except;
    int second = t1.second-t2.second;
    int minute = t1.minute-t2.minute;
    int hour = t1.hour-t2.hour;

    Time result(hour,minute,second);

    return result;
}

Time operator --(Time &t1,int){
    Time temp = t1;
    --t1;
    return temp;
}

Time &operator --(Time &t1){
    --t1.second;
    if(t1.second<0)
    {
        t1.second+=60;
        t1.minute-=1;
    }
    if(t1.minute<0)
    {
        t1.minute+=60;
        t1.hour-=1;
    }
    return t1;
}


void Time::disp(){
    cout<<hour<<":"<<minute<<"\'"<<second<<"\""<<endl;
}





int main()

{

    int h1,m1,s1,h2,m2,s2;

    cin>>h1>>m1>>s1>>h2>>m2>>s2;

    Time t1(h1,m1,s1), t2(h2,m2,s2), t;

    t=t1-t2;

    t.disp();

    t--;

    t.disp();

    (--t)--;

    t.disp();

    (t--).disp();

    t.disp();

    return 0;

}

*/









//------------------------------------------------------------------------










// t5  应该是上机题，未找到oj题目
/*
#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
    Person(){
        pname = nullptr;
    }
    Person(char* pname1){
        pname = new char[strlen(pname1)+1];
        strcpy(pname,pname1);
    }

    ~Person(){
        delete[] pname;
    }

    char* getName(){
        return pname;
    }



    virtual void Disp(){
        cout<<pname<<endl;
    }

    private:
    char* pname;
};

class Student:virtual public Person{
    public:
    Student(){

    }
    Student(char* sname,int sscore):Person(sname),score(sscore){

    }

    void Disp(){
        cout<<getName()<<","<<score<<endl;
    }

    int getScore(){
        return score;
    }

    friend class StuTeacher;

    private:
    int score;

};


class Teacher:virtual public Person{
    public:
    Teacher(){
        title = nullptr;
    }
    Teacher(char* tname,char* ttitle):Person(tname){
        title = new char[strlen(ttitle)+1];
        strcpy(title,ttitle);
    }
    ~Teacher(){
        delete[] title;
    }

    void Disp(){
        cout<<getName()<<","<<title<<endl;
    }

    char* getTitle(){
        return title;
    }

    private:
    char* title;
};

class StuTeacher:public Student,public Teacher{
    public:
    StuTeacher(){

    }
    StuTeacher(char* stname,int stscore,char* sttitle,int stage):Person(stname),Student(stname,stscore),Teacher(stname,sttitle),age(stage){

    }

    void Disp(){
        cout<<getName()<<","<<getScore()<<","<<getTitle()<<","<<age<<endl;
    }

    void Edit(Student &s,int newscore){
        s.score = newscore;
    }


    private:
    int age;
};

int main()

{

    char name[10],title[10];

    int score,age;

    cin>>name>>score;

    Student s(name,score);

    cin>>name>>title;

    Teacher t(name,title);

    cin>>name>>score>>title>>age;

    StuTeacher st(name,score,title,age);



        Person *p;

    p=&s;    p->Disp();   //显示学生信息

    p=&t;    p->Disp();   //显示教师信息

    p=&st;  p->Disp();   //显示师范生信息

    st.Edit(s,90);           //修改学生成绩为90

    s.Disp();

    return 0;

}*/









//------------------------------------------------------------------------










// t6  5553   36、重载-、--运算符（成员函数形式）
/*
#include <iostream>
using namespace std;
 
class Time
{
public:
    Time()
    {
    }
 
    Time(int hou, int min, int sec)
    {
        hour = hou;
        minute = min;
        second = sec;
        if (second < 0)
        {
            second = second + 60;
            minute -= 1;
        }
 
        if (minute < 0)
        {
            minute = minute + 60;
            hour -= 1;
        }
    }

    Time operator - (Time &t2){//返回的是值
        hour = hour - t2.hour;
        minute = minute - t2.minute;
        second = second - t2.second;
        Time except(hour,minute,second);

        return except;
    }

    Time &operator -- (){//前减减  传的是引用
        --(*this).second;
        if (second < 0)
        {
            second = second + 60;
            minute -= 1;
        }
 
        if (minute < 0)
        {
            minute = minute + 60;
            hour -= 1;
        }
        //这里不能用
        //Time result(this->hour,this->minute,this->second);
        //return result;
        //???
        return *this;
    }

    Time operator -- (int){//后减减  传的是值，值传递
        Time temp = *this;
        --(*this).second;
        return temp;
    }
 

    void disp()
    {
        cout << hour << ":" << minute << "\'" << second << "\"" << endl;
    }
 
private:
    int hour;
    int minute;
    int second;
};
int main()

{

    int h1, m1, s1, h2, m2, s2;

    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    Time t1(h1, m1, s1), t2(h2, m2, s2), t;

    t = t1 - t2;

    t.disp();

    t--;

    t.disp();

    (--t)--;

    t.disp();

    (t--).disp();

    t.disp();

    return 0;
}*/







//------------------------------------------------------------------------







//t7    5555    37、重载赋值运算符
/*
#include <iostream>
#include <string.h>
using namespace std;


class Teacher{
    public:
    Teacher():age(0){
        pname = nullptr;
    }

    Teacher(char* tname,int tage){
        pname = new char[strlen(tname)+1];
        strcpy(pname,tname);
        age = tage;
    }
    Teacher(Teacher &t){
        pname = new char[strlen(t.pname)+1];
        strcpy(pname,t.pname);
        age = t.age;
    }

    

    ~Teacher(){
        delete[] pname;
    }

    Teacher &operator = (Teacher&t){
        delete pname;
        pname = new char[strlen(t.pname)+1];
        strcpy(pname,t.pname);
        age = t.age;
        return *this;
    }

    void Disp(){
        cout<<"Teacher:"<<pname<<","<<age<<endl;
    }

    private:
        char *pname;  //存名字的地址 ***用到堆
        int age;
};

class Student{

    public:
    Student(){
        
    }
    Student(char* sname, int sscore){
        strcpy(name,sname);
        score = sscore;
    }



    void Disp(){
        cout<<"Student:"<<name<<","<<score<<endl;
    }

    protected:
        char name[10];// 未用堆，属于栈
        int score;

};


class Tutor{
    public:
    Tutor():num(0){

    }

    Tutor(char* ttname1,int ttscore,char* ttname2,int ttage):s(ttname1,ttscore),t(ttname2,ttage),num(0){
        
    }

    Tutor(Tutor &tt2):s(tt2.s),t(tt2.t),num(tt2.num){
        
    }

    void Date(){
        num++;
    }

    void Disp(){
        s.Disp();
        t.Disp();
        cout<<"Number:"<<num<<endl;
    }

    protected:
        Student s;
        Teacher t;
        int num;//存储师生会面次数
};



int main()

{

    char name1[15],name2[15];

    int score,age;

    cin>>name1>>score>>name2>>age;

    Tutor tt1(name1,score,name2,age),tt2;

    tt1.Disp();

    tt1.Date();    //师生碰面一次

    tt2=tt1;       //此处调用的哪段代码？

    tt2.Disp();

    Tutor tt3=tt1;    //此处调用的哪段代码？

    tt3.Date();

    tt3.Disp();

    return 0;

}
*/






//------------------------------------------------------------------------







//t8   5556  37. 类的分解、多继承、虚拟继承、多态、运算符重载

#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
    Person():page(0){
        pname = nullptr;
    }
    Person(char* name ,int age){
        pname = new char[strlen(name)+1];
        strcpy(pname,name);
        page = age;
    }
    ~Person(){
        delete[] pname;
    }

    Person(Person &p)
    {
        pname = new char[strlen(p.pname)+1];
        strcpy(pname,p.pname);
        page = p.page;
    }

    Person &operator = (Person&p){
        delete []pname;
        pname = new char[strlen(p.pname)+1];
        strcpy(pname,p.pname);
        page = p.page;
        return *this;
    }
    Person operator ++ (int){
        Person temp = *this;
        ++(*this).page;
        return temp;

    }
    Person &operator ++ (){
        ++(*this).page;

        return *this;
    }

    char* getName(){
        return pname;
    }
    int getAge(){
        return page;
    }
    virtual void Disp(){
        cout<<pname<<","<<page<<endl;
    }


    private:
    char* pname;
    int page;
};

class Student:virtual public Person{
    public:
    Student():score(0){

    }
    Student(char* sname,int sage,int sscore):Person(sname,sage){
        score = sscore;
    }

    Student &operator ++ (){
        Person::operator++();
        return *this;
    }

    Student operator ++ (int){
        Student temp = *this;
        Person::operator++();
        return temp;

    }

    int getScore(){
        return score;
    }

    void Disp(){
        cout<<getName()<<","<<getAge()<<","<<score<<endl;
    }
    private:
    int score;
};

class Teacher:virtual public Person{
    public:
    Teacher(){
        title = nullptr;
    }
    Teacher(char* tname,int tage,char* ttitle):Person(tname,tage){
        title = new char[strlen(ttitle)+1];
        strcpy(title,ttitle);
    }
    Teacher(char* tname,int tage):Person(tname,tage){
        title = new char[strlen("jxjs")+1];
        strcpy(title,"jxjs");
    }
    
    Teacher(Teacher &t):Person(t.getName(),t.getAge()){
        title = new char[strlen(t.title)+1];
        strcpy(title,t.title);
    }
    //************理解？？************ 
    Teacher &operator = (Teacher& t){
        Person::operator=(t); // 虚继承的Person
        delete[] title;
        title =new char[strlen(t.title) + 1];
        strcpy(title, t.title);
        return *this;
    }
    //******************************* 
    ~Teacher(){
        delete[] title;
    }
    char* getTitle(){
        return title;
    }
    Teacher& operator++() {
        Person::operator++();
        return *this;
    }
    Teacher operator ++(int){
        Teacher temp=*this;
        ++(*this);
        return temp;
    }

    void Disp(){
        cout<<getName()<<","<<getAge()<<","<<title<<endl;
    }


    private:
    char* title;
};

class StuTeacher:public Student,public Teacher{
    public:
    StuTeacher(){
        company = nullptr;
    }
    StuTeacher(char* stname,int stage,int stscore,char* stcompany):Person(stname,stage),Student(stname,stage,stscore),Teacher(stname,stage){
        company = new char[strlen(stcompany)+1];
        strcpy(company,stcompany);
    }
    StuTeacher(StuTeacher &st):Person(st.getName(),st.getAge()),Student(st.getName(),st.getAge(),st.getScore()),Teacher(st.getName(),st.getAge(),st.getTitle()){
        company = new char[strlen(st.company)+1];
        strcpy(company,st.company);
    }
    StuTeacher &operator =(StuTeacher& st){
        Student::operator=(st);  
        Teacher::operator=(st);
        delete[] company;
        company = new char[strlen(st.company)+1];
        strcpy(company,st.company);
        return *this;
    }
    ~StuTeacher(){
        delete[] company;
    }

    StuTeacher& operator++() {
        Person::operator++();
        return *this;
    }
    StuTeacher operator++(int) {
        StuTeacher temp = *this;
        ++(*this);
        return temp;
    }

    void Disp(){
        cout << getName() << "," << getAge() << "," << getScore() << "," << getTitle() << "," << company << endl;
    }

    private:
    char* company;
};

void fn(Person &p){
    p.Disp();
}


int main()
{
    char name[20],title[20],company[20];
    int age,score;

    cout<<"输入学生信息:";
    cin>>name>>age>>score;
    Student s(name,age,score);
    (s++).Disp();    //显示学生信息，并使学生年龄增加1岁
    s.Disp();
    
    cout<<"输入教师信息:";
    cin>>name>>age>>title;
    Teacher t(name,age,title);
    t.Disp();  //显示教师信息
    (++(++t)).Disp();  //显示教师增加2岁后的信息

    cout<<"输入见习教师信息:";
    cin>>name>>age>>score>>company;
    StuTeacher st1(name,age,score,company);
    StuTeacher st2=st1,st3,st4;
    st4=st3=st2;
    (st3++).Disp();
    (++st3).Disp();

    StuTeacher  st5;

    st5=++st3;  

    fn(s);  //显示学生信息
    fn(t);  //显示教师信息
    fn(st3); //显示见习教师信息
    return 0;
}








//------------------------------------------------------------------------









//t9:     5560    40、重载插入运算符
/*
#include <iostream>
#include <string.h>
using namespace std;

class Student{
    public:
    Student():score(0){
        name = nullptr;
    }

    Student(char* sname,int sscore){
        name = new char[strlen(sname)+1];
        strcpy(name,sname);
        score = sscore;
    }

    ~Student(){
        delete[] name;
    }

    virtual void Disp(ostream &out){
        out<<"name:"<<name<<",score:"<<score<<endl;
    }

    char* getName(){
        return name;
    }
    int getScore(){
        return score;
    }


    private:
    char* name;
    int score;

};

    ostream &operator <<(ostream &out,Student &s){
        s.Disp(out);
        return out;
    }

class GraduateStudent:virtual public Student{
    public:
    GraduateStudent(){
        gsname = nullptr;
    }

    GraduateStudent(char* gss_name,int gsscore,char* t_name):Student(gss_name,gsscore){
        gsname = new char[strlen(t_name)+1];
        strcpy(gsname,t_name);
    }

    ~GraduateStudent(){
        delete[] gsname;
    }

    void Disp(ostream &out2){
        out2<<"name:"<<getName()<<",score:"<<getScore()<<",teacher:"<<gsname<<endl;
    }
    private:
    char* gsname;
};



void fn(Student&s)
{
    cout<<s;
}


int main()   
{
    char s_name[20], t_name[20];

    int  score;

    cin>>s_name>>score;

    Student s(s_name, score);   

    cin>>s_name>>score>>t_name;

    GraduateStudent g(s_name, score , t_name);      

    cout<<s<<g;   

    fn(s);

    fn(g);

    return 0;

} 

*/







//--------------------------------------------------------------------
//GPT


//t1
/*
#include <iostream>
#include <string.h>
using namespace std;

class Book{
    public:
    Book():price(0){
        title = nullptr;
    }

    Book(char* bname,int bprice){
        title = new char[strlen(bname)+1];
        strcpy(title,bname);
        price = bprice;
    }

    ~Book(){
        delete[] title;
    }

    friend ostream &operator <<(ostream&,Book &b); 

    private:
    char* title;
    int price;
};

ostream &operator << (ostream& out,Book &b){
    out<<"title:"<<b.title<<",price:"<<b.price<<endl;
    return out;
}

int main() {
    char title[100];
    int price;
    cin >> title >> price;
    Book b(title, price);
    cout << b;
    return 0;
}*/




//--------------------------------------------


 

//t2

/*


#include <iostream>
#include <string.h>
using namespace std;

class Book{
    public:
    Book():price(0){
        title = nullptr;
    }

    Book(char* title1,int price1){
        title = new char[strlen(title1)+1];
        strcpy(title,title1);
        price = price1;
    }

    ~Book(){
        delete[] title;
    }

    char* getTitle(){
        return title;
    }
    int getPrice(){
        return price;
    }

    friend ostream &operator <<(ostream&,Book &);

    private:
    char* title;
    int price;
};

ostream &operator <<(ostream& out,Book &b){
    out<<"title:"<<b.title<<",price:"<<b.price<<endl;
    return out;
}

class EBook:virtual public Book{
    public:

    EBook(){
        url = nullptr;
    }
    
    EBook(char* etitle,int eprice,char* eurl):Book(etitle,eprice){
        url = new char[strlen(eurl)+1];
        strcpy(url,eurl);
    }

    ~EBook(){
        delete[] url;
    }

    friend ostream &operator <<(ostream&,EBook &);

    private:
    char* url;
};

ostream &operator <<(ostream& out2,EBook & eb){
    out2<<"title:"<<eb.getTitle()<<",price:"<<eb.getPrice()<<",url:"<<eb.url<<endl;
    return out2;
}


int main() {
    char title[100], url[100];
    int price;
    cin >> title >> price;
    Book b(title, price);
    cin >> title >> price >> url;
    EBook e(title, price, url);
    cout << b << e;
    return 0;
}

*/

//--------------------------------------------



//t3
/*
#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
    Person(){
        name = nullptr;
        gender = nullptr;
    }

    Person(char* pname, char* pgender){
        name = new char[strlen(pname)+1];
        strcpy(name,pname);

        gender = new char[strlen(pgender)+1];
        strcpy(gender,pgender);
    }

    virtual void Disp(ostream &){
        cout<<"name:"<<name<<",gender:"<<gender<<endl;
    }

    ~Person()
    {
        delete[] name;
        delete[] gender;
    }

    char* getN(){
        return name;
    }

    char* getG(){
        return gender;
    }

    friend ostream &operator <<(ostream &,Person &);
        
    private:
    char* name;
    char* gender;
};



class Employee:virtual public Person{
    public:
    Employee(){
        position = nullptr;
    }

    Employee(char* Ename, char* Egender, char* Eposition):Person(Ename,Egender){
        position = new char[strlen(Eposition)+1];
        strcpy(position,Eposition);
    }

    ~Employee(){
        delete[] position;
    }

    void Disp(ostream &pout){
        cout<<"name:"<<getN()<<",gender:"<<getG()<<endl;
    }

    char* getP(){
        return position;
    }

    private:
    char* position;

};

class Manager:public Employee{
    public:
    Manager(){
        department = nullptr;
    }

    Manager(char* mname, char* mgender, char* mposition, char* mdepartment):Person(mname,mgender),Employee(mname,mgender,mposition){
        department = new char[strlen(mdepartment)+1];
        strcpy(department,mdepartment);
    }

    ~Manager(){
        delete[] department;
    }
    
    void Disp(ostream &pout){
        pout<<"name:"<<getN()<<",gender:"<<getG()<<",position:"<<getP()<<",department:"<<department<<endl;
    }

    private:
    char* department;
};

ostream &operator <<(ostream &pout,Person &p){
    p.Disp(pout);
    return pout;
}

int main() {
    char name[30], gender[10], position[30], department[30];
    cin >> name >> gender;
    Person p(name, gender);
    cin >> name >> gender >> position;
    Employee e(name, gender, position);
    cin >> name >> gender >> position >> department;
    Manager m(name, gender, position, department);
    cout << p << e << m;
    return 0;
}
*/


