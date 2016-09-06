#include<iostream>
using namespace std;
void keyPad(char *str, char *comb, int index) {
    if (*str == '\0') {
        cout << comb << endl;
        return;
    }
    char s[][5] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int k = 0;
    int digit = *str - '0';
    while (s[digit][k] != 0) {
        comb[index] = s[digit][k];
        comb[index+1] = 0;
        keyPad(str + 1, comb, index+1);
        k++;
    }
}
int main() {
    char str[] = "999";
    char comb[100];
    keyPad(str, comb, 0);
    return 0;
}
