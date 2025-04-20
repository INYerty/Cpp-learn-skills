#include <iostream>
#include <cstdlib>       //包含exit()函数
using namespace std;

int &put(int vals[],int i){
    if((i>=10)||(i<0))
    {
        cout<<"out of range"<<endl;
        exit(1);
    }
    return vals[i];
    
}

int get(int vals[],int i){
    if((i>=10)||(i<0))
    {
        cout<<"out of range"<<endl;
        exit(1);
    }
    return vals[i];
    
}

int main(){
    int vals[10],a,b,c,i;
    for(i=0; i<=9; i++)
        vals[i]=i*i;   //给元素赋值
    cin>>a>>b>>c;
    if (a < 0 || a >= 10 || b < 0 || b >= 10 || c < 0 || c >= 10) {
        cout << "out of range" << endl;
        exit(1);
        }
    put(vals,a)=a*a+1;       //让数组vals[a]的值变为a*a+1
    put(vals,b)=b*b+1;  
    put(vals,c)=c*c+1;
    cout<<get(vals,a)<<endl;  //输出数组vals[a]的值
    cout<<get(vals,b)<<endl;
    cout<<get(vals,c)<<endl;
    return 0;
}

