#include<iostream>
using namespace std;
int main() {
    int a = 0;

    cout << (a++ && 5) << endl;
    a = 0;
    cout << (++a && 5) << endl;

    cout << ~0 << endl;
    cout << ( 7 << 4) << endl;
    return 0;
}
