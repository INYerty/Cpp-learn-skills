#include <iostream>
#include <cstring>
using namespace std;


void p(int a,int b)
{
    cout<<a+b<<endl;
    
}

void p(float a,float b)
{
    cout<<a+b<<endl;
}

void p(char *a,char *b)
{
    cout << a << b << endl;
    
}

int  main()

{    
    int   a,b;
     float  x,  y;
     char  s1[50],  s2[20];
     cin>>a>>b;
     cin>>x>>y;
     cin>>s1>>s2;
     //  此处调用被调函数计算a+b
    p(a,b);

     // 此处调用被调函数计算x+y
    p(x,y);

     //  此处调用被调函数连接两个字符串
    p(s1,s2);

     return 0;
}

