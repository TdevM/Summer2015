#include<iostream>
#include<string.h>
using namespace std;
int getAllPermuations(char *str, char permuations[][100]) {
    if (*(str+1) == '\0') {
        permuations[0][0] = *str;
        permuations[0][1] = '\0';
        return 1;
    }
    char subp[10000][100];
    int count = getAllPermuations(str+1, subp);
    int len = strlen(subp[0]), anslen = 0;
    for (int i = 0; i < count; i++) {
        for(int j =0 ; j < len+1; j++) {
            for (int k = 0; k < len+1;k++) {
                if (k < j) {
                permuations[anslen][k] = subp[i][k];
                } else if (k == j) {
                    permuations[anslen][k] = str[0];
                } else {
                    permuations[anslen][k] = subp[i][k-1];
                }
            }
            permuations[anslen][len+1] = '\0';
            anslen++;
        }
    }
    return anslen;
}
int main() {
    char str[100], permutations[1000][100];
    cin.getline(str,100);
    int count = getAllPermuations(str, permutations);
    for(int i = 0; i < count;i++) {
        cout << permutations[i] << endl;
    }
}
