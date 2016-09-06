#include<iostream>
using namespace std;
float convertFtoC(int c) {
    return (5.0/9) * (c - 32);
}
void printFtoC(int start,int limit, int step) {
    for(int i = start; i <=limit; i+=step) {
        cout << i << " " << convertFtoC(i) << endl;
    }
    return;
}
int factorial(int n ) {
    int factorial = 1;
    for(int i = n; i >=1;i--) {
        factorial*=i;
    }
    return factorial;
}
bool checkISPrime(int n) {
    for(int i = 2; i < n/2;i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
void printPrimeNumbersToN(int N) {
    for(int i = 2; i <= N; i++) {
        if (checkISPrime(i) == true) {
            cout << i << " ";
        }
    }
    return;
}
int main() {
    int a = 100;
    cout << " Anushray " ;
    a++;
    printFtoC(0, 200, 20);
    int start, limit, step;
    cin >> start >> limit >> step;
    printFtoClimit,start, step);
    cout << a << endl;
    cout << " welcome to coding blocks!!!" << endl;
    return 0;
}
