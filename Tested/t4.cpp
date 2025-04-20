#include <iostream>
using namespace std;

class Test {
public:
    int &geta(int &a) {  // 使用引用传递
        return a;
    }
protected:
    int a;
};

int main() {
    int x;
    cin >> x;
    Test test;
    cout << ++test.geta(x) << endl;
}