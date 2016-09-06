#include<iostream>
using namespace std;
void printAllCombination(char *str, char *comb, int index){
    if (*str == '\0') {
        cout << comb << endl;
        return ;
    }
    comb[index] = *str - '0' + 'A';
    comb[index+1] = '\0';
    printAllCombination(str+1, comb, index+1);
    if (*str != '0' && *(str+1) != '\0') {
        int number = (*str - '0')*10 + (*(str+1) - '0');
        if (number < 26) {
            comb[index] = number + 'A';
            comb[index+1] = '\0';
            printAllCombination(str+2, comb, index+1);
        }
    }
    return;
}
int main() {
    char str[100], combination[100];
    cin.getline(str, 100);
    combination[0] = '\0';
    printAllCombination(str, combination,0);
    return 0;
}
