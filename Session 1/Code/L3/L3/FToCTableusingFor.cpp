#include<iostream>
using namespace std;
int main() {
 //   cout << a << endl;
    int inital, final, step;
    cin >> inital >> final >> step;
    for(;inital<=final; inital+=step) {
        cout << inital << " " << (int) (((float) 5/ 9) *(inital - 32)) << endl;
    }
    return 0;
}
