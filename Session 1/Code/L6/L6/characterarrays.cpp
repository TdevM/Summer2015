#include<iostream>
using namespace std;
int main() {
    int arr[] = { 1,2,3};
    char ch1[] = "abcd\0efghi";
    ch1[2] = '\0';
    char * ptr = "abcdefghi";

    char name[1000];
    cin.getline(name,1000,'$');
    cout << name << endl;
    char ch = cin.get();
    cout << ch << endl;
/*    char ch = cin.get();
    int index = 0;
    while (ch!='$') {
        name[index] = ch;
        index++;
        ch = cin.get();
    }
    name[index] = '\0';
*/
    cout << sizeof(ptr) << endl;
    cout << ptr << endl;
    cout << ptr+4 << endl;
    ch1[0] = 'c';
    cout << ch1 << endl;
    ptr = ch1+6;
    ptr[0] = 'z';
    char ch2[] = {'a', 'b','c','\0','d','e','f'};

    cout << sizeof(int) << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(ch1) << endl;
    cout << sizeof(ch2) << endl;
    cout << arr << endl;
    cout << ch1 << endl;
    cout << ch1[5] << endl;
    cout << ch2 << endl;
//    cout << arr[4000000] << endl;
  //  cout << ch << endl;
    return 0;
}
