#include<iostream>
using namespace std;
int fibo(int n) {
    cout << n << endl;
    if(n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int ans = fibo(n-2) + fibo(n-1);
    cout << "Ans for n = " << n << " is " << ans << endl;
    return ans;
}
int main() {
   cout << fibo(5) << endl;
   return 0;

}
