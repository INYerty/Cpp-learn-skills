/*算法实验5：求最大和最小值

Description
给定n个数，在最坏情况下用╔ 3n/2－2 ╕次比较找出这n个数中元素的最大值和最小值。
要求只编写函数 
void maxmin(int a[],int low,int high,int *max,int *min).
系统会自动在程序的最后加上如下代码：

int main()
{
    int max,min,k,a[200];
    int m;
    while(scanf("%d",&k)&&k)
    {
        for(m=0;m<k;m++)
            scanf("%d",&a[m]);
        maxmin(a,0,k-1,&max,&min);
        printf("%d %d\n",max,min);
   
    }
   
} 

Input
包含多组测试数据。每组测试数据的第一个元素是整数的个数n,接下来是n个整数。0表示结束。 n<=200
Output
这n个数中的最大值和最小值。
Sample Input
5 1 8 2 4 3
3 2 4 1
0
Sample Output
8 1
4 1
HINT
需要在注释中证明为什么比较次数是╔ 3n/2－2 ╕次，给出递推公式。
加上相应的头文件，并实现函数
void maxmin(int a[],int low,int high,int *max,int *min).
Source*/

/*#include<stdio.h>
void findMaxMin(int a[],int low,int high,int *resultMax,int *resultMin){
    if(low==high){
        *resultMax=*resultMin=a[low];
        return;
    }
    if(high==low+1){
        if(a[low]>a[high]){
            *resultMax=a[low];
            *resultMin=a[high];

        }else{
            *resultMin=a[low];
            *resultMax=a[high];

        }
        return;
    }
    int mid=(low+high)/2;
    int leftmax,leftmin,rightmax,rightmin;
    findMaxMin(a,low,mid,&leftmax,&leftmin);
    findMaxMin(a,mid,high,&rightmax,&rightmin);
    *resultMax = (leftmax > rightmax) ? leftmax : rightmax;
    *resultMin = (leftmin < rightmin) ? leftmin : rightmin;


}
int main() {
    int max, min, n, a[200];
    int i;
    while(scanf("%d", &n) && n) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        findMaxMin(a, 0, n - 1, &max, &min);
        printf("%d %d\n", max, min);
    }
    return 0;
}*/

#include <stdio.h>


void maxmin(int a[], int low, int high, int *max, int *min) {
    if (low == high) {  // 只有一个元素
        *max = *min = a[low];
        return;
    }
    if (high == low + 1) { 
        if (a[low] > a[high]) {
            *max = a[low];
            *min = a[high];
        } else {
            *min = a[low];
            *max = a[high];
        }
        return;
    }
    int mid = (low + high) / 2;
    int leftmax, leftmin, rightmax, rightmin;
    maxmin(a, low, mid, &leftmax, &leftmin);  
    maxmin(a, mid + 1, high, &rightmax, &rightmin); 
    *max = (leftmax > rightmax) ? leftmax : rightmax;  
    *min = (leftmin < rightmin) ? leftmin : rightmin;  
}

int main() {
    int max, min, k, a[200];
    int m;
    while(scanf("%d", &k) && k) {  // 读取每组测试数据
        for(m = 0; m < k; m++) {
            scanf("%d", &a[m]); 
        }
        maxmin(a, 0, k - 1, &max, &min);  
        printf("%d %d\n", max, min); 
    }
    return 0;
}

