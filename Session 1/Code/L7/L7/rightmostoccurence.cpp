#include<iostream>
#include<cstring>
using namespace std;
int length(char *s) {
    int count = 0;
    while (*s) {
        count++;
        s++;
    }
    return count;
}
int strrfind(char *s, char *t) {
    int slen = length(s);
    int tlen = length(t);
    if (tlen > slen) return -1;
    for(int j = slen-tlen; j >=0; j--) {
        if (s[j] == t[0]) {
            int i = 1;
            while (i < tlen && s[j+i] == t[i]) {
                i++;
            }
            if (i == tlen) {
                return j;
            }
        }
    }
    return -1;
}
void reverse(char *start, char *end) {
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
void compress(char *str) {
    char temp[10000];
    temp[0] = str[0];
    int count = 1, j=1;
    for(int i = 1; str[i-1] != '\0';i++) {
        if (str[i] == str[i-1]) {
            count++;
        } else {
            int k = j;
            while(count > 0) {
                temp[j] = count%10 + '0';
                count = count/10;
                j++;
            }
            if (j > k+1) {
                reverse(temp+k, temp+j-1);
            }
            temp[j] = str[i];
            count = 1;
            j++;
        }
    }
    strcpy(str,temp);
    return;
}
int main() {
    char s[1000], t[1000];
    cin.getline(s, 1000);
    cin.getline(t, 1000);
    int index = strrfind(s,t);
    if (index == -1) {
        cout << t << " is not present in " << s << endl;
    } else {
        cout << " rightmost occurrence of "  << t << " in " << s << " is at " << index  << " index!! " << endl;
    }
    compress(s);
    cout << s << endl;

    return 0;
}
