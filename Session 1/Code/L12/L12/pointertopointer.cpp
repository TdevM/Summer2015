#include<iostream>
using namespace std;
int main() {
    int x = 10;
    int *ptr = &x;
    long long *myotherptr = (long long*) &ptr;
    cout <<*((int *)*myotherptr)<< endl;
    return 0;
}
