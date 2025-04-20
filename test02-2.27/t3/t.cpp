#include<iostream>
#include<cstring>
using namespace std;

inline int f(int a,int b)
{
    return a+b;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          



int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<f(i,i+1)<<endl;
    }
    return 0;
}




/*Description
编写函数，用来计算i和i+1两个整数的和。主函数调用该函数对下面每一组数据进行操作。 （使用内联函数以缩短运行时间）

1  2
2  3
3  4
.......

30000  30001

Input
输入一个终值，例如，输入100，则只计算到100  101这一组数据


Output
输出每一组数据的计算结果，每个结果占一行


Sample Input
10
Sample Output
3
5
7
9
11
13
15
17
19
21
Code 1 here:*/