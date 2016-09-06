#include<iostream>
using namespace std;
int main() {
    int n, i = 1, divisor, dividend, j = 1, digit;
    cin >> n;
    while (i * i < n) {
        i = i + 1;
    }
    i = i - 1;
    cout << i << '.';

    divisor  = 2 * i;
    dividend = n - (i * i );
    while( j <= 5) {
        dividend = dividend * 100;
        digit = 0;
        while ((divisor * 10 + digit) * digit < dividend) {
            digit = digit + 1;
        }
        digit = digit  - 1;
        cout << digit;
        dividend = dividend - ((divisor * 10 + digit) * digit);
        divisor = divisor * 10 + 2*digit;
        j = j + 1;
    }
    cout << endl;
    return 0;
}
