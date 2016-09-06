#include<iostream>
using namespace std;
int main() {
    int x = 97+256+512+1024;
    char ch = 'A';
    char chararr[] = "abc";
    cout << chararr << endl;
    int *intptr = (int *)chararr;
    *intptr = 97 + (4096+8192);
    cout << chararr << endl;
    cout << (*intptr) << endl;
    char *charptr = (char *)&x;
    cout << x << endl;
    cout << charptr << endl;
    cout << sizeof(intptr) << endl;
    cout << sizeof(charptr) << endl;

    void *voidptr = charptr;
    cout << voidptr << endl;
    cout << *((int *)voidptr) << endl;


    return 0;
}
