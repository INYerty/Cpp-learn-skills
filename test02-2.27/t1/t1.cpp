#include <iostream>
#include <cstring>
using namespace std;

float V(float a=1.2,float b=0.6,float c=0.03)
{
    return a*b*c;
}

int main()

 {
    int a,b,c,d;
    float sum;
    cin>>a>>b>>c>>d;
    sum=a*V(1.2,0.6,0.03)+b*V(1.5,1.0,0.03)+c*V(1.0,0.6,0.03)+d*V(2,1.2,0.05);
    cout<<sum<<endl;
    return 0;
}

/*Description
某工厂生产写字台，标准写字台的台面木料尺寸规格是1.2*0.6*0.03 立方米，

老板桌的台面木料规格是1.5*1.0*0.03立方米，

儿童写字台的是1.0*0.6*0.03，

还有一种特大写字台，规格：2.0*1.2*0.05。

设某单位购买四种写字台的数量都是从键盘输入，下面的主函数用来计算制作这些台面总共需要多少立方米的木料，其中V()是一个函数，
用来计算一张写字台台面的体积，请你用
“带默认值参数的函数”
的知识来改写程序，并给出V()函数的定义，以便使程序简单

int main()

 {

    int a,b,c,d;
    float sum;
    cin>>a>>b>>c>>d;
    sum=a*V(1.2,0.6,0.03)+b*V(1.5,1.0,0.03)+c*V(1.0,0.6,0.03)+d*V(2,1.2,0.05);
    cout<<sum<<endl;
    return 0;
}
提示：主函数调用V函数时，有些参数经常是某一个确定值
注意：本题必须用带默认值参数的函数来编程，否则不得分
Input
输入4个数据，分别代表4种写字台的数量
Output
输出制作这些写字台台面总共需要多少木料（立方米）
Sample Input
1 1 1 1
Sample Output
0.2046
Code 1 here:*/