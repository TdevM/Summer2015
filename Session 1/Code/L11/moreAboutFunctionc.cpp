#include<iostream>
using namespace std;
int a = 10;
void myFunction() {
    a++;
    cout << a << endl;
}
void functionWithStaticVariable() {
    static int i = 10;
    i++;
    cout << i << endl;
}
int functionWithDefaultArguments(int a = 10, int b=40){
    return a * b;
}
void mygetline(char *str, int len, char delim = '\n') {
}
int main() {
    cout << functionWithDefaultArguments(30) << endl;
    cout << functionWithDefaultArguments(40) << endl;

/*    static int i = 10;
    if(--i) {
        main();
        cout << i << endl;
    }
    return 0;
*/
    /*a++;
    cout << a << endl;
    myFunction();
    cout << a << endl;
    functionWithStaticVariable();
    functionWithStaticVariable();
    functionWithStaticVariable();
    return 0;*/
}
