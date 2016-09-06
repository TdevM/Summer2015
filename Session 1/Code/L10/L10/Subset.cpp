#include<iostream>
#include<cstring>
using namespace std;
void printSubset(char * str, char *subset, int index) {
    cout << "Current String is " << str << endl;
    cout << " Current Subset is " << subset << endl;
    if (*str == '\0') {
        cout << subset << endl;
        return;
    }

    cout << " calling path without including " << *str << endl;
    printSubset(str+1, subset, index);
    cout << " Finished path without including " << *str << endl;
    subset[index] = *str;
    subset[index+1] = '\0';
    cout << " calling path after including " << *str << endl;
    printSubset(str+1, subset, index+1);
    cout << " Finished path after including " << *str << endl;
    return;
}
int main() {
    char str[100], subset[100];
    subset[0] = '\0';
    cin.getline(str, 100);
    printSubset(str, subset, 0);
    return 0;
}
