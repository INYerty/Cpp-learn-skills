#include <iostream>
using namespace std;

void hanoi(int n, char source, char target, char auxiliary) {
    if (n > 0) {
        hanoi(n - 1, source, auxiliary, target);
        cout << "Move disk " << n << " from " << source << " to " << target << endl;
        hanoi(n - 1, auxiliary, target, source);
    }
}
int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}