#include<iostream>
using namespace std;
int main() {
    int N, reverse;
    cin >> N;
    for(reverse = 0; N > 0; N = N/10) {
        reverse  = reverse * 10 + N%10;
    }
    cout << reverse << endl;
}
