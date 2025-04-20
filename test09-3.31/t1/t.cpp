#include <iostream>
using namespace std;

class Box{
    public:
    Box(){
        int length=40;
        int width=20;
        int high = 25;
        max=(length*width*high*0.01*0.01*0.01)*1000;
        count=0;
    }

    Box(int len,int wid,int hig){
        length=len;
        width=wid;
        high=hig;
        count=0;
        max=(length*width*high*0.01*0.01*0.01)*1000;
    }
    void insert(int inst){
        if(inst>max){
            inst=max;
        }else{
            count+=inst;
        }
        cout<<count<<endl;
    }
    void out(int o){
        if(o>max){
            count=0;
        }else{
            count-=o;
        }

    }
    void Disp(){

        cout<<count<<endl;        
        if(count>0)
        {
            cout<<"Empty First"<<endl;
        }
    }


    private:
    int length;
    int width;
    int high;
    int max;
    int count;

};






int main(){
    Box b;
    int choice;
    cin>>choice;
    if(choice==1){
        int inst1,out1;
        cin>>inst1>>out1;
        b.insert(inst1);
        b.out(out1);
        b.Disp();
    }
    if(choice==2){
        int x,y,z;
        cin>>x>>y>>z;
        Box b(x,y,z);
        int inst1,out1;
        cin>>inst1>>out1;
        b.insert(inst1);
        b.out(out1);
        b.Disp(); 
    }
}