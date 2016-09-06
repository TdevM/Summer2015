#include<iostream>
using namespace std;
int main() {
    char str[100];
    cin.getline(str, 100);
    int ws = 0, maxstart = 0, maxlen = 0;
    char ch1 = str[0], ch2 = 0, pws = 0;
    for (int i = 1; str[i] != '\0';i++) {
        if (str[i] != str[i-1]) {
            if (ch2 == 0) {
                ch2 = str[i];
                pws= i;
            } else if (str[i] == ch1 || str[i] == ch2) {
                pws = i;
            } else {
                if(i-ws > maxlen) {
                    maxlen = i-ws;
                    maxstart = ws;
                }
                ws = pws;
                ch1 = str[ws];
                ch2 = str[i];
                pws = i;
            }
        }
    }
    if (maxlen == 0) {
        cout << str << endl;
    } else {
        for (int i = maxstart; i < maxstart+maxlen; i++) {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
