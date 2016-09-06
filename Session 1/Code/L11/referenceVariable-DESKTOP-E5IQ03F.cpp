#include<iostream>
using namespace std;
void myFunction(int &x, int &y) {
    x = 20;
    y = 30;
    return;
}
int main() {

    int a = 10, d = 20;
    myFunction(a,d);
    cout << a << " " << d << endl;
    int arr[] = {1,2,3,5};
    int &c = arr[2];
    c++;
    cout << arr[2] << endl;
    int &b = a;
    b++;
    cout << &b << endl;
    cout << &a << endl;
    cout << a << endl;
    return 0;
}
