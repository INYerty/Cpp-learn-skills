// 自行设计一个日期类Tdate，含有三个数据成员：月、日、年。
#include <iostream>
using namespace std;

class Tdate
{
public:
    void Set(int, int, int);
    void out();
    void Edit(int,int,int);

private:
    int month, day, year;
};

void Tdate::Set(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Tdate::out()
{
    cout << year << "/" << month << "/" << day << endl;
}

void Tdate::Edit(int newyear,int newmonth,int newday)
{
    day = newday;
    month = newmonth;
    year = newyear;
}
// 用下面的主函数生成一个日期对象，然后在fn函数中将日期设置为某年某月某日，并输出这个日期。

int main()
{
    int a, b, c;
    Tdate d; // 生成一个日期对象
    cin >> a >> b >> c;
    d.Set(c, a, b); // 将对象d设置成c年a月b日
    void fn(Tdate &); // 声明fn函数
    fn(d); // 调用fn函数，不允许拿a,b,c做参数
    d.out(); // 输出经fn修改后的新日期
    return 0;
}

void fn(Tdate &d)
{
    d.out(); // 先显示原来的日期，即c年a月b日
    int m,day,y;
    cin>>m>>day>>y; // 要设置的月日年
    d.Edit(y,m,day);// 在此填写代码，将主函数中对象设置成新日期
}
