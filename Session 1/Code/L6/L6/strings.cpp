#include<iostream>
using namespace std;
int length(char * str) {
    int len = 0; 
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}
bool isPalin(char * str) {
    int start = 0, end = length(str)-1;
    while (start <= end && str[start] == str[end]) {
        start++;
        end--;
    }
    return start > end ? 1 : 0; // return str[start] != str[end] : 0 : 1;
}
int main() {
    char mystring[1000];
    cin.getline(mystring, 1000);
    cout << length(mystring);
    cout << mystring << "random!" << endl;
    return 0;
}
