#include<iostream>
using namespace std;
int main() {
    const double pi = 3.14;
//    int a = 099;

 //   cout << a << endl;
    int inital, final, step;
    cin >> inital >> final >> step;
//   bool a = true;
 //  pi = 5.43;
    while (inital <= final) {
        cout << 'n';
        cout << inital << " " << ((float) 5/ 9) *(inital - 32) << endl;
        inital  = inital + step;
    }
    return 0;
}
