#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int *array=new int[10];
    for(int i=0;i<10;i++)
    {
        cin>>array[i];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(array[i]<array[j])
            {
                int tp=array[i];
                array[i]=array[j];
                array[j]=tp;
            }
        }
    }

    for(int i=0;i<10;i++)
    {
        cout<<array[i]<<" ";
    }
}

/*Description
利用new和delete，使用堆内存存储键盘输入的10个整数，并排序输出（从大到小）。
Input
输入十个整数
Output
按从大到小顺序输出10个整数
Sample Input
-5 1 6 8 2 9 4 7 -10 3
Sample Output
9 8 7 6 4 3 2 1 -5 -10
Code 1 here:*/

