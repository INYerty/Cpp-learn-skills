#include <iostream>
#include <string.h>
using namespace std;

class Furniture
{
public:
void Disp(){
    cout<<"type:"<<ptype<<endl;
}
Furniture(){
    ptype = nullptr;
}
Furniture(char* type){
    ptype = new char[strlen(type)+1];
    strcpy(ptype,type);
}
~Furniture(){
    delete[] ptype;
}

protected:
    char *ptype;
};

class Bed : virtual public Furniture
{
public:
    void Sleep()
    {
        cout<<"Sleep"<<endl;
    }
    void Disp(){
        Furniture::Disp();
        cout<<"length:"<<length<<endl;
        cout<<"width:"<<width<<endl;
        cout<<"high:"<<high<<endl;
        cout<<"material:"<<material<<endl;
    }
    Bed(){
        material = nullptr;
    }
    Bed(char* type,int x,int y,int z,char* mater):Furniture(type){
        length = x;
        width = y;
        high = z;
        material = new char[strlen(mater)+1];
        strcpy(material,mater);

    }


protected:
    int length;
    int width;
    int high;
    char *material;
    // char* ptype 继承
};

class Sofa : virtual public Furniture,virtual public Bed
{
public:
void WatchTV(){
    cout<<"Watch TV"<<endl;
}
void Disp(){
    Furniture::Disp();
    cout<<"length:"<<Bed::length<<endl;
    cout<<"width:"<<Bed::width<<endl;
    cout<<"high:"<<Bed::high<<endl;
    cout<<"Num:"<<sitnum<<endl;
}
Sofa(){

}
Sofa(char* type,int x,int y,int z,int people):Furniture(type){
    length = x;
    width = y;
    high = z;
    sitnum = people;
    
}
~Sofa(){

}
protected:
// char* ptype 继承
//len,wid,hig 继承
int sitnum;
};

class SleeperSofa:virtual public Bed,virtual public Sofa{
public:
SleeperSofa(char* type,int x,int y,int z,char* mater,int people):Furniture(type){
    length = x;
    width = y;
    high = z;
    sitnum = people;
    material = new char[strlen(mater)+1];
    strcpy(material,mater);
    count++;
}
~SleeperSofa(){
    delete[] material;
    count--;
}

SleeperSofa(SleeperSofa& ss){
    ptype = new char[strlen(ss.ptype)+1];
    strcpy(ptype,ss.ptype);
    length = ss.length;
    width = ss.width;
    high = ss.high;
    sitnum = ss.sitnum;
    material = new char[strlen(ss.material)+1];
    strcpy(material,ss.material);
    count++;
}

void FoldOut(){
    cout<<"Fold Out"<<endl;
}

static int GetNum(){
    return count;
}
void Disp(){
    Furniture::Disp();
    cout<<"length:"<<Bed::length<<endl;
    cout<<"width:"<<Bed::width<<endl;
    cout<<"high:"<<Bed::high<<endl;
    cout<<"material:"<<Bed::material<<endl;
    cout<<"num:"<<Sofa::sitnum<<endl;
    
}
protected:
    static int count;
};
int SleeperSofa::count=0;
int main()

{
    char type[20];     // 存储床、沙发等家具的型号
    int a, b, c;       // 存储长宽高
    char material[10]; // 床的材质
    int num;           // 沙发可坐人数量

    /////////////////////////////////////////////////////

    cin>>type>>a>>b>>c>>material;         // 输入床的数据
    Bed bed(type,a,b,c,material); // 生成一个床
    bed.Disp();          // 显示床的数据
    bed.Sleep();    // 展示睡觉功能

    /////////////////////////////////////////////////////

    cin>>type>>a>>b>>c>>num;        // 输入沙发的数据
    Sofa s(type,a,b,c,num); // 生成一个沙发
    s.Disp();                 // 显示沙发的数据
    s.WatchTV();           // 展示看电视功能

    /////////////////////////////////////////////////////

    cout<<SleeperSofa::GetNum()<<endl; // 显示两用沙发产品数量
    cin>>type>>a>>b>>c>>material>>num;                    // 输入两用沙发的数据
    SleeperSofa ss(type,a,b,c,material,num); // 生成一个两用沙发
    ss.Disp();                                 // 显示两用沙发各项数据
    cout<<SleeperSofa::GetNum()<<endl;                             // 显示两用沙发产品数量

    //////////////////////////////////////////////////////

    SleeperSofa sss(ss); // 再生成一个
    sss.Disp();              // 显示刚生成产品信息
    cout<<SleeperSofa::GetNum()<<endl;         // 显示两用沙发产品数量

    ///////////////////////////////////////////////////////

    SleeperSofa *ssss = new SleeperSofa(sss);      // 堆中生成一个两用沙发,与前面sss数据相同
    ssss->Disp();   // 显示堆中刚生成的产品信息
    cout<<SleeperSofa::GetNum()<<endl; // 显示两用沙发产品数量

    ///////////////////////////////////////////////////////

    delete ssss;    // 析构堆中产品
    cout<<SleeperSofa::GetNum()<<endl; // 显示两用沙发产品数量

    /////////////////////////////////////////////////////////

    ss.Sleep();         // 展示ss睡觉功能
    ss.WatchTV();     // 展示ss看电视功能
    ss.FoldOut(); // 展示ss折叠功能

    /////////////////////////////////////////////////////

        return 0;
}