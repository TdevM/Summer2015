#include<iostream>
using namespace std;
/*int multiply(int a, int b) {
    cout << " In multiply with integer arguments" << endl;
    return a*b;
}*/
int multiply(float a , float b) {
    cout << " In multiply with flaoting arguments" << endl;
    return a * b;
}
int main() {
    cout << multiply(10.0F, 30.5F) << endl;
    cout << multiply(10, 20) << endl;
    cout << multiply('A', 30) << endl;
    cout << multiply(false, 50) << endl;
    return 0;
}
