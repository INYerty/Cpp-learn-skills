#include <iostream>
using namespace std;

class Box {
private:
    int x, y, z;      // 长、宽、高（单位 cm）
    double value;      // 体积（立方米）
    int nummax;        // 最大能装的苹果数
    int bcount;        // 当前箱子里的苹果数

public:
    // 标准箱子构造函数
    Box() {
        x = 40;
        y = 20;
        z = 25;
        bcount = 0;
        value = (x * y * z) / 1000000.0;  // 计算体积（立方米）
        nummax = value * 1000;            // 计算最大苹果数
    }

    // 定制箱子构造函数
    Box(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
        bcount = 0;
        value = (x * y * z) / 1000000.0;
        nummax = value * 1000;
    }

    // 添加苹果
    void add(int cou) {
            bcount += cou;
    }

    // 取出苹果
    void out(int cou1) {
            bcount -= cou1;
    }

    // 显示当前苹果数量
    void left() {
        cout << bcount << endl;
    }

    // 析构函数，销毁时检查是否为空
    ~Box() {
        if (bcount > 0) {
            cout << "Empty First" << endl;
        }
    }
};

int main() {
    int choice;
    cin >> choice;

    Box b1;
    if (choice == 2) {
        int a, b, c;
        cin >> a >> b >> c;
        b1 = Box(a, b, c);
    }

    int cou, cou1;// 添加和取出的苹果数量
    cin >> cou;//add
    b1.add(cou);
    b1.left();//剩余

    cin >> cou1;//取出
    b1.out(cou1);
    b1.left();//剩余

    return 0;
}
