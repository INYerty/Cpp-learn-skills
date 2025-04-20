/*问题描述
晓宇新买了一本书，这本书的页码是从 1−n 编号的连续整数：1,2,3,...,n 。请你帮她求出全部页码中所有单个数字的和，例如第 123 页，它的和就是 1+2+3=6 。
输入格式
一行一个正整数 n 。
输出格式
一行一个正整数，代表所有单个数字的和。
样例输入
3456789
样例输出
96342015
评测数据范围
对于 100% 的数据，保证 1≤n≤109 。 */
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long t=i;
        while(t)
        {
            ans+=t%10;
            t/=10;
        }
    }
    cout<<ans<<endl;
    return 0;

}