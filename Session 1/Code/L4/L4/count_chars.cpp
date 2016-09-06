#include<iostream>
using namespace std;
int main() {
/*    int sum = 0, n;
    char ch;
    for(int i =0 ; i < 10; i++) {
        cin >> n >> ch;
        cout << ch;
        sum = sum + n;
    }
    cout << "Sum = " << sum << endl;*/
    int count = 0;
    char ch; 
    ch = cin.get();
    while (ch != '$') {
        count++;
        ch = cin.get();
    }
    cout << "Total Characters " << count << endl;
    return 0;
}
