#include<iostream>
using namespace std;
int factorial(int n) {
    cout << " Entering Function  with n = " << n << endl;
    if (n == 0) {
        return 1;
    }
    int ans = n * factorial(n-1);
    cout << " Exiting function with n = "<< n << endl;
    return ans;
}
int main() {
    cout << factorial(5) << endl;
    return 0;
}
