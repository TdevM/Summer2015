#include<iostream>
using namespace std;
bool printStringComparison(int n, int limit) {
    if (n > limit ) {
        return false;
    }
    if (n != 0) {
        cout << n << endl;
    }
    int i = n == 0 ? 1 : 0;
    for (; i <= 9; i++) {
        bool ans = printStringComparison(n*10+i, limit);
        if (ans == false) {
            break;
        }
    }
    return true;
}
int main() {
    printStringComparison(0, 333);
    return 0;
}
