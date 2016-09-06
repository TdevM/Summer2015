// Read  P,R,T and calculate SI
#include<iostream>
using namespace std;
int main() {
    int principal;
    int rate;
    int time_years;
    cin >> principal >> rate >> time_years;
    float si = (principal * rate * time_years)/100.0;
    cout << "Simple Interest is" << si << '\n';
    return 0;
}
