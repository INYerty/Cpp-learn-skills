#include <iostream>
#include <string>
using namespace std;
class Box
{
public:
    Box();
    ~Box();
    void out()
    {
        cout << x << "," << y << "," << z << endl;
    }
    
private:
    int x;
    int y;
    int z;
};

Box::Box()
{
    x = 20;
    y = 15;
    z = 10;
    cout << "construct a box" << endl;
}
Box::~Box()
{
    cout << "destruct a box" << endl;
}

Box b;

int main()

{
    cout << "main Begin:" << endl;
    Box Array[2];
    b.out();
    cout << "main end" << endl;
    return 0;
}