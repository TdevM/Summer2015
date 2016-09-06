#include<iostream>
using namespace std;
int main() {
    int digitcount = 0, whitespacecount = 0, alphacount = 0, others = 0;
    char ch;
    for(ch = cin.get(); ch!='$'; ch = cin.get()) {
        if (ch >= '0' && ch <='9') {
            digitcount++;
        } else if ((ch >='a' && ch <='z') || (ch >='A' && ch<='Z')) {
            alphacount++;
        } else if (ch == '\n' || ch == ' ' || ch == '\t') {
            whitespacecount++;
        } else {
            others++;
        }
    }
    cout << " Total digits" << digitcount << endl;
    cout << " Total alphabets" << alphacount << endl;
    cout << " Total whitespaces" << whitespacecount << endl;
    cout << " Rest " << others << endl;
    return 0;

}
