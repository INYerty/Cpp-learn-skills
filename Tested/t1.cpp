#include <iostream>
using namespace std;

class Example {
    public:
        Example(int x, int y) : a(x), b(y) { 
            int c,d;
            cin>>c>>d;
            x=c;
            y=d;
        }
        void display() {
            cout << "a: " << a << ", b: " << b << endl;
        }
    private:
        int a, b;
    };

    int main() {
        Example obj(5, 10);
        obj.display();
        return 0;
    }