#include<iostream>
using namespace std;
int main() {
    int x = 10;
    cout << (x &1) << endl;
    cout << ((x>>1) & 1) << endl;
    cout << ((x >> 2) & 1) << endl;
    cout << ((x>>3) & 1) << endl;
    return 0;
}
